#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, sum, min_diff = 1e9, power[21][21];

vector<int> TheOtherTeam(vector<int> v) {	//상대팀에 해당하는 멤버 구하기
	vector<int> v2;
	bool selected[21];
	memset(selected, false, sizeof(selected));
	
	for (int i = 0; i < N/2; i++) {
		selected[v[i]] = true;
	}
	for (int i = 1; i <= N; i++) {
		if (!selected[i])
			v2.push_back(i);
	}
	return v2;
}

int CalcPower(vector<int> v) {	//능력치 계산
	int s = 0;
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			s += power[v[i]][v[j]];
		}
	}
	return s;
}

void Match(int n, vector<int> v) {	//현재 멤버를 팀에 포함시킨다/안 시킨다로 recursive function 구현 (func call stack 최대 20)
	if (v.size() == N / 2) {
		vector<int> v2 = TheOtherTeam(v);
		int p1 = CalcPower(v);
		int p2 = CalcPower(v2);
		int diff = abs(p1 - p2);
		min_diff = min(diff, min_diff);
		return;
	}
	if (n > N)
		return;
	Match(n + 1, v);
	v.push_back(n);
	Match(n + 1, v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int p;
			cin >> p;
			power[i][j] = p;
			sum += p;
		}
	}
	vector<int> v;
	v.push_back(1);
	Match(2, v);	//1은 항상 포함하도록 해야 중복되지 않게 팀을 나눌 수 있음 
	cout << min_diff << "\n";
}