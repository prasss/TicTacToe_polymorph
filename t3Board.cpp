/*
 * t3Board.cpp
 *
 *  Created on: 13-Dec-2020
 *      Author: prasanna
 */

#include <iostream>
using namespace std;

#include "t3Board.h"


void t3Board::setChar(char symbol, int i) {
	board[i / 3][i % 3] = symbol;
}
void t3Board::setChar(char symbol, int i, int j) {
	board[i][j] = symbol;
}
char t3Board::getChar(int i) {
	return board[i / 3][i % 3];
}
char t3Board::getChar(int i, int j) {
	return board[i][j];
}
char t3Board::whoWon() {
	return winner;
}

t3Board::t3Board(unsigned int rows, unsigned int cols) {

	num_rows = rows;
	num_cols = cols;
	winner = '-';

    for (int i = 0; i < (int)num_rows; i++)
      {
          for (int j = 0; j < (int)num_cols; j++)
              board[i][j] = '-';
      }

}

t3Board::~t3Board() {
	// TODO Auto-generated destructor stub
}

char t3Board::getField(unsigned int r, unsigned int c) {
	char temp = this->board[r][c];
	return temp;
}

void t3Board::setField(unsigned int r, unsigned int c, char symbol) {
	this->board[r][c] = symbol;
}

bool t3Board::rcParser(int &row, int &column, string CinData) {
	cout << "string:"<<CinData << " Row:"<< CinData[0] << " Col:" << CinData[1] <<endl;
	column = (int)CinData[1] - '0' - 1;

	if(CinData[0] == 'A'){
		row = 0;
	}
	if(CinData[0] == 'B'){
		row = 1;
	}
	if(CinData[0] == 'C'){
		row = 2;
	}
	if(CinData[0] == 'D'){
		row = 3;
	}
	if(CinData[0] == 'E'){
		row = 4;
	}
	if(CinData[0] == 'F'){
		row = 5;
	}
	if(CinData[0] == 'G'){
		row = 6;
	}
	if(CinData[0] == 'H'){
		row = 7;
	}

	if(row >=0 && row <=7 && column >=0 && column <=7){
		return true;
	}
	else{
		return false;
	}

	cout << "\nRow: "<< row << "  Col:" << column <<endl;
}

bool t3Board::checkWinner(char symbol)
    {
        // horizontal check
        for (int i = 0; i < BOARD_DIMENSION; i++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == symbol)
                return true;
        }

        // vertical check
        for (int i = 0; i < BOARD_DIMENSION; i++)
        {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == symbol)
                return true;
        }

        // diagonal 1 check
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == symbol)
            return true;

        // diagonal 2 check
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == symbol)
            return true;

        return false;
    }


// possible moves
bool t3Board::isMovePossible()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (this->board[i][j] == '-')
				return true;
		}
	}
	return false;
}
vector<int> t3Board::allPossibleMoves()
{
	vector<int> move_set;
	for (int i = 0; i < BOARD_DIMENSION; i++)
	{
		for (int j = 0; j < BOARD_DIMENSION; j++)
		{
			char temp = board[i][j];
			if(temp == '-'){
				move_set.push_back(3 * i + j);
			}
		}
	}
	return move_set;
}

// do move
void t3Board::doMove(char symbol, int index)
{
    int i = index / 3, j = index % 3;
    board[i][j] = symbol;

    if (checkWinner(symbol))
        winner = symbol;
}

void t3Board::resetWinner() {
	winner = '-';
}

void t3Board::reset() {

	 resetBoard();
	 resetWinner();
}

void t3Board::resetBoard() {

    for (int i = 0; i < BOARD_DIMENSION; i++)
    {
        for (int j = 0; j < BOARD_DIMENSION; j++)
            board[i][j] = '-';
    }
}
