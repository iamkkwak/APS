#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> p;
vector<int> m;

int main() {
	int N;
	scanf("%d", &N);
	int zero = 0, one = 0;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		if (x == 0)
			zero++;
		else if (x == 1)
			one++;
		else if (x > 0)
			p.push_back(x);
		else if (x < 0)
			m.push_back(x);
	}
	sort(p.begin(), p.end());
	reverse(p.begin(), p.end());
	sort(m.begin(), m.end());

	if (p.size() % 2 == 1)
		p.push_back(1);
	if (m.size() % 2 == 1)
		m.push_back(zero > 0 ? 0 : 1);

	int ans = one;
	for (int i = 0; i < p.size(); i += 2)
		ans += (p[i] * p[i + 1]);
	for (int i = 0; i < m.size(); i += 2)
		ans += (m[i] * m[i + 1]);

	printf("%d\n", ans);
	return 0;
}
