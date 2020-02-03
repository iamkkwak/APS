#include <iostream>
using namespace std;

int N, ans;
bool dig_r[30], dig_l[30], ver[16];

void make_check(int r, int c, bool v) {
	dig_r[r + c - 1] = v;
	dig_l[r - c + N] = v;
	ver[c] = v;
}

bool okay(int r, int c) {
	if (!(dig_r[r + c - 1] || dig_l[r - c + N] || ver[c]))
		return true;
	else
		return false;
}

void backtracking(int r = 1) {
	if (r == N + 1) {
		ans++;
		return;
	}
	for (int c = 1; c <= N; c++) {
		if (okay(r, c)) {
			make_check(r, c, true);
			backtracking(r + 1);
			make_check(r, c, false);
		}
	}
}

int main() {
	cin >> N;
	backtracking();
	cout << ans << endl;
	return 0;
}
