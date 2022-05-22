#pragma once

#include <string>
#include <limits.h>

using Vertex = std::string;

struct Edge{
	Vertex source;
	Vertex destination;
	double weight = 1;
	
	Edge() {
		source = ""; 
		destination = "";
		weight = INT_MAX;
	}

	Edge(Vertex src, Vertex dst, double w) : source(src), destination(dst), weight(w) {}
	bool operator==(const Edge& e) const{
		return source == e.source && (destination == e.destination) && (weight && e.weight);
	}
};



namespace std
{
    template<> struct hash<Edge>
    {
        using argument_type = Edge;
        using result_type = std::size_t;
        result_type operator()(argument_type const& a) const
        {
            result_type const h1 ( std::hash<std::string>()(a.source) );
            result_type const h2 ( std::hash<std::string>()(a.destination) );
			result_type const h3 (std::hash<double>()(a.weight) );
            return h1 ^ (h2 << 1) ^ (h3 << 2);
        }
    };
}

