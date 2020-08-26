#include <iostream>
#include <vector>
using namespace std;

const int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int N, K;
int map[10][10];
vector<pair<int, int>> peaks;

// 해당 위치에서 dfs 탐색하는 함수
int dfs(int x, int y) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
			if (map[x][y] > map[nx][ny]) {
				int L = dfs(nx, ny);
				if (ret < L)
					ret = L;
			}
		}
	}
	return ret + 1;
}

// 꼭대기부터 dfs 시작
int solve() {
	int ret = 1;
	for (int i = 0; i < peaks.size(); i++) {
		int row = peaks[i].first;
		int col = peaks[i].second;
		int L = dfs(row, col);
		if (ret < L) ret = L;
	}
	return ret;
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		peaks.clear();	// 꼭대기 초기화
		cin >> N >> K;

		// 입력 받고 가장 높은 봉우리 높이를 max에 저장
		int max = 0;
		for (int row = 1; row <= N; row++) {
			for (int col = 1; col <= N; col++) {
				cin >> map[row][col];
				if (max < map[row][col])
					max = map[row][col];
			}
		}

		// 꼭대기 위치 저장
		for (int row = 1; row <= N; row++) {
			for (int col = 1; col <= N; col++) {
				if (map[row][col] == max) {
					peaks.push_back({ row, col });
				}
			}
		}
		
		// 아무것도 안 깎은 상태에서 최댓값 저장
		int answer = solve();

		// 순서대로 해당 칸 마다 1부터 K까지 깎아가면서 다시 dfs
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k <= K; k++) {
					map[i][j] -= k;	// 깎고
					int ret = solve();
					if (answer < ret)
						answer = ret;
					map[i][j] += k;	// 원래대로
				}
			}
		}

		cout << "#" << t << " " << answer << '\n';
	}
	return 0;
}
