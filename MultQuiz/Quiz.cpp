/*
 * Quiz.cpp
 *
 *  Created on: Sep 17, 2019
 *      Author: jpalmeri
 */

#include <iostream>
using namespace std;

class Quiz {
	int testNum;
	int numRight;
	int total;

public:

	Quiz(int x){ //constructor
		testNum = x;
		numRight = 0;
		total = 0;
	}

	int getTestNum(){
		return testNum;
	}

	int getNumRight(){
		return numRight;
	}

	int getTotal(){
		return total;
	}

	void mathMultQuiz(){
		string question;
		int test; //Random test value
		int answer;

		test = rand() % 13;

		question = "What is " + to_string(getTestNum()) + " x " + to_string(test) + "?";
		cout << question << endl;

		cin >> answer;

		if (answer == (getTestNum() * test)){
			cout << "Correct!" << endl;
			numRight++;
			total++;
		}

		else{
			cout << "Wrong!" << endl;
			total++;
		}

	}

	void printNumRight(){
		cout << "You answered " + to_string(getNumRight()) + " out of " + to_string(getTotal()) + " correct!" << endl;
	}

};// Quiz

/*int main(){
	int i = 0;
	Quiz q(5);
	srand(time(NULL));

	while (i < 10){
		q.mathMultQuiz();
		i++;
	}

	q.printNumRight();

	return 0;
} //main*/




