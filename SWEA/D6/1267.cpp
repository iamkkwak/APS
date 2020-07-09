// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV18TrIqIwUCFAZN

// 처음으로 접해본 위상정렬 문제였는데, 위상정렬이라는 것을 모르고도 내가 생각해서 풀어낸 문제라서 뿌듯했다!
// 나중에 보니 위상정렬이라는 개념이 있었고, 결국 내가 생각한 거랑 비슷한 방식이었다.

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int V, E;
vector<int> Graph[1001];
int Cnt[1001];
bool Visit[1001];

void init() {
	for (int i = 0; i <= V; i++) {
		Graph[i].clear();
	}
	memset(Cnt, 0, sizeof(Cnt));
	memset(Visit, false, sizeof(Visit));
}

void solve() {
	int remain = V;
	while (remain) {
		for (int i = 1; i <= V; i++) {
			if (!Cnt[i] && !Visit[i]) {
				remain--;
				Visit[i] = true;
				for (int j = 0; j < Graph[i].size(); j++) {
					Cnt[Graph[i][j]]--;
				}
				cout << i << " ";
				if (!remain) break;
			}
		}
	}
	cout << endl;
}

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		cin >> V >> E;
		init();
		for (int i = 0; i < E; i++) {
			int start, end;
			cin >> start >> end;
			Graph[start].push_back(end);
			Cnt[end]++;
		}
		cout << "#" << tc << " ";
		solve();
	}
	return 0;
}
