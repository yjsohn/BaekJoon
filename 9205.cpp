#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int t, n;
vector<pair<int, int>> coordinate;
vector<int> graph[102];
bool visited[102];

bool Distance(pair<int, int> p1, pair<int, int> p2) {
	int d = abs(p1.first - p2.first) + abs(p1.second - p2.second);	//맨허튼 거리
	bool ans = (d > 50 * 20 ? false : true);
	return ans;
}

void DFS(int node) {	
	//Q.visited[] = false가 없는데도 성립하는 이유는?
	//A.이미 한 번 들러서 실패한 편의점은 어차피 다시 들러도 실패 -> 들리지 않도록 만들어줘야 시간초과 발생x
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (!visited[next]) {
			DFS(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		coordinate.clear();	//좌표 벡터 초기화
		memset(visited, false, sizeof(visited));	//visited 배열 초기화
		for (int i = 0; i < n + 2; i++) {
			int x, y;
			cin >> x >> y;
			coordinate.push_back(make_pair(x, y));
			graph[i].clear();	//graph 각 index의 벡터 초기화
		}

		for (int i = 0; i < n + 2; i++) {	//그래프 연결
			for (int j = i + 1; j < n + 2; j++) {
				if (Distance(coordinate[i], coordinate[j])) {
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}
		DFS(0);
		string ans = (visited[n + 1] ? "happy" : "sad");
		cout << ans << "\n";
	}

	system("pause");
}