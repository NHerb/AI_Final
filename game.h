#include "board_representation.h"
#include <vector>
#include <iostream>

using namespace std;

void init_board(game_state* board);
void print_state(game_state board);
int is_game_over(game_state current_state);
vector<game_state> generate_children(game_state parent_state);
void human_move(game_state current_state);
void ai_move(game_state current_state);
