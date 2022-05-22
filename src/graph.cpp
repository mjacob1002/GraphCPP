#include "graph.h"

Graph::Graph() {}

Graph::Graph(bool is_directed) : _directed(is_directed) {}

// helper function that will be called; inserts the edges for a directed graph; method will simply be called twice for undirected
void Graph::_addEdge(Vertex p, Vertex q, double weight) {
	if(_adj.count(p) ==  0){
		std::cout << "VERTEX " << p << " doesn't exist.\n";
		return; // the vertex p does not exist
	}
	auto& p_adj_list = _adj[p];
	Edge e(p, q, weight);
	if(p_adj_list.count(q) == 0){ // p is not connected to q
	
		// std::cout << "ADDING " << q << "to the adjacency list of " << p << std::endl;
		p_adj_list[q] = e; // insert the pair of the to vertex and its corresponding edge
		_edgeset.insert(e); // insert the edge into the edgeset
	} else {
		std::cout << p << " is already connected to " << q << std::endl;
	}
}

void Graph::addEdge(Vertex p, Vertex q, double weight){
	_addEdge(p, q, weight);
	if(!_directed) _addEdge(q, p, weight);
}

void Graph::addEdge(Vertex p, Vertex q) {
	addEdge(p, q, 1.0);
	if(!_directed) addEdge(q,p,1.0);
}

void Graph::addVertex(Vertex v) {
	if(_adj.count(v) != 0) return; // the vertex already exists
	_adj[v] = std::unordered_map<Vertex, Edge>(); // map the new vertex to an empty adjacency list
}

std::vector<Vertex> Graph::getVertices(){
	std::vector<Vertex> res;
	for(auto p : _adj) {
		res.push_back(p.first);
	}
	return res;
}

void Graph::dfs() {
	auto vertices = getVertices();
	unordered_set<Vertex> visited;
	for(Vertex v : vertices) {
		if(visited.count(v) == 1) continue;
		dfs(v, visited);
	}
	std::cout << visited.size() << std::endl;
}

void Graph::dfs(Vertex curr, unordered_set<Vertex>& visited){
	std::cout << "PROCESSING " << curr << " "; // print out the node
	visited.insert(curr); // mark the node as visited
	auto neighbors = _adj[curr];
	// std::cout << "AMOUNT OF NEIGHBORS: " << neighbors.size() << std::endl;
	for(auto p : neighbors) {
		Vertex neighbor = p.first;
		if(visited.count(neighbor) == 1) continue;
		dfs(neighbor, visited);
	}
	// std::cout << "PROCESSED NEIGHBORS OF " << curr << std::endl;
}

Edge Graph::_removeEdge(Vertex p, Vertex q){
	auto& neighbors_p = _adj[p];
	if(neighbors_p.count(q) == 0) return Edge();
	Edge data = neighbors_p[q];
	neighbors_p.erase(q); // remove it from the adjacency list
	Edge target_to_remove;
	for(Edge e : _edgeset) { // look for the edge with the corresponding source and destination
		if(e.source == p && e.destination == q)
		{
			target_to_remove = e;
			break;
		}
	}
	_edgeset.erase(target_to_remove); // remove the edge from the edgeset
	return data;
}

Edge Graph::removeEdge(Vertex p, Vertex q){
	auto data = _removeEdge(p, q);
	if(!_directed) _removeEdge(q, p);
	return data;
}


void Graph::removeVertex(Vertex v) {
	std::vector<Edge> to_remove;
	for(Edge e : _edgeset) {
		if(e.source == v || e.destination == v){
			to_remove.push_back(e);
		}
	}
	for(Edge e : to_remove){
		removeEdge(e.source, e.destination);
	}

	_adj.erase(v); // remove from the overall adjacency list
}
