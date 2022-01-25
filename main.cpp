#include "parser.h"

int main(){
    parsedFile p;
    string line;
    while(getline(cin, line)){
        p.parse(line);
    }
    p.storeTokens();
    p.printResults();

    return 0;

}
