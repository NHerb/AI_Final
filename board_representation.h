#ifndef BOARD_REPRESENTATION_H
#define BOARD_REPRESENTATION_H

enum {
   EMPTY, 
   WHITE,
   BLACK
};

// You can edit rows/columns to resize the game.  It works!
const int ROWS = 5;
const int COLUMNS = 3;
const int STARTING_PAWNS = ROWS;

/*******************************************************************

            Explanation of board representation
      The 3x5 game board is represented by a 3x5 2D array.
      The value stored indicates the player ID which owns 
      a pawn located in that space, or 0 if the space is 
      empty.

********************************************************************/


struct game_state{
   int state[ROWS][COLUMNS];
   int white_remaining_pawns;
   int black_remaining_pawns;
};

#endif
