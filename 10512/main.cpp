

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Point.h"
#include "AdjacencyList.h"

using li_algorithm::AdjacencyList;
using std::cin;
using std::cout;
using std::vector;



int main()
{
	int test_value_num;
	unsigned int row,
		point_num,
		question;

	unsigned int x, y;
	vector<AdjacencyList*>graphs;
	vector<Point>question_point;
	vector<unsigned int> communicating_branchs;
	cin >> test_value_num;

	// generate adjacency list
	for (size_t i = 0; i < test_value_num; ++i)
	{
		cin >> row >> point_num;
		AdjacencyList* adjacency_list = new AdjacencyList(row, false);
		for (size_t j = 0; j < point_num; ++j)
		{
			cin >> x >> y;
			(*adjacency_list).push(x, y);
		}
		graphs.push_back(adjacency_list);
	}
	
	for (unsigned i = 0; i < graphs.size(); ++i)
	{
		graphs.at(i)->print();
	}

	// save question data
	cin >> question;
	for (size_t i = 0; i < question; ++i)
	{
		Point p;
		cin >> p.x >> p.y;
		question_point.push_back(p);
	}



	system("pause");
    return 0;
}

