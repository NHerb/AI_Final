#ifndef BOARD_REPRESENTATION_H
#define BOARD_REPRESENTATION_H

const int ROWS = 3;
const int COLUMNS = 5;
const int STARTING_PAWNS = 3;

/*******************************************************************

            Explanation of board representation
      The 3x5 game board is represented by a 3x5 2D array.
      The value stored indicates the player ID which owns 
      a pawn located in that space, or 0 if the space is 
      empty.

********************************************************************/


struct game_state{
   int state[COLUMNS][ROWS];
   int player1_remaining_pawns;
   int player2_remaining_pawns;
};

#endif
