/*
 * t3Display.h
 *
 *  Created on: 13-Dec-2020
 *      Author: prasanna
 */

#ifndef T3DISPLAY_H_
#define T3DISPLAY_H_

#include "t3Board.h"

class t3Display {
public:

	virtual ~t3Display();

	/**
	 * This is the constructor for the t3Display class
	 */
	t3Display();

	/**
	 * This is the virtual function to be used to print the whole TicTacToe board
	 * \param t3Board		: IN
	 */
	virtual void printBoard(t3Board *board);
};

/*
 *  Provisions for a Screen
 */
class Screen: public t3Display{
public:
	void printBoard(t3Board *board);
};

/*
 *  Provisions for the console
 */
class console: public t3Display{

public:
	void printBoard(t3Board *board);

};



#endif /* T3DISPLAY_H_ */
