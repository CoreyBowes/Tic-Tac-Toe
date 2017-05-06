/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TicTacToeBoard.h
 * Author: coreybowes
 *
 * Created on March 6, 2017, 3:00 AM
 */

#ifndef TICTACTOEBOARD_H
#define TICTACTOEBOARD_H

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

class TicTacToeBoard
{
    
private:
    char Board[3][3];
    bool XsWon;
    bool OsWon;
    list<pair <int,int> > BlankSpacePositions;
    list<pair <int,int> > XPositions;
    list<pair <int,int> > OPositions;
        
public:
    TicTacToeBoard()
    {
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
    bool AddX(int Row, int Column);
    // ^Adds X to board. 0-indexed.
    bool AddO(int Row, int Column);
    // ^Adds O to board. 0-indexed.
    bool GetXsWon() {return XsWon;}
    bool GetOsWon() {return OsWon;}
    bool IsBoardFull();
    char GetSpace(int Row, int Column) {return Board[Row][Column];}
    void PrintBoard();
    void GetRandomBlankSpace(int& Row, int& Column);
    void Reset();
    void PrintSpacesLists();
    list<pair <int,int> > GetBlankSpacePositions() {return BlankSpacePositions;}
    list<pair <int,int> > GetXPositions() {return XPositions;}
    list<pair <int,int> > GetOPositions() {return OPositions;}
};

#endif /* TICTACTOEBOARD_H */

