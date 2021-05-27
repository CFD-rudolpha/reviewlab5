#include <iostream>
#include <string>
#include <cstdlib>
#include "three_mens_morris.h"

Move GetMove(Board board) 
/*
input board
output Move
Generally the same as given. I did have a version that tried to decipher between what to do through a turn cycle 
it looked crisper and made my brain hurt less to seperate it up into a phase 2 though
*/
{
  Move move;
  do {
    std::string input;
    std::cout << "Enter a space to move: ";
    std::getline(std::cin, input);
    if (input == "x") {
      exit(0);
    }

     move = ParseMove(input);
  } while (!ValidMove(board, move));

  return move;
}

void PrintBoard(Board board)
/*
I found a trick with %c I am not using that here but be warned I could in future
*/
{
  std::cout<< " " << " " << " " << "a" << " " << "b" << " " << "c" <<std::endl;
  std::cout<< " " << " " << " " << "_" << "_" << "_" << "_" << "_" <<std::endl;
  std::cout<< "1" << " " << "|" << board[0][0] << "-" << board[0][1] << "-" << board[0][2]<<std::endl;
  std::cout<< "2" << " " << "|" << board[1][0] << "-" << board[1][1] << "-" << board[1][2]<<std::endl;
  std::cout<< "3" << " " << "|" << board[2][0] << "-" << board[2][1] << "-" << board[2][2]<<std::endl;
  std::cout<<std::endl;

}

int PlayerAtSpace(Board board, const Move &space)
/*
Unchanged from what you made me. whiy change mroe than i have to you know
*/
{
  return board[space.first][space.second];
}

void SetPlayerAtSpace(Board board, const int player, const Move &space) 
{
  board[space.first][space.second] = player;
}

Move ParseMove(const std::string &input)
//Same 
{
  Move ret;

  if (input.size() != 2) {
    std::cerr << "Unable to parse" << std::endl;
    ret.first = -1;
    ret.second = -1;
    return ret;
  }

  int col = input.at(0);
  int row = input.at(1);

  if (col == 'a') {
    ret.second = 0;
  } else if (col == 'b') {
    ret.second = 1;
  } else if (col == 'c') {
    ret.second = 2;
  } else {
    ret.second = -1;
  }

  row = row - '0' - 1;

  ret.first = row;

  return ret;
}

bool ValidMove(Board board, Move move) {
  if (!ValidSpace(move)) {
    std::cerr << "Invalid destination" << std::endl;
    return false;
  }

  if (board[move.first][move.second] != 0 ) {
    std::cerr << "Cannot move to a space that is occupied" << std::endl;
    return false;
  }

  return true;
}

bool ValidSpace(Move space) {
  int col = space.first;
  int row = space.second;

  if (col < 0 || col > 2) {
    std::cerr << "column " << col << " out of range" << std::endl;
    return false;
  }
  if (row < 0 || row > 2) {
    std::cerr << "row " << row << " out of range" << std::endl;
    return false;
  }

  return true;
}

bool check_win(Board board, const int active_player)
// 9 possible board states available for either player
//I test each row to check if all equal a number
// If they are we got a winner.
{
  bool check = false;
  if (
      (board[0][0] == active_player && board[0][1] == active_player && board[0][2]== active_player)||
      (board[0][0] == active_player && board[1][0] == active_player && board[2][0]== active_player)||
      (board[1][0] == active_player && board[1][1] == active_player && board[1][2]== active_player)||
      (board[2][0] == active_player && board[2][1] == active_player && board[2][2]== active_player)||
      (board[0][1] == active_player && board[1][1] == active_player && board[2][1]== active_player)||
      (board[0][2] == active_player && board[1][2] == active_player && board[2][2]== active_player))
      {
        check = true;
        std::cout<<"\nPlayer "<< active_player << " you gorgeous beast you won!!! \nCollect you winnings from Daniel Defreez today!!!!\n"<< std::endl;
        PrintBoard(board);
      }
      return check;
}

void A_Turn(Board board, int turn_cycle, int active_player)
/*
    I made the main fucntion less cluttered
*/
{
  Move move;
  Locations_of_Moves move_locations;

  PrintBoard(board);  
  std::cout<< "Passing turn to player "<< active_player << std::endl;  
  if(turn_cycle < 3)
  {
    if(active_player == 2)
      move = AI_Move(board);
    else
      move = GetMove(board);  
    SetPlayerAtSpace(board, active_player, move);
  }  
  if(turn_cycle >= 3)
  {
    if(active_player == 2)
    {
      if(No_Valid_Moves_Test(board, active_player))
        return;
      move_locations = Phase_2_AI_Move(board); 
      Phase_2_SetPlayerAtSpace(board, active_player, move_locations);     
    }

    else
    {
      if(No_Valid_Moves_Test(board, active_player))
        return;
      move_locations = Phase_2_GetMove(board, active_player);
      Phase_2_SetPlayerAtSpace(board, active_player, move_locations);
    }
      
  }
    
}

bool No_Valid_Moves_Test(Board board, int active_player)
/*
    I go around the board and test if all the surroundign peices of an active player are 0
    if they are not then i add one to a counter 
    if all three peices are surrounded it returns 0 and tells them sol
*/
{
  int Valid_Moves_Counter = 0;

  //corner cases
  if(board[0][0] == active_player)
  {
    if(board[1][0] != 0 && board[0][1] != 0)
    {
      Valid_Moves_Counter++;
    }
  }

  if(board[0][2] == active_player)
  {
    if(board[1][2] != 0 && board[0][1] != 0)
    {
      Valid_Moves_Counter++;
    }
  }

  if(board[2][2] == active_player)
  {
    if(board[1][2] != 0 && board[2][1] != 0)
    {
      Valid_Moves_Counter++;
    }
  }

  if(board[2][0] == active_player)
  {
    if(board[1][0] != 0 && board[2][1] != 0)
    {
      Valid_Moves_Counter++;
    }
  }
  //middle cases
  if(board[1][0] == active_player)
  {
    if(board[0][0] != 0 && board[1][1] != 0 && board[2][0] != 0)
    {
      Valid_Moves_Counter++;
    }
  }

  if(board[2][1] == active_player)
  {
    if(board[2][0] != 0 && board[1][1] != 0 && board[2][2] != 0)
    {
      Valid_Moves_Counter++;
    }
  }

  if(board[1][2] == active_player)
  {
    if(board[0][2] != 0 && board[1][1] != 0 && board[2][2] != 0)
    {
      Valid_Moves_Counter++;
    }
  }

  if(board[0][1] == active_player)
  {
    if(board[0][0] != 0 && board[1][1] != 0 && board[0][2] != 0)
    {
      Valid_Moves_Counter++;
    }
  }

  //Middle Case
      if(board[1][1] == active_player)
  {
    if(board[1][0] != 0 && board[1][2] != 0 && board[2][1] != 0 && board[0][1] != 0)
    {
      Valid_Moves_Counter++;
    }
  }

  if(Valid_Moves_Counter == 3)
  {
    std::cout<< "Player "<< active_player << " has no valid moves(sucks to be you)" <<" Skipping your turn"<< std::endl;
    return true;

  }
    

    return false;

}
