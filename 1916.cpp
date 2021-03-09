#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9

using namespace std;

int N, M;
int d[1001];
vector<pair<int, int>> graph[1001];

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (d[now] < dist)	//d를 INF로 초기화 시키지 않으면 d[] = 0으로 항상 가장 작은 값 -> 갱신 안 됨
			continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int cost = d[now] + graph[now][i].first;
			int next = graph[now][i].second;
			if (cost < d[next]) {
				d[next] = cost;
				pq.push({ -cost, next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int dept, dest;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, v;
		cin >> a >> b >> v;
		graph[a].push_back({ v, b });
	}
	fill_n(d, N + 1, INF);
	cin >> dept >> dest;
	dijkstra(dept);
	cout << d[dest] << "\n";
}