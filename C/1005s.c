#include <stdio.h>
#include <stdlib.h>

int redundancyCountCheck(int *rc, int target, int minAbs, int size)
{
	int index = target + minAbs;
	if (0 <= index && index < size)
		return rc[index];
	return 0;
}

int main(void)
{
	int n;
	int *inputs;
	scanf("%d", &n);
	inputs = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) scanf("%d", &inputs[i]);

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

	int redundancySize = minAbs + maxAbs + 1;
	int *redundancyCount = (int*)calloc(redundancySize, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		int value = inputs[i];
		int index = value + minAbs;
		redundancyCount[index]++;
	}

	int zeroCount = 0;

	int zeros = redundancyCountCheck(redundancyCount, 0, minAbs, redundancySize);
	if (zeros >= 3)
		zeroCount++;

	for (int i = 0; i < redundancySize; i++)
	{
		if (!zeros)
			break;

		int value = i - minAbs;
		if (value >= 0)
			break;

		int count = redundancyCountCheck(redundancyCount, value, minAbs, redundancySize);
		if (count && redundancyCountCheck(redundancyCount, -value, minAbs, redundancySize))
			zeroCount++;
	}
	
	for (int i = 0; i < redundancySize; i++)
	{
		int value = i - minAbs;
		if (!value)
			continue;

		int count = redundancyCountCheck(redundancyCount, value, minAbs, redundancySize);
		if ((count >= 2) && redundancyCountCheck(redundancyCount, -value * 2, minAbs, redundancySize))
			zeroCount++;
	}
	
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

	printf("%d\n", zeroCount);

	free(inputs);
	free(redundancyCount);

	return 0;
}