#include "Adjacencylist.hpp"
#include "DepthFirstSearch.hpp"

using namespace std;

bool nTopologicalSort::Adjacencylist::Make_adjacencylist(int(*graph_array)[SIZE])
{
	//�������� �ʴ� edge ����
	Remove_empty_edge(graph_array);

	//2���� �迭�� edge�� �������� 2���� ���Ϳ� ����
	vector<int> vector1;
	vector<vector<int>> tmp;
	for (int i = 0; i < mAvertex; i++)
	{
		if (graph_array[i][0] != 2) {
			vector1.push_back(i + 1);
			for (int j = 0; j < mAvertex; j++)
			{
				if (graph_array[i][j] == 1)
					vector1.push_back(j + 1);
			}
			mAadj_list.push_back(vector1);
			vector1.clear();
		}
	}
	mAedge_iter = mAadj_list.begin();
	mAdest_iter = mAadj_list.begin()->begin();
	//���Կ� �����Ͽ����� false
	if (mAadj_list.empty())
		return false;

	return true;
}

//�������� �ʴ� edge ����
void nTopologicalSort::Adjacencylist::Remove_empty_edge(int(*graph_array)[SIZE])
{
	bool flag = 0;
	vector<int> check;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			if (graph_array[i][j] == 1)
			{
				flag = 1;
				break;
			}
		if (flag == 0)
			check.push_back(i);
		flag = 0;
	}

	for (int i = 0; i < check.size(); i++)
	{
		int tmp = check.at(i);
		for (int j = 0; j < SIZE; j++)
			if (graph_array[j][tmp] == 1)
			{
				flag = 1;
				break;
			}
		if (flag == 0)
			graph_array[tmp][0] = 2;
		flag = 0;
	}
}

//���Ե� ���� ���
void nTopologicalSort::Adjacencylist::Display_adjacencylist()
{
	Set_color(0);
	cout << "Adjacency List\n";
	Set_color(1);
	for (mAedge_iter = mAadj_list.begin(); mAedge_iter != mAadj_list.end(); mAedge_iter++)
	{
		if ((*mAedge_iter).size() != 1)
		{
			for (mAdest_iter = mAedge_iter->begin(); mAdest_iter != mAedge_iter->end(); mAdest_iter++)
			{
				if (mAdest_iter == mAedge_iter->begin())
				{

					cout << *mAdest_iter << " -> ";
				}
				else
					cout << *mAdest_iter << " ";
			}
			cout << endl;
		}
	}
	cout << endl;
	mAedge_iter = mAadj_list.begin();
	mAdest_iter = mAadj_list.begin()->begin();
}

//Adjacency list�� getter
std::vector<std::vector<int>>::iterator nTopologicalSort::Adjacencylist::container_getter()
{
	vector<vector<int>>::iterator tmp = mAadj_list.begin();
	return tmp;
}

std::vector<std::vector<int>>::iterator nTopologicalSort::Adjacencylist::container_end_getter()
{
	vector<vector<int>>::iterator tmp = mAadj_list.end();

	return tmp;
}