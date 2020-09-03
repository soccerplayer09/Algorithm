#include <iostream>

using namespace std;

int **arr = new int*[1];
int **arr_c = new int*[1];
int **stick = new int*[1];
int stick_c[40][40] = { 0 };
int n, m, t, a, b, sum;

//���ʹ迭 �� �Է¹ް� ���ʹ迭, ���ʹ迭 ī�� �ʱ�ȭ
void input1() {
	int i, j;

	cin >> n >> m >> t;

	arr = new int*[n];
	for (i = 0; i < n; i++) {
		arr[i] = new int[m];
	}

	arr_c = new int*[n];
	for (i = 0; i < n; i++) {
		arr_c[i] = new int[m];
	}
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			arr[i][j] = 0;
			arr_c[i][j] = 0;
		}
	}

}
//��ƼĿ �Է¹���
void input2() {
	int i, j;

	cin >> a >> b;

	stick = new int*[a];
	for (i = 0; i < a; i++) {
		stick[i] = new int[b];
	}

	for (i = 0; i < a; i++) {
		for (j = 0; j < b; j++) {
			cin >> stick[i][j];
		}
	}
}
//��ƼĿ����ī��Ʈ
int count() {
	int i, j;
	sum = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				sum++;
			}
		}
	}

	return (n*m - sum);
}

void copy1() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			arr[i][j] = arr_c[i][j];
		}
	}
}

void copy2() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			arr_c[i][j] = arr[i][j];
		}
	}
}
//90��ȸ��
void rotate() {
	int i, j, temp;
	//������Ŀ� ��ƼĿ�� 90�� ȸ�����Ѽ� ����
	for (i = 0; i < a; i++) {
		for (j = 0; j < b; j++) {
			stick_c[j][a-1-i] = stick[i][j];
		}
	}
	//��� �� �ٲٰ�
	temp = a;
	a = b;
	b = temp;
	//�ٲ� ��� ���� ��ƼĿ�迭 �����Ҵ�
	stick = new int*[a];
	for (i = 0; i < a; i++) {
		stick[i] = new int[b];
	}
	//����迭���� �� �������
	for (i = 0; i < a; i++) {
		for (j = 0; j < b; j++) {
			stick[i][j] = stick_c[i][j];
		}
	}
}
//���ʹ迭ī���� �� �ϳ��� üũ
int check(int x, int y) {
	int i, j;
	for (i = 0; i < a; i++) {
		for (j = 0; j < b; j++) {
			//���� ���ʹ迭ī��, ��ƼĿ �� �� 0�� �ƴϸ� ���ʹ迭ī�� ���ʹ迭������ refresh�ϰ� 1����
			if (arr_c[x + i][y + j] && stick[i][j] != 0) {
				copy2();
				return 1;
			}
			//�ƴϸ� ��ƼĿ�� ������
			else {
				arr_c[x + i][y + j] += stick[i][j];
			}
		}
	}
	return 0;
}
//üũ�Ҹ��� �迭 �ε��� ã��
int find(){
	int i, j, x, y;
	
	for (i = 0; i < n - a + 1; i++) {
		for (j = 0; j < m - b + 1; j++) {
			//���ʹ迭ī���� ���� 0�̰ų� ��ƼĿ ù��°���� 0�̸� ���� �� �ִ��� üũ
			if (arr_c[i][j] == 0 || stick[0][0]==0) {
				//�����ϸ� ���ʹ迭�� ���ʹ迭ī�ǰ����� �ٲ��ְ� 0����
				if (check(i,j) == 0) {
					copy1();
					return 0;
				}
			}
		}
	}
	//��ƼĿ�� ȸ�����ѵ� �� ���̸� 1����
	return 1;
}

void print() {
	int i, j;
	cout << "sticker" << endl;
	for (i = 0; i < a; i++) {
		for (j = 0; j < b; j++) {
			cout << stick[i][j];
		}
		cout << endl;
	}
	cout << endl;

	cout << "arr" << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;

	cout << "arr_c" << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << arr_c[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	int i, j;
	input1();
	for (i = 0; i < t; i++) {
		input2();
		//print();
		if (find()!=0) {
			for (j = 0; j < 3; j++) {
				rotate();
				//cout << "a : " << a << " b : " << b << " n : " << n << " m : " << m << endl;
				//print();
				if (find() == 0) {
					break;
				}
			}
		}
		//print();
	}
	cout << count() << endl;
	
	
	return 0;
}