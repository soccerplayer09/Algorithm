#include <iostream>
#include <vector>
using namespace std;

int arr[101][101] = { 0 };
int d_r[4] = {0,-1, 0, 1 };
int d_c[4] = {1, 0,-1, 0 };
vector<int> v;
int r, c, d, g;

void input() {
	cin >> c >> r >> d >> g;
}

int rotate(int a) {
	if (a == 0) {
		return 1;
	}
	else if (a == 1) {
		return 2;
	}
	else if (a == 2) {
		return 3;
	}
	else {
		return 0;
	}
}

void drawCurve() {
	int j, h, k;
	
	//0세대 그리기
	arr[r][c] = 1;
	k = v.front();
	r += d_r[k];
	c += d_c[k];
	arr[r][c] = 1;

	//iterator 하면서 puch_back 하면 문제 생기는거 티스토리에 포스팅하기
	//g세대까지 그리기
	for (h = 0; h < g; h++) {
		for (j = v.size() - 1; j >= 0; j--) {
			r += d_r[rotate(v[j])];
			c += d_c[rotate(v[j])];
			if (r >= 0 && c >= 0) {
				arr[r][c] = 1;
			}
		}
		for (j = v.size() - 1; j >= 0; j--) {
			v.push_back(rotate(v[j]));
		}
	}

	v.clear();
	return;
}

//정사각형 갯수 찾기
int squareNum() {
	int cnt = 0;
	for (int e = 0; e < 100; e++) {
		for (int f = 0; f < 100; f++) {
			if (arr[e][f] == 1 && arr[e + 1][f] == 1 && arr[e][f + 1] == 1 && arr[e + 1][f + 1] == 1) {
				cnt++;
			}
		}
	}
	return cnt;
}

void print() {
	for (int a = 0; a < 101; a++) {
		for (int b = 0; b < 101; b++) {
			cout << arr[a][b];
		}
		cout << endl;
	}
	return;
}

int main() {
	int i, n;

	cin >> n;

	for (i = 0; i < n; i++) {
		input();
		v.push_back(d);
		drawCurve();
	}
	cout << squareNum();

	return 0;
}