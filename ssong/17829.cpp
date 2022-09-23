#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1024

using namespace std;

int matrix[MAX][MAX];

vector<int> v;

int Pulling(int x, int y)
{
	v.clear();

    // 4개씩 넣어서 정렬
	for (int i = x; i <= x + 1; i++)
		for (int j = y; j <= y + 1; j++)
			v.push_back(matrix[i][j]);

	sort(v.begin(), v.end());

	return v[2]; //2번째로 큰 수 리턴
}


int main()
{
	int N = 0;
	cin >> N;

    //matrix 입력
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j];

	while (N > 1)
	{
		for (int i = 0; i < N; i += 2)
			for (int j = 0; j < N; j += 2)
				matrix[i / 2][j / 2] = Pulling(i, j);
		N /= 2;
	}

	cout << matrix[0][0] << "\n";
	return 0;
}