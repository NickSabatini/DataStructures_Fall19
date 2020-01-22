/*
 * HanningWindow.cpp
 *
 *  Created on: Sep 18, 2019
 *      Author: jpalmeri
 */

#include<cstdlib>
#include<ctime>
#include<iostream>
#include<stdlib.h>
using namespace std;

class Hanning{
	int windowSize;
	int arraySize;
	int* originalArray;
	int* filteredArray;
public:
	Hanning(int w, int a, int* arr, int* arr2);
	void windowAvg(int a);
	void filter();
	void printArray(bool p);
	void setWindowSize(int size);
};//Hanning header

	Hanning::Hanning(int w, int a, int arr[], int arr2[]){
		windowSize = w;
		arraySize= a;
		originalArray= arr;
		filteredArray= arr2;
	}

	void Hanning::windowAvg(int a){
		int avg=0;
		int weight=0;
		int weightSum=0;

		int midpoint = (windowSize-1)/2;

		bool passedMiddle = 0;
		for (int i=a; i< a+windowSize; i++) {

			if (weight<=windowSize/2 && passedMiddle==0) {
				weight++;
				weightSum += weight;
			}
			else if (weight>windowSize/2) {
				passedMiddle = 1;
				weight--;
				weightSum += weight;
			}
			else if (weight<=windowSize/2 && passedMiddle==1) {
				passedMiddle = 1;
				weight--;
				weightSum += weight;
			}
			avg+= originalArray[i] * weight;
		}
		avg = avg/(weightSum);
		//avg = avg/(windowSize);
		filteredArray[a + midpoint] = avg;
	}

	void Hanning::filter() {
		//loops through the original and calls windowAvg() for each index
		for (int a=0; a<arraySize; a++) {
			windowAvg(a);
		}
		//makes the ends 0
		for (int i=0; i<arraySize; i++) {
			if (i < (windowSize-1)/2) {
				filteredArray[i]=0;
			}
			if (i+(windowSize-1)/2 >= arraySize) {
				filteredArray[i] = 0;
			}
		}
	}

	void Hanning::printArray(bool p){
		if (p) {
			cout << "Filtered Array: " << endl;
			for (int i=0; i<arraySize; i++) {
				cout << filteredArray[i] << " ";
			}
			cout << endl;
		}
		else{
			cout << "Original Array: " << endl;
			for (int i=0; i<arraySize; i++) {
				cout  << originalArray[i] << " ";
			}
			cout << endl;
		}
	}

	void Hanning::setWindowSize(int size){
		if (size%2==0) {
			size--;
		}
		windowSize=size;
	}


	/*int main() {

		srand(time(NULL));
		int* a;
		int* b;

		a = new int[10];
		b = new int[10];

		for (int i=0; i<10; i++) {
			int r = rand()%20;
			a[i]=r;
			b[i]=r;
		}

		Hanning h(3, 10, a , b);
		h.filter();
		h.printArray(1);
		h.printArray(0);

	}*/

