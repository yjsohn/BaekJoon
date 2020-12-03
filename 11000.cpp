#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define mp make_pair

using namespace std;

//전략: 최대한 빈틈없이 각 강의실에 수업을 채워넣자

int N;
vector<pair<int, int>> classes;
priority_queue<int, vector<int>, greater<int>> room;    //room의 원소: 각 강의실의 가장 늦게 끝나는 수업의 종료 시간

void Schedule() {
	room.push(classes[0].second);
	for (int i = 1; i < N; i++) {	
		if (room.top() <= classes[i].first) {   //room의 원소 중 가장 일찍 끝나는 수업 뒤에 배정 가능
			room.pop(); //해당 강의실의 수업 종료 시간 갱신을 위해 pop (삭제)
		}
        //pop했다면 해당 강의실 종료시간 갱신을 위해 push
        //pop 하지 않았다면 새로운 강의실을 추가하기 위해 push
		room.push(classes[i].second);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		classes.push_back(mp(s, e));
	}
	sort(classes.begin(), classes.end());   //수업 시작 시간이 이른 순으로 배치
	Schedule();
	cout << room.size() << endl;
}