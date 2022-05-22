#include "graph.h"
#include <iostream>



int main(){
	std::cout << "ELLO WORLD\n";
	Graph g(true);
	g.addVertex("A");
	g.addVertex("B");
	g.addVertex("C");
	g.addVertex("D");
	g.addVertex("E");
	g.addVertex("F");
	g.addEdge("A", "B");
	g.addEdge("B", "C");
	g.addEdge("D", "F");
	g.addEdge("F", "A");
	g.addEdge("F", "C");
	g.removeVertex("F");
	for(Vertex v : g.getVertices())
		std::cout << v << " ";
	std::cout << std::endl;
	g.dfs();
	std::cout << "PROGRAM FINISHED\n";
}
