//
//  InfiniteString.h
//  Interpreter
//
//  Created by Jeanpierre Bendezu on 9/22/20.
//  Copyright © 2020 Jeanpierre Bendezu. All rights reserved.
//

#ifndef InfiniteString_h
#define InfiniteString_h




class InfiniteString : public Automaton {
private:
    char toMatch = 0x27;
public:
    InfiniteString(): Automaton(UNDEFINED){
    }
    int Read(const string& input){
        newLines = 0;
        int inputRead = 0;
        if(input[0] == toMatch){
            inputRead++;
            for (unsigned int i = 1; i < input.size(); i++) {
                if(input[i] == '\n'){
                    ++newLines;
                }
                inputRead++;
                if(input[i] == toMatch && input[i + 1] == toMatch){
                    inputRead++;
                    i++;
                }
                else if (input[i] == toMatch && input[i + 1] != toMatch) {
                        return 0;
                }
            }
            return inputRead;
        }
        return 0;
    }
};

#endif /* InfiniteString_h */
