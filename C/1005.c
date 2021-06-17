// URL: https://judge.koreatech.ac.kr/problem.php?id=1005
// Memory Usage: 1984 KB
// Runnig Time: 552 ms
// Code Size: 2925 bytes

#include <stdio.h>
#include <stdlib.h>

// return redandancy count.
int redundancyCountCheck(int *rc, int target, int minAbs, int size);

int main(void)
{
	// input.
	int n;
	int *inputs;
	scanf("%d", &n);
	inputs = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) scanf("%d", &inputs[i]);

	// min, max from input.
	int min = inputs[0];
	int max = inputs[0];
	for (int i = 0; i < n; i++)
	{
		int value = inputs[i];
		if (inputs[i] < min)
			min = value;
		if (inputs[i] > max)
			max = value;
	}

	int minAbs = min < 0 ? -min : min;
	int maxAbs = max < 0 ? -max : max;

	// redundancy counter.
	int redundancySize = minAbs + maxAbs + 1;
	int *redundancyCount = (int*)calloc(redundancySize, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		int value = inputs[i];
		int index = value + minAbs;
		redundancyCount[index]++;
	}

	// counting 0s.
	int zeroCount = 0;

	int zeros = redundancyCountCheck(redundancyCount, 0, minAbs, redundancySize);
	// if you have 3 0s, then you can make 0 with them.
	if (zeros >= 3)
		zeroCount++;

	for (int i = 0; i < redundancySize; i++)
	{
		// no need to check if you don't have any 0s.
		if (!zeros)
			break;

		// no need to check 0s.
		int value = i - minAbs;
		if (value >= 0)
			break;

		// if you have some neg num and its counterpart pos num, then you can make 0 with them.
		int count = redundancyCountCheck(redundancyCount, value, minAbs, redundancySize);
		if (count && redundancyCountCheck(redundancyCount, -value, minAbs, redundancySize))
			zeroCount++;
	}
	
	for (int i = 0; i < redundancySize; i++)
	{
		// no ndeed to check 0s.
		int value = i - minAbs;
		if (!value)
			continue;

		// if you have two or more neg nums and their counterpart pos num, then you can make 0 wiht them.
		int count = redundancyCountCheck(redundancyCount, value, minAbs, redundancySize);
		if ((count >= 2) && redundancyCountCheck(redundancyCount, -value * 2, minAbs, redundancySize))
			zeroCount++;
	}
	
	// 2 negs and 1 pos.
	for (int i = 0; i < redundancySize; i++)
	{
		int value1 = i - minAbs;
		if (value1 >= 0)
			break;
		int count1 = redundancyCountCheck(redundancyCount, value1, minAbs, redundancySize);
		if (!count1)
			continue;

		for (int j = i + 1; j < redundancySize; j++)
		{
			int value2 = j - minAbs;
			if (value2 >= 0)
				break;
			int count2 = redundancyCountCheck(redundancyCount, value2, minAbs, redundancySize);
			if (!count2)
				continue;

			if (redundancyCountCheck(redundancyCount, -(value1 + value2), minAbs, redundancySize))
				zeroCount++;
		}
	}

	// 2 pos' and 1 neg.
	for (int i = 0; i < redundancySize; i++)
	{
		int value1 = i - minAbs;
		if (value1 <= 0)
			continue;
		int count1 = redundancyCountCheck(redundancyCount, value1, minAbs, redundancySize);
		if (!count1)
			continue;

		for (int j = i + 1; j < redundancySize; j++)
		{
			int value2 = j - minAbs;
			if (value2 <= 0)
				continue;
			int count2 = redundancyCountCheck(redundancyCount, value2, minAbs, redundancySize);
			if (!count2)
				continue;

			if (redundancyCountCheck(redundancyCount, -(value1 + value2), minAbs, redundancySize))
				zeroCount++;
		}
	}

	// printing result.
	printf("%d\n", zeroCount);

	// free memories.
	free(inputs);
	free(redundancyCount);

	return 0;
}

int redundancyCountCheck(int *rc, int target, int minAbs, int size)
{
	int index = target + minAbs;
	if (0 <= index && index < size)
		return rc[index];
	return 0;
}