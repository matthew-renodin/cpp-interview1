#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// data structure to store graph edges
struct Edge {
	int src, dest;
};

// class to represent a graph object
class Graph
{
public:
	// construct a vector of vectors to represent adjacency list in C++
	vector<vector<int>> adjList;

	// Graph Constructor
	Graph(const vector<Edge> &edges, int N)
	{
		// resize the vector to N elements of type vector<int>
		adjList.resize(N);

		// add edges to the undirected graph
		for (const Edge &edge: edges) {
			adjList[edge.src].push_back(edge.dest);
			adjList[edge.dest].push_back(edge.src);
		}
	}
};

// Perform BFS on graph starting from vertex v	
vector<Edge> BFS(Graph const &graph, int N, int v)
{
	// stores directed graph edges
	vector<Edge> edges;
	
	// stores vertex is discovered or not
	vector<bool> discovered(N);

	// mark source vertex as discovered
	discovered[v] = true;

	// create a queue used to do BFS
	queue<int> q;

	// push source vertex into the queue
	q.push(v);
 
	// run till queue is not empty
	while(!q.empty())
	{
		// pop front node from queue
		v = q.front();
		q.pop();

		// do for every edge (v -> u)
		for (int u : graph.adjList[v])
		{
			if (!discovered[u])
			{
				// mark it discovered and push it into queue
				discovered[u] = true;
				
				// add edge from i to s in directed graph
				edges.push_back({u, v});
				
				q.push(u);
			}
		}
	}
	
	return edges;
}

