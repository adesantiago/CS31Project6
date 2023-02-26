//
//  Board.cpp
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Board.h"


namespace cs31
{
    Board::Board() : mHumanScore(0), mComputerScore(0), mHumanTotal(0), mComputerTotal(0), mRunningTotal(0)
    {

    }

    // TODO: Complete all these getters and setters
    void Board::setHumanScore( int humanScore )
    {
        mHumanScore = humanScore;
    }

    void Board::setComputerScore( int computerScore )
    {
        mComputerScore = computerScore;
    }

    void Board::setHumanTotal( int humanTotal )
    {
        mHumanTotal = humanTotal;
    }

    void Board::setComputerTotal( int computerTotal )
    {
        mComputerTotal = computerTotal;
    }


    void Board::setRunningTotal( int runningtotal )
    {
        mRunningTotal = runningtotal;
    }

    int  Board::getRunningTotal( ) const
    {
        return(mRunningTotal);
    }

    int  Board::getHumanScore( ) const
    {
        // For now...
        return( mHumanScore );
    }

    int  Board::getComputerScore( ) const
    {
        // For now...
        return( mComputerScore );
    }

    int  Board::getHumanTotal( ) const
    {
        // For now...
        return( mHumanTotal );
    }

    int  Board::getComputerTotal( ) const
    {
        // For now...
        return( mComputerTotal );
    }

    std::string Board::display( ) const
    {
        std::string s = "\n\n\t\t   --BlackJack Dice Game--\n";
        
        s += "\n";
        s += "\t";
        s += "Human Score: ";
        s += std::to_string( mHumanScore );
        s += "\t\t";
        s += "Computer Score: ";
        s += std::to_string( mComputerScore );
        s += "\n";
        s += "\t";
        s += "Human Total: ";
        s += std::to_string( mHumanTotal );
        s += "\t\t";
        s += "Computer Total: ";
        s += std::to_string( mComputerTotal );
        s += "\n";
        s += "\n\n";
        s += "Running Total: ";
        s += std::to_string( mRunningTotal );
        s += "\n\n";
        s += mBoardMessage;
        s += "\n\n";
        return( s );
    }
    

    void Board::updateBoardMessageForHuman( Player human )
    {
        setRunningTotal( human.getRunningTotal() );
        buildBoardMessage( true, human.getDie1(), human.getDie2(), human.getPriorRunningTotal() );
    }

    void Board::updateBoardMessageForComputer( Player computer )
    {
        setRunningTotal( computer.getRunningTotal() );
        buildBoardMessage( false, computer.getDie1(), computer.getDie2(), computer.getPriorRunningTotal() );
    }

    void Board::buildBoardMessage( bool forHuman, Die d1, Die d2, int priorRunningTotal )
    {
        if (forHuman)
        {
            // once the total hits 16, only mDie1 get added in...
            if (priorRunningTotal >= 16)
            {
                mBoardMessage = "Human Die1: " + std::to_string( d1.getValue() );
            }
            else
            {
                mBoardMessage = "Human Die1: " + std::to_string( d1.getValue() ) + "\tHuman Die2: " + std::to_string( d2.getValue() );
            }
        }
        else
        {
            // once the total hits 16, only mDie1 get added in...
            if (priorRunningTotal >= 16)
            {
                mBoardMessage = "Computer Die1: " + std::to_string( d1.getValue() );
            }
            else
            {
                mBoardMessage = "Computer Die1: " + std::to_string( d1.getValue() ) + "\tComputer Die2: " + std::to_string( d2.getValue() );
            }
        }
    }

    void Board::buildBoardMessageForHumanEndTurn()
    {
        mBoardMessage = HUMAN_TURN_ENDED;
    }
    
    void Board::buildBoardMessageForComputerEndTurn()
    {
        mBoardMessage = COMPUTER_TURN_ENDED;
    }

    void Board::buildBoardMessageForComputerWon()
    {
        mBoardMessage = COMPUTER_WON;
    }

    void Board::buildBoardMessageForHumanWon()
    {
        mBoardMessage = HUMAN_WON;
    }

    void Board::clearBoardMessage()
    {
        mBoardMessage = "";
    }

    void Board::humanHitBlackJackMessage()
    {
        mBoardMessage += HUMAN_HIT_BLACKJACK;
    }

    void Board::computerHitBlackJackMessage()
    {
        mBoardMessage += COMPUTER_HIT_BLACKJACK;
    }

    void Board::humanWonTurnMessage()
    {
        mBoardMessage += HUMAN_WON_TURN;
    }

    void Board::computerWonTurnMessage()
    {
        mBoardMessage += COMPUTER_WON_TURN;
    }

    void Board::humanBustedMessage()
    {
        mBoardMessage += HUMAN_BUSTED;
    }

    void Board::computerBustedMessage()
    {
        mBoardMessage += COMPUTER_BUSTED;
    }

    void Board::nooneWonTurnMessage()
    {
        mBoardMessage += NOONE_WON_TURN;
    }

}
