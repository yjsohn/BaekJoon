#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<int> alpha(26);

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		int cipher = 1;
		//각 알파벳이 의미하는 숫자를 알 필요 없이 동일한 알파벳이 어느 자리에 얼마나 등장하는지만 알 수 있으면 됨
		for (int j = str.length() - 1; j >= 0; j--) {	//일의자리부터 계산
			int index = str[j] - 'A';
			alpha[index] += cipher;
			cipher *= 10;	//자릿수
		}
	}
	sort(alpha.begin(), alpha.end(), greater<int>());	//내림차순 정렬
	int sum = 0;
	for (int i = 0, j = 9; i < 26; i++, j--) {	//j: 알파벳에게 부여된 수
		if (!alpha[i])
			break;
		sum += j * alpha[i];
	}
	cout << sum << "\n";
}