#include <iostream>

using namespace std;

bool function(string a, string b) {
	if (a.size() != b.size())
		return false;
	int k = -1;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b[0])
			k = i;
	}
	if (k == -1)
		return false;
	for (int i = 1; i < a.size(); i++) {
		if (k == a.size() - 1)
			k = 0;
		else
			k++;
		if (a[k] != b[i])
			return false;
	}
	return true;
}

int main() {
	string a="abcd";
	string b="bcda";
	if (function(a, b) == 1)
		cout << "true";
	else
		cout << "false";
	cout << endl;
	system("pause");
	return 0;
}