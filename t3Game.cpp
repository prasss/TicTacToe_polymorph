/*
 * t3Game.cpp
 *
 *  Created on: 14-Dec-2020
 *      Author: prasanna
 */

#include "t3Game.h"

t3Game::t3Game() {
	// TODO Auto-generated constructor stub

}

t3Game::~t3Game() {
	// TODO Auto-generated destructor stub
}

void t3Game::gamePlay(t3Board board, t3Player *x_player, t3Player *o_player, console *display) {

	char letter = 'X';
	    int index;
	    board.reset();
	    while (board.isMovePossible())
	    {
	        if (letter == 'O')
	            index = o_player->getMove(&board);
	        else
	            index = x_player->getMove(&board);

	        board.doMove(letter, index);
	        cout << endl
	             << letter << " makes move to " << index + 1 << endl;
	        display->printBoard(&board);
	        cout << endl;

	        if (board.checkWinner(letter))
	        {
	            cout << endl
	                 << letter << " wins !";
	            return;
	        }

	        letter = (letter == 'X') ? 'O' : 'X';
	    }
	    cout << endl
	         << "Draw";
}
