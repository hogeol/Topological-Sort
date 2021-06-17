#ifndef __IMPLEMENT__
#define __IMPLEMENE__
#include <iostream>
#include "GUI.hpp"

#define GRAPH1 "graph1.txt"
#define GRAPH2 "graph2.txt"
#define GRAPH3 "graph3.txt"
#define GRAPH4 "graph4.txt"
#define SIZE 9
#define MAX 81

bool Scan(int(*graph_array)[SIZE], std::string graph_num, int vertex = SIZE);
void Display_scan(int(*graph_array)[SIZE], std::string graph_num);

#endif __IMPLEMENT__
