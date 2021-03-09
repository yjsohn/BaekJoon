#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define INF 1e9

using namespace std;

int N, M;
int d[1001];
vector<pair<int, int>> graph[1001];
priority_queue<pair<int, int>> pq;
int before[1001];	//최적의 경로가 갱신된다면 부모 노드를 저장해주기

void dijkstra(int start) {
	d[start] = 0;
	pq.push({ 0, start });
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
				d[node] = cost;
				pq.push({ -cost, node });
				before[node] = now;	//경로 갱신 -> 부모 노드 저장
			}
		}
	}
}

void Track(int start, int end) {    //거쳐가는 도시 수, 경로 출력
	int node = end;
	stack<int> s;	//역추적이기 때문에 stack에 경로 저장 후 top부터 출력
	while (node != 0) {
		s.push(node);
		node = before[node];
	}
	cout << s.size() << "\n";	//!거쳐가는 도시 개수 반드시 출력해줄 것! - 처음에 이거 없어서 WA
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, v;
		cin >> a >> b >> v;
		graph[a].push_back({ v, b });
	}

	int dept, dest;
	cin >> dept >> dest;

	fill_n(d, N + 1, INF);
	dijkstra(dept);
	cout << d[dest] << "\n";
	Track(dept, dest);
}