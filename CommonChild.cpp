#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1, s2;
	int cnt = 0;
	int max_cnt = 0;
	
	cin >> s1;
	cin >> s2;

	int j = 0;
	int temp = 0;
	for (int a = 0; a < s1.length()-max_cnt; a++) {
		for (int i = a; i < s1.length(); i++) {
			j = temp;
			for (j; j < s2.length(); j++) {
				cout << s1[i] << s2[j] << endl;
				if (s1[i] == s2[j]) {
					cout <<"got it"<< s1[i] << s2[j]<< endl;
					cnt++;
					j++;
					temp = j;
					break;
				}
			}
		}
		cout << "cnt is" << cnt << endl;
		cout << "max_cnt is" << max_cnt << endl;
		if (max_cnt < cnt) {
			max_cnt = cnt;
		}

		cnt = 0;
		j = 0;
		temp = 0;
		cout << "one cycle"<<endl;
	}

	cout << max_cnt;
	return 0;
}
