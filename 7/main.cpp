
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
using std::cin;
using std::cout;
using std::string;
using std::ostringstream;

int main()
{
	string first;
	string second;
	string result;
	ostringstream ost;

	cin >> first >> second;

	for (size_t i = 0; i < first.length(); ++i)
	{
		if (first[i] == second[i])
		{
			ost << "1";
		} 
		else
		{
			ost << "0";
		}
	}

	result = ost.str();

	cout << result;
    return 0;
}

