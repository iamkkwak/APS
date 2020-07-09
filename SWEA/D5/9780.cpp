// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXE0gpIa3dADFAVX

// 처음에 DFS가 먼저 생각나서 시간초과를 걱정했던 문제.
// 근데 생각해보면 결국 각 마을은 침공하고 안 하고로 나뉘고,
// 최대의 정답을 만들어야 하기 때문에 DP 문제가 된다.

#include <iostream>
#define max(a, b) (a > b? a : b)
using namespace std;

const int MAX = 1000000;
int N, A[MAX + 1];
long long DP[MAX + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		for (int i = 1; i <= N; i++)
            cin >> A[i];

		DP[1] = A[1];
		DP[2] = max(A[1], A[2]);
		for (int i = 3; i <= N; i++)
            DP[i] = max(DP[i - 2] + A[i], DP[i - 1]);
		cout << "#" << tc << " " << DP[N] << '\n';
	}
	return 0;
}
