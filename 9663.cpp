#include <iostream>

using namespace std;

int N, cnt;
bool visited[15][15];
bool cols[15];

void SetQueen(int row) {
	if (row == N) {	//N-1번째 줄까지 성공
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {	//select column
		if (cols[i]) continue;
		bool flag = false;
		for (int ny = row - 1, nx = i + 1; ny >= 0 && nx < N; ny--, nx++) {	//오른쪽 대각선 탐색
			if (visited[ny][nx]) {
				flag = true;
				break;
			}
		}
		if (flag)
			continue;
		for (int ny = row - 1, nx = i - 1; ny >= 0 && nx >= 0; ny--, nx--) {	//왼쪽 대각선 탐색
			if (visited[ny][nx]) {
				flag = true;
				break;
			}
		}
		if (flag)
			continue;

		visited[row][i] = true;
		cols[i] = true;
		SetQueen(row + 1);
		visited[row][i] = false;
		cols[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N;
	SetQueen(0);
	cout << cnt << "\n";
}