#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> coordinate;  //{좌표값, 인덱스}
vector<int> ans(1000001);

void Compress() {   //좌표 압축
	int order = 0, std = coordinate[0].first;
	for (int i = 0; i < N; i++) {
		int index = coordinate[i].second;
		if (coordinate[i].first == std) //이전 좌표값과 동일
			ans[index] = order;
		else {  //새로운 좌표값
			ans[index] = ++order;
			std = coordinate[i].first;  //새로운 기준 적용
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		coordinate.push_back(make_pair(x, i));
	}
	sort(coordinate.begin(), coordinate.end());

	Compress();
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
}