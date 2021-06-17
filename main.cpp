#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "GUI.hpp"
#include "Implement.hpp"
#include "Adjacencylist.hpp"
#include "DepthFirstSearch.hpp"

using namespace std;
using namespace nTopologicalSort;

int main(int argc, char** argv)
{
	int num = 1;
	do
	{
		string input = Display(num);
		if (input == "-1")
			break;
		//.txt���Ϸκ��� 2�����迭 �׷����� �о�´�
		int MgraphArray[SIZE][SIZE] = {};
		Scan(MgraphArray, input);
		Display_scan(MgraphArray, input);

		//2�����迭 �׷����� adjacency list�� ������ش�
		Adjacencylist Madj_list(SIZE);
		Madj_list.Make_adjacencylist(MgraphArray);
		Madj_list.Display_adjacencylist();

		//DFS sort�� �����Ѵ�.
		DepthFirstSearch Mdfs;
		Mdfs.Topological_sort(Madj_list);
		Mdfs.Print_after_TPS();
		if (num == 1)
			num++;
	} while (true);

	return 0;
}