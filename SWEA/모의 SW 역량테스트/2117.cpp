// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V61LqAf8DFAWu

// 단순히 구현만 하면 되는 문제.
// 마름모꼴의 영역을 어떻게 다룰 수 있는지만 생각하면 되는 것 같다.

#include <iostream>
#include <queue>
using namespace std;

const int MAX = 22;
const int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int N, M, ans;
int Map[MAX][MAX];
int Check[MAX][MAX];
int Money[MAX];
int House[MAX];

void bfs(int x, int y) {
	for (int i = 1; i <= N + 1; i++) {
		for (int j = 1; j <= N; j++) {
			Check[i][j] = 0;
			House[i] = 0;
		}
	}

	queue<pair<int, int>> q;
	q.push({ x, y });
	Check[x][y] = 1;
	House[1] = Map[x][y] ? 1 : 0;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		int k = Check[r][c];

		for (int d = 0; d < 4; d++) {
			int nr = r + dir[d][0];
			int nc = c + dir[d][1];
			int nk = k + 1;

			if (0 < nr && nr <= N && 0 < nc && nc <= N) {
				if (Check[nr][nc] == 0 && nk <= N + 1) {
					q.push({ nr, nc });
					Check[nr][nc] = nk;
					if (Map[nr][nc]) House[nk]++;
				}
			}
		}
		q.pop();
	}
}

int main() {
	for (int i = 1; i < MAX; i++) {
		Money[i] = i * i + (i - 1) * (i - 1);
	}

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;
		int ans = 0;

		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				cin >> Map[r][c];
			}
		}

		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				bfs(r, c);
				for (int i = 1; i <= N + 1; i++) {
					House[i] += House[i - 1];
					if (Money[i] <= House[i] * M) {
						if (ans < House[i]) ans = House[i];
					}
				}
			}
		}
		cout << "#" << tc << " " << ans << endl;
	}
	return 0;
}
