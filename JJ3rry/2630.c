#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int func(int** a, int start1, int end1, int start2, int end2, int b) {
	int range = end1 - start1 + 1, num = range / 2, pivot = num * num, result = 0, board = b;
	int sum1 = 0;
	if (start1 == end1) {
		return 0;
	}
	for (int i = start1; i <= end1; i++) {
		for (int j = start2; j <= end2; j++) {
			if (board == a[i][j]) {
				sum1++;
			}
			else {
				continue;
			}
		}
	}
	if (sum1 == range * range) {
		return 1;
	}

	for (int t = 0; t < 4; t++) {
		int x = t / 2, y = t % 2;
		int sum = 0;
		for (int i = start1 + x * num; i < start1 + (x + 1) * num; i++) {
			for (int j = start2 + y * num; j < start2 +(y + 1) * num; j++) {
				if (board == a[i][j]) {
					sum++;
				}
				else {
					continue;
				}
			}
		}
		if (sum == pivot) {
			result++;
		}
		else {
			result += func(a, start1 + x * num, start1 - 1 + (x + 1) * num, start2 + y * num, start2 - 1 + (y + 1) * num, board);
		}
	}
	return result;
}

int main(void) {
	int n, ** arr, result, pivot;
	scanf("%d", &n);
	arr = (int**)malloc(sizeof(int*) * n);
	for (int t = 0; t < n; t++) {
		arr[t] = (int*)malloc(sizeof(int) * n);
	}
	for (int t = 0; t < n; t++) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[t][i]);
		}
	}
	result = func(arr, 0, n - 1, 0, n - 1, 1);
	printf("%d\n%d", func(arr, 0, n - 1, 0, n - 1, 0), func(arr, 0, n - 1, 0, n - 1, 1));
}