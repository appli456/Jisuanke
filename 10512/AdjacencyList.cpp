#include "stdafx.h"
#include "AdjacencyList.h"
#include <algorithm>
#include <iostream>
#include <type_traits>
#include <queue>

namespace li_algorithm 
{
	AdjacencyList::AdjacencyList()
	{

	}

	AdjacencyList::AdjacencyList(unsigned row, bool if_direction)
		:AdjacencyList()
	{
		start_point = 1;
		this->if_direction = if_direction;
		this->row = row;
		for (unsigned i = 0; i < row; ++i)
		{
			adjacency_list[i] = new set<unsigned>;
		}
	}

	AdjacencyList::AdjacencyList(unsigned row, bool if_direction, unsigned start_point)
		:AdjacencyList(row, if_direction)
	{
		this->start_point = start_point;

	}


	AdjacencyList::~AdjacencyList()
	{
		for (unsigned i = 0; i < row; ++i)
		{
			(*adjacency_list[i]).clear();
		}
		adjacency_list.clear();
	}

	/**
	 * push point
	 * @param x {unsigned}
	 * @param y {unsigned}
	 * @retrun true
	 */
	bool AdjacencyList::push(unsigned x, unsigned y) const
	{

		// 输入数据是从start_point开始，所以此处要减
		(*adjacency_list.at(x - start_point)).insert(y - start_point);

		// non direction graph
		if (!if_direction)
		{
			(*adjacency_list.at(y - start_point)).insert(x - start_point);
		}
		return true;
	}


	bool AdjacencyList::push(Point p) const
	{
		return this->push(p.x, p.y);
	}

	bool AdjacencyList::push(Point& p) const
	{
		return this->push(p.x, p.y);
	}

	// 获取子图
	AdjacencyList* AdjacencyList::get_children_graph(AdjacencyList* children_graph)
	{
		unsigned children_row(children_graph->get_row());
		unsigned children_start_point(children_graph->get_start_point() - 1);
		unsigned children_end_point(children_start_point + children_row - 1);

		std::for_each(adjacency_list.begin(), adjacency_list.end(), 
			[&](std::pair<unsigned, set<unsigned>*> list_elem)
		{
			std::for_each((*list_elem.second).begin(), (*list_elem.second).end(), 
				[&](unsigned end_point)
			{
				if (children_row <= row && 
					list_elem.first <= children_end_point && 
					list_elem.first >= children_start_point && 
					end_point <= children_end_point && 
					end_point >= children_start_point)
				{
					children_graph->push(list_elem.first + start_point, 
						end_point + start_point);
				}
			});
		});

		return children_graph;
	}

	/**
	 * get number of communicating branch
	 * @return number of communicating branch
	 */
	unsigned AdjacencyList::get_number_of_communicating_branch()
	{
		unsigned int result = 0;
		std::set<unsigned int>visited_node;
		size_t size = adjacency_list.size();
		for (unsigned int i = 0; i < size; ++i)
		{
			if (BFS_adjacency_list(&visited_node, i))
			{
				result++;
			}
		}
		return result;
	}

	/**
	 * DFS Graph and find communicating branch
	 * @param pre {vector<unsigned>*}
	 * @param root {unsigned}
	 * @return {true} the root not be visited
	 *			{false} the root be visited
	 */
	bool AdjacencyList::BFS_adjacency_list(std::set<unsigned>* pre, unsigned int root)
	{

		// find root in set 
		if ((*pre).find(root) != (*pre).end())
		{
			return false;
		}

		queue<unsigned>point;
		point.push(root);

		// bfs
		while (!point.empty())
		{
			unsigned top = point.front();
			(*pre).insert(top);

			set<unsigned>*adjacency_point = adjacency_list[top];
			std::for_each((*adjacency_point).begin(), 
				(*adjacency_point).end(), 
				[&](unsigned value)
			{
				// cannot find value
				if ((*pre).find(value) == (*pre).end())
				{
					point.push(value);
				}
			});

			point.pop();
		}

		return true;
	}


	void AdjacencyList::print()
	{
		for (unsigned i = 0; i < row; ++i)
		{
			std::for_each((*adjacency_list[i]).begin(), 
				(*adjacency_list[i]).end(), 
				[&](unsigned value)
			{
				std::cout << i + start_point << ',' << value + start_point << '\n';
			});
		}
	}

	unsigned AdjacencyList::get_start_point() const
	{
		return start_point;
	}

	unsigned AdjacencyList::get_row() const
	{
		return row;
	}


}
