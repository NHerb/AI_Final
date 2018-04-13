#ifndef BOARD_REPRESENTATION_H
#define BOARD_REPRESENTATION_H

enum {
   EMPTY, 
   WHITE,
   BLACK
};

// You can edit rows/columns to resize the game.  It works!  Needs a recompile, though.
const int ROWS = 5;
const int COLUMNS = 3;
const int STARTING_PAWNS = COLUMNS;

/*******************************************************************

            Explanation of board representation
      The 3x5 game board is represented by a simple 3x5 2D 
      array. The value stored indicates the player ID/Color which  
      owns a pawn located in that space, or 0/EMPTY if the space is 
      empty.  See the enum at the top.

********************************************************************/


struct game_state{
   int state[ROWS][COLUMNS];
};

#endif
