#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 20;
const int dir[4][2] = { {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };

int N;
int Map[MAXN + 1][MAXN + 1];
bool Visit[101];
int Answer;

bool in_range(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}

int tour(int r, int c, int w, int h) {
	Visit[Map[r][c]] = true;

	int nr = r, nc = c;
	for (int d = 0; d < 4; d++) {
		int l = d % 2 ? h : w;
		while(l--) {
			nr += dir[d][0];
			nc += dir[d][1];

			if (nr == r && nc == c) break;
			if (!in_range(nr, nc) || Visit[Map[nr][nc]]) return -1;
			Visit[Map[nr][nc]] = true;
		}
	}
	return 2 * (w + h);
}

void solve() {
	for (int r = 0; r < N - 2; r++) {
		for (int c = 1; c <= N - 2; c++) {
			for (int w = 1; w < N - r && w < N - c; w++) {
				for (int h = 1; h <= c && h < N - r - w; h++) {
					int tmp = tour(r, c, w, h);
					Answer = Answer < tmp ? tmp : Answer;
					memset(Visit, false, sizeof(Visit));
				}
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> Map[i][j];
			}
		}
		Answer = -1;
		solve();
		cout << "#" << tc << " " << Answer << endl;
	}
	return 0;
}
