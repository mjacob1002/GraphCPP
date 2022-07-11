#pragma once

#include <vector>


class DisjointSet {
	std::vector<int> _rank;
	std::vector<int> _parent;
	
	public:
		DisjointSet(int num_elements); // the number of elements in total
		void setUnion(int p, int q); // join p and q
		int find(int p); // find the representative number of the set p is in
		bool isConnected(int p, int q); // determines if two numbers are in the same set	


};
