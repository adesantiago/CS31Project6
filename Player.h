//
//  Player.h
//  BeatThat
//
//

#ifndef Player_h
#define Player_h
#include "Die.h"
#include <string>

namespace cs31
{
    
    class Player
    {
    public:
        Player();
        
        // roll the dice
        void roll( );
        void roll( Die d1, Die d2 );  // cheating...
        
        // trivial getters
        Die  getDie1( ) const;
        Die  getDie2( ) const;
        
        std::string whatWasRolled();  // for testing...
        
        // TODO: for this Player's two dies, update the running total
        void addDiceToRunningTotal( );
        
        int  getRunningTotal( ) const;
        int  getPriorRunningTotal( ) const;
        void resetRunningTotal( );
        
        int  getScore() const;
        
        // TODO: update the Player's current score based on winning a turn
        void wonTurn();
        // TODO: update the Player's current score based on hitting 21
        void won21();
    private:
        Die  mDie1, mDie2;
        int  mPriorRunningTotal;
        int  mRunningTotal;
        int  mScore;

    };
    
}

#endif /* Player_h */
