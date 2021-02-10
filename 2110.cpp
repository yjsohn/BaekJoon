#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> loc;

int InstallRouter() {
	//기준을 공유기간 간격으로

	int left = 1, right = loc[N - 1] - loc[0], mid, ans;
	while (left <= right) {
		mid = (left + right) / 2;
		int cnt = 1;
		int start = loc[0];
		for (int i = 1; i < N; i++) {
			int dis = loc[i] - start;
			if (mid <= dis) {
				start = loc[i];
				cnt++;
			}
		}
		if (cnt >= C) {
			left = mid + 1;
			ans = mid;	//모든 공유기간 거리는 최소 mid 이상 && (cnt == C)여도 성립하는 mid가 최대가 될 때까지 while문 반복됨 
		}
		else {
			right = mid - 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int r;
		cin >> r;
		loc.push_back(r);
	}
	sort(loc.begin(), loc.end());
	cout << InstallRouter() << "\n";
}