//
//  IdMatcher.h
//  Interpreter
//
//  Created by Jeanpierre Bendezu on 9/18/20.
//  Copyright © 2020 Jeanpierre Bendezu. All rights reserved.
//

#ifndef IdMatcher_h
#define IdMatcher_h
#include "Automaton.h"


class IdMatcher : public Automaton {
private:
public:
    string A = "Schemes";
    string B = "Facts";
    string C = "Rules";
    string D = "Queries";
    IdMatcher(): Automaton(ID){
    }
    
    int Read(const string& input) {
        if(input.substr(0,6) == "Schemes" || input.substr(0,6) == "Queries" || input.substr(0,5) == "Facts" || input.substr(0,5) == "Rules"){
            return 0;
        }
        if(isalpha(input[0])){
            for(unsigned int i = 1; i< input.size(); i++){
                if(isalpha(input[i]) == false && isdigit(input[i]) == false){
                    return i;
                }
            }
        }
        return 0;
    }
};
#endif /* IdMatcher_h */
