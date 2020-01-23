/*
 * graph.hpp
 *
 *  Created on: Dec 5, 2019
 *      Author: sabat
 */



#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include <iostream>
#include <stdlib.h>
//#include "BinHeap.hpp"
using namespace std;

class Graph {
	int **adjMatrix;
	int numOfVerts;
	int start;
	int finish;
	string *dataArr;
	//BinHeap priorityQueue();
	bool *visited;
	int *distances;
	int *prev;
	public:
	Graph(int n, int first, int last, string vertexnames[]);
	void dijkstra();
	void setDistances(int lv);
	int minDistance();
	void printAdjMat();
	void printInfoSoFar();
	void printPath(int end);
	void genGraph();
};
#endif /* GRAPH_HPP_ */

