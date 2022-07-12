#pragma once

#include <vector>

#include "graph.h"

struct isAcyclic{
	private:
		bool dfs(Vertex current, const Graph& g);
		bool dfs(Vertex current, Vertex parent, const Graph& g);
		std::unordered_map<Vertex, int> _coloring_of_nodes;
	public:
		isAcyclic();
		bool operator()(const Graph& g);
};
