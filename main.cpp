#include <iostream>
#include <string>
#include <cstdlib>
#include "three_mens_morris.h"



int main() {
  Board board;
  
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      board[i][j] = 0;
    }
  }

  std::string input;
  int turn_cycle = 0;
  const int player_turn = 1;
  const int computer_turn = 2;
  bool over = false;

  while (!over) {
    std::cout<<"Welcome to turn "<< turn_cycle + 1 << " you mighty warriors"<<std::endl;

    A_Turn(board,turn_cycle,player_turn);
    over = check_win(board, player_turn);
    if(over)
      break;

    A_Turn(board, turn_cycle, computer_turn);
    over = check_win(board, computer_turn);
    if(over)
      break;
  
    turn_cycle ++;
    
  }
  
}

