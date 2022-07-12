#define CATCH_CONFIG_MAIN


#include "MST/DisjointSet.h"
#include "catch.hpp"


TEST_CASE("Simple Disjoint Set"){
	DisjointSet ds(10);
	REQUIRE(!ds.isConnected(0, 9));
	REQUIRE(!ds.isConnected(0,8));
	SECTION("Simple unions and make sure they are connected"){
		ds.setUnion(0, 2);
		REQUIRE(ds.isConnected(0,2));
		ds.setUnion(2, 5);
		REQUIRE(ds.isConnected(2, 5));
		REQUIRE(ds.isConnected(0, 5));
	}
}

#include "utility.h"
TEST_CASE("Simple Acyclic Utility"){
	Graph g(false);
	g.addVertex("A");
	g.addVertex("B");
	g.addVertex("C");
	SECTION("Contains a cycle"){
		g.addEdge("A", "B");
		g.addEdge("A", "C");
		REQUIRE(isAcyclic{}(g) == true);
		g.addEdge("B", "C");
		REQUIRE(isAcyclic{}(g) == false);
	}
}

