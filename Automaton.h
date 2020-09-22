#ifndef INTERPRETER_AUTOMATON_H
#define INTERPRETER_AUTOMATON_H
#include <string>
#include "Token.h"
using namespace std;

class Automaton{
protected:
    int newLines = 0;
    TokenType type;
public:
    Automaton(TokenType type) {
        this->type = type;
    }
    virtual int Read(const string& input) = 0;
    virtual Token* CreateToken(string input, int lineNumber) {
        return new Token(type, input, lineNumber);
    }
    virtual int NewLinesRead() const {
        return newLines;
    }
};


#endif //INTERPRETER_AUTOMATON_H
