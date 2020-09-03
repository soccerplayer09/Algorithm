#include <iostream>
#include <string>
using namespace std;


int main() {
	int n, i, j;
	int cnt = 0;
	string a;
	
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> a;
		
		for (j = 0; j < a.size()-1; j++) {
			if (a[j] == a[j+1]) {
				cnt++;
			}
		}
		
		cout << cnt << endl;
		
		cnt = 0;
	}

	return 0;
}