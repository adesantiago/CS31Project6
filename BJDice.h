//
//  BJDice.h
//  Project7
//

#ifndef BJDice_h
#define BJDice_h

#include <string>
#include "Die.h"
#include "Player.h"
#include "Board.h"

namespace cs31
{

    class BJDice
    {
    public:
        BJDice();
        
        // the possible states of the game
        enum GAMEOUTCOME { HUMANWONGAME, COMPUTERWONGAME, GAMENOTOVER };
        
        std::string display( std::string msg = "" );

        // TODO: Play a random human roll...
        void humanPlay( );
        void humanPlay( Die d1, Die d2 );  // cheating...
        // called to mark the end of the human's turn
        void humanEndTurn( );
        
        // TODO: Play a random computer roll...
        void computerPlay( );
        void computerPlay( Die d1, Die d2 ); // cheating...
        // called to mark the end of the computer's turn
        void computerEndTurn( );
        // should the computer keep playing?
        bool computerKeepPlaying( );

        // called to mark end of both player's turns
        // figure out what happened
        void finishTurn();
        // TODO: what is the current state of the game?
        GAMEOUTCOME determineGameOutcome( ) const;
        bool isGameOver();
        
        // to test the state of the game...
        Player getHuman() const;
        Player getComputer() const;
        Board  getBoard() const;
    private:
        Player      mHuman;
        Player      mComputer;
        Board       mBoard;
        
        // some important constants
        const int    REQUIRED_WINNING_SCORE = 10;

    };

}


#endif /* BJDice */
