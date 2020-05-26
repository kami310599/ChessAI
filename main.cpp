/*
Name : Ahmad Jamal Shaikh
Title : Chess AI
Description : A chess playing AI made with MinMax Algorithm and Alpha Beta Pruning
*/

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <time.h>
#include <climits>
#include "board.hpp"
#include "piece.hpp"
#include "algorithms.hpp"

int main() {

	
	cout<< "To play the game, basically when you move is asked enter your move as source letter source number destination letter destination number."<<endl;
	cout<< "For example, 'a 2 a 3' will move your piece at a 2 to a 3."<<endl;
	cout<< "Let the game begin... "<<endl<<endl;

	Board *b = new Board();
	Board *test;
	b->initialize();
	cout << "Board:" << endl;
	b->print();
	//	int i = 1;

	char src_x = 0, src_y = 0, dest_x = 0, dest_y = 0;


	while (true) {
		cout << "Enter your move: ";
		cin >> src_y >> src_x >> dest_y >> dest_x;
		cout << endl;
		//integerize
		src_x -= '1';
		dest_x -= '1';

		src_y -= 'a';
		dest_y -= 'a';

		test = b->move(src_x, src_y, dest_x, dest_y);
		if (test == NULL) {
			cout << "Invalid move. Try again." << endl << endl;
		} else {
			b = test;
			b->print();
		}
		//cout << "White: " << b->evaluate_board(White) << endl;
		//cout << "Black: " << b->evaluate_board(Black) << endl;

		//enemy turn

		time_t start = time(NULL);
		b = ABMinMax(b,5);
		cout<< "passed time = "<< time(NULL) - start <<"s"<<endl;

//		start = time(NULL);
//		b = MinMax(b,5);
//		cout<< "passed time = "<< time(NULL) - start <<endl;

		if(b!=NULL){
			b->print();
		}
		else{
			cout<< "null dondu exiting"<<endl;
			break;
		}
	}

	return 0;
}
