#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int num[501][501];
int ans;
bool visited[501][501];
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x, int cnt, int sum){
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
			continue;
		int tmp;
		tmp = sum + num[ny][nx];
		if (cnt == 4)
			ans = max(ans, tmp);
		else {
			visited[ny][nx] = true;
			dfs(ny, nx, cnt + 1, tmp);
			visited[ny][nx] = false;
		}
	}
}

void TetrominoT(int y, int x) {
	//ㅏ
	if (y + 1 < N && y + 2 < N && x + 1 < M)
		ans = max(ans, num[y][x] + num[y + 1][x] + num[y + 2][x] + num[y + 1][x + 1]);
	//ㅗ
	if (y + 1 < N && x - 1 >= 0 && x + 1 < M)
		ans = max(ans, num[y][x] + num[y + 1][x] + num[y + 1][x - 1] + num[y + 1][x + 1]);
	
	//ㅓ
	if (y + 1 < N && y + 2 < N && x - 1 >= 0)
		ans = max(ans, num[y][x] + num[y + 1][x] + num[y + 2][x] + num[y + 1][x - 1]);
	
	//ㅜ
	if (y + 1 < N && x - 1 >= 0 && x + 1 < M)
		ans = max(ans, num[y][x] + num[y + 1][x] + num[y][x - 1] + num[y][x + 1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> num[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = true;
			dfs(i, j, 1, 0);
			TetrominoT(i, j);
			visited[i][j] = false;
		}
	}
	cout << ans << "\n";
}