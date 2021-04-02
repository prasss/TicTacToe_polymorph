/*
 * main.cpp
 *
 *  Created on: 13-Dec-2020
 *      Author: prasanna
 */


#include <iostream>
using namespace std;

#include "t3Board.h"
#include "t3Display.h"
#include "t3Player.h"
#include "t3Game.h"

//
//void gamePlay(t3Board board, t3Player *x_player, t3Player *o_player, console *display)
//{
//    char letter = 'X';
//    int index;
//    board.reset();
//    while (board.isMovePossible())
//    {
//        if (letter == 'O')
//            index = o_player->getMove(&board);
//        else
//            index = x_player->getMove(&board);
//
//        board.doMove(letter, index);
//        cout << endl
//             << letter << " makes move to " << index + 1 << endl;
//        display->printBoard(&board);
//        cout << endl;
//
//        if (board.checkWinner(letter))
//        {
//            cout << endl
//                 << letter << " wins !";
//            return;
//        }
//
//        letter = (letter == 'X') ? 'O' : 'X';
//    }
//    cout << endl
//         << "Draw";
//}




int main(){

	t3Board t3b(BOARD_DIMENSION, BOARD_DIMENSION);
	console t3Disp;
	t3Game t3g;

//	int r,c;
//	string str = "B2";
//	t3Disp.printBoard(&t3b);
//
//	t3b.rcParser(r,c,str);
//
//	cout << r << c <<endl;
//
//	t3b.setField(0,0,'X');
//	t3b.setField(1,1,'X');
//	t3b.setField(2,2,'X');
//
//	t3Disp.printBoard(&t3b);
//
//	cout<< t3b.checkWinner('X') <<endl;
//
//	return 0;


	    char ch;
	    int mode;

	    HumanPlayer x_human('X');
	    HumanPlayer o_human('O');
	    CompPlayer x_Comp('X');
	    CompPlayer o_Comp('O');

	    t3Player *x, *o;

	    do
	    {
	        cout << endl;
	        cout << "Choose an option for the TicTacToe game:" << endl
	             << "1. Human v/s Human" << endl
	             << "2. Human v/s Computer" << endl
	             << "3. Computer v/s Human" << endl
	             << "4. Computer v/s Computer" << endl
	             << endl
	             << "Mode : ";
	        cin >> mode;

	        switch (mode)
	        {
	        case 1:
	            x = &x_human;
	            o = &o_human;
	            break;

	        case 2:
	            x = &x_human;
	            o = &o_Comp;
	            break;

	        case 3:
	            x = &x_Comp;
	            o = &o_human;
	            break;

	        case 4:
	            x = &x_Comp;
	            o = &o_Comp;
	            break;

	        default:
	            cout << "Wrong choice";
	        }

	        t3g.gamePlay(t3b, x, o, &t3Disp);

	        cout << endl
	             << "Wish to Play again?(y/n) : ";
	        cin >> ch;

	    } while (ch == 'y' || ch == 'Y');

	    cout << "Quitting... Thanks for Playing!" <<endl;
	    return 0;
}


