#include "board_representation.h"
#include "game.h"
#include <iostream>

using namespace std;

void display_game_results(int, game_state);

int main(){

   game_state board;
   init_board(&board);
   print_state(board);
   int human_color_id = -1;
   int ai_color_id = -1;


   while (human_color_id != WHITE and human_color_id != BLACK){
      cout << "Choose to be Player 1 (white, move first) or Player 2 (black, move second)." << endl;
      cin >> human_color_id;
   }
   if (human_color_id == WHITE) 
      ai_color_id = BLACK;
   else 
      ai_color_id = WHITE;


   

   while (true){

      print_state(board);
      cout << "White's turn." << endl;

      if (human_color_id == WHITE)
         while (human_move(&board, human_color_id) == -1);
      else
         ai_move(&board, ai_color_id, human_color_id);

      display_game_results(is_game_over(board, human_color_id), board);


      print_state(board);
      cout << "Black's turn." << endl;
      if (human_color_id == BLACK)
         while (human_move(&board, human_color_id) == -1);
      else
         ai_move(&board, ai_color_id, human_color_id);
      display_game_results(is_game_over(board, human_color_id), board);

   }

   return 0;
}



void display_game_results(int results, game_state board){
      if (results == WHITE){
         cout << "White wins!" << endl;
         print_state(board);
         exit(0);
      } else if (results == BLACK){
         cout << "Black wins!" << endl;
         print_state(board);
         exit(0);
      } else if (results == -1)
         cout << "Game unfinished." << endl;
      else if (results == 0)
         cout << "Draw." << endl;
      else
         cout << "PANIC" << endl;
}
