#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int pivot[1000] = { 0, };

int pivot_set(int n, int index) {
	if (index == 0) {
		pivot[index] = 3;
	}
	else {
		pivot[index] = 2 * pivot[index - 1] + index + 3;
	}
	if (pivot[index] < n) { //문자열이 충분하지않은경우
		pivot_set(n, index + 1);
	}
	else {
		return index;
	}
}

int moo(int n, int index) {//문자탐색
	if (n <= 3) { //S(0)에서 결과나오는경우
		if (n == 1) {
			return 1;
		}
		else {
			return 2;
		}
	}
	else { //S(n) (단, n != 0인 케이스에 대한 탐색)
		for (int t = 0; t <= index; t++) {
			if (pivot[t] < n) {//문자열 길이 부족
				continue;
			}
			else {//문자열 길이 만족
				int a = pivot[t - 1], b = t + 3;
				if (a + b < n) {//part 3에 n이 위치
					moo(n - a - b, t - 1);
					break;
				}
				else {// part 2에 n이 위치
					if (n == a + 1) {
						return 1;
					}
					else {
						return 2;
					}
				}
			}
		}
	}
}

int main(void) {
	int num, index = 0, param, result;
	scanf("%d", &num);
	param = pivot_set(num, index);
	result = moo(num, param);
	if (result == 1) {
		printf("m");
	}
	else {
		printf("o");
	}
}