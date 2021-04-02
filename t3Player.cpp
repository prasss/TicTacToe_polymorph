/*
 * t3Player.cpp
 *
 *  Created on: 13-Dec-2020
 *      Author: prasanna
 */

#include "t3Player.h"
#include <iostream>
using namespace std;


t3Player::~t3Player()
{
	//blank
}


char t3Player::getSymbol() {

	return symbol;
}

int HumanPlayer::getMove(t3Board *board) {
	int r, c;
	string move;

	while(1)
	{
		cout << "\nEnter your Move eg. A1: ";
		cin >> move;
		board->rcParser(r,c,move);

		char temp = board->getField(r,c);

		if (temp == '-'){
			return r*BOARD_DIMENSION + c;
		}

		cout << "Wrong Move, please try again!";
	}
}

int CompPlayer::getMove(t3Board *board){

	t3_move move;
	srand(time(0));

	if (board->allPossibleMoves().size() == 9)
		move.index = rand() % 9;
	else
		move = minimax(board, getSymbol());

	return move.index;
}

HumanPlayer::~HumanPlayer()
{
	//blank
}

CompPlayer::~CompPlayer()
{
	//blank
}



t3_move CompPlayer::minimax(t3Board *board, char curr_player)
{
	char max_player = this->getSymbol();
	char other_player = (curr_player == 'X') ? 'O' : 'X';
	t3_move best, current;

	// base condition for win - lose
	if (board->whoWon() == other_player)
	{
		best.score = board->allPossibleMoves().size() + 1;
		if (other_player != max_player)
			best.score = -best.score;
		return best;
	}
	// base condtion for draw
	if (!board->isMovePossible())
	{
		best.score = 0;
		return best;
	}

	if (curr_player == max_player)
		best.score = -1000000;
	else
		best.score = 1000000;

	vector<int> move_set = board->allPossibleMoves();

	for (int i = 0; i < (int)move_set.size(); i++)
	{
		board->doMove(curr_player, move_set[i]);
		current = minimax(board, other_player);
		board->setChar('-', move_set[i]);
		board->resetWinner();
		current.index = move_set[i];
		if (curr_player == max_player)
		{
			if (current.score > best.score)
				best = current;
		}
		else
		{
			if (current.score < best.score)
				best = current;
		}
	}
	return best;
}
