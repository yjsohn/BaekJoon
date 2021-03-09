#include <iostream>
#include <algorithm>
#define INF 100000

using namespace std;

int N, M, R;
int dist[101][101];
int items[101];

void Floyd() {	//각 지역간 거리 구하기
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int tmp = dist[i][k] + dist[k][j];
				dist[i][j] = (tmp < dist[i][j] ? tmp : dist[i][j]);
			}
		}
	}
}

int MaxItem() {	//수색범위 내에서 얻을 수 있는 최대의 아이템 수 구하기
	int ans = 0;

	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] <= M) {
				sum += items[j];
			}
		}
		ans = max(ans, sum);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++) {
		cin >> items[i];
	}
	for (int i = 1; i <= N; i++) {	//Floyd - Warshall을 위한 기초작업
		for (int j = 1; j <= N; j++) {
			dist[i][j] = (i == j ? 0 : INF);
		}
	}
	for (int i = 0; i < R; i++) {	//양방향 그래프 생성
		int a, b, l;
		cin >> a >> b >> l;
		dist[a][b] = dist[b][a] = l;
	}

	Floyd();
	cout << MaxItem() << "\n";
}