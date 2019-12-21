/*
 * BinHeap.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: sabat
 */

#include "BinHeap.hpp"

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


BinHeap::BinHeap(string arr[], int len) {
	heaplen = 0;
	arrlen = len;
	heap = new string[arrlen];
	for (int i = 0; i < len; i++) {
		insertHeap(arr[i]);
	}
	printHeap();
}

BinHeap::~BinHeap() {
	delete [] heap;
}

void BinHeap::printHeap() {
	cout << endl;
	for (int i = 0; i < arrlen;i++) {
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < heaplen;i++) {
		cout << heap[i] << " ";
	}
	cout << endl;
}

int BinHeap::findMax(int x, int y) {
	if ((x < heaplen) && (y < heaplen)) {
		if (heap[x] > heap[y]) {
			return(x);
		}
		else {
			return(y);
		}
	}
	else if (x < heaplen) {  // assumes that x is less than y
		return x;
	}
	else
		return -1;
}

void BinHeap::insertHeap(string s) {
	heap[heaplen] = s;
	bubbleUp(heaplen);
	heaplen ++;
}

string BinHeap::deleteHeap() { // returns the string that was deleted

	string tmp = heap[0];		//this is saving what was deleted to return at the end
	heap[0] = heap[heaplen-1];	//this is assigning the last string to be the first
	delete &heap[heaplen-1];

	heaplen--;

	bubbleDown(0); //this begins the bubble down process to get the heap back in order

	return tmp;
}

void BinHeap::bubbleUp(int i) {

	if ((i != 0) && (heap[i] > heap[(i-1)/2])){ // important that checking for root comes first because if not,
												//the statement will try to check at a negative index
		string tmp;
		tmp = heap[i];
		heap[i] = heap[(i-1)/2];
		heap[(i-1)/2] = tmp;
		bubbleUp((i-1)/2);
	}
}

void BinHeap::bubbleDown(int i) {
	printHeap();
	int idx = findMax(2*i + 1, 2*i + 2);
	if (idx >= 0  && heap[idx] > heap[i]){
		string tmp;
		tmp = heap[i];
		heap[i] = heap[idx];
		heap[idx] = tmp;
		bubbleDown(idx);
	}
}

string BinHeap::deleteHeap2() {
	string tmp = heap[0];		//this is saving what was deleted to return at the end
	heap[0] = heap[heaplen-1];	//this is assigning the last string to be the first
	heap[heaplen-1] = tmp;  	//places the deleted value at the end of the heap but since heaplen is decremented it is left behind
	heaplen--;

	bubbleDown(0);				//this begins the bubble down process to get the heap back in order

	return tmp;
}

void BinHeap::deleteAll() {
	int tmpHeaplen = heaplen;
	for (int i=heaplen; i > 0; i--) {
		deleteHeap2();
	}
	heaplen = tmpHeaplen;
}

