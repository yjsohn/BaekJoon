#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> crane;
vector<int> box;
vector<int> order(50);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int c;
		cin >> c;
		crane.push_back(c);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int b;
		cin >> b;
		box.push_back(b);
	}
	sort(crane.begin(), crane.end());
	sort(box.begin(), box.end());

	if (crane.back() < box.back()) {	//가장 무거운 박스를 옮길 수 없는 경우
		cout << -1 << "\n";
		return 0;
	}
	int cnt = 0, pivot = 0;
	for (int i = 0; i < M; i++) {	//각 크레인에 할당될 수 있는 박스의 개수 계산
		//한 i에 대해 맞는 pivot을 찾을 때까지 pivot++ 해줘야됨
		while (box[i] > crane[pivot] && pivot < N) {
			order[pivot++] = cnt;
			cnt = 0;
		}
		if (box[i] <= crane[pivot]) {
			cnt++;
		}
	}
	order[pivot] = cnt;

	int minutes = order[N - 1], box_num = 0;

	for (int i = N - 1; i >= 0; i--) {
		box_num += order[i];
		int crane_num = N - i;
		int blank = minutes * crane_num - box_num;
		if (blank < 0) {	//부족할 경우 minutes 다시 계산
			//idea: 박스를 각 크레인에 공평하게 나눠준 뒤 박스가 남는다면 minutes++
			int tmp =  box_num / crane_num;
			if (box_num % crane_num)
				tmp++;
			minutes = tmp;
		}
	}
	cout << minutes << "\n";
}