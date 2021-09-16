#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <string>
#include <queue>
#include <fstream>

using namespace std;

void dfs(int &s, vector<int> &color, list<int>* &adjLists)
{
	
	color[s-1] = 1;
	for (auto& u : adjLists[s-1])
	{
		if (color[u-1] == 0)
		{
			dfs(u, color, adjLists);
		}
	}
	color[s-1] = 2;
}

vector<int> split(const string& s, char delimiter)
{
	vector<int> words;
	string word;
	istringstream wordStream(s);
	while (getline(wordStream, word, delimiter))
		words.push_back(stoi(word));
	return words;
}

int main()
{
	ifstream fin("input.txt");
	freopen("output.txt", "w", stdout);
	int n, s; //number of nodes and starting node
	
	string str;
	getline(fin, str);
	n = stoi(str);
	getline(fin, str);
	s = stoi(str);
	//cin >> n;
	//cin >> s;
	//vector<int> dist(n, -1);
	//vector<int> par(n, 0);
	list<int>* adjLists = new list<int>[n];
	vector<int> color(n, 0); // 0 - white, 1 - grey, 2 - black

	for (int i = 0; i < n; ++i)
	{
		getline(fin, str);
		vector<int> nodes;
		nodes = split(str, ' ');
		for (size_t j = 0; j < nodes.size(); ++j)
		{
			adjLists[i].push_back(nodes[j]);
			//cout << nodes[j] << ' ';
		}
		//cout << endl;
	}
	fin.close();
	dfs(s, color, adjLists);
	for (auto& c : color)
		cout << c << endl;
	getchar();
	return 0;

}
