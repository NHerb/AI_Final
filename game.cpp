#include "board_representation.h"
#include <vector>
#include <iostream>


using namespace std;

void init_board(game_state* board){
   for (int i = 0; i < COLUMNS; i++){
      for (int j = 0; j < ROWS; j++){
         if (j == 0)
            board->state[j][i] = BLACK;
         else if (j == ROWS - 1)
            board->state[j][i] = WHITE;
         else
            board->state[j][i] = EMPTY;
      }
   }
   board->white_remaining_pawns = STARTING_PAWNS;
   board->black_remaining_pawns = STARTING_PAWNS;
}


void print_state(game_state board){
   cout << endl;
   for (int i = 0; i < ROWS; i++){
      cout << "\t";
      for (int j = 0; j < COLUMNS; j++){
         cout << board.state[i][j] << " ";
      }
      cout << endl << endl;
   }
}


// Return ID of winning player, 0 if draw, -1 if incomplete
int is_game_over(game_state board, bool verbose_mode){

   // Win on capturing all enemy pawns
   if (board.white_remaining_pawns == 0)
      return BLACK;
   else if (board.black_remaining_pawns == 0)
      return WHITE;
   else;

   // Win on reaching opponent's starting row
   for (int i = 0; i < COLUMNS; i++)
      if (board.state[0][i] == WHITE)
         return WHITE;
   for (int i = 0; i < COLUMNS; i++)
      if (board.state[ROWS - 1][i] == BLACK)
         return BLACK;


   // NOTE: once generate_children() is implemented (which probably will just use this code), 
   // we can simply check the size of children states for the current player - lose on 0 child states

   // Losing game (can't make any moves & no captures possible)
   bool black_valid_moves_remaining = false;
   bool white_valid_moves_remaining = false;
   for (int i = 0; i < ROWS; i++){       
      for (int j = 0; j < COLUMNS; j++){
         // check space for white/black - if there's a valid move, flag and move one
         if (board.state[i][j] == BLACK and !black_valid_moves_remaining){
if (verbose_mode) cout << "black at " << i << "," << j << ".  Below: " << board.state[i+1][j] << endl;
            if (board.state[i+1][j] == EMPTY){         // Shouldn't go OOB - black can't reach bottom without winning (see above code)
               black_valid_moves_remaining = true;
if (verbose_mode) cout << "black can move down from " << i << "," << j << endl;
            } else {
               // Need to check for capture possibilities on valid moves
               if (j != 0){
                  // Check down-left space 
                  if (board.state[i+1][j-1] == WHITE)
                     black_valid_moves_remaining = true;
               }
               if (j != COLUMNS - 1){
                  // Check down-right space
                  if (board.state[i+1][j+1] == WHITE)
                     black_valid_moves_remaining = true;
               }
            }
         } else if (board.state[i][j] == WHITE and !white_valid_moves_remaining){
 if (verbose_mode) cout << "white at " << i << "," << j << ".  Above: " << board.state[i-1][j] << endl;
            if (board.state[i-1][j] == EMPTY){          // Similarly, won't go OOB as white cannot reach botton without winning 
               white_valid_moves_remaining = true;
 if (verbose_mode) cout << "white can move up from " << i << "," << j << endl;
            } else {
               // Check capture possibilities
               if (j != 0){
                  // Check up-left space 
                  if (board.state[i-1][j-1] == WHITE)
                     white_valid_moves_remaining = true;
               }
               if (j != COLUMNS - 1){
                  // Check up-right space
                  if (board.state[i-1][j+1] == WHITE)
                     white_valid_moves_remaining = true;
               }

            }
         }
      }
   }

   if (!black_valid_moves_remaining and !white_valid_moves_remaining)
      return 0;   // Draw

   if (!black_valid_moves_remaining)
      return WHITE;

   if (!white_valid_moves_remaining)
      return BLACK;

   return -1;    // Game incomplete
}

vector<game_state> generate_children(game_state parent_state){
   vector<game_state> list_of_children;

   return list_of_children;
}


void human_move(game_state board){

}


void ai_move(game_state board){

}
