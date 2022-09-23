#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cnn(int** a, int start, int end) {
	int	pivot = end - start + 1, num;
	int** temp;
	num = pivot / 2;
	temp = (int**)malloc(sizeof(int*) * num);
	for (int t = 0; t < num; t++) {
		temp[t] = (int*)malloc(sizeof(int) * num);
	}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			int result, max1, max2, min1, min2;
			if (a[2 * i][2 * j] > a[2 * i][2 * j + 1]) {
				max1 = a[2 * i][2 * j];
				min1 = a[2 * i][2 * j + 1];
			}
			else {
				min1 = a[2 * i][2 * j];
				max1 = a[2 * i][2 * j + 1];

			}
			if (a[2 * i + 1][2 * j] > a[2 * i + 1][2 * j + 1]) {
				max2 = a[2 * i + 1][2 * j];
				min2 = a[2 * i + 1][2 * j + 1];
			}
			else {
				min2 = a[2 * i + 1][2 * j];
				max2 = a[2 * i + 1][2 * j + 1];
			}
			if (max1 < max2) {
				result = max1 > min2 ? max1 : min2;
			}
			else {
				result = min1 > max2 ? min1 : max2;
			}
			temp[i][j] = result;
		}
	}
	if (num == 1) {
		return temp[0][0];
	}
	else {
		return cnn(temp, 0, num - 1);
	}
}

int main(void){
	int n, ** arr;
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
	printf("%d", cnn(arr, 0, n - 1));
}