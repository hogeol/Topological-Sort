#ifndef __ADJACENCYLIST__
#define __ADJACENCYLIST__
#include "GUI.hpp"
#include <iostream>
#include <vector>

#define SIZE 9

namespace nTopologicalSort {
	class Adjacencylist
	{
	private:
		int mAvertex;
		std::vector<std::vector<int>>::iterator mAedge_iter;
		std::vector<int>::iterator mAdest_iter;
		std::vector<std::vector<int>> mAadj_list;
	public:
		Adjacencylist(int vertex) : mAvertex(vertex) {}
		bool Make_adjacencylist(int(*graph_array)[SIZE]);
		void Remove_empty_edge(int(*graph_array)[SIZE]);
		void Display_adjacencylist();
		std::vector<std::vector<int>>::iterator container_getter();
		std::vector<std::vector<int>>::iterator container_end_getter();
	};
}
#endif __ADJACENCYLIST__