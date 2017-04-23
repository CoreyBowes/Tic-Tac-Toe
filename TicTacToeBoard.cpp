/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TicTacToeBoard.cpp
 * Author: coreybowes
 * 
 * Created on March 6, 2017, 3:00 AM
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <list>
#include "TicTacToeBoard.h"

using namespace std;

void TicTacToeBoard::PrintBoard()
{
    cout<<Board[0][0]<<Board[0][1]<<Board[0][2]<<"\n"<<Board[1][0]<<
            Board[1][1]<<Board[1][2]<<"\n"<<Board[2][0]<<Board[2][1]<<
            Board[2][2]<<"\n";
}

bool TicTacToeBoard::AddX(int Row, int Column)
{
    if(Board[Row][Column]!=' ')
    {
        return false;
    }
    Board[Row][Column]='X';
    XPositions.push_back(make_pair(Row, Column));
    BlankSpacePositions.remove(make_pair(Row, Column));
    // Need to check whether Xs won.
    if((Board[Row][0]=='X')&&(Board[Row][1]=='X')&&(Board[Row][2]=='X'))
    {
        XsWon=true;
    }
    else if((Board[0][Column]=='X')&&(Board[1][Column]=='X')&&(Board[2][Column]=='X'))
    {
        XsWon=true;
    }
    else if((Board[0][0]=='X')&&(Board[1][1]=='X')&&(Board[2][2]=='X'))
    {
        XsWon=true;
    }
    else if((Board[0][2]=='X')&&(Board[1][1]=='X')&&(Board[2][0]=='X'))
    {
        XsWon=true;
    }
    return true;
}

bool TicTacToeBoard::AddO(int Row, int Column)
{
    if(Board[Row][Column]!=' ')
    {
        return false;
    }
    Board[Row][Column]='O';
    OPositions.push_back(make_pair(Row, Column));
    BlankSpacePositions.remove(make_pair(Row, Column));
    // Need to check whether Os won.
    if((Board[Row][0]=='O')&&(Board[Row][1]=='O')&&(Board[Row][2]=='O'))
    {
        OsWon=true;
    }
    else if((Board[0][Column]=='O')&&(Board[1][Column]=='O')&&(Board[2][Column]=='O'))
    {
        OsWon=true;
    }
    else if((Board[0][0]=='O')&&(Board[1][1]=='O')&&(Board[2][2]=='O'))
    {
        OsWon=true;
    }
    else if((Board[0][2]=='O')&&(Board[1][1]=='O')&&(Board[2][0]=='O'))
    {
        OsWon=true;
    }
    return true;
}

bool TicTacToeBoard::IsBoardFull()
{
    for(int i=0; i<=2; i++)
    {
        for(int j=0; j<=2; j++)
        {
            if(Board[i][j]==' ')
            {
                return false;
            }
        }
    }
    return true;
}

void TicTacToeBoard::GetRandomBlankSpace(int& Row, int& Column)
{
    list<pair<int,int> >::iterator MyIterator=BlankSpacePositions.begin();
    int RandomPosition=rand()%BlankSpacePositions.size();
    for(int i=0; i<RandomPosition; i++)
    {
        MyIterator++;
    }
    Row=(*MyIterator).first;
    Column=(*MyIterator).second;
}

void TicTacToeBoard::Reset()
{
    BlankSpacePositions.clear();
    XPositions.clear();
    OPositions.clear();
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            Board[i][j]=' ';
            BlankSpacePositions.push_back(make_pair(i,j));
        }
    }
    XsWon=false;
    OsWon=false;
}

void TicTacToeBoard::PrintSpacesLists()
{
    list<pair<int,int> >::iterator MyIterator=BlankSpacePositions.begin();
    cout << "Blank spaces: " << "\n";
    for(MyIterator=BlankSpacePositions.begin(); MyIterator!=BlankSpacePositions.end(); MyIterator++)
    {
        cout << (*MyIterator).first << ", " << (*MyIterator).second << "\n";
    }
    cout << "X spaces: " << "\n";
    for(MyIterator=XPositions.begin(); MyIterator!=XPositions.end(); MyIterator++)
    {
        cout << (*MyIterator).first << ", " << (*MyIterator).second << "\n";
    }
    cout << "O spaces: " << "\n";
    for(MyIterator=OPositions.begin(); MyIterator!=OPositions.end(); MyIterator++)
    {
        cout << (*MyIterator).first << ", " << (*MyIterator).second << "\n";
    }
}



