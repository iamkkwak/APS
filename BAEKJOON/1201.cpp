// https://www.acmicpc.net/problem/1201

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	if (M + K > N + 1 || N > M * K)
		printf("-1");
	else {
		vector<vector<int>> v(M);
		for (int i = 1; i <= K; i++)
			v[0].push_back(i);
		int a = K + 1;
		int index = 0;
		while (a <= N) {
			v[index++ % (M - 1) + 1].push_back(a++);
		}
		for (int i = 0; i < M; i++) {
			reverse(v[i].begin(), v[i].end());
			for (int num : v[i])
				printf("%d ", num);
		}
	}
	puts("");
	return 0;
}
