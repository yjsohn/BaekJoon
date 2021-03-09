#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

int N, D, C;
int d[10001];
vector<pair<int, int>> graph[10001];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty()) {
		int now = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();

		if (d[now] < dist)
			continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int node = graph[now][i].second;
			int cost = d[now] + graph[now][i].first;
			if (cost < d[node]) {
				pq.push({ -cost, node });
				d[node] = cost;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> N >> D >> C;
		for (int i = 1; i <= N; i++) {
			graph[i].clear();
		}
		for (int i = 0; i < D; i++) {
			int a, b, v;
			cin >> a >> b >> v;
			graph[b].push_back({ v, a });
		}
		fill_n(d, N + 1, INF);
		dijkstra(C);
		int sec = 0, cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (d[i] < INF) {	//감염되는데 0초 걸리는 컴퓨터도 있음. => (d[i] < INF -> visited)
				sec = max(sec, d[i]);	//감염되는데 가장 오래걸리는 컴퓨터 == 마지막으로 감염되는 컴퓨터
				cnt++;
			}
		}
		cout << cnt << " " << sec << "\n";
	}
}
