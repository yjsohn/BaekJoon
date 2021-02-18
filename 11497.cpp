#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
vector<int> logs;

int MinDiff() {
	int max_diff, sorted[10001];
	int mid = N / 2;
	sorted[mid] = logs[N - 1];	//가장 큰 값을 가운데에 배치
	for (int i = 0, j = 0; i < mid; i++, j += 2) {
		sorted[i] = logs[j];
		int next = N - 1 - i;
		if (next == mid)	break;
		sorted[next] = logs[j + 1];
	}

	max_diff = abs(sorted[N - 1] - sorted[0]);
	for (int i = 0; i < N - 1; i++) {
		int tmp = abs(sorted[i] - sorted[i + 1]);
		max_diff = (tmp > max_diff ? tmp : max_diff);
	}

	return max_diff;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  //입력 시간 단축

	cin >> T;
	while (T--) {
		logs.clear();
		cin >> N;
		for (int i = 0; i < N; i++) {
			int l;
			cin >> l;
			logs.push_back(l);
		}
		sort(logs.begin(), logs.end());
		cout << MinDiff() << "\n";
	}
}