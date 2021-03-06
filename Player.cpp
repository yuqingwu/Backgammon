#include"Player.h"
 
bool Player::isInChessBoard(int x,int y)
{
    if(x<ROW-1 && x>0 && y<COL-1 && y>0)
        return true;
    else
        return false;
}

bool Player::isLine(int x,int y)
{
    for(int direc=HORIZON;direc<=LEFTTOPTORIGHTBOTTOM;direc++)//Four directions, expediency
    {
        int tempX,tempY,cnt=1;
        for(int i=-4;i<=4;i++)
        {
            if(i==0)continue;//At this point the cycle again equivalent to doing nothing
            switch(direc)
            {
            case HORIZON:
                tempX=x;    tempY=y+i;      break;
            case VERTICAL:  
                tempX=x+i;  tempY=y;        break;
            case LEFTBOTTOMTORIGHTTOP:
                tempX=x-i;  tempY=y+i;      break;
            case LEFTTOPTORIGHTBOTTOM:
                tempX=x+i;  tempY=y+i;      break;
            }
            if(isInChessBoard(tempX,tempY) && m_ptBoard->m_cSquare[tempX][tempY]==m_chessType)
                cnt++;
            else
                cnt=0;
            if(cnt==5)//Five children into the line
                return true;
        }
    }return false;
}
 
void Player::setChess()
{   
    cout<<"Enter Players"<<m_name<<"The x and y coordinates："<<endl;
    cin>>m_x>>m_y;
    while(cin.fail() || m_ptBoard->m_cSquare[m_x][m_y]!=' ')//Int variable input is not on an existing piece or this location
    {
        cout<<"You make a mistake, enter the player again"<<m_name<<"The x and y coordinates："<<endl;
        cin.clear();    //Clear fail status  
        cin.sync();   //Clear Buffer
        cin>>m_x>>m_y;
    }
    if(isInChessBoard(m_x,m_y))
        m_ptBoard->m_cSquare[m_x][m_y]=m_chessType;  
}
 
bool Player::isWin()
{   
    return isLine(m_x,m_y)?true:false;
}
