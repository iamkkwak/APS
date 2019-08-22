#include <iostream>
#include <queue>
using namespace std;

const int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int M, N;
int tomato[1002][1002];
queue<pair<int, int>> q;

int result() {
  int max = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (tomato[i][j] == 0)
        return -1;
      if (max < tomato[i][j])
        max = tomato[i][j];
    }
  }
  return max - 1;
}

int main() {
  cin >> M >> N;

  int zero = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      int x;
      cin >> x;
      tomato[i][j] = x;
      if (x == 0)
        zero++;
      else if (x == 1)
        q.push({ i, j });
    }
  }

  if (!zero) {
    cout << "0\n";
    return 0;
  }

  while (!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nr = r + dir[i][0];
      int nc = c + dir[i][1];
      if (nr < 1 || nc < 1 || N < nr || M < nc)
        continue;
      if (tomato[nr][nc] == 0) {
        tomato[nr][nc] = tomato[r][c] + 1;
        q.push({ nr, nc });
      }
    }
  }
  cout << result() << '\n';
  return 0;
}
