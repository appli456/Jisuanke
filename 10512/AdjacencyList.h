#pragma once
#include <map>
#include <set>
#include <unordered_map>
#include "Point.h"
using std::unordered_map;
using std::set;
namespace li_algorithm
{
	class AdjacencyList
	{
	public:
		AdjacencyList();
		AdjacencyList(unsigned int row, bool if_direction);
		AdjacencyList(unsigned row, bool if_direction, unsigned start_point);
		~AdjacencyList();

		unsigned get_start_point() const;
		unsigned get_row() const;
		bool push(unsigned x, unsigned y) const; // ��ӵ�
		bool push(Point p) const;
		bool push(Point &p) const;
		AdjacencyList* get_children_graph(AdjacencyList* children_graph); // ��ȡ�ӵ�start��end����ͼ
		void print(); // ��ӡͼ
		unsigned get_number_of_communicating_branch();

	private:
		unordered_map<unsigned, set<unsigned>*> adjacency_list;
		bool if_direction;
		unsigned row;
		unsigned start_point;
	};
}
