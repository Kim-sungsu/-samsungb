#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int n, m; // 재료 수 , 달러
int minjr;

struct JR {
	int x;
	int y;
	int sm;
	int pm;
	int sv;
	int pv;
	int nowcnt;
} jr[101];

void findminjr() {
	for (int i = 0; i < n; i++)
		if (jr[minjr].nowcnt > jr[i].nowcnt)
			minjr = i;
}
int buy(int i, struct JR *_jr, int _cur, int _mode) {
	struct JR jr[101] = _jr;
	int m = i;
	int cur = _cur;
	int mode = _mode;

	if (mode == 0 && m > jr[cur].pv) {
		m -= jr[cur].pv;
		jr[cur].y += jr[cur].pv;
		jr[cur].nowcnt = jr[i].x / jr[i].y;
		jr[cur].y = jr[i].x % jr[i].y;
	}
	else if (mode == 1) {
		if (m < jr[cur].pm)
			return jr[cur].nowcnt;

		m -= jr[cur].pm;
		jr[cur].y += jr[cur].sm;
		jr[cur].nowcnt = jr[i].x / jr[i].y;
		jr[cur].y = jr[i].x % jr[i].y;
	}
	for (int i = 0; i < n; i++) {
	}

}

int main(void)

{

	// 여기서부터 작성
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d %d %d", &jr[i].x, &jr[i].y, &jr[i].sm, &jr[i].pm, &jr[i].sv, &jr[i].pv);
		jr[0].nowcnt = jr[i].x / jr[i].y;
		jr[0].nowcnt = jr[i].x % jr[i].y;
	}


	findminjr();
	buy(m, jr, minjr, 0);
	buy(m, jr, minjr, 1);




	return 0;

}
