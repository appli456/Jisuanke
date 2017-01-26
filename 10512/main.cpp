

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
	// vector<Point>question_point;
	vector<vector<unsigned int>> communicating_branchs;
	cin >> test_value_num;

	// generate adjacency list
	for (size_t i = 0; i < test_value_num; ++i)
	{
		vector<unsigned>result_vec;
		cin >> row >> point_num;
		AdjacencyList* adjacency_list = new AdjacencyList(row, false);
		for (size_t j = 0; j < point_num; ++j)
		{
			cin >> x >> y;
			(*adjacency_list).push(x, y);
		}
		graphs.push_back(adjacency_list);
		communicating_branchs.push_back(result_vec);
		// save and generate question data
		cin >> question;
		for (size_t j = 0; j < question; ++j)
		{
			Point p;
			cin >> p.x >> p.y;
			// question_point.push_back(p);
			AdjacencyList* children_graph = new AdjacencyList(p.y - p.x + 1, false, p.x);

			adjacency_list->get_children_graph(children_graph);
			// children_graph->print();
			communicating_branchs.at(i).push_back(
				(*children_graph).get_number_of_communicating_branch()
			);

			delete children_graph;
			// children_graph.print();
			// cout << "========================================" << std::endl;
		}

		delete adjacency_list;
	}
	
	size_t size = communicating_branchs.size();

	for(unsigned i = 0; i < size; ++i)
	{
		cout << "Case #" << i + 1 << ":" << std::endl;
		for (auto it : communicating_branchs.at(i))
		{
			cout << it << std::endl;
		}
	}


	// system("pause");
    return 0;
}

