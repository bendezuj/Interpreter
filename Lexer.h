#ifndef INTERPRETER_LEXER_H
#define INTERPRETER_LEXER_H
using namespace std;
#include <string>
#include <vector>
#include "Automaton.h"
#include "MatcherAutomaton.h"
#include "StringMatcher.h"
#include "BlockMatcher.h"
#include "IdMatcher.h"
#include "InfiniteString.h"
#include "InfiniteComment.h"

class Lexer {
	private: 
		vector<Automaton*> machines;
        vector<Token*> tokens;
	public: 
	Lexer(){
		machines.push_back(new MatcherAutomaton(",", TokenType::COMMA));
		machines.push_back(new MatcherAutomaton(".", TokenType::PERIOD));
		machines.push_back(new MatcherAutomaton("?", TokenType::Q_MARK));
		machines.push_back(new MatcherAutomaton("(", TokenType::LEFT_PAREN));
		machines.push_back(new MatcherAutomaton(")", TokenType::RIGHT_PAREN));
		machines.push_back(new MatcherAutomaton(":", TokenType::COLON));
        machines.push_back(new MatcherAutomaton(":-", TokenType::COLON_DASH));
		machines.push_back(new MatcherAutomaton("*", TokenType::MULTIPLY));
		machines.push_back(new MatcherAutomaton("+", TokenType::ADD));
		machines.push_back(new MatcherAutomaton("Schemes", TokenType::SCHEMES));
		machines.push_back(new MatcherAutomaton("Facts", TokenType::FACTS));
		machines.push_back(new MatcherAutomaton("Rules", TokenType::RULES));
		machines.push_back(new MatcherAutomaton("Queries", TokenType::QUERIES));
        machines.push_back(new StringMatcher());
        machines.push_back(new BlockMatcher());
        machines.push_back(new IdMatcher());
        machines.push_back(new InfiniteString());
        machines.push_back(new InfiniteComment());
        
    }
    ~Lexer(){
    }
    
    int Run(string input) {
        int maxNewLines = 0;
        int lineNumber = 1;
        while(input.size()>0){
            int inputRead = 0;
            int maxRead = 0;
            Automaton* maxMachine = machines[0];
            while(input[0] == '\n'){
                input = input.substr(1);
                lineNumber++;
            }
            while(isspace(input[0])){
                input = input.substr(1);
            }
            if(input.size()==0){
                break;
            }
            for(unsigned int i = 0; i < machines.size(); i++){
                inputRead = machines.at(i)->Read(input);
                if (inputRead > maxRead){
                    maxRead = inputRead;
                    maxMachine = machines[i];
                    maxNewLines = machines[i]->NewLinesRead();
                }
            }
           
            if(maxRead > 0){
                Token* newToken = maxMachine->CreateToken(input.substr(0,maxRead), lineNumber);
                tokens.push_back(newToken);
                lineNumber += maxNewLines;
            }
            else{
                maxRead = 1;
                Token* newToken = new Token(UNDEFINED, input.substr(0,1), lineNumber);
                tokens.push_back(newToken);
            }
            input = input.substr(maxRead);
        }
        Token* newToken = new Token(END_OF_FILE, "", lineNumber);
        tokens.push_back(newToken);
        return 0;
    }
    
    string toString(){
        stringstream out;
        for(unsigned int i = 0; i < tokens.size(); i++){
            out << tokens[i]->toString();
        }
        out << "Total Tokens = " << tokens.size() << endl;
        return out.str();
    }
};
#endif //INTERPRETER_AUTOMATON_H



