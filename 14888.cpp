#include <iostream>
#include <algorithm>

using namespace std;

int N, ans1 = -0x7FFFFFFF, ans2 = 0x7FFFFFFF;
int A[11], op[4];

void FindMax(int now, int cnt) {
	for (int i = 0; i < 4; i++) {
		if (!op[i])
			continue;
		int tmp;
		switch (i) {
		case 0:	//+
			tmp = now + A[cnt];
			break;
		case 1:	//-
			tmp = now - A[cnt];
			break;
		case 2:	//*
			tmp = now * A[cnt];
			break;
		default:	// /
			tmp = now / A[cnt];
			break;
		}
		if (cnt == N - 1) {
			ans1 = max(ans1, tmp);
			ans2 = min(ans2, tmp);
		}
		else {
			op[i]--;
			FindMax(tmp, cnt + 1);
			op[i]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	FindMax(A[0], 1);
	cout << ans1 << "\n" << ans2 << "\n";
}