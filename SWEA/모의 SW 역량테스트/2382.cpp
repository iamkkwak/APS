#include <iostream>
#include <vector>
using namespace std;

struct cell {
	int n;
	int d;
	int max;
};

const int MAX = 101;
const int dir[5][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1} };	// 1 : 상, 2 : 하, 3 : 좌, 4 : 우
const int changeDir[5] = { 0, 2, 1, 4, 3 };	// 상 <-> 하, 좌 <-> 우
int N, M, K;
cell map[MAX][MAX];
cell newMap[MAX][MAX];

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = { 0, 0, 0 };
			newMap[i][j] = { 0, 0, 0 };
		}
	}
}

void one_hour() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// 현재 칸에 미생물이 있는 경우
			if (map[i][j].n > 0) {
				int n = map[i][j].n;
				int d = map[i][j].d;
				int max = map[i][j].n;	// 이미 합쳐진 미생물의 max값은 현재의 미생물 수로 갱신

				// 다음 위치
				int x = i + dir[d][0];
				int y = j + dir[d][1];

				// 약품이 있는 가장자리라면 미생물 수와 방향을 변경
				// 미생물이 0이 되면 추가해 줄 필요 없음
				if (x == 0 || x == N - 1 || y == 0 || y == N - 1) {
					n /= 2;
					if (n == 0)
						continue;
					d = changeDir[d];
				}

				// 다음 위치에 이미 기존에 들어온 미생물이 있다면 전체 수는 누적
				// 현재의 미생물 수보다 해당 칸의 최댓값이 더 크다면 방향과 최댓값을 갱신
				else if (newMap[x][y].n > 0) {
					if (n < newMap[x][y].max) {
						max = newMap[x][y].max;
						d = newMap[x][y].d;
					}
					n += newMap[x][y].n;
				}

				newMap[x][y] = { n, d, max };
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = newMap[i][j];
			newMap[i][j] = { 0, 0, 0 };
		}
	}
}

int count() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cnt += map[i][j].n;
		}
	}
	return cnt;
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> K;
		init();
		for (int i = 0; i < K; i++) {
			int x, y, k, d;
			cin >> x >> y >> k >> d;
			cell c = { k, d, k };
			map[x][y] = c;
		}

		for (int i = 0; i < M; i++)
			one_hour();

		cout << "#" << tc << " " << count() << endl;
	}
	return 0;
}
