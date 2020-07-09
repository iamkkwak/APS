// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V1SYKAaUDFAWu

// 처음에 Film 배열을 2차원으로 선언했더니 test 함수에서 오버헤드가 많이 발생해서 시간초과가 났다.
// 그래서 어차피 한 층이 64bit를 넘지 않으니까 int로 선언해서 bitmask를 사용했다.
// 시간초과 문제를 해결하기 위해서 bitmask를 활용할 수 있었던 좋은 문제였던거 같다.

#include <iostream>
using namespace std;

#define MAXW 21
#define MAXD 14

int Film[MAXD];
int D, W, K;
bool Pass;

bool test(int state[MAXD]) {
	for (int i = 0; i < W; i++) {
		int cnt = 1;
		for (int j = 1; j < D; j++) {
			if ((state[j] & (1 << i)) == (state[j - 1] & (1 << i))) cnt++;
			else cnt = 1;
			if (cnt == K) break;
		}
		if (cnt != K)
			return false;
	}
	return true;
}

void solve(int state[MAXD], int n, int prev = -1, int cnt = 0) {
	if (Pass) return;
	if (cnt == n) {
		if (test(state)) Pass = true;
	}

	int before;
	for (int i = prev + 1; i < D; i++) {
		before = state[i];

		state[i] = 0;
		solve(state, n, i, cnt + 1);
		state[i] = (1 << W) - 1;
		solve(state, n, i, cnt + 1);

		state[i] = before;
	}
}

int answer() {
	for (int i = 0; i <= D; i++) {
		solve(Film, i);
		if (Pass)
			return i;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> D >> W >> K;
		Pass = 0;
		for (int i = 0; i < D; i++) {
			int n;
			Film[i] = 0;
			for (int j = W - 1; 0 <= j; j--) {
				cin >> n;
				Film[i] |= (n << j);
			}
		}
		cout << "#" << tc << " " << (K == 1 ? 0 : answer()) << endl;
	}
	return 0;
}
