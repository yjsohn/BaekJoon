#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//전화번호를 string으로 저장한 뒤 오름차순 정렬하여 앞, 뒤 번호의 일관성 여부만 판단 후 답 도출
int T, N;
vector<string> phone;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		phone.clear();
		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;
			phone.push_back(str);
		}
		sort(phone.begin(), phone.end());
		bool ans;
		for (int i = 0; i < N - 1; i++) {
			ans = true;	//앞, 뒤 번호 동일 여부
			if (phone[i].length() >= phone[i + 1].length()) {	//길이가 동일하거나 앞 번호가 더 길면 무조건 일관성O
				ans = false;
				continue;
			}
			for (int j = 0; j < phone[i].length(); j++) {
				if (phone[i][j] != phone[i + 1][j]) {	//번호 중간에 서로 다른 숫자가 나오면 무조건 일관성 O
					ans = false;
					break;
				}
			}
			if (ans)	break;	//일관성 없는 번호 발생시 break
		}
		if (ans)	//일관성 없음
			cout << "NO\n";
		else //일관성 있음
			cout << "YES\n";
	}
}