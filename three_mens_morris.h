#include <utility>
#include <string>

#ifndef _THREE_MENS_MORRIS_H
#define _THREE_MENS_MORRIS_H

typedef int Board[3][3];
typedef std::pair<int, int> Move;
typedef std::pair<int,int> Location;
typedef std::pair<Move,Move> Locations_of_Moves;

//before three peices are placed down
bool ValidMove(Board board, Move move);
bool ValidSpace(Move space);
Move ParseMove(const std::string &input);
Move GetMove(Board board);
void SetPlayerAtSpace(Board board, const int player, const Move &space);


//after three pieces are placed down
bool Phase_2_ValidMove(Board board, Location origin, Location destination, int active_player);
bool Phase_2_ValidSpace(Location space);
bool Phase_2_ValidCoordinates(Board board, Location origin, Location destination);
Locations_of_Moves Phase_2_GetMove(Board board, int active_player);
Locations_of_Moves Phase_2_ParseMove(const std::string &input);
void Phase_2_SetPlayerAtSpace(Board board, const int player, const Locations_of_Moves &space);

//AI functions
bool AI_ValidSpace(Move space);
bool AI_ValidMove(Board board, Move move);
Move AI_Move(Board board);
Move Random_Move_Generator(Board board, Move move);
bool AI_Phase_2_ValidSpace(Location space);
bool AI_Phase_2_ValidMove(Board board, Location origin, Location destination);
Locations_of_Moves Phase_2_Random_Move_Generator(Board board);
Locations_of_Moves Phase_2_AI_Move(Board board);

//Not affected by peice count
void PrintBoard(Board board);
void SetPlayerAtSpace(Board board, const int player, const Move &space);
void PrintSpace(const Move space);
bool check_win(Board board, const int active_player);
void A_Turn(Board board, int turn_cycle, int active_player);
bool No_Valid_Moves_Test(Board board, int active_player);

#endif