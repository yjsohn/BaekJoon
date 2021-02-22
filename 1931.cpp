#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//끝나는 시간이 이른 순으로 먼저 배치
int N;
vector<pair<int, int>> conference;	//{끝나는 시간, 시작 시간}

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second <= p2.second) {
		if (p1.second == p2.second)
			return p1.first < p2.first;
		else
			return true;
	}
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		conference.push_back({ e, s });
	}
	sort(conference.begin(), conference.end());
	int cnt = 1, fin = conference[0].first;

	for (int i = 1; i < N; i++) {
		if (fin <= conference[i].second) {
			cnt++; fin = conference[i].first;
		}
	}

	cout << cnt << "\n";
}