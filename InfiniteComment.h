//
//  InfiniteComment.h
//  Interpreter
//
//  Created by Jeanpierre Bendezu on 9/22/20.
//  Copyright © 2020 Jeanpierre Bendezu. All rights reserved.
//

#ifndef InfiniteComment_h
#define InfiniteComment_h

class InfiniteComment : public Automaton {
private:
    char matchA = '#';
    char matchB = '|';
public:
    InfiniteComment(): Automaton(UNDEFINED){
    }
    int Read(const string& input) {
        int inputRead = 0;
        if(input[0] == matchA && input[1] == matchB){
                for(unsigned int i = 0; i < input.size(); i++){
                    if(input[i] == '\n'){
                        ++newLines;
                    }
                    inputRead++;
                    if(input[i] == matchB && input[i+1] == matchA){
                            inputRead++;
                            return 0;
                    }
                }
                return inputRead;
        }
        return 0;
    }
};

#endif /* InfiniteComment_h */
