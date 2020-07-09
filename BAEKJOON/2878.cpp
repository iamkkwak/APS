// https://www.acmicpc.net/problem/2878

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const long long DIVISION = (long long)(pow(2, 64));
int candy[100001];

int main() {
	int M, N;
	cin >> M >> N;

	long long total = -M;	// 못 받는 사탕의 수
	long long ans = 0;

	for (int i = 0; i < N; i++) {
		cin >> candy[i];
		total += candy[i];
	}

	sort(candy, candy + N);

	for (int i = 0; i < N; i++) {
		long long tmp = min((long long)candy[i], total / (N - i));
		ans += (long long)(tmp * tmp);
		ans %= DIVISION;
		total -= tmp;
	}

	cout << ans << endl;
	return 0;
}
