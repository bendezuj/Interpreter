#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Lexer.h"

using namespace std;


int main(int argc, const char * argv[]){
    Lexer lexer;
    
	string inputFile = argv[1];
	ifstream inStream;
	stringstream in;
	inStream.open(inputFile);
    in << inStream.rdbuf();
    inStream.close();
    
    lexer.Run(in.str());
    cout << lexer.toString();
    return 0;
}
