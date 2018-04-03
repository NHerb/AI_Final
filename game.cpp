#include "board_representation.h"
#include <vector>
#include <iostream>


using namespace std;

void init_board(game_state* board){
   for (int i = 0; i < COLUMNS; i++){
      board->state[0][i] = BLACK;
      board->state[1][i] = EMPTY;
      board->state[2][i] = EMPTY;
      board->state[3][i] = EMPTY;
      board->state[4][i] = WHITE;
   }
   board->white_remaining_pawns = 3;
   board->black_remaining_pawns = 3;
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
int is_game_over(game_state current_state){
   // Winning states: 
   // Player loses all pawns (that player loses)
   // Player's pawn reaches back line (that player wins)
   // All pawns blocked (draw game)

   if (current_state.white_remaining_pawns == 0)
      return BLACK;
   else if (current_state.black_remaining_pawns == 0)
      return WHITE;
   else;

   for (int i = 0; i < COLUMNS; i++)
      if (current_state.state[0][i] == WHITE)
         return WHITE;
   for (int i = 0; i < COLUMNS; i++)
      if (current_state.state[ROWS - 1][i] == BLACK)
         return BLACK;

   return -1;   // Game incomplete
}

vector<game_state> generate_children(game_state parent_state){

}


void human_move(game_state current_state){

}


void ai_move(game_state current_state){

}
