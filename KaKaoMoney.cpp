#include <iostream>
#include <queue>
using namespace std;

int t, x, y, a1, b1, M;
int first = 0;
int quit = 1;
queue<pair<int, int>> q;
queue<int> qM;

void input() {

	cin >> t;

}

void store() {
	int temp = 0;
	
	//첫번째 그냥 푸시
	if (first == 0) {
		if (qM.front() == 0) {
			qM.pop();
		}
		qM.push(M);
	}
	else {
		//큐에 넣고자 하는 값이 프론트보다 크면 리턴(내림차순이기 떄문에 큐에 해당 값이 없음)
		if (M > qM.front()) {
			return;
		}

		temp = qM.front();
		while (qM.size()!=0) {
	
			temp = qM.front();
			//큐의 프론트 값이 M이랑 같으면 푸시하고 팝
			if (temp == M) {
				qM.push(M);
				qM.pop();
				break;
			}
			//같지 않으면 같을 때까지 팝, 내림차순이라서 팝하다 보면 나옴
			qM.pop();
		}
	}
	//사이즈가 0이면 M이 없는 거
	if (qM.size() == 0) {
		quit = 0;
	}

}

//M을 검사
void check() {
	int i, j, needTocharge, charged, n;
	
	//충전해야되는금액(음의값)
	needTocharge = b1 + x;
	//충전된 금액
	charged = y + (-x) - b1;
	
	if (y == 0) {
		n = charged + 1;
	}
	else if (charged%y == 0) {
		n = (charged / y);
	}
	else if(charged%y != 0){
		n = (charged / y) + 1;
	}
	
	for (i = 1; i < n; i++) {
		//나눠지는 경우에만 실행
		if (charged%i == 0) {
			//최소충전금액은 충전된금액 나누기 정수
			M = charged / i;
		}
		else {
			continue;
		}
		//충전해야되는 금액이 양이 될 때까지 최소충전금액을 더해줌
		while (needTocharge < 0) {
			needTocharge += M;
		}
		//마지막 충전 후 잔액이 실제 잔액과 동일하면 최소충전금액M을 보관
		if (needTocharge == y) {
			store();
			
		}
	}
	first = 1;
}

//큐를 정리함 //말로 설명이 필요한 부분임
void clear() {
	while (M > qM.front()) {
		qM.pop();
		if (qM.size() == 0) {
			quit = 0;
			break;
		}
	}
}

void input_log() {
	
	cin >> x >> y;
	q.push({ x,y });

	b1 = q.front().second;

	//잔액보다 큰 값을 인출하려고 할 때
	if (b1 < (-x)) {
		check();
		clear();
	}
	q.pop();
}

int main() {
	int i;
	q.push({ 0,0 });
	qM.push(0);

	input();

	for (i = 0; i < t; i++) {
		input_log();
	}
	if (quit != 0) {
		cout << qM.front();
	}
	else {
		cout << "-1";
	}
	

	return 0;
}