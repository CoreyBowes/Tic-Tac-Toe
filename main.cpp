/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: coreybowes
 * Project: Tic Tac Toe
 * Description: 
 *
 * Created on December 29, 2016, 11:30 PM
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <list>
#include <time.h>
#include <unistd.h>
#include "TicTacToeBoard.h"

using namespace std;

/*
 * 
 */

void PlayTicTacToePvP(TicTacToeBoard playBoard, bool bXStarts);
void PlayTicTacToePvC(TicTacToeBoard playBoard, bool bXStarts, bool bPlayerStarts, int iDifficulty);
void PlayTicTacToeCvC(TicTacToeBoard playBoard, bool bPrintGame, int iGamesToPlay, int iFirstPlayerDifficulty, int iSecondPlayerDifficulty); // Automatically plays games between two computer opponents at the given difficulties.
void PlayerMove(TicTacToeBoard& playBoard, bool bIsCurrentPlayerX);
void ComputerMove(TicTacToeBoard& playBoard, bool bIsCurrentPlayerX, int iDifficulty);

int main(int argc, char** argv) {
    TicTacToeBoard myBoard;
    string sInput="";
    srand(time(NULL));
/****
 * // Code to enter the random seed manually.
    string sRandomSeed="42";
    cout<<"Please enter a seed for the random function.\n";
    cin>>sRandomSeed;
    srand(atoi(sRandomSeed.c_str()));
****/
    bool bExit=false;
    while(!bExit)
    {
        cout<<"Welcome to Tic Tac Toe! Please enter a number to select an option: \n"
                <<"1) Play game Player vs Player\n"
                <<"2) Play game Player vs Computer\n"
                <<"3) Watch game(s) Computer vs Computer\n"
                <<"4) About\n"
                <<"5) Quit\n";
        cin>>sInput;
        if((sInput=="1"))
        {
            bool bDoesXStart=true;
            bool bExitXStarts=false;
            while(!bExitXStarts)
            {
                cout<<"Do you want X to start? (Y/N)\n";
                cin>>sInput;
                if((sInput=="Y")||(sInput=="y"))
                {
                    bDoesXStart=true;
                    bExitXStarts=true;
                }
                else if((sInput=="N")||(sInput=="n"))
                {
                    bDoesXStart=false;
                    bExitXStarts=true;                    
                }
                else
                {
                    cout<<"Invalid input, please try again.\n";
                }
            }
            PlayTicTacToePvP(myBoard, bDoesXStart);
            myBoard.Reset();
            // Play Tic-Tac-Toe            
        }
        else if((sInput=="2"))
        {
            int iDifficulty=0;
            cout<<"Please enter the difficulty level.\n"
                    <<"0: Very Easy\n"
                    <<"1: Easy (random)\n"
                    <<"2: Medium\n";
            cin>>sInput;
            if(sInput=="0")
            {
                iDifficulty=0;
            }
            else if(sInput=="1")
            {
                iDifficulty=1;
            }
            else if(sInput=="2")
            {
                iDifficulty=2;
            }
            else
            {
                cout<<"I'll take that as Very Easy.\n";
                iDifficulty=0;
            }
            bool bDoesXStart=true;
            bool bIsPlayerX=true;
            bool bDoesPlayerStart=true;
            bool bExitIsPlayerX=false;
            while(!bExitIsPlayerX)
            {                
                cout<<"Do you to play as X? (Y/N)\n";
                cin>>sInput;
                if((sInput=="Y")||(sInput=="y"))
                {
                    bIsPlayerX=true;
                    bExitIsPlayerX=true;
                }
                else if((sInput=="N")||(sInput=="n"))
                {
                    bIsPlayerX=false;
                    bExitIsPlayerX=true;                    
                }
                else
                {
                    cout<<"Invalid input, please try again.\n";
                }
            }
            bool bExitPlayerStarts=false;
            while(!bExitPlayerStarts)
            {                
                cout<<"Do you want to start? (Y/N)\n";
                cin>>sInput;
                if((sInput=="Y")||(sInput=="y"))
                {
                    bDoesPlayerStart=true;
                    bExitPlayerStarts=true;
                    if(bIsPlayerX)
                    {
                        bDoesXStart=true;
                    }
                    else
                    {
                        bDoesXStart=false;
                    }
                }
                else if((sInput=="N")||(sInput=="n"))
                {
                    bDoesPlayerStart=false;
                    bExitPlayerStarts=true;                    
                    if(bIsPlayerX)
                    {
                        bDoesXStart=false;
                    }
                    else
                    {
                        bDoesXStart=true;
                    }
                }
                else
                {
                    cout<<"Invalid input, please try again.\n";
                }
            }
            PlayTicTacToePvC(myBoard, bDoesXStart, bDoesPlayerStart, iDifficulty);
            myBoard.Reset();
        }
        else if((sInput=="3"))
        {
            int iFirstPlayerDifficulty=0;
            cout<<"Please enter the difficulty level for the player to go first.\n"
                    <<"0: Very Easy\n"
                    <<"1: Easy (random)\n"
                    <<"2: Medium\n";
            cin>>sInput;
            if(sInput=="0")
            {
                iFirstPlayerDifficulty=0;
            }
            else if(sInput=="1")
            {
                iFirstPlayerDifficulty=1;
            }
            else if(sInput=="2")
            {
                iFirstPlayerDifficulty=2;
            }
            else
            {
                cout<<"I'll take that as Very Easy.\n";
                iFirstPlayerDifficulty=0;
            }
            int iSecondPlayerDifficulty=0;
            cout<<"Please enter the difficulty level for the player to go second.\n"
                    <<"0: Very Easy\n"
                    <<"1: Easy (random)\n"
                    <<"2: Medium\n";
            cin>>sInput;
            if(sInput=="0")
            {
                iSecondPlayerDifficulty=0;
            }
            else if(sInput=="1")
            {
                iSecondPlayerDifficulty=1;
            }
            else if(sInput=="2")
            {
                iSecondPlayerDifficulty=2;
            }
            else
            {
                cout<<"I'll take that as Very Easy.\n";
                iSecondPlayerDifficulty=0;
            }
            bool bPrintGames=true;
            int iHowManyGames=0;
            bool bExitPrintGames=false;
            while(!bExitPrintGames)
            {                
                cout<<"Do you want to print the games? (Y/N)\n";
                cin>>sInput;
                if((sInput=="Y")||(sInput=="y"))
                {
                    bPrintGames=true;
                    bExitPrintGames=true;
                }
                else if((sInput=="N")||(sInput=="n"))
                {
                    bPrintGames=false;
                    bExitPrintGames=true;                    
                }
                else
                {
                    cout<<"Invalid input, please try again.\n";
                }
            }
            bool bExitHowManyGames=false;
            while(!bExitHowManyGames)
            {                
                cout<<"How many games would you like to be played? "
                        <<"(Please enter a whole number greater than zero.)\n";
                cin>>sInput;
                iHowManyGames=atoi(sInput.c_str());
                if(atoi(sInput.c_str())==0)
                {
                    cout<<"Invalid input. Returning to main menu.\n";
                }
                bExitHowManyGames=true;
            }
            PlayTicTacToeCvC(myBoard, bPrintGames, iHowManyGames, iFirstPlayerDifficulty, iSecondPlayerDifficulty);
            myBoard.Reset();
        }
        else if((sInput=="4"))
        {
            cout<<"Welcome to Tic Tac Toe! A console game where you can play "
                    <<"Tic Tac Toe against another player on the same computer "
                    <<"or against one of several computer opponents, or you can "
                    <<"watch the computer play itself. Created by Corey Bowes "
                    <<"using C++.\n\n";
        }
        else if((sInput=="5"))
        {
            bExit=true;
        }
        else
        {
            cout<<"Invalid input, please try again.\n";
        }
    }
    return 0;
}

void PlayTicTacToePvP(TicTacToeBoard playBoard, bool bXStarts)
{
    bool bGameOver=false;
    bool bIsXsTurn=bXStarts;
    while(!bGameOver)
    {
        PlayerMove(playBoard, bIsXsTurn);
        if(playBoard.GetXsWon())
        {
            cout<<"Three in a row, Tic-Tac-Toe! Xs win!\n";
            bGameOver=true;
        }
        else if(playBoard.GetOsWon())
        {
            cout<<"Three in a row, Tic-Tac-Toe! Os win!\n";
            bGameOver=true;
        }
        else if(playBoard.IsBoardFull())
        {
            cout<<"Tie game!\n";
            bGameOver=true;
        }
        bIsXsTurn=!bIsXsTurn;
        // playBoard.PrintSpacesLists(); // Debugging code.
    }    
}

void PlayTicTacToePvC(TicTacToeBoard playBoard, bool bXStarts, bool bPlayerStarts, int iDifficulty)
{
    bool bGameOver=false;
    bool bIsXsTurn=bXStarts;
    bool bIsPlayersTurn=bPlayerStarts;
    while(!bGameOver)
    {
        if(bIsPlayersTurn)
        {
            PlayerMove(playBoard, bIsXsTurn);
        }
        else
        {
            ComputerMove(playBoard, bIsXsTurn, iDifficulty);
            playBoard.PrintBoard();
        }
        if(playBoard.GetXsWon())
        {
            cout<<"Three in a row, Tic-Tac-Toe! Xs win!\n";
            bGameOver=true;
        }
        else if(playBoard.GetOsWon())
        {
            cout<<"Three in a row, Tic-Tac-Toe! Os win!\n";
            bGameOver=true;
        }
        else if(playBoard.IsBoardFull())
        {
            cout<<"Tie game!\n";
            bGameOver=true;
        }
        bIsXsTurn=!bIsXsTurn;
        bIsPlayersTurn=!bIsPlayersTurn;
        // playBoard.PrintSpacesLists(); // Debugging code
    }        
}

void PlayTicTacToeCvC(TicTacToeBoard playBoard, bool bPrintGame, int iGamesToPlay, int iFirstPlayerDifficulty, int iSecondPlayerDifficulty)
{
    int iFirstPlayerWins=0;
    int iSecondPlayerWins=0;
    int iTies=0;
    for(int i=0; i<iGamesToPlay; i++)
    {
        bool bGameOver=false;
        bool bIsXsTurn=true;
        while(!bGameOver)
        {
            if(bIsXsTurn)
            {
                ComputerMove(playBoard, bIsXsTurn, iFirstPlayerDifficulty);
            }
            else
            {
                ComputerMove(playBoard, bIsXsTurn, iSecondPlayerDifficulty);
            }
            if(bPrintGame)
            {
                // Add code here to wait for a fraction of a second?
                playBoard.PrintBoard();
            }
            if(playBoard.GetXsWon())
            {
                if(bPrintGame)
                {
                    cout<<"Three in a row, Tic-Tac-Toe! Xs win!\n";
                }
                iFirstPlayerWins++;
                bGameOver=true;
            }
            else if(playBoard.GetOsWon())
            {
                if(bPrintGame)
                {
                    cout<<"Three in a row, Tic-Tac-Toe! Os win!\n";
                }
                iSecondPlayerWins++;
                bGameOver=true;
            }
            else if(playBoard.IsBoardFull())
            {
                if(bPrintGame)
                {
                    cout<<"Tie game!\n";
                }
                iTies++;
                bGameOver=true;
            }
            bIsXsTurn=!bIsXsTurn;
            // playBoard.PrintSpacesLists(); // Debugging code
        }
        playBoard.Reset();
    }
    cout<<"First player wins: "<<iFirstPlayerWins<<", Second player wins: "
            <<iSecondPlayerWins<<", Ties: "<<iTies<<"\n";
}

void PlayerMove(TicTacToeBoard& playBoard, bool bIsCurrentPlayerX)
{
    string sTicTacToeInput;
    int iRowPlace=0;
    int iColumnPlace=0;
    bool bValidPlacement=false;
    while(!bValidPlacement)
    {
        bool bRowInputValid=false;
        while(!bRowInputValid)
        {
            if(bIsCurrentPlayerX==true)
            {
                cout<<"X Player, please enter the row on which "
                        "you wish to place (1-3).\n";
            }
            else
            {
                cout<<"O Player, please enter the row on which "
                        "you wish to place (1-3).\n";
            }
            cin>>sTicTacToeInput;
            if((atoi(sTicTacToeInput.c_str())>=1)&&(atoi(sTicTacToeInput.c_str())<=3))
            {
                bRowInputValid=true;
                iRowPlace=atoi(sTicTacToeInput.c_str())-1;
            }
            else
            {
                cout<<"Invalid input, please try again.\n";
            }
        }
        bool bColumnInputValid=false;
        while(!bColumnInputValid)
        {
            if(bIsCurrentPlayerX==true)
            {
                cout<<"X Player, please enter the column on which "
                        "you wish to place (1-3).\n";
            }
            else
            {
                cout<<"O Player, please enter the column on which "
                        "you wish to place (1-3).\n";                        
            }
            cin>>sTicTacToeInput;
            if((atoi(sTicTacToeInput.c_str())>=1)&&(atoi(sTicTacToeInput.c_str())<=3))
            {
                bColumnInputValid=true;
                iColumnPlace=atoi(sTicTacToeInput.c_str())-1;
            }
            else
            {
                cout<<"Invalid input, please try again.\n";
            }
        }
        if(bIsCurrentPlayerX)
        {
            if(playBoard.AddX(iRowPlace, iColumnPlace))
            {
                bValidPlacement=true;
            }
        }
        else
        {
            if(playBoard.AddO(iRowPlace, iColumnPlace))
            {
                bValidPlacement=true;
            }
        }
        if(!bValidPlacement)
        {
            cout<<"There is already something at that place. "
                    <<"Please make another selection.\n";
        }
        playBoard.PrintBoard();
    }
}

void ComputerMove(TicTacToeBoard& playBoard, bool bIsCurrentPlayerX, int iDifficulty)
{
    if(iDifficulty==0)
    {
        bool bMoveMade=false;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if((playBoard.GetSpace(i,j)==' ') && !bMoveMade)
                {
                    if(bIsCurrentPlayerX)
                    {
                        playBoard.AddX(i,j);
                    }
                    else
                    {
                        playBoard.AddO(i,j);                        
                    }
                    bMoveMade=true;
                }
            }
        }
    }
    else if(iDifficulty==1)
    {
        int Row=0;
        int Column=0;
        playBoard.GetRandomBlankSpace(Row, Column);
        if(bIsCurrentPlayerX)
        {
            playBoard.AddX(Row,Column);
        }
        else
        {
            playBoard.AddO(Row,Column);                        
        }
    }
    else if(iDifficulty==2)
    {
        list<pair<int,int> >::iterator FirstIterator=(playBoard.BlankSpacePositions).begin();
        list<pair<int,int> > ListToCheck=playBoard.BlankSpacePositions;
        if(bIsCurrentPlayerX)
        {
            ListToCheck=playBoard.XPositions;
        }
        else
        {
            ListToCheck=playBoard.OPositions;
        }
        FirstIterator=ListToCheck.begin();
        bool bMoveMade=false;
        for(; FirstIterator!=ListToCheck.end(); FirstIterator++)
        {
            list<pair<int,int> >::iterator SecondIterator=FirstIterator;
            SecondIterator++;
            for(; (SecondIterator!=ListToCheck.end())&&!bMoveMade; SecondIterator++)
            {
                if((*FirstIterator).first==(*SecondIterator).first)
                {
                    for(int i=0; (i<=2)&&(!bMoveMade); i++)
                    {
                        if(((*FirstIterator).second!=i)&&((*SecondIterator).second!=i))
                        {
                            if(bIsCurrentPlayerX)
                            {
                                bMoveMade=playBoard.AddX((*FirstIterator).first,i);
                            }
                            else
                            {
                                bMoveMade=playBoard.AddO((*FirstIterator).first,i);
                            }
                        }                        
                    }
                }
                else if((*FirstIterator).second==(*SecondIterator).second)
                {
                    for(int i=0; (i<=2)&&(!bMoveMade); i++)
                    {
                        if(((*FirstIterator).first!=i)&&((*SecondIterator).first!=i))
                        {
                            if(bIsCurrentPlayerX)
                            {
                                bMoveMade=playBoard.AddX(i,(*FirstIterator).second);
                            }
                            else
                            {
                                bMoveMade=playBoard.AddO(i,(*FirstIterator).second);
                            }
                        }                        
                    }                    
                }
                else if(((*FirstIterator).first==(*FirstIterator).second)&&((*SecondIterator).first==(*SecondIterator).second))
                {
                    for(int i=0; (i<=2)&&(!bMoveMade); i++)
                    {
                        if(((*FirstIterator).first!=i)&&((*SecondIterator).first!=i))
                        {
                            if(bIsCurrentPlayerX)
                            {
                                bMoveMade=playBoard.AddX(i,i);
                            }
                            else
                            {
                                bMoveMade=playBoard.AddO(i,i);
                            }
                        }                        
                    }                    
                }
                else if(((2-(*FirstIterator).first)==(*FirstIterator).second)&&((2-(*SecondIterator).first)==(*SecondIterator).second))
                {
                    for(int i=0; (i<=2)&&(!bMoveMade); i++)
                    {
                        if(((*FirstIterator).first!=i)&&((*SecondIterator).first!=i))
                        {
                            if(bIsCurrentPlayerX)
                            {
                                bMoveMade=playBoard.AddX(i,(2-i));
                            }
                            else
                            {
                                bMoveMade=playBoard.AddO(i,(2-i));
                            }
                        }                        
                    }                    
                }
            }
        }
        if(bIsCurrentPlayerX)
        {
            ListToCheck=playBoard.OPositions;
        }
        else
        {
            ListToCheck=playBoard.XPositions;
        }
        FirstIterator=ListToCheck.begin();
        for(; FirstIterator!=ListToCheck.end(); FirstIterator++)
        {
            list<pair<int,int> >::iterator SecondIterator=FirstIterator;
            SecondIterator++;
            for(; (SecondIterator!=ListToCheck.end())&&!bMoveMade; SecondIterator++)
            {
                if((*FirstIterator).first==(*SecondIterator).first)
                {
                    for(int i=0; (i<=2)&&(!bMoveMade); i++)
                    {
                        if(((*FirstIterator).second!=i)&&((*SecondIterator).second!=i))
                        {
                            if(bIsCurrentPlayerX)
                            {
                                bMoveMade=playBoard.AddX((*FirstIterator).first,i);
                            }
                            else
                            {
                                bMoveMade=playBoard.AddO((*FirstIterator).first,i);
                            }
                        }                        
                    }
                }
                else if((*FirstIterator).second==(*SecondIterator).second)
                {
                    for(int i=0; (i<=2)&&(!bMoveMade); i++)
                    {
                        if(((*FirstIterator).first!=i)&&((*SecondIterator).first!=i))
                        {
                            if(bIsCurrentPlayerX)
                            {
                                bMoveMade=playBoard.AddX(i,(*FirstIterator).second);
                            }
                            else
                            {
                                bMoveMade=playBoard.AddO(i,(*FirstIterator).second);
                            }
                        }                        
                    }                    
                }
                else if(((*FirstIterator).first==(*FirstIterator).second)&&((*SecondIterator).first==(*SecondIterator).second))
                {
                    for(int i=0; (i<=2)&&(!bMoveMade); i++)
                    {
                        if(((*FirstIterator).first!=i)&&((*SecondIterator).first!=i))
                        {
                            if(bIsCurrentPlayerX)
                            {
                                bMoveMade=playBoard.AddX(i,i);
                            }
                            else
                            {
                                bMoveMade=playBoard.AddO(i,i);
                            }
                        }                        
                    }                    
                }
                else if(((2-(*FirstIterator).first)==(*FirstIterator).second)&&((2-(*SecondIterator).first)==(*SecondIterator).second))
                {
                    for(int i=0; (i<=2)&&(!bMoveMade); i++)
                    {
                        if(((*FirstIterator).first!=i)&&((*SecondIterator).first!=i))
                        {
                            if(bIsCurrentPlayerX)
                            {
                                bMoveMade=playBoard.AddX(i,(2-i));
                            }
                            else
                            {
                                bMoveMade=playBoard.AddO(i,(2-i));
                            }
                        }                        
                    }                    
                }
            }
        }
        if(!bMoveMade)
        {
            ComputerMove(playBoard, bIsCurrentPlayerX, 1);
            return;
        }
    }
    else
    {
        cout<<"Error. Difficulty setting not valid.\n";
        ComputerMove(playBoard, bIsCurrentPlayerX, 0);
    }    
}