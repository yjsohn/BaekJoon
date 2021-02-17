#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 10000000	//플로이드-와샬에서의 INF

using namespace std;

int n, min_score = INF;
int score[51];
int friends[51][51];
vector<int> presidents;	//후보자

void Floyd() {	//플로이드 와샬
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int tmp = friends[i][k] + friends[k][j];
				friends[i][j] = (tmp < friends[i][j] ? tmp : friends[i][j]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {	//자기 자신과의 관계 = 0; 다른 사람과의 관계 = INF;
		for (int j = 1; j <= n; j++) {
			friends[i][j] = (i == j ? 0 : INF);
		}
	}
	memset(score, 0, sizeof(score));

	while (true) {
		int p, q;
		cin >> p >> q;
		if (p == -1)
			break;
		friends[p][q] = friends[q][p] = 1;	//직접적인 연관 = 1
	}

	Floyd();

	for (int i = 1; i <= n; i++) {	//각 회원의 점수, 회장 후보자의 점수 결정
		for (int j = 1; j <= n; j++) {
			if (i == j)	continue;
			score[i] = (friends[i][j] > score[i] ? friends[i][j] : score[i]);	//한 회원의 score = 가장 먼 사람과의 관계 점수
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