#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> coin;

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int c;
		cin >> c;
		coin.push_back(c);
	}

	int ans = 0, index = coin.size() - 1;
	while(K){	//A(i)는 A(i-1)의 배수이기 때문에 무조건적 값이 큰 동전일수록 많이 사용하는 것이 유리함
		ans += K / coin[index];
		K %= coin[index--];
	}
	cout << ans << "\n";
}