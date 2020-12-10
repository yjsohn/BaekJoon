#include <iostream>

using namespace std;

int N, M;
bool room[51][51];	//true: wall
bool visited[51][51];

//전진
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
//후진
int by[4] = {1, 0, -1, 0};
int bx[4] = {0, -1, 0, 1};

int Clean(int r, int c, int d) {
	int cnt = 0;
	int turned = 0;
	while (true) {
		if (!room[r][c] && !visited[r][c]) {	//clean the area
			visited[r][c] = true;
			cnt++;
		}
		d = (d + 3) % 4;	//turn left
		turned++;
		int ny = r + dy[d];
		int nx = c + dx[d];

		if (!room[ny][nx] && !visited[ny][nx]) {	//cleanable area
			r = ny; c = nx;
			turned = 0;
		}
		else if (turned == 4) {	//unable to clean all directions
            //go backward
			r = r + by[d];
			c = c + bx[d];
			if (room[r][c])	//unable to go backward
				return cnt;
			turned = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cin.tie(NULL);

	cin >> N >> M;
	int r, c, d;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room[i][j];
		}
	}
	cout << Clean(r, c, d) << "\n";
}