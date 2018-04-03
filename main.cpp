#include "board_representation.h"
#include "game.h"
#include <iostream>

using namespace std;

int main(){

   game_state board;
   init_board(&board);
   int human_id = 0;

   // Uncomment any line to test basic win states.
   //board.white_remaining_pawns = 0;        // Black Wins
   //board.black_remaining_pawns = 0;        // White Wins
   //board.state[0][0] = WHITE;              // White wins
   //board.state[ROWS - 1][0] = BLACK;       // Black wins

   print_state(board);





   if (is_game_over(board) == WHITE)
      cout << "White wins!" << endl;
   else if (is_game_over(board) == BLACK)
      cout << "Black wins!" << endl;
   else
      cout << "No winner." << endl;

/*
   while (human_id != 1 and human_id != 2){
      cout << "Choose to be Player 1 (move first) or Player 2 (move second)." << endl;
      cin >> human_id;
   }
*/


   return 0;
}
