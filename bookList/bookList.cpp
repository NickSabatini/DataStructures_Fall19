/*
 * bookList.cpp
 *
 *  Created on: Dec 21, 2019
 *      Author: sabat
 */


#include"bookList.hpp"

	book::book(string f, string l, string n, int p) {
		first = f;
		last = l;
		ratings = new int[10];
		for (int i=0; i<10; i++) {
			*&ratings[i]=0;
		}
		name = n;
		pdate = p;
	}

	book::book(string f, string l, int r[], string n, int p) {
			first = f;
			last = l;
			ratings = r;
			name = n;
			pdate = p;
	}

	book::~book(){
		cout<<"...destructing a book..." << endl;
	}

	double book::avg(){
		double sum=0;
		for (int i=0; i<10; i++) {
			sum+=ratings[i];
		}
		return sum/10;
	}

	void book::printRating(){
		if(avg()==0){
			cout << "No ratings yet." << endl;
		}
		else {
			cout << "The rating is " << avg() << endl;
		}
	}

	void book::showBook(){
		cout << name << ": " << avg() << endl << first << " " << last << endl << pdate << endl;
	}

	bool book::operator>(book b){
		if (avg() > b.avg()) {
			return true;
		}
		else {
			return false;
		}
	}

	void findBest(book bookshelf[]){
		int i=0;
		int j=0;
		for (j=i+1; j<5; j++) {
			if (bookshelf[j] > bookshelf[i]) {
				i=j;
			}
		}
		bookshelf[i].showBook();
	}
