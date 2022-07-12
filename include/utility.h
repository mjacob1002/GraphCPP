#pragma once

#include <vector>

#include "graph.h"

struct isAcyclic{
	private:
		bool dfs(Vertex current, const Graph& g);
		bool dfs(Vertex current, Vertex parent, const Graph& g);
		std::unordered_set<Vertex> visited;
	public:
		isAcyclic();
		bool operator()(const Graph& g);
};
