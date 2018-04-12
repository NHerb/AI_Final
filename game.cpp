#include "board_representation.h"
#include "game.h"
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
   cout << endl << endl << endl;
   cout << "White Pawns Remaining: " << board.white_remaining_pawns << endl;
   cout << "Black Pawns Remaining: " << board.black_remaining_pawns << endl;
   for (int i = 0; i < ROWS; i++){
      cout << "\t";
      for (int j = 0; j < COLUMNS; j++){
         cout << board.state[i][j] << " ";
      }
      cout << endl << endl;
   }
}


// Return ID of winning player, 0 if draw, -1 if incomplete
int is_game_over(game_state board, int current_player){

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



   // Losing game (can't make any moves & no captures possible)
   vector<game_state> children;
   children = generate_children(board, current_player);


   if (current_player == BLACK and children.size() == 0)
      return WHITE;
   else if (current_player == WHITE and children.size() == 0)
      return BLACK;


   return -1;    // Game incomplete
}


vector<game_state> generate_children(game_state board, int current_player){
   vector<game_state> list_of_children;

   for (int i = 0; i < ROWS; i++){       
      for (int j = 0; j < COLUMNS; j++){
         game_state child;
         child = board;
         // check space for white/black - if there's a valid move, add and move one
         if (board.state[i][j] == BLACK and current_player == BLACK){
            if (board.state[i+1][j] == EMPTY){         // Shouldn't go OOB - black can't reach bottom without winning (see above code)
               child.state[i][j] = EMPTY;
               child.state[i+1][j] = BLACK;
               list_of_children.push_back(child);
            } else {
               // Need to check for capture possibilities on valid moves
               if (j != 0){
                  // Check down-left space 
                  if (board.state[i+1][j-1] == WHITE)
                     child = board;
                     child.state[i][j] = EMPTY;
                     child.state[i+1][j-1] = BLACK;
                     child.white_remaining_pawns--;
                     list_of_children.push_back(child);
               }
               if (j != COLUMNS - 1){
                  // Check down-right space
                  if (board.state[i+1][j+1] == WHITE)
                     child = board;
                     child.state[i][j] = EMPTY;
                     child.state[i+1][j+1] = BLACK;
                     child.white_remaining_pawns--;
                     list_of_children.push_back(child);
               }
            }
         } else if (board.state[i][j] == WHITE and current_player == WHITE){
            if (board.state[i-1][j] == EMPTY){          // Similarly, won't go OOB as white cannot reach botton without winning 
               child.state[i][j] = EMPTY;
               child.state[i-1][j] = WHITE;
               list_of_children.push_back(child);
            } else {
               // Check capture possibilities
               if (j != 0){
                  // Check up-left space 
                  if (board.state[i-1][j-1] == WHITE)
                     child = board;
                     child.state[i][j] = EMPTY;
                     child.state[i-1][j-1] = WHITE;
                     child.black_remaining_pawns--;
                     list_of_children.push_back(child);
               }
               if (j != COLUMNS - 1){
                  // Check up-right space
                  if (board.state[i-1][j+1] == WHITE)
                     child = board;
                     child.state[i][j] = EMPTY;
                     child.state[i-1][j+1] = WHITE;
                     child.black_remaining_pawns--;
                     list_of_children.push_back(child);
               }

            }
         }
      }
   }




   return list_of_children;
}


// Return -1 on invalid move
int human_move(game_state* board, int color){
   // Dumb thought for validating player input - let's just generate 
   // child states and see if player's choice is one of those options

   vector<game_state> children = generate_children(*board, color);
   game_state new_board = *board;
   int x1, y1, x2, y2;
   cout << "Input start coord and end coord. Ex: 0 1 1 1)" << endl;
   cin >> x1 >> y1 >> x2 >> y2;

   // Check for segfault then make a state according to player input
   if (x1 < 0 or x2 < 0 or y1 < 0 or y2 < 0 or x1 >= ROWS or x2 >= ROWS or y1 >= COLUMNS or y2 >= COLUMNS){
      std::cout << "Input out of bounds!" << std::endl;
      return -1;
   } else {
      new_board.state[x1][y1] = EMPTY;
      if (new_board.state[x2][y2] == WHITE)
         new_board.white_remaining_pawns--;
      else if (new_board.state[x2][y2] == BLACK)
         new_board.black_remaining_pawns--;
      new_board.state[x2][y2] = color;
   }

   // check if player's choice is one of the children states
   bool is_valid_move = false;
   for (auto i : children){
      if (is_equal_state(new_board, i))
         is_valid_move = true;
   }

   // If player made a valid move, then edit the pointer to the main game board to reflect the change
   if (is_valid_move){
      board->state[x1][y1] = EMPTY;
      if (board->state[x2][y2] == WHITE)
         board->white_remaining_pawns--;
      if (board->state[x2][y2] == BLACK)
         board->black_remaining_pawns--;
      board->state[x2][y2] = color;       
      return 0;
   } else {
      std::cout << "Invalid move!" << std::endl;
      return -1;
   }
}


void ai_move(game_state board){

}


bool is_equal_state(game_state board, game_state board2){

   if (board.white_remaining_pawns != board2.white_remaining_pawns or board.black_remaining_pawns != board2.black_remaining_pawns)
      return false;

   for (int i = 0; i < ROWS; i++){
      for (int j = 0; j < COLUMNS; j++){
         if (board.state[i][j] != board2.state[i][j])
            return false;
      }
   }
   return true;
}
