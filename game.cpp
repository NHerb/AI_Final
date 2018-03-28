#include "board_representation.h"
#include <vector>
#include <iostream>

enum {
   EMPTY, 
   WHITE,
   BLACK
};

using namespace std;

void init_board(game_state* board){
   for (int i = 0; i < ROWS; i++){
      board->state[0][i] = BLACK;
      board->state[1][i] = EMPTY;
      board->state[2][i] = EMPTY;
      board->state[3][i] = EMPTY;
      board->state[4][i] = WHITE;
   }
}


void print_state(game_state board){
   cout << endl;
   for (int i = 0; i < COLUMNS; i++){
      cout << "\t";
      for (int j = 0; j < ROWS; j++){
         cout << board.state[i][j] << " ";
      }
      cout << endl << endl;
   }
}


int is_game_over(game_state current_state, int player_id){

}

vector<game_state> generate_children(game_state parent_state){

}


void human_move(game_state current_state){

}


void ai_move(game_state current_state){

}
