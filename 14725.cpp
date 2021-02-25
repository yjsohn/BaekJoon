#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
vector<string> ans;
vector<vector<string>> foods;

string Depth(int d) {	//parameter로 깊이 받아서 알맞은 "--" 출력해주기
	string str = "";
	for (int i = 0; i < d; i++) {
		str += "--";
	}
	return str;
}

void MakeTree() {	//트리 도출
	for (int i = 0; i < foods[0].size(); i++) {	//첫 번째 index tree는 미리 구현
		string str = Depth(i);
		ans.push_back(str + foods[0][i]);
	}

	for (int i = 1; i < N; i++) {	//두 번째 index tree부터는 첫 번째 tree와 비교하며 구현
		bool isSame = true;
		for (int j = 0; j < foods[i].size(); j++) {
			int before = i - 1;
			if (isSame) {
				if (foods[before].size() - 1 < j || foods[before][j] != foods[i][j])
					isSame = false;
				else
					continue;
			}
			//앞의 tree와 다른 node가 나왔다면 tree에 추가
			string str = Depth(j);
			ans.push_back(str + foods[i][j]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int K;
		cin >> K;
		vector<string> v;
		for (int j = 0; j < K; j++) {
			string str;
			cin >> str;
			v.push_back(str);
		}
		foods.push_back(v);
	}
    
	sort(foods.begin(), foods.end());
	MakeTree();

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}