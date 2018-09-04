#include "graph-a.h"

struct Edge
{
	int v1;
	int v2;
	int weight;
};

bool Graph::existVertex(int v) {
	if(graph.size() == 0)
		return false;
	if(v < graph.size())
			return true;
	return false;
}
// в конец
void Graph::addVertex() {
    graph.push_back(list<int>());
}
 
void Graph::add_orient_Edge(int i, int j) {
	graph[i].push_back(j);
}

void Graph::addEdge(int i, int j) {
	graph[i].push_back(j);
	graph[j].push_back(i);
}

void Graph::addWeight(int i, int j, int k) {
		if (weight.empty())
		{
			weight = vector<vector<int>>(graph.size(), vector<int>(graph.size(), 0));
		}
		weight[i][j] = k;
		weight[j][i] = k;
}

void Graph::print_weight() {
	for(int i = 0; i < graph.size(); i++)
		for(int j = 0; j < graph.size(); j++)
		cout << i << " " << j << " " << weight[i][j] << endl; 		
}

void Graph::listVertex() {
    for(int i = 0; i < graph.size(); i++) {	
		cout << i << ": ";
		for (int j: graph[i])
			cout << j << " ";
		cout << endl;
	}
}

void Graph::print_matrix(int** matrix, int v, int INF) {	
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (matrix[i][j] == INF) 	
				cout << "INF" << " ";	
			else 	
				cout << matrix[i][j] << " ";	
		}
		cout << endl;	
	}
}

void Graph::print_result() {
	int i =0;
	int k = result.size(); 
	while(k != 0) {
		cout << result[i] << " ";
		i++;
		k--;
	}
	cout << endl;
}

void Graph::dfs_interface(int s) {	
	visited = vector<bool>(graph.size(), false);
	dfs(s);
}

void Graph::dfs(int v) {
	visited[v] = true;
	result.push_back(v);
	for(auto i = graph[v].begin(); i != graph[v].end(); ++i) {// для всех смежных вершин 
		if(!visited[*i])
			dfs(*i);
		}	
}

void Graph::bfs(int s) {
	int n = graph.size();
	vector<bool> visited(n, false);
	vector<int> result;
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while(!q.empty()) {
		int temp = q.front(); 
		q.pop();
		result.push_back(temp);
		for(int to: graph[temp]) {
			if(!visited[to]) {
				visited[to] = true;
				q.push(to);
			}
		}
	}
}

void Graph::dejkstra(int s) { 
	int n = graph.size();
	int index = 0, v = 0;
	const int INF = 1000000;
	vector<int> D(n, INF);
	vector<bool> visited(n, false);
	for(int i = 0; i < weight.size(); i++) 
	{
		for (auto x: weight[i])
			cout << x << " ";	
		cout <<endl;
	}
	D[s] = 0;
	for(int i = 1; i < graph.size(); i++) 
	{
		int min=INF;
		int min_ind = -1;
		for (int j = 1; j < graph.size(); j++)
			if(!visited[j] && (D[j] <= min)) 
			{ 
				min = D[j]; 
				min_ind = j;
			}
		if (min_ind == -1) break;
		visited[min_ind] = true;
		for(int j = 1; j < weight[min_ind].size(); j++) 
		{
			int weightU = weight[min_ind][j];
			if (weightU == 0) continue;
			if ((D[min_ind] + weightU) < D[j]) 
			{ 
				D[j] = weightU + D[min_ind];
			}
		}
	}
	for (int i = 1; i < n; i++) 
	{
		cout << i << " : " << D[i] <<endl;
	}
}	

void Graph::FU() 
{
	for(int i = 0; i < graph.size(); i++) 
		weight[i][i] = 0;
	for (int k = 0; k < graph.size(); k++)
		for (int i = 0; i < graph.size(); i++)
			for (int j = 0; j < graph.size(); j++)
				if (weight[i][k] && weight[k][j] && i != j)
					if (weight[i][k] + weight[k][j] < weight[i][j] || weight[i][j]==0)
						weight[i][j] = weight[i][k] + weight[k][j];
	
	for (int i = 0; i < graph.size(); i++) 
	{ 
		for (int j = 0; j < graph.size(); j++) 
		{
			cout << weight[i][j] << " ";
		}
			cout << endl;
	}
}

void Graph::Prim() {
	const int INF = 1000000;
	size_t n = graph.size();
	vector<int> D(n, INF);
	vector<int> Parent(n, 0);
	int s = 1, v;
	vector<bool> visited(n, false);
	
	for(int i = 0; i < n; i++)
	{
		D[s] = 0;
		int min = INF;
		int index = -1;
		for(int k = 1; k < n; k++)
		if (!visited[k] && D[k] <= min) 
		{ 
			min = D[k]; 
			index = k; 
		}
		v=index;
		if (v == -1) break;
		visited[v]=true;
		for(int j = 1; j < weight[v].size(); j++) 
		{
			int weightV = weight[v][j];
			if (weightV == 0) continue;
	    	if (weightV < D[j] && !visited[j]) 
			{ 
				D[j] = weightV;
				Parent[j] = v;
			}
		}
	}
	
	for(int i = 0; i < graph.size(); i++) 
	{ 
		int k = Parent[i];
		int weightP = weight[i][k];
		
		if (k != 0)
		{
			cout << "(" << k << "," << i << ")" << endl;
		}		
	}	
}

void Graph::Kruskal(const vector<vector<int>> &weight_matrix) {
	int temp = 0;
	vector<Edge> edges;
	vector<Edge> result;
	size_t n = weight_matrix.size();
	vector<int> D(n, 0);

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (weight_matrix[i][j] > 0)
				edges.push_back({i,j, weight_matrix[i][j]});
			
	sort (edges.begin(), edges.end(), [](Edge a, Edge b){return a.weight < b.weight;});
		
	for (int i = 0; i < n; i++) 
		D[i] = i;

	for(auto i = edges.begin(); i != edges.end(); ++i) {
		if(D[i->v1] != D[i->v2]) {
			cout << i->v1 << " " << i->v2 << endl;
			result.push_back(*i);
			temp = D[i->v1];
			for(int j = 0; j < n; j++) 
				if(D[j] == temp)
					D[j] = D[i->v2];
		}
	}
}
