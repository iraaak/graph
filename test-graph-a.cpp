#include "graph-a.h"

int main() {
	
	Graph G2;
	G2.addVertex();
	G2.addVertex();
	G2.addVertex();
	G2.addVertex();
	G2.addVertex();
	G2.addVertex();
	G2.addVertex(); 
	G2.addVertex(); 
		
    G2.addEdge(1, 2);
    G2.addEdge(1, 3);
    G2.addEdge(2, 4);
    G2.addEdge(2, 5);
    G2.addEdge(3, 6);
    G2.addEdge(3, 7);
    G2.addEdge(4, 5);
    
    cout << "Поиск в глубину" << endl;
    G2.dfs_interface(1);
    G2.print_result();
    
	cout << "Поиск в ширину" << endl;	
	G2.bfs(1);
    G2.print_result();
    
    Graph G1;
    G1.addVertex();
    G1.addVertex();
    G1.addVertex();
    G1.addVertex();
    G1.addVertex();
    G1.addVertex();
    G1.addVertex(); 
	G1.addVertex(); 
    
    G1.addEdge(1, 2);
    G1.addEdge(1, 3);
    G1.addEdge(1, 6);
    G1.addEdge(2, 4);
    G1.addEdge(2, 5);
    G1.addEdge(3, 4);
    G1.addEdge(3, 6);
    G1.addEdge(4, 7);
    G1.addEdge(5, 7);
    G1.addEdge(6, 7);
     
    G1.addWeight(1,2,2);
    G1.addWeight(1,3,1);
    G1.addWeight(1,4,4);
    G1.addWeight(2,4,1);
    G1.addWeight(2,5,3);
    G1.addWeight(3,4,2);
    G1.addWeight(3,6,4);
    G1.addWeight(4,7,1);
    G1.addWeight(5,7,4);
    G1.addWeight(6,7,7);
    
    cout << "Алгоритм Дейкстры" << endl;
	G1.dejkstra(4);

	Graph G3;
	G3.addVertex();
    G3.addVertex();
    G3.addVertex();
    G3.addVertex();
    G3.addVertex();
    G3.addVertex();
    G3.addVertex(); 
    G3.addVertex();

	G3.addEdge(1, 2);
    G3.addEdge(1, 3);
    G3.addEdge(1, 4);
    G3.addEdge(2, 4);
    G3.addEdge(2, 5);
    G3.addEdge(3, 4);
    G3.addEdge(3, 6);
    G3.addEdge(3, 7);
    G3.addEdge(4, 5);
    G3.addEdge(4, 7);
    
    G3.addWeight(1,2,1);
    G3.addWeight(1,3,2);
    G3.addWeight(1,4,4);
    G3.addWeight(2,4,2);
    G3.addWeight(2,5,5);
    G3.addWeight(3,4,7);
    G3.addWeight(3,6,4);
    G3.addWeight(3,7,1);
    G3.addWeight(4,5,1);
    G3.addWeight(4,7,1);
	
	cout << "Алгоритм Флойда — Уоршелла" << endl;
	G3.FU();
	
	cout << "Алгоритм Прима" << endl;
	G1.Prim();
	
	Graph G;
	vector<vector<int>> matrix
	{
		{0,1,5,0,0},
		{1,0,4,1,0},
		{5,4,0,0,3},
		{0,1,0,0,2},
		{0,0,3,2,0}
	};
	cout << "Алгоритм Крускала" << endl;
	G.Kruskal(matrix);
	return 0;
}
