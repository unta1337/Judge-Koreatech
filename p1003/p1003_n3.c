// 1003: 0을 만들자
/*
 * 길이가 n인 배열이 주어졌을 때, 배열 안의 수 세 개를 더했을 때 0이 되는 경우의 수를 출력하는 프로그램을 작성하여라.
 */
// https://judge.koreatech.ac.kr/problem.php?id=1003

// 메모리 사용량: KB
// 실행 시간: ms
// 코드 용량: bytes

#include <stdio.h>

int zeroCount(int arr[], int size)
{
	int count = 0;

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			for (size_t k = i + j + 1; k < size; k++)
			{
				if (arr[i] + arr[j] + arr[k] == 0)
					count++;
			}
		}
	}

	return count;
}

int main(void)
{
	int input[300] = { };
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &input[i]);

	printf("%d\n", zeroCount(input, n));

	return 0;
}
