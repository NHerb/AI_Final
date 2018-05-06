# AI_Final

This is a simple project to implement an optimal AI for the three-pawn game to 
improve and demonstrate my understanding of Artificial Intelligence.

The Pawn Game is a chess-like zero-sum competitive two-player game in which the player
competes against an AI by manipulating pawns on a 3x5 grid. Like in chess, pawns can only 
move one space forward, optionally two spaces forward on first move, or diagonally when 
capturing an enemy pawn.

A player wins in one of the three following conditions:
  -A player moves his pawn to the opposite end of the board (win by speed)
  -A player captures all of his opponent's pawns (win by capture)
  -A player blocks all possible moves of his opponent (win by lock)

This AI plays the game using minimax for the core logic of the AI’s decision-making, and 
as a result, it is unlikely to lose against human players.

The constant values ROW and COLUMNS in the board representation file can be edited to change 
the size of the board, resulting in a larger or smaller version of the game.

Further possible future improvements:
  -implement pruning (alpha-beta and/or depth-limited) for runtime improvements
  -implement a GUI
  -add difficulty modes
