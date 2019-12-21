/*
 * bookList.hpp
 *
 *  Created on: Dec 21, 2019
 *      Author: sabat
 */


#include<time.h>
#include<iostream>
#include<string>
using namespace std;

class book {
public:
	string first;
	string last;
	int* ratings = new int[10];
	string name;
	int pdate;

	book(string f, string l, string n, int p);
	book(string f, string l, int r[], string n, int p);
	~book();
	double avg();
	void printRating();
	void showBook();
	bool operator>(book b);
};

void findBest(book bookshelf[]);

