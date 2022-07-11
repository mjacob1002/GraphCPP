#include "MST/DisjointSet.h"

DisjointSet::DisjointSet(int num_elements){
	_rank = std::vector<int>(num_elements, 1); // all trees have a starting rank of 1
	for(int i = 0; i < num_elements; ++i){
		_parent.push_back(i);
	}
}

void DisjointSet::setUnion(int p, int q){
	int p_parent = find(p);
	int q_parent = find(q);
	if(p_parent == q_parent) return;

	if(_rank[p_parent] > _rank[q_parent]){
		_parent[q_parent] = p_parent;
		_rank[p_parent] += _rank[q_parent];
	} else {
		_parent[p_parent] = q_parent;
		_rank[q_parent] += _rank[p_parent];
	}
}

int DisjointSet::find(int p){
	if(_parent[p] == p) return p;
	int rep= find(_parent[p]); // get the representative member of the parent
	_parent[p] = rep; // path compression
	return rep;
}

bool DisjointSet::isConnected(int p, int q) {
	return find(p) == find(q);
}
