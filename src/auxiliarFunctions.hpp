#include <iostream>
#include <string>
#include <sstream>

std::string getToken(short numberPlays);
bool isPicked(short line, short column, std::string board[3][3]);
bool checkWon(std::string board[3][3]);
bool isEmpty(std::string line[3]);
bool checkDiagMay(std::string board[3][3]);
bool checkDiagMen(std::string board[3][3]);