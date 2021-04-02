/*
 * t3Display.cpp
 *
 *  Created on: 13-Dec-2020
 *      Author: prasanna
 */
#include <iostream>
using namespace std;
#include "t3Display.h"


t3Display::t3Display() {
	// TODO Auto-generated constructor stub

}

t3Display::~t3Display() {
	// TODO Auto-generated destructor stub
}

void t3Display::printBoard(t3Board *board){
	//blank, for virtual fuunction
}

void console::printBoard(t3Board *board) {

	cout << "\nTo make a move, enter the Row Alphabet A->C and Column numbers 1->3\n"<< endl;

	char alpha = 'A';
	for(int i = 0; i < BOARD_DIMENSION; i++){
		for(int j = 0; j < BOARD_DIMENSION; j++){
			if(i==0 && j==0){
				cout <<" |_1_||_2_||_3_|"<<endl;
				}

			if(j==0){
				cout << char(i+int(alpha));
			}
			cout <<"| " << board->getField(i,j) << " |" ;
		}
		cout << endl;
	}

}
