#include "board_representation.h"
#include "game.h"
#include <iostream>

using namespace std;

int main(){

   game_state board;
   init_board(&board);
   int human_id = 0;

   // Uncomment any line to test basic win states.
   //board.white_remaining_pawns = 0;        // Black Wins by full capture
   //board.black_remaining_pawns = 0;        // White Wins by full capture
   //board.state[0][0] = WHITE;              // White wins by finish line
   //board.state[ROWS - 1][0] = BLACK;       // Black wins by finish line
   bool verbose_mode = true;

   print_state(board);



   int results = is_game_over(board, verbose_mode);

   if (results == WHITE)
      cout << "White wins!" << endl;
   else if (results == BLACK)
      cout << "Black wins!" << endl;
   else if (results == -1)
      cout << "Game unfinished." << endl;
   else if (results == 0)
      cout << "Draw." << endl;
   else
      cout << "PANIC" << endl;

/*
   while (human_id != 1 and human_id != 2){
      cout << "Choose to be Player 1 (move first) or Player 2 (move second)." << endl;
      cin >> human_id;
   }
*/


   return 0;
}
