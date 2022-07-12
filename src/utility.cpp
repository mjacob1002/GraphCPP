#include "utility.h"

isAcyclic::isAcyclic(){}

bool isAcyclic::dfs(Vertex current, const Graph& g){
	if(_coloring_of_nodes[current] == 1) return false; // "grey" color of the node
	_coloring_of_nodes[current] = 1;
	auto adjacency = g._adj.at(current); 
	for(auto p : adjacency){
		if(_coloring_of_nodes[p.first] != 2 && !dfs(p.first, g)) return false; // if the node isn't completed and the exploration from that node leads to a cycle
	}
	_coloring_of_nodes[current] = 2;
	return true;
}

bool isAcyclic::dfs(Vertex current, Vertex parent, const Graph& g){
	if(_coloring_of_nodes[current] == 1) return false; // "grey" color of the node
	_coloring_of_nodes[current] = 1;
	auto adjacency = g._adj.at(current);
	for(auto p : adjacency){
		if(p.first == parent) continue; // skip the predecessor node in the case of an undirected graph
		if(_coloring_of_nodes[p.first] != 2 && !dfs(p.first, current, g)) return false;
	}
	_coloring_of_nodes[current] = 2; // completely visited
	return true;
}

bool isAcyclic::operator()(const Graph& g){
	auto adjacency = g._adj;
	for(auto p : adjacency)
		_coloring_of_nodes[p.first] = 0;
	for(auto p : adjacency){
		if(_coloring_of_nodes[p.first] != 0) continue; // if it isn't 0, then it has already been explored 
		bool containsCycle;
		if(g.isDirected()){
			containsCycle = dfs(p.first, g);
		} else {
			containsCycle = dfs(p.first, "", g);
		}
		if(!containsCycle) return false;
	}
	return true;
}

