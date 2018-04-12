#include "board_representation.h"
#include "game.h"
#include <iostream>

using namespace std;

int main(){

   game_state board;
   init_board(&board);
   int human_color_id = -1;
   int ai_color_id = -1;

   // Uncomment any line to test basic win states, which will trigger after the very first move is entered
   //board.white_remaining_pawns = 0;        // Black Wins by full capture
   //board.black_remaining_pawns = 0;        // White Wins by full capture
   //board.state[0][0] = WHITE;              // White wins by finish line
   //board.state[ROWS - 1][0] = BLACK;       // Black wins by finish line

   print_state(board);


   while (human_color_id != WHITE and human_color_id != BLACK){
      cout << "Choose to be Player 1 (white, move first) or Player 2 (black, move second)." << endl;
      cin >> human_color_id;
   }
   if (human_color_id == WHITE) 
      ai_color_id = BLACK;
   else 
      ai_color_id = WHITE;


   

   while (true){
/* // Uncomment to print all possible next states (of next player)
vector<game_state> children = generate_children(board, human_color_id);
cout << "-------------------------------------------------" << endl;
for (auto i : children)
   print_state(i);
cout << "-------------------------------------------------" << endl;
*/ // End block comment here
      print_state(board);
      cout << "White's turn." << endl;
      human_move(&board, human_color_id);
      int results = is_game_over(board, human_color_id);

      if (results == WHITE){
         cout << "White wins!" << endl;
         return 0;
      } else if (results == BLACK){
         cout << "Black wins!" << endl;
         return 0;
      } else if (results == -1)
         cout << "Game unfinished." << endl;
      else if (results == 0)
         cout << "Draw." << endl;
      else
         cout << "PANIC" << endl;


      print_state(board);
      cout << "Black's turn." << endl;
      human_move(&board, ai_color_id);
      results = is_game_over(board, human_color_id);

      if (results == WHITE){
         cout << "White wins!" << endl;
         return 0;
      } else if (results == BLACK){
         cout << "Black wins!" << endl;
         return 0;
      } else if (results == -1)
         cout << "Game unfinished." << endl;
      else if (results == 0)
         cout << "Draw." << endl;
      else
         cout << "PANIC" << endl;




   }

   return 0;
}
