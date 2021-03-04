#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int dp[102][100002];
//완전탐색시 시간초과 발생 (2^100)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	vector<pair<int, int>> object(N + 1);
	for (int i = 1; i <= N; i++) {
		int w, v;
		cin >> w >> v;
		object[i] = { w, v };
	}
	int max_v = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			int w = object[i].first;
			int v = object[i].second;
			if (j < w)	dp[i][j] = dp[i - 1][j];	//i번째 물건을 포함하는 최대 가치를 구할 수 없으므로 i-1번째의 j무게일 때의 최대값으로 대체
			else {
				dp[i][j] = max(v + dp[i - 1][j - w], dp[i - 1][j]);	//max(i번째 물건을 포함하는 최대 가치, i-1번째의 j무게일 때의 최대값)
			}
		}
	}

	cout << dp[N][K] << "\n";	//최종적으로 업데이트된 최대 값 = dp[N][K]
}