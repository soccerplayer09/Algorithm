#include <iostream>
#include <map>
using namespace std;

map<int, int> m;
int temp1, temp2;

void input(int key) {
	cin >> temp1 >> temp2;
	m.insert(pair<int,int>( key, temp1 + temp2));
}

void print() {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
}



int main() {
	int i,n;
	cin >> n;
	for (i = 1; i < n+1; i++) {
		input(i);
	}
	print();

	
	return 0;
}