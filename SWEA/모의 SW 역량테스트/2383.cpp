#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int MAXN = 11;
const int MAXT = MAXN * 2 + MAXN * MAXN;
// 한 사람이 계단 도착까지 걸릴 수 있는 시간의 범위 = 격자 최대 크기의 두 배 이하
// 격자 최대 크기의 두 배 + 계단이 최대 길이(10) * 사람의 수 = 걸릴 수 있는 최대 시간

struct point {
	int r;
	int c;
	point() {}
	point(int r, int c) : r(r), c(c) {}
};

int N, P, S, answer;
int room[MAXN][MAXN];	// 빈 공간은 0, 사람은 1, 계단은 2 ~ 10
point people[MAXN];
point stair[2];
int match[MAXN];
// match[x] = y : x번째 사람이 y(0 또는 1)번째 계단을 타도록 결정

void init() {
	P = 0;
	S = 0;
	answer = MAXT;
}

// 해당 사람의 번호와 계단 사이의 거리를 구해주는 함수
int dist(int p_id, int s_id) {
	int dx = abs(people[p_id].c - stair[s_id].c);
	int dy = abs(people[p_id].r - stair[s_id].r);
	return dx + dy;
}

void update() {
	// 모든 사람들이 계단을 내려가는데 필요한 최소 시간
	int total_min = 0;

	// 두 계단은 서로 독립적이므로 각각의 계단에 대하여 계산
	for (int s_id = 0; s_id < 2; s_id++) {
		point& curr_stair = stair[s_id];
		int p_arrived[MAXN * 2] = { 0, };	// 각 시간에서 계단에 도착하는 사람의 수
		int p_on_stair[MAXT] = { 0, };		// 각 시간에서 계단을 내려가고 있는 사람의 수

		for (int p_id = 0; p_id < P; p_id++) {
			if (match[p_id] == s_id) {
				// 계단 입구에 도착하면 1분 뒤부터 계단을 내려갈 수 있음
				p_arrived[dist(p_id, s_id) + 1]++;
			}
		}
		/* arrival_time[t]에는 t분에 계단에 도착해서 내려갈 준비가 된 사람의 수가 저장된 상태 */

		int curr_min = 0;	// s_id 계단을 내려가는 사람이 모두 내려가기 위한 최소 시간
		// 각 계단에 먼저 도착한 사람부터(시간 오름차순) 계단을 내려감
		for (int time = 1; time <= 20; time++) {
			// time에 도착한 사람이 있다면
			while (p_arrived[time] > 0) {
				// 한 명씩 내려보내기
				p_arrived[time]--;
				// 계단의 높이 = 계단을 내려가는데 걸리는 시간
				int remaining_time = room[curr_stair.r][curr_stair.c];

				// 계단에 도착한 시점(time)부터 3명까지만 1칸씩 밑으로 내려보냄
				for (int down = time; down < MAXT; down++) {
					if (p_on_stair[down] < 3) {
						p_on_stair[down]++;
						remaining_time--;

						if (remaining_time == 0) {
							curr_min = max(curr_min, down + 1);
							break;
						}
					}
				}
			}
		}
		// 전체 계단을 내려가는데 필요한 시간 = 두 계단을 내려가는데 필요한 최소 시간 중 최댓값
		total_min = max(total_min, curr_min);
	}
	// 현재 match 상태일 때의 최솟값을 비교해서 갱신
	answer = min(answer, total_min);
}

void dfs(int p_id = 0) {
	if (p_id == P) {
		// 모든 사람에게 계단 번호가 부여됐으면
		// 해당 상태(match)에서의 값을 계산하는 함수 호출
		update();
		return;
	}
	for (int s_id = 0; s_id < 2; s_id++) {
		match[p_id] = s_id;	// 현재 사람한테 계단 번호를 부여해주고
		dfs(p_id + 1);		// 다음 사람으로 넘어감
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		init();
		for (int r = 1; r <= N; r++) {
			for (int c = 1; c <= N; c++) {
				cin >> room[r][c];
				if (room[r][c] == 1)
					people[P++] = point(r, c);
				if (room[r][c] > 1)
					stair[S++] = point(r, c);
			}
		}
		dfs();
		cout << "#" << tc << " " << answer << endl;
	}
	return 0;
}
