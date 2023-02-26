//
//  Die.h
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#ifndef Die_h
#define Die_h

namespace cs31
{
    
// This class is completely finished and there is nothing for a CS 31 student to do here.
// The purpose of this class is to provide a random die toss
class Die
{
public:
    Die( int sides = 6 ); // by default, a six sided die
    void roll();
    int  getValue( ) const;
    void setValue( int amount );  // cheating...
private:
    int  mSides;
    int  mValue;
};

    
}
#endif /* Die_h */
