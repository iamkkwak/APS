// https://www.acmicpc.net/problem/3190

#include <iostream>
#include <cstring>
using namespace std;

const int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };	// 우하상좌
const int EMPTY = -1;
const int APPLE = 4;

struct Point {
	int x;
	int y;
};
struct Snake {
	Point head;
	Point tail;
	int direction;
	int time;
};

int N, K, L, X, ans;
int map[101][101];
int cmd[10001];
Snake snake;

void init() {
	snake = { {0, 0}, {0, 0}, 0, 0 };
	memset(map, EMPTY, sizeof(map));
	memset(cmd, 0, sizeof(cmd));
	map[0][0] = 0;
}

bool is_end(int x, int y) {
	if (0 <= x && x < N && 0 <= y && y < N) {	// 벽이 아니고
		if (map[x][y] == EMPTY || map[x][y] == APPLE) {	// 뱀 몸도 없음
			return false;
		}
	}
	return true;
}

void game() {
	while (true) {
		int x = snake.head.x;
		int y = snake.head.y;
		int& t = snake.time;
		int& d = snake.direction;
		if (cmd[t]) {	// 해당 시간에 명령이 있으면 방향 바꾸기
			d += cmd[t];
			d = (d + 4) % 4;
		}
		// 다음 위치를 보자
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		if (!is_end(nx, ny)) {	// 종료 조건이 아니면
			// 이동 정보를 저장하고 머리를 움직인다
			map[x][y] = d;
			snake.head.x = nx;
			snake.head.y = ny;
			if (map[nx][ny] != APPLE) {
				// 사과가 아니면 꼬리도 이동
				int& tx = snake.tail.x;
				int& ty = snake.tail.y;
				int td = map[tx][ty];

				map[tx][ty] = EMPTY;	// 꼬리가 없어져서 빈 공간이 됨
				tx += dir[td][0];
				ty += dir[td][1];
			}
			t++;	// 시간 증가
		}
		else {	// 종료 조건이면
			break;
		}
	}
}

int main() {
	init();
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = APPLE;
	}
	cin >> X;
	for (int i = 0; i < X; i++) {
		int t;
		char d;
		cin >> t >> d;
		if (d == 'L') cmd[t] = -1;
		else if (d == 'D') cmd[t] = 1;
	}
	game();
	cout << snake.time + 1 << endl;
	return 0;
}
