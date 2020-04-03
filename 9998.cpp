#include <iostream>
#include <cmath>
using namespace std;

const long long MAX_H = 1000000000000;
int N;
long long Y[300000];
long long D[300000];

void calc(long long low, long long& ret) {
	int mid = N / 2;
	int left = mid - 1, right = mid + 1;

	ret = abs(Y[mid] - low) + abs(D[mid] - low);
	while (0 <= left && right < N) {
		low++;
		ret += (abs(Y[left] - low) + abs(D[left] - low));
		ret += (abs(Y[right] - low) + abs(D[right] - low));
		left--; right++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();

	cin >> N;
	for (int i = 0; i < N; i++) cin >> Y[i];
	for (int i = 0; i < N; i++) cin >> D[i];

	long long min_low = 0, max_low = MAX_H - N / 2;
	long long min_block = 0, max_block = 0;
	calc(min_low, min_block); calc(max_low, max_block);

	while (min_low <= max_low) {
		long long mid = (min_low + max_low) / 2;
		if (min_block < max_block) {
			max_low = mid - 1;
			calc(max_low, max_block);
		}
		else {
			min_low = mid + 1;
			calc(min_low, min_block);
		}
	}
	cout << (min_block < max_block ? min_block : max_block) << endl;
	return 0;
}
