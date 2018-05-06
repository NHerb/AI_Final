# AI_Final

This is a simple project to implement an optimal AI for the three-pawn game to 
improve and demonstrate my understanding of Artificial Intelligence.

The Pawn Game is a chess-like zero-sum competitive two-player game in which the player
competes against an AI by manipulating pawns on a 3x5 grid. Like in chess, pawns can only 
move one space forward, optionally two spaces forward on first move, or diagonally when 
capturing an enemy pawn.

This AI plays the game using minimax for the core logic of the AI’s decision-making, and 
as a result, it is unlikely to lose against human players.

The constant values ROW and COLUMNS in the board representation file can be edited to change 
the size of the board, resulting in a larger or smaller version of the game.

Further possible future improvements:
  -implement pruning (alpha-beta and/or depth-limited) for runtime improvements
  -implement a GUI
  -add difficulty modes
