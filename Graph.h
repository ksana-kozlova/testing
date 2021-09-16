#pragma once

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <string>



using namespace std;

class Graph
{
private:
	unsigned int n;
	vector<list<int>> adjLists;
	vector<int> color; // 0 - white, 1 - grey, 2 - black

	int timer = 0;
	vector<int> ent;
	vector<int> out;
	vector<string> features;

public:
	Graph(const string& path);
	void add_edge(int v, int u);
	void dfs(int s);
	void get_color(int v) const;
	void get_colors() const;
	void get_adjList() const;
	void topo_dfs(int s);
};

#endif