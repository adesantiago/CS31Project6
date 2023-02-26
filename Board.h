//
//  Board.h
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#ifndef Board_h
#define Board_h
#include "Player.h"
#include "Die.h"
#include <string>

namespace cs31
{
    
    class Board
    {
    public:
        Board();

        // TODO: Complete all these getters and setters
        void setHumanScore( int humanScore );
        void setComputerScore( int computerScore );
        void setHumanTotal( int humanTotal );
        void setComputerTotal( int computerTotal );
        void setRunningTotal( int runningtotal );
        int  getRunningTotal( ) const;
        int  getHumanScore( ) const;
        int  getComputerScore( ) const;
        int  getHumanTotal( ) const;
        int  getComputerTotal( ) const;

        
        void updateBoardMessageForHuman( Player human );
        void updateBoardMessageForComputer( Player computer );

        void buildBoardMessageForHumanEndTurn();
        void buildBoardMessageForComputerEndTurn();
        void buildBoardMessageForComputerWon();
        void buildBoardMessageForHumanWon();
        
        void clearBoardMessage();
        void humanHitBlackJackMessage();
        void computerHitBlackJackMessage();
        void humanWonTurnMessage();
        void computerWonTurnMessage();
        void humanBustedMessage();
        void computerBustedMessage();
        void nooneWonTurnMessage();
        
        std::string display() const;
    private:
        int mHumanScore;
        int mComputerScore;
        int mHumanTotal;
        int mComputerTotal;
        int mRunningTotal;
        
        
        // Various Board messages
        const std::string HUMAN_BUSTED           = "Human Busted!\n";
        const std::string COMPUTER_BUSTED        = "Computer Busted!\n";
        const std::string HUMAN_HIT_BLACKJACK    = "Human Hit BlackJack!\n";
        const std::string COMPUTER_HIT_BLACKJACK = "Computer Hit BlackJack!\n";
        const std::string HUMAN_WON_TURN         = "Human Won This Turn!\n";
        const std::string COMPUTER_WON_TURN      = "Computer Won This Turn!\n";
        const std::string NOONE_WON_TURN         = "No One Won This Turn!\n";
        const std::string COMPUTER_TURN_ENDED    = "Computer Turn Ended!";
        const std::string HUMAN_TURN_ENDED       = "Human Turn Ended!";
        const std::string HUMAN_WON              = "Human Won The Game!";
        const std::string COMPUTER_WON           = "Computer Won The Game!";
        
        std::string mBoardMessage;
        void buildBoardMessage( bool forHuman, Die d1, Die d2, int priorRunningTotal );
        

    };
}

#endif /* Board_h */
