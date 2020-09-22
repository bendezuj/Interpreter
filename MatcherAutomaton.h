#ifndef INTERPRETER_MATCHERAUTOMATON_H
#define INTERPRETER_MATCHERAUTOMATON_H
#include "Automaton.h"
using namespace std;


class MatcherAutomaton : public Automaton {
private:
    string toMatch;
public:
    MatcherAutomaton(string tokenString, TokenType myToken): Automaton(myToken){
        toMatch = tokenString; 
    };
    int Read(const string& input) {
    bool isMatch = true;
    int inputRead = 0;
    for (unsigned int i = 0; i < (int)toMatch.size() && isMatch; i++) {
        if (input[i] != toMatch[i]) {
            isMatch = false;
        }
    }
    if (isMatch) {
        inputRead = toMatch.size();
    }
    return inputRead;
    }
};


#endif //INTERPRETER_MATCHERAUTOMATON_H
