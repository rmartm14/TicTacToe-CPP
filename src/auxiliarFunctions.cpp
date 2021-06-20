#include <iostream>
#include <string>
#include <sstream>
#include "auxiliarFunctions.hpp"

std::string getToken(short numberPlays)
{
    return (numberPlays %2 == 0) ? "X" : "O";
}

bool isPicked(short line, short column, std::string board[3][3])
{
    return (board[line][column] == "") ? true : false;
}

bool checkWon(std::string board[3][3])
{
    for (size_t i = 0; i < 3; i++)
    {
        if( !isEmpty(board[i]))
        {
            if( (board[i][0] == board[i][1] ) && ( board[i][1] == board[i][2] ) )
            {
                return true;
            }
        }
        if( ( board[0][i] != "" ) || ( board[1][i] != "" ) || ( board[2][i] != "" ))
            //columns
            if( (board[0][i] == board[1][i] ) && ( board[1][i] == board[2][i] ) )
            {
                return true;
            }
        
        //lines

        
    }

    //Diag
    if(!checkDiagMay(board)){
        if( (board[0][0] == board[1][1] ) && ( board[1][1] == board[2][2] ) )
        {
                return true;
        }
    }
    if(!checkDiagMen(board)){
        if( (board[0][2] == board[1][1] ) && ( board[1][1] == board[2][0] ) )
        {
                return true;
        }
    }


    return false;
    
}
bool isEmpty (std::string line[3]){
    for (size_t i = 0; i < 3; i++)
    {
        if(line[i] == "")
        {
            return true;
        }
    }
    return false;  
}

bool checkDiagMay(std::string board[3][3])
{
    std::string diagMayor[3] = {board[0][0], board[1][1], board[2][2] };
    return (diagMayor[0] == "" || diagMayor[1] == "" || diagMayor[2] == "");
}
bool checkDiagMen(std::string board[3][3]){
    std::string diagMenor[3] = {board[0][2], board[1][1], board[2][0] };
    return (diagMenor[0] == "" || diagMenor[1] == "" || diagMenor[2] == "");
}