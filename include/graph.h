#pragma once

#include <unordered_map>
#include <unordered_set>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>


#include "edge.h"
using Vertex=std::string;
using std::unordered_set;
class Graph {
	private:
		std::unordered_map<Vertex, std::unordered_map<Vertex, Edge>> _adj; // an adjacency list
		std::unordered_set<Edge> _edgeset; // list of edges
		bool _directed = true; // assumes a directed graph
		void dfs(Vertex curr, unordered_set<Vertex>&);
		Edge _removeEdge(Vertex p, Vertex q); // helper; remove an edge from the graph
		void _addEdge(Vertex p, Vertex q, double weight);
		
	public:
		
		Graph();
		Graph(bool is_directed); 
		void addEdge(Vertex p, Vertex q); // add an edge between two vertices
		void addEdge(Vertex p, Vertex q, double weight); 
		void addVertex(Vertex v); // add a vertex to the graph
		std::vector<Vertex> getVertices();
		void dfs();
		Edge removeEdge(Vertex p, Vertex q); // deals with the directed or undirected nature of graphs
		void removeVertex(Vertex v); // remove the vertex and all the corresponding edges from the graph
};
