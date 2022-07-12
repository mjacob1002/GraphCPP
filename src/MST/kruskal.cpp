#include "MST/kruskal.h"

Graph kruskal(const Graph& g){
	assert(!g.isDirected());
	std::vector<Edge> edges = g.getEdges();	
	std::vector<Vertex> vertices = g.getVertices();
	Graph ret(false);
	for(Vertex v : vertices){
		ret.addVertex(v);
	}
	std::unordered_map<Vertex, int> indirection;
	int indirection_counter = 0;
	for(Vertex v : vertices)
		indirection[v] = indirection_counter++;

	auto comparison = [](Edge first, Edge second) {
		return first.weight > second.weight;
	};

	std::priority_queue<Edge, std::vector<Edge>, decltype(comparison) > pq(comparison);
	DisjointSet djs(g.numVertices());
	while(!pq.empty()){
		Edge top = pq.top();
		pq.pop();
		if(djs.isConnected(indirection[top.source], indirection[top.destination])) continue;
		ret.addEdge(top.source, top.destination);
		djs.setUnion(indirection[top.source], indirection[top.destination]);
	}
	return ret;
}
