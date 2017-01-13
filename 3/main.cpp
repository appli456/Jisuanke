
#include "stdafx.h"
#include <iostream>
#include <cmath>

int main()
{
	unsigned int n;
	std::cin >> n;
	auto max_count = sqrt(n);
	bool flag = true;
	if (n != 2)
	{
		for (unsigned int i = 2; i <= max_count; ++i)
		{
			if (n % i == 0)
			{
				flag = !flag;
				break;
			}
		}
	}
	std::cout << (flag ? "YES" : "NO");
	system("pause");
    return 0;
}

