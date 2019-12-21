/*
 * bookMain.cpp
 *
 *  Created on: Dec 21, 2019
 *      Author: sabat
 */


#include"bookList.hpp"
using namespace std;

int main(){

	srand(time(0));

	int* arr2 = new int[10];
	int* arr3 = new int[10];
	int* arr4 = new int[10];
	int* arr5 = new int[10];
	for (int i=0; i<10; i++) {
		arr2[i] = rand() % 3;
		arr3[i] = rand() % 5;
		arr4[i] = rand() % 6 + 5;
		arr5[i] = rand() % 3 + 8;

	}

	book myBook("Nick", "Sabatini", "Moby Nick", 1999);
	book myBook2("Sophia", "Eick", arr2 , "Mike and Eick", 2000);
	book myBook3("Trey", "Vonn", arr3 , "Vonnaroo", 1890);
	book myBook4("Finn", "McCool", arr4 , "Total Freeze", 2046);
	book myBook5("Phinneas", "Ferb", arr5 , "Worst Show Ever", 100);

	book bookshelf[] = {myBook,myBook2,myBook3,myBook4,myBook5};


	for (int i=0; i<5; i++) {
		for (int j=0; j<10; j++) {
			cout << bookshelf[i].ratings[j] << " " ;
		}
		cout << endl;
	}
	cout << endl;

	for (int i=0; i<5; i++){
		bookshelf[i].showBook();
		cout << endl;
	}
	cout << endl;

	findBest(bookshelf);
	cout<< endl;

	book* heapBook = new book("Johnny", "Smith", arr2, "King of The Hill", 2019);
	book* heapBook2 = new book("Suzie", "Smith", arr4, "Suzie's Recipes", 2020);
	book* heapShelf[] = {heapBook, heapBook2};

	heapBook->showBook();
	cout<<endl;
	heapShelf[0]->showBook();
	cout<<endl;
	heapShelf[1]->showBook();
	cout<< endl;




return 0;
}

