#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int T;
string str;	//매개변수로 넘겨줬더니 메모리 초과

bool isPalindrome() {
	int left = 0, right = str.length() - 1;
	while (left <= right) {
		if (str[left++] != str[right--])
			return false;
	}
	return true;
}

//Recursive Function
bool isPseudo(int left, int right, int skipped) {	//처음 코드의 반례: baaba 
	//처음에 했던 while문으로 안 되는 이유: 동일한 left와 right로 left + 1, right - 1을 모두 실행해봐야해서
	if (left > right)	return true;
	else if (str[left] == str[right])
		return isPseudo(left + 1, right - 1, skipped);
	else if (skipped)	return false;
	else {
		return max(isPseudo(left + 1, right, true), isPseudo(left, right - 1, true));
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while (T--) {
		cin >> str;
		if (isPalindrome())
			cout << 0 << "\n";
		else if (isPseudo(0, str.length() - 1, false))
			cout << 1 << "\n";
		else
			cout << 2 << "\n";
	}
}