#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int MAP_MAX = 10;
const int SEC_MAX = 100;
const int BC_MAX = 8;
const int dir[][2] = { {0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
struct Point {
	int x;
	int y;
};
struct BC {
	Point point;
	int range;
	int performance;
};

int M, A;
short info[SEC_MAX][2];		// 0 - A, 1 - B
BC BCs[BC_MAX];
Point user[2];
short connect[BC_MAX][2];	// 접속 가능 - 0, 불가능 - 1
int answer;

void init() {
	answer = 0;
	user[0] = { 1, 1 }, user[1] = { 10, 10 };
	memset(connect, 0, sizeof(connect));
}

void input() {
	cin >> M >> A;
	for (int i = 0; i < 2; i++) {
		for (int m = 0; m < M; m++) {
			cin >> info[m][i];
		}
	}
	for (int a = 0; a < A; a++) {
		int x, y, c, p;
		cin >> y >> x >> c >> p;
		BCs[a] = { {x, y}, c, p };
	}
}

int dist(Point bc, Point user) {
	return abs(bc.x - user.x) + abs(bc.y - user.y);
}

int max_charge() {
	int max = 0;
	for (int a = 0; a < A; a++) {
		for (int b = 0; b < A; b++) {
			int tmp = 0;
			if (a == b && connect[a][0] && connect[b][1])	// 똑같은 곳에 연결되어 있으면 같이
				tmp += BCs[a].performance;
			else	// 다른 곳에 연결되어 있으면 각각 계산
				tmp += (BCs[a].performance * connect[a][0] + BCs[b].performance * connect[b][1]);
			if (max < tmp)	// 최댓값 갱신
				max = tmp;
		}
	}
	return max;
}

void solve() {
	for (int sec = 0; sec <= M; sec++) {
		for (int bc = 0; bc < A; bc++) {
			for (int i = 0; i < 2; i++) {
				if (dist(BCs[bc].point, user[i]) <= BCs[bc].range)
					connect[bc][i] = 1;
			}
		}
		// 최댓값 더해주기
		answer += max_charge();
		memset(connect, 0, sizeof(connect));

		// 위치 이동시켜주기
		if (sec != M) {
			for (int i = 0; i < 2; i++) {
				user[i].x += dir[info[sec][i]][0];
				user[i].y += dir[info[sec][i]][1];
			}
		}
	}
}

int main() {
	int T;
	cin >> T;

	for(int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();
		cout << "#" << tc << " " << answer << endl;
	}

	return 0;
}
