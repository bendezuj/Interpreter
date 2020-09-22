#ifndef INTERPRETER_TOKEN_H
#define INTERPRETER_TOKEN_H
#include <map>
#include <string>
using namespace std;

enum TokenType {
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,
    COLON_DASH,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    WHITESPACE,
    UNDEFINED,
    END_OF_FILE
};


class Token {
protected:
    string stringFromFile;
    int lineNum;
    TokenType theToken;
    map<TokenType, string> tokenMap;
public:
    
    Token(TokenType myToken, string myString,  int lineNumber){
        stringFromFile = myString;
        theToken = myToken;
        lineNum = lineNumber;
        tokenMap.insert(pair<TokenType, string>(COMMA, "COMMA"));
        tokenMap.insert(pair<TokenType, string>(PERIOD, "PERIOD"));
        tokenMap.insert(pair<TokenType, string>(Q_MARK, "Q_MARK"));
        tokenMap.insert(pair<TokenType, string>(LEFT_PAREN, "LEFT_PAREN"));
        tokenMap.insert(pair<TokenType, string>(RIGHT_PAREN, "RIGHT_PAREN"));
        tokenMap.insert(pair<TokenType, string>(COLON, "COLON"));
        tokenMap.insert(pair<TokenType, string>(COLON_DASH, "COLON_DASH"));
        tokenMap.insert(pair<TokenType, string>(MULTIPLY, "MULTIPLY"));
        tokenMap.insert(pair<TokenType, string>(ADD, "ADD"));
        tokenMap.insert(pair<TokenType, string>(SCHEMES, "SCHEMES"));
        tokenMap.insert(pair<TokenType, string>(FACTS, "FACTS"));
        tokenMap.insert(pair<TokenType, string>(RULES, "RULES"));
        tokenMap.insert(pair<TokenType, string>(QUERIES, "QUERIES"));
        tokenMap.insert(pair<TokenType, string>(ID, "ID"));
        tokenMap.insert(pair<TokenType, string>(STRING, "STRING"));
        tokenMap.insert(pair<TokenType, string>(COMMENT, "COMMENT"));
        tokenMap.insert(pair<TokenType, string>(WHITESPACE, "WHITESPACE"));
        tokenMap.insert(pair<TokenType, string>(UNDEFINED, "UNDEFINED"));
        tokenMap.insert(pair<TokenType, string>(END_OF_FILE, "EOF"));
        
    }
    string toString(){
        stringstream str;
        str << "(" << tokenMap.at(theToken) << ", \""  << stringFromFile << "\" ," << lineNum << ")" << endl;
        return str.str();
    }
};

#endif //INTERPRETER_TOKEN_H
