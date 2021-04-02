/*
 * t3Player.h
 *
 *  Created on: 13-Dec-2020
 *      Author: prasanna
 */

#ifndef T3PLAYER_H_
#define T3PLAYER_H_

#include "t3Board.h"

struct t3_move
{
    int index;
    long score;
};

class t3Player{
private:
	    char symbol;

public:

	/*
	 * Destructor to the player
	 */
	virtual ~t3Player();
	/*
	 * Constructor to intialise the player
	 * \param char s	:IN
	 */
	t3Player(char s) { symbol = s; }

	/*
	 * This function gets the Symbol of the player
	 * \return char, returns the player Symbol as 'X' or 'O' as set through the constructor
	 */
	char getSymbol();

	/*
	 * This is a virtual function that gets the move for the player
	 */
	virtual int getMove(t3Board *board) = 0;
	};


class HumanPlayer : public t3Player
{
public:
    //constructor
	HumanPlayer(char s) : t3Player(s) {};

	/*
	 * Function override fro getMove
	 */
    int getMove(t3Board *board);

    ~HumanPlayer();

};

class CompPlayer : public t3Player
{
public:
    /*
     * constructor
     */
	CompPlayer(char s) : t3Player(s) {};

    /*
     * Function override fro getMove
     */
    int getMove(t3Board *board);


    	/*
         * Function minimax
         */
    t3_move minimax(t3Board *board, char curr_player);

    ~CompPlayer();
};

#endif /* T3PLAYER_H_ */
