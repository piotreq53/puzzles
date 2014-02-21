// *****************************************************************************************************************
// Description	: Solution to the problem 79 from Project Euler using Topological Sorting.
// Author				:	Piotr Rżysko
// *****************************************************************************************************************

#include <set>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int time = 0;

void dfs(set<int> graph[], int theResult[], bool visited[], int node)
{
	visited[node] = true;
	for(set<int>::iterator it = graph[node].begin(); it != graph[node].end(); it++) {
		if(!visited[*it]){
			dfs(graph, theResult, visited, *it);
		}		
	}
	theResult[time++] = node;
}

void readGraphFromFile(set<int> graph[])
{
	char node1, node2, node3;
	ifstream str;
	
	str.open("keylog.txt");
	str >> node1 >> node2 >> node3;
	while(!str.eof()) {
		graph[(int)node1 - '0'].insert((int)node2 - '0');
		graph[(int)node2 - '0'].insert((int)node3 - '0');
		str >> node1 >> node2 >> node3;
	}
	str.close();
}

int main(){
	set<int> graph[10];
	int theResult[10];
	bool visited[10];
	
	for(int i = 0; i < 10; i++) {
		theResult[i] = -1;
		visited[i] = false;
	}
		
	readGraphFromFile(graph);
	for(int i = 0; i < 10; i++)
		if(!visited[i] && !graph[i].empty())
			dfs(graph, theResult, visited, i);
	
	for(int i = 9; i >= 0; i--) {
		if(theResult[i] != -1)
			cout << theResult[i];
	}

	return 0;
}
