#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M, max_len = 0;
int dp[1001][1001];

void MakeSquare() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!dp[i][j])	continue;
			dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			max_len = (dp[i][j] > max_len ? dp[i][j] : max_len);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {	//N == 1, M == 1일 때의 경우도 고려하도록 dp[1][1]부터 저장
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			dp[i][j + 1] = str[j] - '0';
		}
	}
	MakeSquare();
	cout << max_len * max_len << "\n";
}