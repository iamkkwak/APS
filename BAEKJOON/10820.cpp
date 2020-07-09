#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;

	while (getline(cin, s)) {
		int lower = 0;
		int upper = 0;
		int num = 0;
		int space = 0;

		for (int i = 0; s[i]; i++) {
			if ('a' <= s[i] && s[i] <= 'z') lower++;
			else if ('A' <= s[i] && s[i] <= 'Z') upper++;
			else if ('0' <= s[i] && s[i] <= '9') num++;
			else if (' ' == s[i]) space++;
		}

		cout << lower << " " << upper << " " << num << " " << space << '\n';
	}

	return 0;
}
