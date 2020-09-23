#ifndef INTERPRETER_BLOCKMATCHER_H
#define INTERPRETER_BLOCKMATCHER_H
#include "Automaton.h"


class BlockMatcher : public Automaton {
private:
    char matchA = '#';
    char matchB = '|';
public:
    BlockMatcher(): Automaton(COMMENT){
    }
    int Read(const string& input) {
        newLines = 0;
        int inputRead = 0;
        if(input[0] == matchA && input[1] == matchB){
                for(unsigned int i = 0; i < input.size(); i++){
                    if(input[i] == '\n'){
                        ++newLines;
                    }
                    inputRead++;
                    if(input[i] == matchB && input[i+1] == matchA){
                            inputRead++;
                            return inputRead;
                    }
                }
                return 0;
        }
        else{
            if(input[0] == matchA){
                    for(unsigned int i = 0; i < input.size(); i++){
                        if(input[i] == '\n'){
                            break;
                        }
                        inputRead++;
                    }
                return inputRead;
            }
        }
        return 0;
    }
};



#endif //INTERPRETER_BLOCKMATCHER_H
