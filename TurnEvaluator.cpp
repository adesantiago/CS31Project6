//
//  TurnEvaluator.cpp
//  Project7
//
//  Created by Howard Stahl on 6/2/21.
//  Copyright © 2021 Howard Stahl. All rights reserved.
//

#include "TurnEvaluator.h"

namespace cs31
{

TurnEvaluator::TurnEvaluator( Player human, Player computer )
{
    mHumanTotal = human.getRunningTotal();
    mComputerTotal = computer.getRunningTotal();
    mComputerPriorRunningTotal = computer.getPriorRunningTotal();
}

// TODO: complete evaluateTurn( )
// based on the player totals saved by the constructor call,
// determine which possibility has occurred
TurnEvaluator::POSSIBILITIES TurnEvaluator::evaluateTurn( ) const
{
    POSSIBILITIES result = NOONEWON;
    if ((mHumanTotal == mComputerTotal && mHumanTotal < 22 && mComputerTotal < 22) || (mHumanTotal > 21 && mComputerTotal > 21))
    {
        result = POSSIBILITIES::NOONEWON;
    }
    else if (mHumanTotal > 21)
    {
        result = POSSIBILITIES::HUMANBUSTED;
    }
    else if (mComputerTotal > 21)
    {
        result = POSSIBILITIES::COMPUTERBUSTED;
    }
    if (mHumanTotal == 21)
    {
        result = POSSIBILITIES::HUMANBLACKJACK;
    }
    else if (mComputerTotal < mHumanTotal && mHumanTotal < 22 && mComputerTotal <=22)
    {
        result = POSSIBILITIES::HUMANWON;
    }
    if (mComputerTotal == 21)
    {
        result = POSSIBILITIES::COMPUTERBLACKJACK;
    }
    else if (mHumanTotal < mComputerTotal && mHumanTotal <= 21 && mComputerTotal <=21)
    {
        result = POSSIBILITIES::COMPUTERWON;
    }
    if (mHumanTotal == 21 && mComputerTotal == 21)
    {
        result = POSSIBILITIES::BOTHHAVEBLACKJACK;
    }
//    if (mHumanTotal < mComputerTotal && mHumanTotal <= 21 && mComputerTotal <=21)
//    {
//        result = POSSIBILITIES::COMPUTERWON;
//    }
//    if (mComputerTotal < mHumanTotal && mHumanTotal < 22 && mComputerTotal <=22)
//    {
//        result = POSSIBILITIES::HUMANWON;
//    }
    return( result );
}

// should the computer keep playing?
bool TurnEvaluator::determineComputerStrategy() const
{
    bool result = true;
    // if human busted, don't bust yourself
    if (mHumanTotal > 21)
        result = false;
    // stop if the computer has won!
    if (mComputerPriorRunningTotal > mHumanTotal)
        result = false;
    // stop once you 17 or more
    if (mComputerTotal > 17)
        result = false;
    return( result );

}

}
