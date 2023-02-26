//
//  main.cpp
//  BlackJack Dice Game Skeleton
//
//

#include <iostream>
#include <cassert>
#include "BJDice.h"


void clearScreen( );





int main()
{
    using namespace cs31;
    using namespace std;
    
    clearScreen();
    
    BJDice game;
    std::string action, prompt = "(r)oll (p)ass (q)uit: ";
    std::cout << prompt;
        
    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                // end the game...
                return( 0 );
                break;
            case 'r':
            case 'R':
                game.humanPlay();
                cout << game.display( prompt ) << endl;
                break;
            case 'p':
            case 'P':
                game.humanEndTurn();
                cout << game.display(  ) << endl;
                getline( cin, action );
                do
                {
                    game.computerPlay();
                    cout << game.display(  ) << endl;
                    getline( cin, action );
                }
                while( game.computerKeepPlaying() );
                game.computerEndTurn();
                cout << game.display(  ) << endl;
                getline( cin, action );
                game.finishTurn();
                cout << game.display( prompt ) << endl;
                break;
        }
    } while( !game.isGameOver() );
    cout << game.display(  ) << endl;

    return( 0 );
}


///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif



//#include <iostream>
//    #include <string>
//    #include <cassert>
//        #include "BJDice.h"
//        #include "Board.h"
//        #include "Player.h"
//        #include "TurnEvaluator.h"
//        #include "Die.h"
//        #include "RandomNumber.h"
//
//    using namespace std;
//
//    int main()
//    {
//           using namespace std;
//           using namespace cs31;
//
//            test code for Die
//
//           Die d1;  d1.setValue( 1 );
//           assert( d1.getValue( ) == 1 );
//           Die d2;  d2.setValue( 2 );
//           assert( d2.getValue( ) == 2 );
//           Die d3;  d3.setValue( 3 );
//           assert( d3.getValue( ) == 3 );
//           Die d4;  d4.setValue( 4 );
//           assert( d4.getValue( ) == 4 );
//           Die d5;  d5.setValue( 5 );
//           assert( d5.getValue( ) == 5 );
//           Die d6;  d6.setValue( 6 );
//           assert( d6.getValue( ) == 6 );
//
//           // test code for Player
//
//           Player p;
//           assert( p.getScore( ) == 0 );
//           p.wonTurn( );
//           assert( p.getScore( ) == 1 );
//           p.won21( );
//           assert( p.getScore( ) == 3 );
//
//           Player busted;
//           assert( busted.getScore( ) == 0 );
//           assert( busted.getRunningTotal( ) == 0 );
//           assert( busted.getPriorRunningTotal( ) == 0 );
//           busted.roll( d5, d6 );
//           assert( busted.getDie1( ).getValue( ) == 5 );
//           assert( busted.getDie2( ).getValue( ) == 6 );
//           assert( busted.getScore( ) == 0 );
//           assert( busted.getRunningTotal( ) == 0 );
//           assert( busted.getPriorRunningTotal( ) == 0 );
//           busted.addDiceToRunningTotal();
//           assert( busted.getScore( ) == 0 );
//           assert( busted.getRunningTotal( ) == 11 );
//           assert( busted.getPriorRunningTotal( ) == 0 );
//           busted.roll( d6, d5 );
//           assert( busted.getDie1( ).getValue( ) == 6 );
//           assert( busted.getDie2( ).getValue( ) == 5 );
//           busted.addDiceToRunningTotal();
//           assert( busted.getScore( ) == 0 );
//           assert( busted.getRunningTotal( ) == 22 ); // failed
//           assert( busted.getPriorRunningTotal( ) == 11 );
//
//           Player blackjack;
//           assert( blackjack.getScore( ) == 0 );
//           assert( blackjack.getRunningTotal( ) == 0 );
//           assert( blackjack.getPriorRunningTotal( ) == 0 );
//           blackjack.roll( d4, d6 );
//           blackjack.addDiceToRunningTotal();
//           assert( blackjack.getScore( ) == 0 );
//           assert( blackjack.getRunningTotal( ) == 10 );
//           assert( blackjack.getPriorRunningTotal( ) == 0 );
//           blackjack.roll( d6, d5 );
//           blackjack.addDiceToRunningTotal();
//           assert( blackjack.getScore( ) == 0 );
//           assert( blackjack.getRunningTotal( ) == 21 );
//           assert( blackjack.getPriorRunningTotal( ) == 10 );
//
//           Player seven;
//           assert( seven.getScore( ) == 0 );
//           assert( seven.getRunningTotal( ) == 0 );
//           assert( seven.getPriorRunningTotal( ) == 0 );
//           seven.roll( d6, d1 );
//           seven.addDiceToRunningTotal();
//           assert( seven.getScore( ) == 0 );
//           assert( seven.getRunningTotal( ) == 7 );
//           assert( seven.getPriorRunningTotal( ) == 0 );
//
//           Player ten;
//           assert( ten.getScore( ) == 0 );
//           assert( ten.getRunningTotal( ) == 0 );
//           assert( ten.getPriorRunningTotal( ) == 0 );
//           ten.roll( d5, d5 );
//           ten.addDiceToRunningTotal();
//           assert( ten.getScore( ) == 0 );
//           assert( ten.getRunningTotal( ) == 10 );
//           assert( ten.getPriorRunningTotal( ) == 0 );
//
//           // test code for Board
//
//           Board b;
//           assert( b.getHumanScore() == 0 );
//           assert( b.getComputerScore() == 0 );
//           assert( b.getHumanTotal() == 0 );
//           assert( b.getComputerTotal() == 0 );
//           assert( b.getRunningTotal( ) == 0 );
//
//           b.setHumanScore( 10 );
//           b.setComputerScore( 20 );
//           b.setHumanTotal( 30 );
//           b.setComputerTotal( 40 );
//           b.setRunningTotal( 50 );
//
//           assert( b.getHumanScore() == 10 );
//           assert( b.getComputerScore() == 20 );
//           assert( b.getHumanTotal() == 30 );
//           assert( b.getComputerTotal() == 40 );
//           assert( b.getRunningTotal( ) == 50 );
//
//           // test code for TurnEvaluator
//           TurnEvaluator t1( busted, seven );
//           assert( t1.evaluateTurn() == TurnEvaluator::HUMANBUSTED );
//
//           TurnEvaluator t2( ten, busted );
//           assert( t2.evaluateTurn() == TurnEvaluator::COMPUTERBUSTED );
//
//           TurnEvaluator t3( blackjack, blackjack );
//           assert( t3.evaluateTurn() == TurnEvaluator::BOTHHAVEBLACKJACK );
//
//           // test code for BJDice
//
//           BJDice game;
//           assert( game.isGameOver() == false );
//           assert( game.determineGameOutcome() == BJDice::GAMENOTOVER );
//
//           game.humanPlay(d1, d2);
//           game.humanEndTurn();
//           game.computerPlay(d6, d5);
//           game.computerEndTurn();
//           game.finishTurn();
//
//           assert( game.isGameOver() == false );
//           assert( game.determineGameOutcome() == BJDice::GAMENOTOVER );
//           assert( game.getHuman().getScore() == 0 );
//           assert( game.getComputer().getScore() == 1 );
//
//           game.humanPlay(d6, d5);
//           game.humanEndTurn();
//           game.computerPlay(d3, d6);
//           game.computerEndTurn();
//           game.finishTurn();
//           assert( game.isGameOver() == false );
//           assert( game.determineGameOutcome() == BJDice::GAMENOTOVER );
//           assert( game.getHuman().getScore() == 1 );
//           assert( game.getComputer().getScore() == 1 );
//
//           game.humanPlay(d1, d2);
//           game.humanPlay(d3, d4);
//           game.humanEndTurn();
//           game.computerPlay(d2, d1);
//           game.computerPlay(d4, d3);
//           game.computerEndTurn();
//           game.finishTurn();
//           assert( game.isGameOver() == false );
//           assert( game.determineGameOutcome() == BJDice::GAMENOTOVER );
//           assert( game.getHuman().getScore() == 1 );
//           assert( game.getComputer().getScore() == 1 );
//
//           game.humanPlay(d6, d5); // 6,5
//           game.humanPlay(d4, d6); // 4,6
//           game.humanEndTurn();
//           game.computerPlay(d3, d6);
//           game.computerEndTurn();
//           game.finishTurn();
//           assert( game.isGameOver() == false );
//           assert( game.determineGameOutcome() == BJDice::GAMENOTOVER );
//           assert( game.getHuman().getScore() == 3 ); //only incrementing 1 here //because in BJDice.cpp the switch statement for finish turn is only using wonturn() and skipping won21() // fix turnevaluator possibilities probably --> else if statement for humanwon?
//           assert( game.getComputer().getScore() == 1 );
//
//           game.humanPlay(d1, d2);
//           game.humanEndTurn();
//           game.computerPlay(d6, d5);
//           game.computerPlay(d5, d5 );
//           game.computerEndTurn();
//           game.finishTurn();
//           assert( game.isGameOver() == false );
//           assert( game.determineGameOutcome() == BJDice::GAMENOTOVER );
//           assert( game.getHuman().getScore() == 3 );
//           assert( game.getComputer().getScore() == 3 );
//
//           game.humanPlay(d6, d5);
//           game.humanPlay(d1, d2);
//           game.humanPlay(d3, d4);
//           game.humanPlay(d5, d6);
//           game.humanEndTurn();
//           game.computerPlay(d5, d6);
//           game.computerPlay(d1, d2);
//           game.computerPlay(d6, d6);
//           game.computerEndTurn();
//           game.finishTurn();
//           assert( game.isGameOver() == false );
//           assert( game.determineGameOutcome() == BJDice::GAMENOTOVER );
//           assert( game.getHuman().getScore() == 3 );
//           assert( game.getComputer().getScore() == 3 );
//           cout << "All tests passed you baddie ;)" << endl;
//           return 0;
//
//}
