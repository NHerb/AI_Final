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
}


void print_state(game_state board){
   cout << endl;
   cout << "\t    COLUMN" << endl;
   cout << "\t    ";
   for (int i = 0; i < COLUMNS; i++) cout << i << " ";
   cout << endl << "\t-------------" << endl;
   for (int i = 0; i < ROWS; i++){
      if (i == ROWS / 2) cout << "ROW\t" << i << " | ";
      else cout << "\t" << i << " | ";
      for (int j = 0; j < COLUMNS; j++){
         if (board.state[i][j] == WHITE) cout << "W ";
         else if (board.state[i][j] == BLACK) cout << "B ";
         else cout << "- ";
      }
      cout << endl;
   }
      cout << endl;
}


// Return ID of winning player, 0 if draw, -1 if incomplete
int is_game_over(game_state board, int current_player){


   // Win on capturing all enemy pawns
   int white_remaining_pawns = 0;
   int black_remaining_pawns = 0;

   for (int i = 0; i < ROWS; i++){
      for (int j = 0; j < COLUMNS; j++){
         if (board.state[i][j] == WHITE)
            white_remaining_pawns++;
         else if (board.state[i][j] == BLACK)
            black_remaining_pawns++;
      }
   }

   if (white_remaining_pawns == 0){
      return BLACK;
   }
   if (black_remaining_pawns == 0){
      return WHITE;
   }


   // Win on reaching opponent's starting row
   for (int i = 0; i < COLUMNS; i++){
      if (board.state[0][i] == WHITE){
         return WHITE;
      }
   }
   for (int i = 0; i < COLUMNS; i++){
      if (board.state[ROWS - 1][i] == BLACK){
         return BLACK;
      }
   }



   // Losing game (can't make any moves & no captures possible)
   vector<game_state> children;
   children = generate_children(board, current_player);


   if (current_player == BLACK and children.size() == 0){
      return WHITE;
   } else if (current_player == WHITE and children.size() == 0){
      return BLACK;
   }


   return -1;    // Game incomplete
}


vector<game_state> generate_children(game_state board, int current_player){

   vector<game_state> list_of_children;

   // Scan the state for all pawns of the current player.  For each of those pawns, check all its move
   // possibilities - all that are valid update the current board with that move and are added to child list
   for (int i = 0; i < ROWS; i++){       
      for (int j = 0; j < COLUMNS; j++){
         game_state child;
         set_equal(&child, board);

         if (board.state[i][j] == BLACK and current_player == BLACK){
            // Black checks below for an empty space
            if (board.state[i+1][j] == EMPTY){         // Shouldn't go OOB - black can't reach bottom without winning (see above code)
               child.state[i][j] = EMPTY;
               child.state[i+1][j] = BLACK;
               list_of_children.push_back(child);

               // There may be more valid moves for this child - reset it to initial state and keep checking
               set_equal(&child, board);

            }

// Last minute addition!
            // Black checks two spaces below if this is initial move
            if (i == 0){
               if (board.state[i+2][j] == EMPTY and board.state[i+1][j] == EMPTY){
                  child.state[i][j] = EMPTY;
                  child.state[i+2][j] = BLACK;
                  list_of_children.push_back(child);
                  set_equal(&child, board);
               }
            }
// Last minute addition!

            // Black checks diagonally for capturing moves (don't check OOB)
            if (j != 0){
               // Check down-left space 
               if (board.state[i+1][j-1] == WHITE){
                  child.state[i][j] = EMPTY;
                  child.state[i+1][j-1] = BLACK;
                  list_of_children.push_back(child);
                  set_equal(&child, board);
               }
            }
            if (j != COLUMNS - 1){
               // Check down-right space
               if (board.state[i+1][j+1] == WHITE){
                  child.state[i][j] = EMPTY;
                  child.state[i+1][j+1] = BLACK;
                  list_of_children.push_back(child);
                  set_equal(&child, board);
               }
            }
            
         } else if (board.state[i][j] == WHITE and current_player == WHITE){
            // White checks above for empty space to move to
            if (board.state[i-1][j] == EMPTY){          // Similarly, won't go OOB as white cannot reach botton without winning 
               child.state[i][j] = EMPTY;
               child.state[i-1][j] = WHITE;
               list_of_children.push_back(child);

               // There may be more valid moves for this child - reset it to initial state and keep checking
               set_equal(&child, board);

            }

// Last minute addition!
            // White checks two spaces below if this is initial move
            if (i == ROWS - 1){
               if (board.state[i-2][j] == EMPTY and board.state[i-1][j] == EMPTY){
                  child.state[i][j] = EMPTY;
                  child.state[i-2][j] = WHITE;
                  list_of_children.push_back(child);
                  set_equal(&child, board);
               }
            }
// Last minute addition!

            // Check capture possibilities
            if (j != 0){
               // Check up-left space 
               if (board.state[i-1][j-1] == BLACK){
                  child.state[i][j] = EMPTY;
                  child.state[i-1][j-1] = WHITE;
                  list_of_children.push_back(child);
                  set_equal(&child, board);
               }
            }
            if (j != COLUMNS - 1){
               // Check up-right space
               if (board.state[i-1][j+1] == BLACK){
                  child.state[i][j] = EMPTY;
                  child.state[i-1][j+1] = WHITE;
                  list_of_children.push_back(child);
                  set_equal(&child, board);
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
   game_state new_board;
   set_equal(&new_board, *board);

   int x1, y1, x2, y2;
   cout << "Input start coord and end coord. Ex: 0 1 1 1)" << endl;
   cin >> x1 >> y1 >> x2 >> y2;

   // Check for segfault then make a state according to player input
   if (x1 < 0 or x2 < 0 or y1 < 0 or y2 < 0 or x1 >= ROWS or x2 >= ROWS or y1 >= COLUMNS or y2 >= COLUMNS){
      std::cout << "Input out of bounds!" << std::endl;
      return -1;
   } else {
      new_board.state[x1][y1] = EMPTY;
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
      board->state[x2][y2] = color;       
      return 0;
   } else {
      std::cout << "Invalid move!" << std::endl;
      return -1;
   }
}


bool is_equal_state(game_state board, game_state board2){

   for (int i = 0; i < ROWS; i++){
      for (int j = 0; j < COLUMNS; j++){
         if (board.state[i][j] != board2.state[i][j])
            return false;
      }
   }
   return true;
}


void set_equal(game_state* target, game_state source){
   for (int i = 0; i < ROWS; i++){
      for (int j = 0; j < COLUMNS; j++){
         target->state[i][j] = source.state[i][j];
      }
   }

}



void ai_move(game_state* board, int ai_color, int human_color){

   int best_choice_val = -10000;
   game_state best_move;
   vector<game_state> children = generate_children(*board, ai_color);
//cout << endl << "I think my move scores are... ";                           // Uncomment this and below comment to see what AI thinks of its moves
   for (auto i : children){
      int temp = minimax(i, human_color, ai_color);
//cout << temp << " ";                                                        // Same here
      if (temp > best_choice_val){
         best_choice_val = temp;
         set_equal(&best_move, i);
      }
   }
   // Best move is found, write that state to the board
   set_equal(board, best_move);
}


int minimax(game_state board, int current_player, int ai_color){
//static int count = 0;
//count++;
//if (count % 10000 == 0) cout << count << endl;

   // Base state: Game is concluded - return high score if AI wins, low if AI loses
   int results = is_game_over(board, current_player);
   if (results == ai_color)
      return 1;
   else if ((results == BLACK or results == WHITE) and results != ai_color)
      return -1;
   else if (results == 0)
      return 0;

   int next_player;
   if (current_player == WHITE)
      next_player = BLACK;
   else
      next_player = WHITE;
 
   // Generate all next states, run minimax on each, return best result
   vector<game_state> children = generate_children(board, current_player);
   int temp = children.size();
   int options[temp]; 
   int iter = 0;
   // Maximizing player
   if (current_player == ai_color){
      int best_val = -10000;
      for (auto i : children){
         options[iter] = minimax(i, next_player, ai_color);
         if (options[iter] > best_val)
            best_val = options[iter];
         iter++;
      }
      return best_val;
   }

   // Minimizing player
   else {
      int best_val = 10000;
      for (auto i : children){
         int temp = minimax(i, next_player, ai_color);
         if (temp < best_val)
            best_val = temp;
      }
      return best_val;
   }


   return -99;
}
