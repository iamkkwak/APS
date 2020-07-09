#include <iostream>
using namespace std;

int V, ans;
int map[100][2];
bool check[100][2];

void go(int curr = 0) {
	if (curr == 99) {
		ans = 1;
		return;
	}
	for (int i = 0; i < 2; i++) {
		int next = map[curr][i];
		if (!check[curr][i] && next) {
			check[curr][i] = true;
			go(next);
		}
	}
}

void init() {
	ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 2; j++) {
			map[i][j] = 0;
			check[i][j] = false;
		}
	}
}

int main() {
	int T = 10;
	while (T--) {
		int tc;
		cin >> tc >> V;

		init();
		for (int i = 0; i < V; i++) {
			int a, b;
			cin >> a >> b;
			if (!map[a][0]) map[a][0] = b;
			else map[a][1] = b;
		}

		go();
		cout << "#" << tc << " " << ans << endl;
	}
	return 0;
}
