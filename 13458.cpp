#include <iostream>

using namespace std;

int N, B, C;
int A[1000001];
long long ans;

int main() {
	cin >> N;
	ans = N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;
	for (int i = 0; i < N; i++) {
		int tmp = A[i] - B;
		if (tmp > 0) {
			int quotient = tmp / C;
			int remainder = tmp % C;
			ans += quotient;
			if (remainder)
				ans++;
		}
	}
	cout << ans << "\n";
}