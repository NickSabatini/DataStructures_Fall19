/*
 * graphMain.cpp
 *
 *  Created on: Dec 5, 2019
 *      Author: sabat
 */


#include "Graph.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	srand (time(NULL));
	string names[27] = {"Albany","Buffalo","Chicago","Detroit","Encino","Fargo","Gotham","Houston",
			"Indianapolis","Jackson","Kenosha","Lewiston","Magnolia","Nantucket","Oakland","Palmyra","Queensbury","Raleigh",
			"Salamanca", "Tallahassee", "Upland", "Vallejo", "Waipio", "Xenia", "Yukon", "Zion"};
	int size =4;
	Graph g1(size, 0, size-1, names);
	cout<<endl<<"**********************************************************************"<<endl;
	size = 7;
	Graph g2(size, 0, size-1, names);
	cout<<endl<<"**********************************************************************"<<endl;
	size = 12;
	Graph g3(size, 0, size-1, names);
	size = 16;
	Graph g4(size, 0, size-1, names);
	size = 20;
	Graph g5(size, 0, size-1, names);
	size = 26;
	Graph g6(size, 0, size-1, names);

}
