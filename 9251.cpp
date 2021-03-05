#include <iostream>
#include <string>

using namespace std;

string str1, str2;
int dp[1001][1001];

int Max(int a, int b) {
	return (a > b ? a : b);
}

void LCS() {
	int n = str1.length(), m = str2.length();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (str1[i] == str2[j]) //비교중인 str1과 str2의 문자가 동일
				dp[i + 1][j + 1] = dp[i][j] + 1;    //각자, 현재 비교중인 문자를 제외한 LCS + 1
			else //비교중인 str1과 str2의 문자가 상이
				dp[i + 1][j + 1] = Max(dp[i][j + 1], dp[i + 1][j]); //Max(str1에서 현재 비교중인 문자 제외 & 비교중인 str2의 LCS, 동일 조건을 str2에 적용)
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> str1 >> str2;
	int n = str1.length(), m = str2.length();
	LCS();
	cout << dp[n][m] << "\n";
}