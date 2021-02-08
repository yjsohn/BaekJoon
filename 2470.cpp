#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> v;

vector<int> Blend() {
	vector<int> ans(2);
	int L = 0, R = v.size() - 1;
	int min_val = 0x7FFFFFFF;   //int 최대값

	while (L < R) {
		int tmp = v[L] + v[R];
		if (abs(tmp) < abs(min_val)) {
			ans[0] = v[L]; ans[1] = v[R];
			min_val = tmp;
		}
		if (tmp == 0)	return ans;
		tmp < 0 ? L++ : R--;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int l;
		cin >> l;
		v.push_back(l);
	}
	sort(v.begin(), v.end());
	vector<int> ans = Blend();
	cout << ans[0] << " " << ans[1] << "\n";
}