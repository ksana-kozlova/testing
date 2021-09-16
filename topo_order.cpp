#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <string>
#include <queue>
#include <fstream>

#include "Graph.h"

using namespace std;



int main()
{
	Graph g("input.txt");
	g.get_colors();
	//g.get_adjList();
	g.topo_dfs(1);

}