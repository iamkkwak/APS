#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int p[100];
vector<int> v;
int check[10001];

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
    int N;
		scanf("%d", &N);
		v.clear();
		memset(check, false, sizeof(check));

		for (int i = 0; i < N; i++)
			scanf("%d", &p[i]);

		v.push_back(0);
		v.push_back(p[0]);
		check[0] = true;
		check[p[0]] = true;

		for (int i = 1; i < N; i++) {
			int size = v.size();
			for (int j = 0; j < size; j++) {
				int x = v[j] + p[i];
				if (check[x] == false) {
					v.push_back(x);
					check[x] = true;
				}
			}
		}
		int ans = v.size();
		printf("#%d %d\n", t, ans);
	}
	return 0;
}
