//
//  TurnEvaluator.h
//  Project7
//
//  Created by Howard Stahl on 6/2/21.
//  Copyright © 2021 Howard Stahl. All rights reserved.
//

#ifndef TurnEvaluator_h
#define TurnEvaluator_h

#include "Player.h"

namespace cs31
{

    class TurnEvaluator
    {
    public:
        TurnEvaluator( Player human, Player computer );
        
        // the choices that are possible
        enum POSSIBILITIES { HUMANBUSTED, COMPUTERBUSTED,
                             HUMANBLACKJACK, COMPUTERBLACKJACK, BOTHHAVEBLACKJACK,
                             HUMANWON, COMPUTERWON, NOONEWON    };
        
        // TODO: Complete evaluateTurn( )
        // determine which possibility has occurred
        POSSIBILITIES evaluateTurn( ) const;
        
        // determine computer play strategy
        // return true if the computer should keep rolling its dice
        bool determineComputerStrategy() const;
        
    private:
        int mHumanTotal;
        int mComputerTotal;
        int mComputerPriorRunningTotal;
        
        // some important constants
        const int    BUSTED_TOTAL           = 22;
        const int    BLACKJACK_TOTAL        = 21;
        
    };

}



#endif /* TurnEvaluator_h */
