#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 20;
int N, X, ans;
int map[MAX][MAX];
bool slope[MAX];

void rotate_90() {
	int newMap[MAX][MAX];
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			newMap[c][N - r - 1] = map[r][c];
		}
	}
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			map[r][c] = newMap[r][c];
		}
	}
}

void set_slope(int start, int end) {
	for (int i = start; i < end; i++)
		slope[i] = true;
}

bool check(int r, int start, int end) {
	if (start < 0 || N < end)
		return false;

	for (int c = start; c < end; c++) {
		if (slope[c])
			return false;
	}

	for (int c = start + 1; c < end; c++) {
		if (map[r][c - 1] != map[r][c])
			return false;
	}
	return true;
}

void search(int r) {
	memset(slope, false, sizeof(slope));
	for (int c = 1; c <= N; c++) {
		// 끝까지 왔음 (활주로 건설 가능)
		if (c == N) {
			ans++;
			return;
		}

		// 높이가 같은 경우
		if (map[r][c - 1] == map[r][c]) {
			continue;
		}

		// 낮아지는 경우
		else if (map[r][c - 1] - map[r][c] == 1) {
			if (check(r, c, c + X)) {
				set_slope(c, c + X);
				continue;
			}
			else
				return;
		}

		// 높아지는 경우
		else if (map[r][c] - map[r][c - 1] == 1) {
			if (check(r, c - X, c)) {
				set_slope(c - X, c);
				continue;
			}
			else
				return;
		}

		else
			return;
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		search(i);
	}
	rotate_90();
	for (int i = 0; i < N; i++) {
		search(i);
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> X;
		ans = 0;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				cin >> map[r][c];
			}
		}
		solve();
		cout << "#" << tc << " " << ans << endl;
	}
	return 0;
}
