#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int a[4][4];
bool check[10000000];
int ans;

void init() {
  ans = 0;
  memset(check, false, sizeof(check));
}

void dfs(int r, int c, int num = 0, int cnt = 0) {
  cnt++;
  num = num * 10 + a[r][c];
  if (cnt == 7) {
    if (check[num] == false) {
      check[num] = true;
      ans++;
    }
  return;
  }
  for (int i = 0; i < 4; i++) {
    int nr = r + dir[i][0];
    int nc = c + dir[i][1];
    if (nr < 0 || nc < 0 || 4 <= nr || 4 <= nc) continue;
    dfs(nr, nc, num, cnt);
  }
}

int main() {
  int T;
  cin >> T;

  for(int t = 1; t <= T; t++) {
    init();
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        dfs(i, j);
      }
    }
    cout << "#" << t << " " << ans << '\n';
  }
  return 0;
}
