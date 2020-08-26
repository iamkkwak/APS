#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
string Code;

int hex2dec(string hex) {
	int ret = 0, cnt = 1;
	for (int i = hex.length() - 1; 0 <= i; i--) {
		if ('0' <= hex[i] && hex[i] <= '9')
			ret += (cnt * (hex[i] - '0'));
		else
			ret += (cnt * (hex[i] - 'A' + 10));
		cnt *= 16;
	}
	return ret;
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> K >> Code;
		Code += Code;
		vector<string> codes;
		int qrt = N / 4;
		for (int i = 0; i < qrt; i++) {
			for (int j = 0; j < 4; j++) {
				string tmp = "";
				for (int k = 0; k < qrt; k++) {
					tmp += Code[i + j * qrt + k];
				}
				if (find(codes.begin(), codes.end(), tmp) == codes.end())
					codes.push_back(tmp);
			}
		}
		sort(codes.rbegin(), codes.rend());
		cout << "#" << tc << " " << hex2dec(codes[K - 1]) << endl;
	}
	return 0;
}
