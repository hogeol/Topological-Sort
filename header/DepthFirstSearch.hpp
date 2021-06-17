#ifndef __DEPTHFIRSTSEARCH__
#define __DEPTHFIRSTSEARCH__
#include "Adjacencylist.hpp"
#include <iostream>
#include <list>
#include <vector>

namespace nTopologicalSort {
	class DepthFirstSearch
	{
	private:
		std::list<int> mDlvalue;
		std::vector<int> mDvector;
		std::vector<std::vector<int>> mDvcontainer;
		std::vector<int> mDvvalue;
	public:
		void Copy(Adjacencylist& adj);
		void Depth_first_search();
		void Topological_sort(Adjacencylist& adj);
		void Print_after_TPS();
	};
}
#endif __DEPTHFIRSTSEARCH__
