
#include "stdafx.h"
#include <iostream>

void quick_sort(int* a, int low, int high)
{
	if (low >= high)
	{
		return;
	}
	int first = low;
	int last = high;
	int key = a[first];

	while (first < last)
	{
		while (first < last && a[last] >= key)
		{
			--last;
		}

		a[first] = a[last];

		while (first < last && a[first] <= key)
		{
			++first;
		}

		a[last] = a[first];
	}
	a[first] = key;
	quick_sort(a, low, first - 1);
	quick_sort(a, first + 1, high);
}

int main()
{
	size_t n;
	std::cin >> n;
	int *a = new int[n];
	for (size_t i = 0; i < n; ++i)
	{
		std::cin >> a[i];
	}
	if (n == 1)
	{
		std::cout << a[0];

		return 0;
	}
	quick_sort(a, 0, n - 1);
	bool flag = false;
	for (size_t i = 1; i < n - 1; ++i)
	{
		if (a[i] != a[i - 1] && a[i] != a[i + 1])
		{
			std::cout << a[i];
			flag = true;
			break;
		}
	}

	if (!flag)
	{
		if (a[0] != a[1])
		{
			std::cout << a[0];
		}
		else
		{
			std::cout << a[n - 1];
		}
	}
    return 0;
}

