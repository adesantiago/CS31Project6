//
//  BJDice.cpp
//  Project7
//

#include "BJDice.h"
#include "TurnEvaluator.h"
#include <iostream>
#include "Board.h"

using namespace std;

namespace cs31
{
    // human goes first
    BJDice::BJDice() : mHuman(), mComputer(), mBoard()
    {
        
    }
    
    std::string BJDice::display( std::string msg )
    {
        using namespace std;
        std::string s( "" );
        
        s = mBoard.display();
        if (!isGameOver())
        {
            s = s + msg;
        }

        return( s );
    }

    // TODO: Play a random human roll...
    void BJDice::humanPlay( )
    {
        
        mHuman.roll();
        mHuman.addDiceToRunningTotal( );
        mBoard.updateBoardMessageForHuman( mHuman );
        // randomly roll the Human Player's dice
        // add what was rolled to the Human Player's running total
        // update the Board message for this round of play by calling:
        // mBoard.updateBoardMessageForHuman( mHuman );
    }
    

    void BJDice::humanPlay( Die d1, Die d2 )
    {
        // cheating...
        mHuman.roll( d1, d2 );
        mHuman.addDiceToRunningTotal( );
        mBoard.updateBoardMessageForHuman( mHuman );
    }

    void BJDice::humanEndTurn()
    {
        mBoard.setHumanTotal( mHuman.getRunningTotal() );
        mBoard.buildBoardMessageForHumanEndTurn();
    }
    
    // TODO: Play a random computer roll
    void BJDice::computerPlay( )
    {
        mComputer.roll();
        mComputer.addDiceToRunningTotal( );
        mBoard.updateBoardMessageForComputer( mComputer );
        // STEPS TO COMPLETE
        // randomly roll the Computer Player's dice
        // add what was rolled to the Computer Player's running total
        // update the Board message for this round of play by calling:
        // mBoard.updateBoardMessageForComputer( mComputer );
    }
    
    void BJDice::computerPlay( Die d1, Die d2 )
    {
        // cheating...
        mComputer.roll( d1, d2 );
        mComputer.addDiceToRunningTotal( );
        mBoard.updateBoardMessageForComputer( mComputer );
    }
    
    void BJDice::computerEndTurn()
    {
        mBoard.setComputerTotal( mComputer.getRunningTotal() );
        mBoard.buildBoardMessageForComputerEndTurn();
    }

    void BJDice::finishTurn()
    {
        // now that both turns have ended, figure out what happened
        TurnEvaluator evaluator( mHuman, mComputer );
        TurnEvaluator::POSSIBILITIES outcome = evaluator.evaluateTurn();
        mBoard.clearBoardMessage();
        switch (outcome) {
            case TurnEvaluator::HUMANWON:
                mHuman.wonTurn();
                mBoard.buildBoardMessageForHumanWon();
                break;
            case TurnEvaluator::HUMANBLACKJACK:
                mHuman.won21();
                mBoard.humanHitBlackJackMessage();
                break;
            case TurnEvaluator::BOTHHAVEBLACKJACK:
            case TurnEvaluator::NOONEWON:
                mBoard.nooneWonTurnMessage();
                break;
            case TurnEvaluator::HUMANBUSTED:
                mComputer.wonTurn();
                mBoard.humanBustedMessage();
                break;
            case TurnEvaluator::COMPUTERWON:
                mComputer.wonTurn();
                mBoard.buildBoardMessageForComputerWon();
                break;
            case TurnEvaluator::COMPUTERBLACKJACK:
                mComputer.won21();
                mBoard.computerHitBlackJackMessage();
                break;
            case TurnEvaluator::COMPUTERBUSTED:
                mHuman.wonTurn();
                mBoard.computerBustedMessage();
                break;
        }
        
        
        mBoard.setHumanScore( mHuman.getScore() );
        mBoard.setComputerScore( mComputer.getScore() );
        mBoard.setComputerTotal(0);
        mBoard.setHumanTotal(0);
        mBoard.setRunningTotal(0);
        mHuman.resetRunningTotal();
        mComputer.resetRunningTotal();
    }

    // TODO: complete determineGameOutcome()
    BJDice::GAMEOUTCOME  BJDice::determineGameOutcome( ) const
    {
        GAMEOUTCOME result = GAMEOUTCOME::GAMENOTOVER;
        // For now...
        if (mBoard.getHumanScore() >= 10)
        {
            result = GAMEOUTCOME::HUMANWONGAME;
        }
        if (mBoard.getComputerScore() >= 10)
        {
            result = GAMEOUTCOME::COMPUTERWONGAME;
        }
        return( result );
    }
    
    bool BJDice::isGameOver()
    {
        GAMEOUTCOME result = determineGameOutcome();
        if (result != GAMEOUTCOME::GAMENOTOVER)
        {
            if (result == GAMEOUTCOME::HUMANWONGAME)
            {
                mBoard.buildBoardMessageForHumanWon();
            }
            else if (result == GAMEOUTCOME::COMPUTERWONGAME)
            {
                mBoard.buildBoardMessageForComputerWon();
            }
        }
        return( result != GAMEOUTCOME::GAMENOTOVER );
    }

    Player BJDice::getHuman() const
    {
        return( mHuman );
    }
    
    Player BJDice::getComputer() const
    {
        return( mComputer );
    }
    
    Board  BJDice::getBoard() const
    {
        return( mBoard );
    }

    bool BJDice::computerKeepPlaying( )
    {
        TurnEvaluator evaluator( mHuman, mComputer );
        return( evaluator.determineComputerStrategy() );
    }

}
