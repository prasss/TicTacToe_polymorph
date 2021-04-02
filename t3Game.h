/*
 * t3Game.h
 *
 *  Created on: 14-Dec-2020
 *      Author: prasanna
 */

#ifndef T3GAME_H_
#define T3GAME_H_

#include "t3Board.h"
#include "t3Player.h"
#include "t3Display.h"

class t3Game {
public:
	t3Game();
	virtual ~t3Game();
	/*
	 * Function to run the game play
	 * \param t3Board board 		:IN
	 * \param t3Player *x_player	:IN
	 * \param t3Player *o_player	:IN
	 * \param console *display		:IN
	 */
	void gamePlay(t3Board board, t3Player *x_player, t3Player *o_player, console *display);
};

#endif /* T3GAME_H_ */
