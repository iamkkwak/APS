// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15OZ4qAPICFAYD

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 987654321;
struct Point {
	int x;
	int y;
};
int N;
Point House, Company;
Point Customer[10];
vector<int> perm;
int Answer;

int dist(Point a, Point b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

void init() {
	perm.clear();
	Answer = MAX;
}

void input() {
	cin >> N;

	int x, y;
	cin >> x >> y;
	House = { x, y };
	cin >> x >> y;
	Company = { x, y };

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		Customer[i] = { x, y };
		perm.push_back(i);
	}
}

void solve() {
	do {
		int sum = 0;
		Point curr = Company;
		for (int i = 0; i < N; i++) {
			Point next = Customer[perm[i]];
			sum += dist(curr, next);
			curr = next;
		}
		sum += dist(curr, House);
		if (sum < Answer)
			Answer = sum;
	} while (next_permutation(perm.begin(), perm.end()));
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();

		cout << "#" << tc << " " << Answer << endl;
	}
	return 0;
}
