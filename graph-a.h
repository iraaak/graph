#ifndef __GRAPH_A_H 
#define __GRAPH_A_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

class Graph {
	private:
		vector<list<int> > graph;
		vector<int> result;
    public:
        Graph() {}
        ~Graph() {}
        Graph(int n) : graph(n+1) {}
		vector<bool> visited;
        //queue<int> q; // для поиска в ширину
        vector<vector<int> > weight; // для Флойда, Дейкстры 
        void addEdge(int, int);
        void add_orient_Edge(int, int);
        void addVertex();
        void addWeight(int, int, int);
        void print_weight();
        bool existVertex(int);
        void listVertex();
        void print_result();
        void dfs_interface(int);
        void dfs(int);
        void bfs(int);
        void dejkstra(int);
        void FU();
        void Prim();
        void Kruskal(const vector<vector<int>> &);
		void print_matrix(int**, int, int);
};

#endif
