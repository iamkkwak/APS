// https://www.acmicpc.net/problem/9466

#include <iostream>
#include <vector>
using namespace std;

int a[100001];
bool check[100001];
vector<int> list;

int dfs(int node) {
	check[node] = true;
	list.push_back(node);
	int next = a[node];
	if (check[next] == false)
		return dfs(next);
	else {
		int index = 0;
		int size = list.size();
		bool is_found = false;
		for (int i = 0; i < size; i++) {
			if (list[i] == next) {
				index = i;
				is_found = true;
				break;
			}
		}
		list.clear();
		if (is_found)
			return size - index;
		else
			return 0;
	}
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, ans = 0;
		cin >> n;
		
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			if (i == x) {
				ans++;
				check[i] = true;
			}
			else {
				a[i] = x;
				check[i] = false;
			}
		}

		for (int i = 1; i <= n; i++) {
			if (check[i] == false) {
				ans += dfs(i);
			}
		}
		printf("%d\n", n - ans);
	}
	return 0;
}
