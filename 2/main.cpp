
#include "stdafx.h"
#include <iostream>

int main()
{
	unsigned int m, n;
	std::cin >> m >> n;
	if (m <= 500 && n <= 500 && m >= 1 && n >= 1) {
		std::cout << (m % n == 0 ? "YES" : "NO") << std::endl;
	}
    return 0;
}

