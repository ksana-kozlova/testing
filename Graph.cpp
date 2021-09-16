#include "Graph.h"
#include <fstream>
#include <sstream>
#include <iostream>

vector<int> split(const string& s, char delimiter)
{
	vector<int> words;
	string word;
	istringstream wordStream(s);
	while (getline(wordStream, word, delimiter))
		words.push_back(stoi(word));
	return words;
}

Graph::Graph(const string& path)
{
	string str;
	ifstream fin(path);
	unsigned int i = 0;
	while (getline(fin, str))
	{
		if (i == 0)
		{
			this->n = stoi(str);
			this->color = vector<int>(n, 0);
			this->adjLists = vector<list<int>>(n);
			ent = vector<int>(n, -1);
			out = vector<int>(n, -1);
		}
		else
		{
			vector<int> nodes;
			nodes = split(str, ' ');
			for (size_t j = 0; j < nodes.size(); ++j)
			{
				adjLists[i-1].push_back(nodes[j]);
			}
		}
		++i;
	}
	fin.close();
}

void Graph::add_edge(int v, int u)
{
	if (v > n)
	{
		color.push_back(0);
		adjLists[n - 1].push_back(u);
	}
	else if (u > n)
	{
		color.push_back(0);
		adjLists[v - 1].push_back(u);
	}
}

void Graph::dfs(int s)
{
	color[s - 1] = 1;
	for (auto& u : adjLists[s - 1])
	{
		if (color[u - 1] == 0)
		{
			dfs(u);
		}
	}
	color[s - 1] = 2;
}

void Graph::get_color(int v) const
{
	cout << color[v - 1] << endl;
}

void Graph::get_colors() const
{
	for (auto& c : color)
		cout << c;
}

void Graph::get_adjList() const
{
	for (int i = 0; i < adjLists.size(); ++i)
	{
		for (auto& node : adjLists[i])
			cout << node << ' ';
//		cout << endl;
	}
}

void Graph::topo_dfs(int s)
{

	color[s - 1] = 1;
	ent[s] = timer;
	++timer;

	for (auto& u : adjLists[s - 1])
	{
		if (color[u - 1] == 0)
			dfs(u);
		else if (color[u - 1] == 1) {
			cout << "cyclic graph" << endl;
			return;
		}
	}
	color[s - 1] = 2;
	out[s - 1] = timer;
	++timer;
}
