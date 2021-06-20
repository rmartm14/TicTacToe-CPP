#include "main.hpp"
int main()
{
    std::string board[3][3];
    short election = menuStart();
    if(election == 1){
        startGame(board);
    }
    return 0;
}

void startGame(std::string board[3][3])
{
    short line, column, numberPlays;
    std::string token = "";
    bool found = false;
    bool won = false;

    line = column = numberPlays = 0;

    while(numberPlays < 9 && won == false){
        std::cout << "Put your token: " << std::endl;
        std::cout << "Which line? " << std::endl;
        std::cin >> line;
        std::cout << "Which column? " << std::endl;
        std::cin >> column;

        found = isPicked(line, column, board);
        if(found)
        {
            token = getToken(numberPlays);
            board[line][column] = token;
            printBoard(board);
            numberPlays = numberPlays + 1;
            won = checkWon(board);
        }
        
    }
    if(won){
        std::cout << "The winner is: " << token << std::endl;
    }
}


//Menu of the game
short menuStart() {
    short election = 0;
    std::string value = "";
    
    std::cout << "Welcome to TIC TAC TOE CPP edition! Pick one of the options from above" << std::endl;
    
    while(value != "1")
    {
        std::cout << "1. Start the game." << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cin >> value;
        std::stringstream(value) >> election;
        if(value == "2"){ return election;}
    }

    return election;
}

/**
 * Method that uses the board array to print the current board
 * It doesn´t return the board
 * Should be called after the moves
 */
void printBoard(std::string board[3][3])
{
    int index = 0;
    for(index = 0; index < 3; index++)
    {
        int i = 0;
        std::cout << "-------------------" << std::endl;
        for(i = 0; i < 3; i++)
        {
            std::cout << "|- " << board[index][i] << " -|";
        }
        
        std::cout << std::endl << "-------------------" << std::endl;
    }
    
}