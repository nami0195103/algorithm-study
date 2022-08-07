#include <iostream>
using namespace std;

#define R 7
#define B 5
#define G 3
#define Y 2
#define W 0

class ingredient {
private:
	int efficiency[4][4];
	int color[4][4];
public:
	void set(int r, int c, int ef, int cl);
	void setEfficiency(int r, int c, int ef);
	void setColor(int r, int c, int cl);
	int getEfficiency(int r, int c);
	int getColor(int r, int c);
};

void ingredient::set(int r, int c, int ef, int cl) {
	efficiency[r][c] = ef;
	color[r][c] = cl;
}

void ingredient::setEfficiency(int r, int c, int ef) {
	efficiency[r][c] = ef;
}

void ingredient::setColor(int r, int c, int cl) {
	color[r][c] = cl;
}

int ingredient::getEfficiency(int r, int c) {
	return efficiency[r][c];
}

int ingredient::getColor(int r, int c) {
	return color[r][c];
}

ingredient ingr[10][4];	//재료(개수), 회전(시계방향)
int arr[5][5][2];	// 가마
int n;	//재료 개수
int ans = 0;

// ingr[idx] 회전(시계방향)
void rotate(int idx) {
	int i, j, k;

	for (i = 0; i < 3; i++) {	// ingr[idx][i] 계산
		for (j = 0; j < 4; j++) {	// r
			for (k = 0; k < 4; k++) {	// c
				ingr[idx][i + 1].set(j, k, ingr[idx][i].getEfficiency(3 - k, j), ingr[idx][i].getColor(3 - k, j));
			}
		}
	}
}

// src(현재 가마 상태) + idxCnt 재료를 dst의 (startR, startC) 위치에 넣음
// (startR, startC) = (0, 0) / (0, 1) / (1, 0) / (1, 1)
void calc(const int (&src)[5][5][2], int (&dst)[5][5][2], int idxCnt, int idxRot, int startR, int startC) {
	int i, j, r, c;

	// 재료가 더해지지 않는 부분 옮겨오기
	r = startR == 0 ? 4 : 0;
	c = startC == 0 ? 4 : 0;
	for (i = 0; i < 5; i++) {
		dst[r][i][0] = src[r][i][0];
		dst[r][i][1] = src[r][i][1];
		dst[i][c][0] = src[i][c][0];
		dst[i][c][1] = src[i][c][1];
	}

	// 재료 더하기
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			// 효능
			dst[startR + i][startC + j][0] = src[startR + i][startC + j][0] + ingr[idxCnt][idxRot].getEfficiency(i, j);
			if (dst[startR + i][startC + j][0] < 0)
				dst[startR + i][startC + j][0] = 0;
			else if (dst[startR + i][startC + j][0] > 9)
				dst[startR + i][startC + j][0] = 9;

			// 원소
			dst[startR + i][startC + j][1] = ingr[idxCnt][idxRot].getColor(i, j);
			if (dst[startR + i][startC + j][1] == 0)
				dst[startR + i][startC + j][1] = src[startR + i][startC + j][1];
		}
	}
}

// 재료 a, b, c에 대한 최대 품질 계산
// src에 cnt번째 재료 넣음
void dfs(int (&src)[5][5][2], int a, int b, int c, int cnt) {
	int i, j, k, idxCnt;
	int dst[5][5][2] = { 0, };

	if (cnt == 0)
		idxCnt = a;
	else if (cnt == 1)
		idxCnt = b;
	else if (cnt == 2)
		idxCnt = c;
	else {
		int tmp = 0;

		for (i = 0; i < 5; i++) {
			for (j = 0; j < 5; j++) {
				tmp += src[i][j][0] * src[i][j][1];
			}
		}

		if (ans < tmp)
			ans = tmp;

		return;
	}

	for (i = 0; i < 2; i++) {	// r
		for (j = 0; j < 2; j++) {	// c
			for (k = 0; k < 4; k++) {	// rot
				calc(src, dst, idxCnt, k, i, j);
				dfs(dst, a, b, c, cnt + 1);
			}
		}
	}
}

int main() {
	char c;
	int i, j, k, tmp;
	int arr[5][5][2] = { 0, };
	
	// 입력
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				scanf("%d", &tmp);
				ingr[i][0].setEfficiency(j, k, tmp);
			}
		}
		scanf("%c", &c);	// '\n'
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				scanf("%c", &c);
				if (c == 'R')
					ingr[i][0].setColor(j, k, R);
				else if (c == 'B')
					ingr[i][0].setColor(j, k, B);
				else if (c == 'G')
					ingr[i][0].setColor(j, k, G);
				else if (c == 'Y')
					ingr[i][0].setColor(j, k, Y);
				else  //'W'
					ingr[i][0].setColor(j, k, W);
				scanf("%c", &c);	// ' ', '\n'
			}
		}
	}

	// 회전
	for (i = 0; i < n; i++)
		rotate(i);

	//i, j, k 번째 재료 골랐을 때 최대 효능 계산
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j)
				continue;
			for (k = 0; k < n; k++) {
				if (i == k || j == k)
					continue;
				dfs(arr, i, j, k, 0);
			}
		}
	}

	printf("%d\n", ans);
}
