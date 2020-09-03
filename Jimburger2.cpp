#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Mystruct {
	int key;
	int value;

	Mystruct(int k, int v) : key(k), value(v) {};
};

vector<Mystruct> vec;

struct less_than_value {
	inline bool operator() (const Mystruct& s1, const Mystruct& s2) {
		if (s1.value == s2.value) {
			return(s1.key < s2.value);
		}
		else {
			return (s1.value < s2.value);
		}
	}
};

int main() {
	int i, n, temp1, temp2;;
	cin >> n;

	for (i = 1; i < n + 1; i++) {
		cin >> temp1 >> temp2;
		vec.push_back(Mystruct(i, temp1 + temp2));
	}

	sort(vec.begin(), vec.end(), less_than_value());

	for (int i = 0; i < vec.size();i++) {
		cout << vec[i].key << " ";
	}

	return 0;
}