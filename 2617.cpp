#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, ans = 0;
bool h_visited[100];
bool l_visited[100];
vector<vector<int>> heavier(100);
vector<vector<int>> lighter(100);

int HeavierDFS(int node) {
	int h = 1;
	for (int i = 0; i < heavier[node].size(); i++) {
		int next_node = heavier[node][i];
		if (!h_visited[next_node]) {
			h_visited[next_node] = true;
			h += HeavierDFS(next_node);
		}
	}
	return h;
}

int LighterDFS(int node) {
	int l = 1;
	for (int i = 0; i < lighter[node].size(); i++) {
		int next_node = lighter[node][i];
		if (!l_visited[next_node]) {
			l_visited[next_node] = true;
			l += LighterDFS(next_node);
		}
	}
	return l;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int h, l;
		cin >> h >> l;
		heavier[l].push_back(h);
		lighter[h].push_back(l);
	}

	for (int i = 1; i <= N; i++) {
		memset(h_visited, false, sizeof(h_visited));
		memset(l_visited, false, sizeof(l_visited));
		h_visited[i] = l_visited[i] = true;

		if (HeavierDFS(i) - 1 > N / 2 || LighterDFS(i) - 1 > N / 2)	ans++;
	}
	cout << ans << "\n";
}