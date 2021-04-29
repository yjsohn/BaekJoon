#include <iostream>
#include <algorithm>

using namespace std;

int N;
int bamboo[501][501];
int dp[501][501];//(y, x)에서 가질 수 있는 최댓값
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

int Move(int y, int x) {    
	if (dp[y][x] > 0)	//이미 방문
		return dp[y][x];
	dp[y][x] = 1;	//첫 방문
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N)
			continue;
		if (bamboo[ny][nx] <= bamboo[y][x])
			continue;
		dp[y][x] = max(dp[y][x], Move(ny, nx) + 1);
	}
	return dp[y][x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> bamboo[i][j];
		}
	}
	int K = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			K = max(Move(i, j), K);
		}
	}
	cout << K << "\n";
    return 0;
}