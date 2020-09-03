#include <iostream>

using namespace std;

int **arr = new int*[1];
int **arr_c = new int*[1];
int **stick = new int*[1];
int stick_c[40][40] = { 0 };
int n, m, t, a, b, sum;

//기초배열 값 입력받고 기초배열, 기초배열 카피 초기화
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
//스티커 입력받음
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
//스티커개수카운트
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
//90도회전
void rotate() {
	int i, j, temp;
	//깡통행렬에 스티커를 90도 회전시켜서 넣음
	for (i = 0; i < a; i++) {
		for (j = 0; j < b; j++) {
			stick_c[j][a-1-i] = stick[i][j];
		}
	}
	//행과 열 바꾸고
	temp = a;
	a = b;
	b = temp;
	//바꾼 행과 열로 스티커배열 동적할당
	stick = new int*[a];
	for (i = 0; i < a; i++) {
		stick[i] = new int[b];
	}
	//깡통배열에서 값 가지고옴
	for (i = 0; i < a; i++) {
		for (j = 0; j < b; j++) {
			stick[i][j] = stick_c[i][j];
		}
	}
}
//기초배열카피의 값 하나씩 체크
int check(int x, int y) {
	int i, j;
	for (i = 0; i < a; i++) {
		for (j = 0; j < b; j++) {
			//만약 기초배열카피, 스티커 둘 다 0이 아니면 기초배열카피 기초배열값으로 refresh하고 1리턴
			if (arr_c[x + i][y + j] && stick[i][j] != 0) {
				copy2();
				return 1;
			}
			//아니면 스티커값 더해줌
			else {
				arr_c[x + i][y + j] += stick[i][j];
			}
		}
	}
	return 0;
}
//체크할만한 배열 인덱스 찾기
int find(){
	int i, j, x, y;
	
	for (i = 0; i < n - a + 1; i++) {
		for (j = 0; j < m - b + 1; j++) {
			//기초배열카피의 값이 0이거나 스티커 첫번째값이 0이면 붙일 수 있는지 체크
			if (arr_c[i][j] == 0 || stick[0][0]==0) {
				//성공하면 기초배열을 기초배열카피값으로 바꿔주고 0리턴
				if (check(i,j) == 0) {
					copy1();
					return 0;
				}
			}
		}
	}
	//스티커를 회전시켜도 못 붙이면 1리턴
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