#include <iostream>
#include <cmath>
using namespace std;

int N;
int S[20][20];
int teamA[10], teamB[10];
bool check[20];
int ans = 987654321;

int calc() {
	int a = 0, b = 0;
	// 1번 방법
	for (int i = 0; i < N; i++) {
		if (teamA[a] == i) {
			a++;
			continue;
		}
		else {
			teamB[b++] = i;
		}
	}
	a = 0, b = 0;
	for (int i = 0; i < N / 2; i++) {
		for (int j = 0; j < N / 2; j++) {
			a += S[teamA[i]][teamA[j]];
			b += S[teamB[i]][teamB[j]];
		}
	}
	// 2번 방법
	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i] && check[j]) a += S[i][j];
			else if (!check[i] && !check[j]) b += S[i][j];
		}
	}
	*/
	return abs(a - b);
}

void solution(int start = 0, int cnt = 0) {
	if (cnt == N / 2) {
		int tmp = calc();
		if (tmp < ans) {
			ans = tmp;
		}
		return;
	}
	for (int i = start; i < N; i++) {
		if (!check[i]) {
			check[i] = true;
			teamA[cnt] = i;
			solution(i, cnt + 1);
			check[i] = false;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
		}
	}
	solution();
	cout << ans << endl;
	return 0;
}
