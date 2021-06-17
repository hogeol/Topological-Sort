#define _CRT_SECURE_NO_WARNINGS
#include "Implement.hpp"

using namespace std;

//graph배열에 file 읽기
bool Scan(int(*graph_array)[SIZE], string graph_num, int vertex)
{
	const char* graph = graph_num.c_str();
	FILE* file = fopen(graph, "rt");
	if (file == NULL)
	{
		cerr << "error occurred when open " << graph << endl;
		return 0;
	}
	fscanf(file, "%d", &vertex);
	while (!feof(file))
		for (int i = 0; i < vertex; i++)
			for (int j = 0; j < vertex; j++)
				fscanf(file, "%d", &graph_array[i][j]);
	fclose(file);
	return true;
}

//읽은 file 콘솔에 출력
void Display_scan(int(*graph_array)[SIZE], string graph_num)
{
	const char* graph = graph_num.c_str();
	Set_color(0);
	cout << "\nReusult of scan ";
	cout << graph << endl;
	Set_color(1);
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			cout << graph_array[i][j] << " ";
		cout << endl;
	}
	cout << "\n\n";
}
