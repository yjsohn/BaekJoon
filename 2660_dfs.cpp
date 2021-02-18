#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 987654321

using namespace std;

int n, min_score = 0x7F7F7F7F;
int score[51];
int friendship[51][51];
bool visited[51];
vector<int> graph[51];
vector<int> presidents;	//후보자

void DFS(int node, int value, int org) {
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (!visited[next]) {
			friendship[org][next] = min(friendship[org][next], value + 1);
			visited[next] = true;
			DFS(next, value + 1, org);
			visited[next] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	memset(friendship, 0x7F, sizeof(friendship));
	memset(score, 0, sizeof(score));
	
	while (true) {
		int p, q;
		cin >> p >> q;
		if (p == -1)
			break;
		graph[p].push_back(q);
		graph[q].push_back(p);
	}
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		visited[i] = true;
		DFS(i, 0, i);
		//각 회원의 점수, 회장 후보자의 점수 결정
		for (int j = 1; j <= n; j++) {
			if (i == j)	continue;
			score[i] = (friendship[i][j] > score[i] ? friendship[i][j] : score[i]);	//한 회원의 score = 가장 먼 사람과의 관계 점수
		}
		min_score = (score[i] < min_score ? score[i] : min_score);	//후보자의 점수 = 회원들의 점수 중 가장 작은 값
	}

	
	for (int i = 1; i <= n; i++) {	//후보자 선출
		if (score[i] == min_score)
			presidents.push_back(i);
	}
	cout << min_score << " " << presidents.size() << "\n";
	for (int i = 0; i < presidents.size(); i++)
		cout << presidents[i] << " ";
}