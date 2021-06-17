#include "DepthFirstSearch.hpp"

using namespace std;

//Adjacency list class로부터 정보를 가져옴
void nTopologicalSort::DepthFirstSearch::Copy(Adjacencylist& adj)
{
	vector<int> tmp;
	vector<int>::iterator tmp_iter;
	vector<vector<int>>::iterator edge_iter = adj.container_getter();
	vector<int>::iterator dest_iter;
	for (edge_iter = adj.container_getter(); edge_iter != adj.container_end_getter(); edge_iter++)
	{
		for (dest_iter = (*edge_iter).begin(); dest_iter != (*edge_iter).end(); dest_iter++)
			tmp.push_back(*dest_iter);
		mDvcontainer.push_back(tmp);
		tmp.clear();
	}
}

//DFS 알고리즘 수행
void nTopologicalSort::DepthFirstSearch::Depth_first_search()
{
	vector<int> tmp;
	vector<int>::iterator tmp_iter;
	vector<vector<int>>::iterator edge_iter = mDvcontainer.begin();
	vector<int>::iterator dest_iter = (mDvcontainer.begin())->begin();
	for (edge_iter = mDvcontainer.begin(); edge_iter != mDvcontainer.end(); edge_iter++)
		tmp.push_back((*edge_iter).front());
	tmp_iter = tmp.begin();
	for (edge_iter = mDvcontainer.begin(); edge_iter != mDvcontainer.end(); edge_iter++)
		for (int i = 1; i < (*edge_iter).size(); i++)
		{
			for (tmp_iter = tmp.begin(); tmp_iter != tmp.end();)
				if (*tmp_iter == (*edge_iter).at(i))
					tmp_iter = tmp.erase(tmp_iter);
				else
					++tmp_iter;
		}
	for (tmp_iter = tmp.begin(); tmp_iter != tmp.end(); tmp_iter++)
		mDlvalue.push_back(*tmp_iter);
}

void nTopologicalSort::DepthFirstSearch::Topological_sort(Adjacencylist& adj)
{
	Copy(adj);
	vector<int> tmp_vector;
	vector<vector<int>>::iterator edge_iter = mDvcontainer.begin();
	list<int>::iterator list_iter = mDlvalue.begin();
	while (mDvcontainer.size())
	{
		for (list_iter = mDlvalue.begin(); list_iter != mDlvalue.end(); list_iter++)
		{
			for (edge_iter = mDvcontainer.begin(); edge_iter != mDvcontainer.end();)
				if (*list_iter == (*(*edge_iter).begin()))
					edge_iter = mDvcontainer.erase(edge_iter);
				else
					++edge_iter;
		}
		if (mDvcontainer.size() == 0)
			break;
		Depth_first_search();
	}
}

//TPS를 끝낸 후 결과를 출력한다.
void nTopologicalSort::DepthFirstSearch::Print_after_TPS()
{
	Set_color(0);
	cout << "After Topological Sort\n";
	Set_color(1);
	list<int>::iterator list_print_iterator = mDlvalue.begin();
	for (list_print_iterator = mDlvalue.begin(); list_print_iterator != mDlvalue.end();)
	{
		cout << *list_print_iterator;
		if (++list_print_iterator != mDlvalue.end())
			cout << " -> ";
	}
	cout << endl;
}
