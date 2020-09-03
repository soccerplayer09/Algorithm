#include <iostream>
using namespace std;

int temp1, temp2, n;
int *arr;

 //n사이즈 배열 동적할당, 원소 입력받기
void input() {
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	return;
}

//for문 이용 배열 원소 출력
void print() {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return;
}

//insertion sort
void insert_sort() {
	temp1 = arr[n - 1]; //배열 맨뒤값 temp에 저장
	//맨 뒤의 한칸 앞부터 첫번째 원소까지 for문
	for (int i = n - 2; i >= 0; i--) {
		//만약 원소가 temp보다 크면 원소 다음 인덱스값 그 원소로 업데이트
		if (arr[i] > temp1) {
			temp2 = arr[i];
			arr[i + 1] = temp2;
			print();
			//만약 원소가 첫번째 원소면 temp를 원소로 저장
			if (i == 0) {
				arr[i] = temp1;
				print();
			}
		}
		else {
			//원소가 temp보다 작거나 같으면
			//원소의 다음원소가 temp랑 같으면
			//temp를 해당원소로 업데이트
			//왜냐하면 배열에 연속되는 수가 나왔을 때 프린트하지 않기 위해서
			if (arr[i + 1] == temp1) {
				temp1 = arr[i];
			}
			//next e is not same to tmep
			//update
			else {
				arr[i + 1] = temp1;
				temp1 = arr[i];
				print();
			}
		}
	}

	return;
}

int main() {
	input();
	for (int i = 0; i < n; i++) {
		insert_sort();
	}
	return 0;
}