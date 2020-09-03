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
	
	//ù��° �׳� Ǫ��
	if (first == 0) {
		if (qM.front() == 0) {
			qM.pop();
		}
		qM.push(M);
	}
	else {
		//ť�� �ְ��� �ϴ� ���� ����Ʈ���� ũ�� ����(���������̱� ������ ť�� �ش� ���� ����)
		if (M > qM.front()) {
			return;
		}

		temp = qM.front();
		while (qM.size()!=0) {
	
			temp = qM.front();
			//ť�� ����Ʈ ���� M�̶� ������ Ǫ���ϰ� ��
			if (temp == M) {
				qM.push(M);
				qM.pop();
				break;
			}
			//���� ������ ���� ������ ��, ���������̶� ���ϴ� ���� ����
			qM.pop();
		}
	}
	//����� 0�̸� M�� ���� ��
	if (qM.size() == 0) {
		quit = 0;
	}

}

//M�� �˻�
void check() {
	int i, j, needTocharge, charged, n;
	
	//�����ؾߵǴ±ݾ�(���ǰ�)
	needTocharge = b1 + x;
	//������ �ݾ�
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
		//�������� ��쿡�� ����
		if (charged%i == 0) {
			//�ּ������ݾ��� �����ȱݾ� ������ ����
			M = charged / i;
		}
		else {
			continue;
		}
		//�����ؾߵǴ� �ݾ��� ���� �� ������ �ּ������ݾ��� ������
		while (needTocharge < 0) {
			needTocharge += M;
		}
		//������ ���� �� �ܾ��� ���� �ܾװ� �����ϸ� �ּ������ݾ�M�� ����
		if (needTocharge == y) {
			store();
			
		}
	}
	first = 1;
}

//ť�� ������ //���� ������ �ʿ��� �κ���
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

	//�ܾ׺��� ū ���� �����Ϸ��� �� ��
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