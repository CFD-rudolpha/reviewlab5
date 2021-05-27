#include <iostream>
#include <string>
#include <cstdlib>
#include<ctime>
#include "three_mens_morris.h"


Move AI_Move(Board board)
/*
    wife: "Where have you been I havnt seen you in a while"
    Me: Grunting noises and terror at a voice that isnt a number
    wife: closes door
*/
{
    Move move;
    Board test_board;
    
    // I want to win section
    //A 
    if((board[0][0] == 2 && board[1][0] == 2) || (board[2][1] == 2 && board[2][2] == 2))
    {
        move.first = 2;
        move.second = 0;
        if(AI_ValidMove(board, move))
            return move;
    }
    if((board[0][0] == 2 && board[2][0] == 2) || (board[1][1] == 2 && board[1][2] == 2))
    {
        move.first = 1;
        move.second = 0;
        if(AI_ValidMove(board, move))
            return move;
    }
    if((board[1][0] == 2 && board[2][0] == 2) || (board[0][1] == 2 && board[0][2] == 2))
    {
        move.first = 0;
        move.second = 0;
        if(AI_ValidMove(board, move))
            return move;
    }
    //B
    if((board[1][1] == 2 && board[2][1] == 2) || (board[0][2] == 2 && board[0][0] == 2))
    {
        move.first = 0;
        move.second = 1;
        if(AI_ValidMove(board, move))
            return move;
    }
    if((board[0][1] == 2 && board[2][1] == 2) || (board[1][0] == 2 && board[1][2] == 2))
    {
        move.first = 1;
        move.second = 1;
        if(AI_ValidMove(board, move))
            return move;
    }
    if((board[0][1] == 2 && board[1][1] == 2) || (board[2][0] == 2 && board[2][2] == 2))
    {
        move.first = 2;
        move.second = 1;
        if(AI_ValidMove(board, move))
            return move;
    }
    //C
    if((board[0][0] == 2 && board[0][1] == 2) || (board[1][2] == 2 && board[2][2] == 2))
    {
        move.first = 0;
        move.second = 2;
        if(AI_ValidMove(board, move))
            return move;
    }
    if((board[1][0] == 2 && board[1][1] == 2) || (board[0][2] == 2 && board[2][2] == 2))
    {
        move.first = 1;
        move.second = 2;
        if(AI_ValidMove(board, move))
            return move;
    }
    if((board[0][2] == 2 && board[1][2] == 2) || (board[2][1] == 2 && board[2][0] == 2))
    {
        move.first = 2;
        move.second = 2;
        if(AI_ValidMove(board, move))
            return move;
    }


    //I do not want to lose section 
    //A 
    if((board[0][0] == 1 && board[1][0] == 1) || (board[2][1] == 1 && board[2][2] == 1))
    {
        move.first = 2;
        move.second = 0;
        if(AI_ValidMove(board, move))
            return move;
    }
    if((board[0][0] == 1 && board[2][0] == 1) || (board[1][1] == 1 && board[1][2] == 1))
    {
        move.first = 1;
        move.second = 0;
        if(AI_ValidMove(board, move))
            return move;
    }
    if((board[1][0] == 1 && board[2][0] == 1) || (board[0][1] == 1 && board[0][2] == 1))
    {
        move.first = 0;
        move.second = 0;
        if(AI_ValidMove(board, move))
            return move;
    }
    //B
    if((board[1][1] == 1 && board[2][1] == 1) || (board[0][2] == 1 && board[0][0] == 1))
    {
        move.first = 0;
        move.second = 1;
        if(AI_ValidMove(board, move))
            return move;
    }
    if((board[0][1] == 1 && board[2][1] == 1) || (board[1][0] == 1 && board[1][2] == 1))
    {
        move.first = 1;
        move.second = 1;
        if(AI_ValidMove(board, move))
            return move;
    }
    if((board[0][1] == 1 && board[1][1] == 1) || (board[2][0] == 1 && board[2][2] == 1))
    {
        move.first = 2;
        move.second = 1;
        if(AI_ValidMove(board, move))
            return move;
    }
    //C
    if((board[0][0] == 1 && board[0][1] == 1) || (board[1][2] == 1 && board[2][2] == 1))
    {
        move.first = 0;
        move.second = 2;
        if(AI_ValidMove(board, move))
            return move;
    }
    if((board[1][0] == 1 && board[1][1] == 1) || (board[0][2] == 1 && board[2][2] == 1))
    {
        move.first = 1;
        move.second = 2;
        if(AI_ValidMove(board, move))
            return move;
    }
    if((board[0][2] == 1 && board[1][2] == 1) || (board[2][1] == 1 && board[2][0] == 1))
    {
        move.first = 2;
        move.second = 2;
        if(AI_ValidMove(board, move))
            return move;
    }
    
    return Random_Move_Generator(board, move);

}

Locations_of_Moves Phase_2_AI_Move(Board board)
/*
    me: "Its simple we just try to account for every single outcome and make the computer do that"
    a reasonable person: "That spounds difficult and dumb"
    Me: "Yes but I did it any ways"
    Reasonable Person: "But doesnt this code not account for moving away from a spot and then you moving there
    thus winning and breaking one of the rules the professor set for you"
    Me: "Why are you here again?"
*/
{
     Location origin;
     Location destination;
     Locations_of_Moves move_locations;

    //I want to win section
     //A 
    if((board[0][0] == 2 && board[1][0] == 2) && board[2][1] == 2)
    {
        origin.first = 2;
        origin.second = 1;
        destination.first = 2;
        destination.second = 0;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[2][1] == 2 && board[2][2] == 2 && board[1][0] == 2))
    {
        origin.first = 1;
        origin.second = 0;
        destination.first = 2;
        destination.second = 0;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[0][0] == 2 && board[2][0] == 2 && board[1][1] == 2))
    {
        origin.first = 1;
        origin.second = 1;
        destination.first = 1;
        destination.second = 0;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[1][1] == 2 && board[1][2] == 2 && board[0][0] == 2))
    {
        origin.first = 0;
        origin.second = 0;
        destination.first = 1;
        destination.second = 0;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
        if((board[1][1] == 2 && board[1][2] == 2 && board[2][0] == 2))
    {
        origin.first = 2;
        origin.second = 0;
        destination.first = 1;
        destination.second = 0;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[1][0] == 2 && board[2][0] == 2 && board[0][1]  == 2))
    {
        origin.first = 0;
        origin.second = 1;
        destination.first = 0;
        destination.second = 0;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[0][1] == 2 && board[0][2] == 2 && board[1][0]  == 2))
    {
        origin.first = 1;
        origin.second = 0;
        destination.first = 0;
        destination.second = 0;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }

    //B
    if((board[1][1] == 2 && board[2][1] == 2 && board[0][0]  == 2))
    {
        origin.first = 0;
        origin.second = 0;
        destination.first = 0;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[1][1] == 2 && board[2][1] == 2 && board[0][2]  == 2))
    {
        origin.first = 0;
        origin.second = 2;
        destination.first = 0;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[0][2] == 2 && board[0][0] == 2 && board[1][1]  == 2))
    {
        origin.first = 1;
        origin.second = 1;
        destination.first = 0;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[0][1] == 2 && board[2][1] == 2 && board[1][2]  == 2))
    {
        origin.first = 1;
        origin.second = 2;
        destination.first = 1;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[0][1] == 2 && board[2][1] == 2 && board[1][0]  == 2))
    {
        origin.first = 1;
        origin.second = 0;
        destination.first = 1;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[1][0] == 2 && board[1][2] == 2 && board[0][1]  == 2))
    {
        origin.first = 0;
        origin.second = 1;
        destination.first = 1;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[1][0] == 2 && board[1][2] == 2 && board[2][1]  == 2))
    {
        origin.first = 2;
        origin.second = 1;
        destination.first = 1;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[0][1] == 2 && board[1][1] == 2 && board[2][0]  == 2))
    {
        origin.first = 2;
        origin.second = 0;
        destination.first = 2;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[0][1] == 2 && board[1][1] == 2 && board[2][2]  == 2))
    {
        origin.first = 2;
        origin.second = 2;
        destination.first = 2;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[2][0] == 2 && board[2][2] == 2 && board[1][1]  == 2))
    {
        origin.first = 1;
        origin.second = 1;
        destination.first = 2;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }

    //C
    if((board[0][0] == 2 && board[0][1] == 2 && board[1][2]  == 2))
    {
        origin.first = 1;
        origin.second = 2;
        destination.first = 0;
        destination.second = 2;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[1][2] == 2 && board[2][2] == 2 && board[0][1]  == 2))
    {
        origin.first = 0;
        origin.second = 1;
        destination.first = 0;
        destination.second = 2;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[1][0] == 2 && board[1][1] == 2 && board[0][2]  == 2))
    {
        origin.first = 0;
        origin.second = 2;
        destination.first = 1;
        destination.second = 2;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[1][0] == 2 && board[1][1] == 2 && board[2][2]  == 2))
    {
        origin.first = 2;
        origin.second = 2;
        destination.first = 1;
        destination.second = 2;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[0][2] == 2 && board[2][2] == 2 && board[1][1]  == 2))
    {
        origin.first = 1;
        origin.second = 1;
        destination.first = 1;
        destination.second = 2;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[0][2] == 2 && board[1][2] == 2 && board[2][1]  == 2))
    {
        origin.first = 2;
        origin.second = 1;
        destination.first = 2;
        destination.second = 2;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[2][1] == 2 && board[2][0] == 2 && board[1][2]  == 2))
    {
        origin.first = 1;
        origin.second = 2;
        destination.first = 2;
        destination.second = 2;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    //I do not want to lose section
    //A 
    if((board[0][0] == 1 && board[1][0] == 1) && board[2][1] == 2)
    {
        origin.first = 2;
        origin.second = 1;
        destination.first = 2;
        destination.second = 0;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[2][1] == 1 && board[2][2] == 1 && board[1][0] == 2))
    {
        origin.first = 1;
        origin.second = 0;
        destination.first = 2;
        destination.second = 0;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[0][0] == 1 && board[2][0] == 1 && board[1][1] == 2))
    {
        origin.first = 1;
        origin.second = 1;
        destination.first = 1;
        destination.second = 0;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[1][1] == 1 && board[1][2] == 1 && board[0][0] == 2))
    {
        origin.first = 0;
        origin.second = 0;
        destination.first = 1;
        destination.second = 0;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
        if((board[1][1] == 1 && board[1][2] == 1 && board[2][0] == 2))
    {
        origin.first = 2;
        origin.second = 0;
        destination.first = 1;
        destination.second = 0;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[1][0] == 1 && board[2][0] == 1 && board[0][1]  == 2))
    {
        origin.first = 0;
        origin.second = 1;
        destination.first = 0;
        destination.second = 0;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[0][1] == 1 && board[0][2] == 1 && board[1][0]  == 2))
    {
        origin.first = 1;
        origin.second = 0;
        destination.first = 0;
        destination.second = 0;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }

    //B
    if((board[1][1] == 1 && board[2][1] == 1 && board[0][0]  == 2))
    {
        origin.first = 0;
        origin.second = 0;
        destination.first = 0;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[1][1] == 1 && board[2][1] == 1 && board[0][2]  == 2))
    {
        origin.first = 0;
        origin.second = 2;
        destination.first = 0;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[0][2] == 1 && board[0][0] == 1 && board[1][1]  == 2))
    {
        origin.first = 1;
        origin.second = 1;
        destination.first = 0;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[0][1] == 1 && board[2][1] == 1 && board[1][2]  == 2))
    {
        origin.first = 1;
        origin.second = 2;
        destination.first = 1;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[0][1] == 1 && board[2][1] == 1 && board[1][0]  == 2))
    {
        origin.first = 1;
        origin.second = 0;
        destination.first = 1;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[1][0] == 1 && board[1][2] == 1 && board[0][1]  == 2))
    {
        origin.first = 0;
        origin.second = 1;
        destination.first = 1;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[1][0] == 1 && board[1][2] == 1 && board[2][1]  == 2))
    {
        origin.first = 2;
        origin.second = 1;
        destination.first = 1;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[0][1] == 1 && board[1][1] == 1 && board[2][0]  == 2))
    {
        origin.first = 2;
        origin.second = 0;
        destination.first = 2;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[0][1] == 1 && board[1][1] == 1 && board[2][2]  == 2))
    {
        origin.first = 2;
        origin.second = 2;
        destination.first = 2;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[2][0] == 1 && board[2][2] == 1 && board[1][1]  == 2))
    {
        origin.first = 1;
        origin.second = 1;
        destination.first = 2;
        destination.second = 1;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }

    //C
    if((board[0][0] == 1 && board[0][1] == 1 && board[1][2]  == 2))
    {
        origin.first = 1;
        origin.second = 2;
        destination.first = 0;
        destination.second = 2;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[1][2] == 1 && board[2][2] == 1 && board[0][1]  == 2))
    {
        origin.first = 0;
        origin.second = 1;
        destination.first = 0;
        destination.second = 2;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[1][0] == 1 && board[1][1] == 1 && board[0][2]  == 2))
    {
        origin.first = 0;
        origin.second = 2;
        destination.first = 1;
        destination.second = 2;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[1][0] == 1 && board[1][1] == 1 && board[2][2]  == 2))
    {
        origin.first = 2;
        origin.second = 2;
        destination.first = 1;
        destination.second = 2;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[0][2] == 1 && board[2][2] == 1 && board[1][1]  == 2))
    {
        origin.first = 1;
        origin.second = 1;
        destination.first = 1;
        destination.second = 2;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[0][2] == 1 && board[1][2] == 1 && board[2][1]  == 2))
    {
        origin.first = 2;
        origin.second = 1;
        destination.first = 2;
        destination.second = 2;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }
    if((board[2][1] == 1 && board[2][0] == 1 && board[1][2]  == 2))
    {
        origin.first = 1;
        origin.second = 2;
        destination.first = 2;
        destination.second = 2;
        move_locations.first = origin;
        move_locations.second = destination;
        std::cout<<"origin "<<origin.first<<origin.second<<" Destination "<<destination.first<<destination.second<<std::endl;
        if(AI_Phase_2_ValidMove(board, origin, destination))
            return move_locations;
    }

    return Phase_2_Random_Move_Generator(board);
}

Locations_of_Moves Phase_2_Random_Move_Generator(Board board)
/*
    The couts were for testing but i decided i liked them so i kept them(also help I cannot get the debugger
    to work)
*/
{
    Locations_of_Moves move_locations;
    srand(time(0));
    Location origin;
    Location destination;
    do
    {
        origin.first = rand()%3;
        origin.second = rand()%3;
        destination.first = rand()%3;
        destination.second = rand()%3;
        
    } while ((!AI_Phase_2_ValidMove(board, origin, destination)));
    std::cout<<"Random: "<<"origin "<< origin.first<<origin.second<<" Destination "<< destination.first<<destination.second<<std::endl;
    move_locations.first = origin;
    move_locations.second = destination;
    return move_locations;

}

Move Random_Move_Generator(Board board, Move move)
{

    srand(time(0));
    do
    {
        move.first = rand()%3;
        move.second = rand()%3;
        
    } while (board[move.first][move.second] != 0 && !AI_ValidMove(board, move));

    return move;
}

bool AI_Phase_2_ValidMove(Board board, Location origin, Location destination) 
/*
    same as the base one without the warning becasue frankly my dear, my computer dosnt give a darn
*/
{
    int active_player = 2;
    if (!AI_Phase_2_ValidSpace(origin) || !AI_Phase_2_ValidSpace(destination)) {
      return false;
    }
    if (!Phase_2_ValidCoordinates(board, origin, destination))
    {
      return false;
    }


    if (board[origin.first][origin.second] != active_player) {
      return false;
    }

    if (board[destination.first][destination.second] != 0) {
      return false;
    }
    return true;
    }

bool AI_Phase_2_ValidSpace(Location space) 
{
  int col = space.first;
  int row = space.second;

  if (col < 0 || col > 2) {
    return false;
  }
  if (row < 0 || row > 2) {
    return false;
  }

  return true;
}

bool AI_ValidMove(Board board, Move move) 
{
  if (!AI_ValidSpace(move)) {
    return false;
  }

  if (board[move.first][move.second] != 0 ) {
    return false;
  }

  return true;
}

bool AI_ValidSpace(Move space) 
{
  int col = space.first;
  int row = space.second;

  if (col < 0 || col > 2) {
    return false;
  }
  if (row < 0 || row > 2) {
    return false;
  }

  return true;
}

