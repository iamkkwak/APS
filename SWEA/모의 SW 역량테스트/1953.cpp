#include <iostream>
#include <queue>
using namespace std;

const int SIZE = 51;
const int tunnel[8][4] = { { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 1, 0, 1, 0 }, { 0, 1, 0, 1 },
						{ 1, 1, 0, 0 }, { 0, 1, 1, 0 }, { 0, 0, 1, 1 }, { 1, 0, 0, 1 } };
const int dir[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

struct point {
	int row;
	int col;
};

int N, M, R, C, L;
int map[SIZE][SIZE];
int visit[SIZE][SIZE];

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = -1;
		}
	}
}

void bfs(int x, int y) {
	queue<point> q;
	q.push({ x, y });
	visit[x][y] = 0;

	while (!q.empty()) {
		int r = q.front().row;
		int c = q.front().col;
		int t = visit[r][c];
		int n = map[r][c];

		for (int i = 0; i < 4; i++) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];
			int nt = t + 1;
			int nn = map[nr][nc];

			if (0 <= nr && nr < N && 0 <= nc && nc < M && nt < L) {
				if (visit[nr][nc] == -1 && tunnel[n][i] && tunnel[nn][(i + 2) % 4]) {
					visit[nr][nc] = nt;
					q.push({ nr, nc });
				}
			}
		}

		q.pop();
	}
}

int answer() {
	bfs(R, C);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] != -1)
				ans++;
		}
	}
	return ans;
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> R >> C >> L;
		init();

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				cin >> map[r][c];
			}
		}
		cout << "#" << tc << " " << answer() << endl;
	}

	return 0;
}
