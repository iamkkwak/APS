#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int H, W;
	scanf("%d %d", &H, &W);

	if (H == 1)
		printf("1");
	else if (H == 2)
		printf("%d", min(4, (W + 1) / 2));
	else
		if (W < 7)
			printf("%d", min(4, W));
		else
			printf("%d", W - 2);
	puts("");
	return 0;
}
