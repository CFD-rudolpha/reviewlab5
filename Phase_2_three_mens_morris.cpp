#include <iostream>
#include <string>
#include <cstdlib>
#include "three_mens_morris.h"

Locations_of_Moves Phase_2_GetMove(Board board, int active_player) 
/*
    same as the base one except I made sure it checks more options through the branch functions that is
    the same story for all phase two functions pretty much
    also added location type or else my brain would melt from deciphering what i was tring to do
*/
{
  Move move;
  Location origin;
  Location destination;
  Locations_of_Moves move_locations;
  do {
    std::string input;
    std::cout << "Choose a space to move from\nand a space to move to(EX: a1a2): ";
    std::getline(std::cin, input);
    if (input == "x") {
      exit(0);
    }

      move_locations = Phase_2_ParseMove(input);
      origin = move_locations.first;
      destination = move_locations.second;
    
  } while (!Phase_2_ValidMove(board, origin, destination, active_player));

  return move_locations;
}

Locations_of_Moves Phase_2_ParseMove(const std::string &input) 
/*
  Step 1: steal what teacher wrote
  step 2: change some things to upgrade it
  step 3: Profit?
*/
{
  Location origin;
  Location destination;
  Locations_of_Moves move_locations;

  if ((input.size() != 4)) 
  {
    std::cerr << "Unable to parse" << std::endl;
    origin.first = -1;
    origin.second = -1;
    destination.first = -1;
    destination.second = -1;
    move_locations.first = origin;
    move_locations.second = destination;
    return move_locations;
  }

    int from_col = input.at(0);
    int from_row = input.at(1);
    int to_col = input.at(2);
    int to_row = input.at(3);

    if (from_col == 'a') {
      origin.second = 0;
    } else if (from_col == 'b') {
      origin.second = 1;
    } else if (from_col == 'c') {
      origin.second = 2;
    } else {
      origin.second = -1;
    }


    if (to_col == 'a') {
      destination.second = 0;
    } else if (to_col == 'b') {
      destination.second = 1;
    } else if (to_col == 'c') {
      destination.second = 2;
    } else {
      destination.second = -1;
    }

  from_row = from_row - '0' - 1;
  to_row = to_row - '0' - 1;
  origin.first = from_row;
  destination.first = to_row;

  move_locations.first = origin;
  move_locations.second = destination;

  return move_locations;

}

bool Phase_2_ValidMove(Board board, Location origin, Location destination, int active_player) 
{
  if (!Phase_2_ValidSpace(origin) || !Phase_2_ValidSpace(destination)) {
    std::cerr << "Invalid selection/destination" << std::endl;
    return false;
  }
  if (!Phase_2_ValidCoordinates(board, origin, destination))
  {
    std::cerr << "Invalid Move" << std::endl;
    return false;
  }


  if (board[origin.first][origin.second] != active_player) {
    std::cerr << "Select one of your peices Please(the " << active_player << " Ones)." << std::endl;
    return false;
  }

  if (board[destination.first][destination.second] != 0) {
    std::cerr << "Destination occupied" << std::endl;
    return false;
  }
  return true;
}

bool Phase_2_ValidSpace(Location space) 
{
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

bool Phase_2_ValidCoordinates(Board board, Location origin, Location destination)
/*
    go around the board and make sure that the origin and destination are next to eachother
    if not they made an error and have to guess again
*/
{
  bool test;
  //corner cases of validity
  //top left corner
  if(origin.first == 0 && origin.second == 0)
    if(destination.first == 0 && destination.second == 1 || 
      destination.first == 1 && destination.second == 0)
    {
      test = true;
      return test;
    }
  //bottom left corner a2
  if(origin.first == 0 && origin.second == 2)
    if(destination.first == 0 && destination.second == 1 || 
      destination.first == 1 && destination.second == 2)
    {
      test = true;
      return test;
    }
    //bottom right corner
    if(origin.first == 2 && origin.second == 2)
    if(destination.first == 1 && destination.second == 2 || 
      destination.first == 2 && destination.second == 1)
    {
      test = true;
      return test;
    }
    //top right corner
    if(origin.first == 2 && origin.second == 0)
    if(destination.first == 1 && destination.second == 0 || 
      destination.first == 2 && destination.second == 1)
    {
      test = true;
      return test;
    }
    //three-way crosses
    //top middle
    if(origin.first == 1 && origin.second == 0)
    if((destination.first == 0 && destination.second == 0) || 
       (destination.first == 2 && destination.second == 0) ||
       (destination.first == 1 && destination.second == 1))
    {
      test = true;
      return test;
    }
    // left middle
    if(origin.first == 0 && origin.second == 1)
    if((destination.first == 0 && destination.second == 0) || 
       (destination.first == 0 && destination.second == 2) ||
       (destination.first == 1 && destination.second == 1))
    {
      test = true;
      return test;
    }
    //bottom middle
    if(origin.first == 1 && origin.second == 2)
    if((destination.first == 2 && destination.second == 2) || 
       (destination.first == 0 && destination.second == 2) ||
       (destination.first == 1 && destination.second == 1))
    {
      test = true;
      return test;
    }
    //right middle
    if(origin.first == 2 && origin.second == 1)
    if((destination.first == 2 && destination.second == 2) || 
       (destination.first == 2 && destination.second == 0) ||
       (destination.first == 1 && destination.second == 1))
    {
      test = true;
      return test;
    }
    //middle
        if(origin.first == 1 && origin.second == 1)
    if((destination.first == 1 && destination.second == 0) || 
       (destination.first == 0 && destination.second == 1) ||
       (destination.first == 1 && destination.second == 2) ||
        (destination.first == 2 && destination.second == 1))
    {
      test = true;
      return test;
    }

  
    test = false;
    return test;
}

void Phase_2_SetPlayerAtSpace(Board board, const int player, const Locations_of_Moves &space)
{
  Location origin = space.first;
  Location destination = space.second;

  board[origin.first][origin.second] = 0;
  board[destination.first][destination.second] = player;
}