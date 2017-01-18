#include "stdafx.h"
#include "AdjacencyList.h"
#include <algorithm>
#include <iostream>
namespace li_algorithm 
{
	AdjacencyList::AdjacencyList()
	{

	}

	AdjacencyList::AdjacencyList(unsigned row, bool if_direction = false)
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

		// 输入数据是从start_point开始，所以此处要减一
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
		unsigned children_row = children_graph->get_row();
		unsigned children_start_point = children_graph->get_start_point();


		return children_graph;
	}

	/**
	 * get number of communicating branch
	 * @return number of communicating branch
	 */
	unsigned AdjacencyList::get_number_of_communicating_branch()
	{
		
	}



	void AdjacencyList::print()
	{
		for (unsigned i = 0; i < row; ++i)
		{
			std::for_each((*adjacency_list[i]).begin(), (*adjacency_list[i]).end(), 
				[&](unsigned value)
			{
				std::cout << i + 1 << ',' << value + 1 << '\n';
			});
		}
	}

	unsigned AdjacencyList::get_start_point()
	{
		return start_point;
	}

	unsigned AdjacencyList::get_row() const
	{
		return row;
	}


}