#ifndef INTERPRETER_STRINGMATCHER_H
#define INTERPRETER_STRINGMATCHER_H
#include "Automaton.h"



class StringMatcher : public Automaton {
private:
    char toMatch = 0x27;
public:
    StringMatcher(): Automaton(STRING){
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
                        return inputRead;
                }
            }
        }
        return 0;
    }
};



#endif //INTERPRETER_STRINGMATCHER_H
