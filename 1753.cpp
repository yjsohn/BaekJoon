#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int V, E, K;
vector<pair<int, int>> graph[20001];
int d[20001];
priority_queue<pair<int, int>> pq;

void dijkstra(int start) {
	d[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int now = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		if (d[now] < dist)
			continue;

		for (int j = 0; j < graph[now].size(); j++) {
			int node = graph[now][j].first;
			int cost = d[now] + graph[now][j].second;	//d[now] == dist
			if (cost < d[node]) {
				d[node] = cost;
				pq.push({ -cost, node });	//priority_queue는 가장 큰 값을 top에 두기 때문에 음수로 바꾸어 저장해야 가장 작은 값이 top에 놓임
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}
	fill_n(d, 20001, INF);
	dijkstra(K);
	for (int i = 1; i <= V; i++) {
		if (d[i] == INF)
			cout << "INF";
		else
			cout << d[i];
		cout << "\n";
	}
}