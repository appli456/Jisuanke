#pragma once
#include<vector>
#include <set>
#include <unordered_map>
#include <queue>
#include "Point.h"
using std::unordered_map;
using std::set;
using std::vector;
using std::queue;
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
		bool BFS_adjacency_list(std::set<unsigned int>*pre, unsigned int root);
		unordered_map<unsigned, set<unsigned>*> adjacency_list;
		bool if_direction;
		unsigned row;
		unsigned start_point;
	};
}
