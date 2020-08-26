// https://www.acmicpc.net/problem/15898

// 처음에는 vector를 사용했고, 순열을 모두 만들었을 때 (즉 cnt가 3이 되었을 때) 재료를 넣어서 계산했다. (제일 아래 코드 참고)
// 그랬더니 통과는 했지만 시간이 꽤 나와서 조금 더 최적화를 해보려고 vector 대신 pair를 사용했고,
// dfs의 깊이가 깊어지기 전 현재 가마의 상태를 복사해두는 식으로 하니 시간이 조금 덜 걸리긴했는데 큰 차이는 없었다..ㅎ
// 다른 사람들 푼 것 보니까 더 최적화시킬 수 있을 것 같긴한데 .. 흠

#include <iostream>
#include <cstring>
using namespace std;

int N, Answer;
bool Check[10];
// pair<효능, 원소>
pair<int, char> Pot[5][5];  // 가마
pair<int, char> Materials[10][4][4][4]; // [n][d][i][j] : 90도씩 d번 회전한 n번째 재료의 [i][j]칸

// Pot의 초기화
void initPot() {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            Pot[i][j] = { 0, 'W' };
}

// 세가지 재료를 모두 섞은 후 폭탄의 품질 계산
int calc() {
    int ret = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (Pot[i][j].second == 'W') continue;
            int power = Pot[i][j].first;
            switch (Pot[i][j].second) {
            case 'R': ret += (7 * power);
                break;
            case 'B': ret += (5 * power);
                break;
            case 'G': ret += (3 * power);
                break;
            case 'Y': ret += (2 * power);
                break;
            }
        }
    }
    return ret;
}

// n번째 재료의 d번 회전을 가마 x, y 시작 위치에서 넣어라
void put(int n, int d, int x, int y) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            Pot[x + i][y + j].first += Materials[n][d][i][j].first;
            if (Pot[x + i][y + j].first > 9) Pot[x + i][y + j].first = 9;
            if (Pot[x + i][y + j].first < 0) Pot[x + i][y + j].first = 0;
            if (Materials[n][d][i][j].second == 'W') continue;
            Pot[x + i][y + j].second = Materials[n][d][i][j].second;
        }
    }
}

void solve(int cnt = 0) {
    if (cnt == 3) {
        if (Answer < calc())
            Answer = calc();
        return;
    }

    // 가마의 현재 상태를 저장해둔다
    pair<int, char> tmp[5][5];
    memcpy(tmp, Pot, sizeof(Pot));
    for (int i = 0; i < N; i++) {
        if (!Check[i]) {
            Check[i] = true;
            for (int d = 0; d < 4; d++) {
                for (int x = 0; x < 2; x++) {
                    for (int y = 0; y < 2; y++) {
                        put(i, d, x, y);    // 가마에 재료 넣기
                        solve(cnt + 1);
                        memcpy(Pot, tmp, sizeof(tmp));
                    }
                }
            }
            Check[i] = false;
        }
    }
}

// 각 재료의 회전 상태를 미리 넣어둔다
void addRotate(int n) {
    for (int d = 0; d < 3; d++) {
        pair<int, char> tmp[4][4];
        auto v = Materials[n];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                tmp[j][3 - i] = v[d][i][j];
        memcpy(v[d + 1], tmp, sizeof(tmp));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int n = 0; n < N; n++) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                cin >> Materials[n][0][i][j].first;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                cin >> Materials[n][0][i][j].second;
        addRotate(n);
    }
    solve();
    cout << Answer << endl;
    return 0;
}
