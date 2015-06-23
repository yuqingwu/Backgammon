#pragma once
//Four macros detect five children together into line direction
#define HORIZON         0
#define VERTICAL            1
#define LEFTBOTTOMTORIGHTTOP    2
#define LEFTTOPTORIGHTBOTTOM    3
 
#include"ChessBoard.h"
#include<iostream>
using namespace std;
#include<string>
 
class Player
{
private:
    string m_name;
    char m_chessType;
    int m_x;
    int m_y;
    ChessBoard* m_ptBoard;
public:
    Player(string name,char chessType):m_name(name),m_chessType(chessType),m_ptBoard(NULL){}
    void attachToBoard(ChessBoard* ptBoard){m_ptBoard=ptBoard;}
    bool isInChessBoard(int x,int y);
    bool isLine(int x,int y);
    bool isWin();
    void setChess();
};
