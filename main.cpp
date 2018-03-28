#include "board_representation.h"
#include "game.h"
#include <iostream>

using namespace std;

int main(){


   game_state board;
   init_board(&board);
   print_state(board);
   int human_id = 0;
/*
   while (human_id != 1 and human_id != 2){
      cout << "Choose to be Player 1 (move first) or Player 2 (move second)." << endl;
      cin >> human_id;
   }
*/


   return 0;
}
