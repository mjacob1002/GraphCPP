#pragma once
#include<queue>

#include "graph.h"

/**
 * Requires that the graph be undirected and the graph is connected
 * @param Graph that needs the minimum spanning tree computed for them
 *@return a graph that is the minimum spanning tree
 */
class MinEdge{
	MinEdge(){}

	bool operator()(Edge e1, Edge e2){
		return e1.weight > e2.weight; 
	}
};
Graph kruskalMST(const Graph& );
