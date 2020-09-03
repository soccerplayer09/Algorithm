#include <iostream>
using namespace std;

int temp1, temp2, n;
int *arr;

 //n������ �迭 �����Ҵ�, ���� �Է¹ޱ�
void input() {
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	return;
}

//for�� �̿� �迭 ���� ���
void print() {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return;
}

//insertion sort
void insert_sort() {
	temp1 = arr[n - 1]; //�迭 �ǵڰ� temp�� ����
	//�� ���� ��ĭ �պ��� ù��° ���ұ��� for��
	for (int i = n - 2; i >= 0; i--) {
		//���� ���Ұ� temp���� ũ�� ���� ���� �ε����� �� ���ҷ� ������Ʈ
		if (arr[i] > temp1) {
			temp2 = arr[i];
			arr[i + 1] = temp2;
			print();
			//���� ���Ұ� ù��° ���Ҹ� temp�� ���ҷ� ����
			if (i == 0) {
				arr[i] = temp1;
				print();
			}
		}
		else {
			//���Ұ� temp���� �۰ų� ������
			//������ �������Ұ� temp�� ������
			//temp�� �ش���ҷ� ������Ʈ
			//�ֳ��ϸ� �迭�� ���ӵǴ� ���� ������ �� ����Ʈ���� �ʱ� ���ؼ�
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