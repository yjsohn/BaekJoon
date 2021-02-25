#include <iostream>

using namespace std;
//끝에 1이 있으면 떼기 -> 어차피 나누기 2 안될거니까
//짝수면 / 2


int A, B, cnt;

int main() {
	cin >> A >> B;
	while (A < B) {
		if (B % 2 == 0)	B /= 2;
		else if (B % 10 == 1)	B /= 10;
		else break;
		cnt++;
		if (A == B) break;
	}
	cout << (A == B ? cnt + 1 : -1) << "\n";
}