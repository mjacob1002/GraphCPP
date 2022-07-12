#include "utility.h"

isAcyclic::isAcyclic(){}

bool isAcyclic::dfs(Vertex current, const Graph& g){
	if(visited.count(current)) return false;
	visited.insert(current);
	auto adjacency = g._adj.at(current); 
	for(auto p : adjacency){
		if(!dfs(p.first, g)) return false;
	}
	return true;
}

bool isAcyclic::dfs(Vertex current, Vertex parent, const Graph& g){
	if(visited.count(current)) return false;
	visited.insert(current);
	auto adjacency = g._adj.at(current);
	for(auto p : adjacency){
		if(p.first == parent) continue; // skip the predecessor node in the case of an undirected graph
		if(!dfs(p.first, current, g)) return false;
	}
	return true;
}

bool isAcyclic::operator()(const Graph& g){
	auto adjacency = g._adj;
	for(auto p : adjacency){
		if(visited.count(p.first)) continue;
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

