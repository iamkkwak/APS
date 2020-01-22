#include <iostream>
#include <algorithm>
using namespace std;

const int dc[3] = { -1, 0, 1 };
const int MAX = 987654321;

int N, M;
int map[1002][1002];
int info[1002][1002][3];

void init() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			for (int d = 0; d < 3; d++) {
				info[r][c][d] = MAX;
			}
		}
	}
	for (int c = 1; c <= M; c++) {
		for (int d = 0; d < 3; d++) {
			info[1][c][d] = map[1][c];
		}
	}
}

void move(int r) {
	int nr = r + 1;
	for (int c = 1; c <= M; c++) {
		for (int d = 0; d < 3; d++) {
			int nc = c + dc[d];
			if (0 < nc && nc <= M) {
				int minFuel = min(info[r][c][(d + 1) % 3], info[r][c][(d + 2) % 3]);
				info[nr][nc][d] = minFuel + map[nr][nc];
			}
		}
	}
}

int solution() {
	for (int r = 1; r <= N; r++) {
		move(r);
	}
	int ans = MAX;
	for (int c = 1; c <= M; c++) {
		for (int d = 0; d < 3; d++) {
			if (info[N][c][d] < ans)
				ans = info[N][c][d];
		}
	}
	return ans;
}

int main() {
	cin >> N >> M;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			cin >> map[r][c];
		}
	}
	init();
	cout << solution() << endl;
	return 0;
}
