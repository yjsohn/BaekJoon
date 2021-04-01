#include <iostream>
#include <cstring>
#include <queue>
//발상의 전환 필요: 치즈 중심이 아닌 공기 중심

/*참조 블로그
https://steady-coding.tistory.com/173
https://jaimemin.tistory.com/1032
*/

using namespace std;

enum { CHEESE = 1, PREAIR, AIR };

int N, M, cheese_cnt, ans = 1;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int cheese[101][101];
bool visited[101][101];

bool MeltCheese() {
	bool cleared = true;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cheese[i][j] == PREAIR) {
				cheese[i][j] = AIR;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cheese[i][j] == CHEESE) {
				cleared = false;
			}
		}
	}
	return cleared;
}

bool FindAir() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	memset(visited, false, sizeof(visited));
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		cheese[y][x] = AIR;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
				continue;
			if (cheese[ny][nx] == CHEESE) {
				cheese[ny][nx] = PREAIR;
				cheese_cnt++;
			}
			else if(cheese[ny][nx] == 0 || cheese[ny][nx] == AIR)
				q.push({ny, nx});
			visited[ny][nx] = true;
		}
	}
	return MeltCheese();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> cheese[i][j];
		}
	}
	while (1) {
		cheese_cnt = 0;
		if (FindAir())
			break;
		ans++;
	}
	cout << ans << "\n" << cheese_cnt << "\n";
}