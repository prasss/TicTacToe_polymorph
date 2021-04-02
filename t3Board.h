/*
 * t3Board.h
 *
 *  Created on: 13-Dec-2020
 *      Author: prasanna
 */

#ifndef T3BOARD_H_
#define T3BOARD_H_
#include<iostream>
#include <string>
#include <vector>
using namespace std;

#define BOARD_DIMENSION 3
class t3Board {
private:
	unsigned int num_rows;
	unsigned int num_cols;
	char winner;
	char board[BOARD_DIMENSION][BOARD_DIMENSION];

public:

	virtual ~t3Board();
	/**
	 * This is the constructor for the t3Board class
     * \param unsigned int rows		: IN
     * \param unsigned int cols		: IN
	 */
	t3Board(unsigned int rows, unsigned int cols);

	/**
	 * This is the function to be used to fetch the Symbol of a particular board position
     * \param unsigned int r	 	: IN input row data
     * \param unsigned int c	 	: IN input column data
     * @return char
	 */
	char getField(unsigned int r, unsigned int c);

	/**
	 * This is the function to be used to set the state of a particular board position and returns a warning type if any
     * \param unsigned int r			: IN
	 * \param unsigned int c			: IN
	 * \param char symbol				: IN
	 */
	void setField(unsigned int r, unsigned int c, char symbol);

	/**
	 * This function is used to get the row and column entries from the user and check if valid
	 * \param int &row					: OUT
     * \param &column					: OUT
     * \param string CinData			:IN
     * \return bool
	 */
	bool rcParser(int &row, int &column, string CinData);


	/**
	 * This function is used to get the row and column entries from the user and check if valid
	 * \param int &row					: OUT
	 * */
	bool checkWinner(char symbol);


	/*
	 * Setter and getter functions
	 */
	/*
	 * setChar()
	 * \param char symbol
	 * \param int i
	 */
    void setChar(char symbol, int i);

	 /* setChar()
	 * \param char symbol
	 * \param int i
	 */
    void setChar(char symbol, int i, int j);

    /* getChar()
   	 * \param char symbol
   	 * \param int i
   	 */
    char getChar(int i);

    /* getChar()
   	 * \param char symbol
   	 * \param int i
   	 */
    char getChar(int i, int j);

    char whoWon();

    void resetWinner();

    void reset();

    void resetBoard();

    bool isMovePossible();

    /*
	 * Function to find all possible moves
	 * return Vector<int>
	 */
    vector<int> allPossibleMoves();

    /*
         * Function doMove()
         */
    void doMove(char symbol, int index);
};



#endif /* T3BOARD_H_ */
