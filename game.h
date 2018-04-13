#include "board_representation.h"
#include <vector>
#include <iostream>

using namespace std;


// Sets a board to starting, ready-to-start-playing state
void init_board(game_state* board);


// Prints the board
void print_state(game_state board);


// Checks if the game is lost, and returns the color of the losing player (or 0 on draw, -1 on incomplete game)
int is_game_over(game_state current_state, int current_player);


//  Finds all valid moves by current player, returns a vector holding each of those states
vector<game_state> generate_children(game_state parent_state, int current_player);


// Gets player input, validates the move, updates board
int human_move(game_state* current_state, int color);


// Asks minimax which of AI's next states is best to take, updates board with that choice
void ai_move(game_state current_state);


// Checks if two states are the same
bool is_equal_state(game_state board, game_state board2);


// Returns the optimal score of a given board state
int minimax(game_state board, int current_player);


// Simple helper function for assigning states equal
void set_equal(game_state* target, game_state source);
