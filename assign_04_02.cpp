/*
* C++ program to count all paths from a source to a
* destination in a graph with character-labeled vertices.
*/
#include <bits/stdc++.h>
using namespace std;

// Map characters to indices
unordered_map<char, int> char_to_index = {
    {'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}
};

// Map indices back to characters for readability if needed
unordered_map<int, char> index_to_char = {
    {0, 'A'}, {1, 'B'}, {2, 'C'}, {3, 'D'}, {4, 'E'}
};

class Graph {
public:
	// Construct the graph given the number of vertices...
	Graph(int vertices);
	// Specify an edge between two vertices
	void add_edge(char src, char dst);
	// Call the recursive helper function to count all the
	// paths
	int count_paths(char src, char dst);

private:
	int m_vertices;
	list<int>* m_neighbours;
	void path_counter(int src, int dst, int& path_count,
					  vector<bool>& visited);
};

Graph::Graph(int vertices)
{
	m_vertices = vertices; 
	m_neighbours = new list<int>[vertices];
}

void Graph::add_edge(char src, char dst)
{
	int src_index = char_to_index[src];
	int dst_index = char_to_index[dst];
	m_neighbours[src_index].push_back(dst_index);
}

int Graph::count_paths(char src, char dst)
{
	int path_count = 0;
	vector<bool> visited(m_vertices, false);
	int src_index = char_to_index[src];
	int dst_index = char_to_index[dst];
	path_counter(src_index, dst_index, path_count, visited);
	return path_count;
}

void Graph::path_counter(int src, int dst, int& path_count,
						 vector<bool>& visited)
{
	visited[src] = true;

	if (src == dst) {
		path_count++;
	}
	else {
		for (auto neighbour : m_neighbours[src]) {
			if (!visited[neighbour])
				path_counter(neighbour, dst, path_count, visited);
		}
	}
	visited[src] = false;  // backtrack
}

// Driver code
int main()
{
	Graph g(5);  // 5 vertices: A, B, C, D, E

	// Define edges: A-B, A-E, A-C, B-D, B-E, C-E, D-C
	g.add_edge('A', 'B');
	g.add_edge('A', 'E');
	g.add_edge('A', 'C');
	g.add_edge('B', 'D');
	g.add_edge('B', 'E');
	g.add_edge('C', 'E');
	g.add_edge('D', 'C');

	// Example: Count paths from A to E
	cout << "Paths from A to E: " << g.count_paths('A', 'E') << endl;

	return 0;
}
