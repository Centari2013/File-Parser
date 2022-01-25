#ifndef ASSIGN7_PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <chrono>

using namespace std;
class parsedFile{
private:
    struct item{
        pair<string, int> p;
        int priority;
    };
    typedef item paired;

    vector<paired> words;
    vector<paired> characters;
    vector<paired> numbers;
    vector<paired> notAlphnum;

    vector<string> tempNotAlphas;
    vector<string> tempNumWordToken;
    vector<string> tempNums;
    vector<string> tempWords;

    bool contains(const vector<paired> &v, const string& s);

    void tokenize(string &s);
    void splitWordNum(string &s);
    void store(vector<paired> &v, const string &s); //store characters, strings, and numbers
    void print(vector<paired> &v, const string& s);
    void fixNotAlphnum();

    static bool sortWordNum(const paired &a, const paired &b);
    static bool sortChar(const paired &a, const paired &b);


public:
    void storeTokens();
    parsedFile();
    bool parse(string& line); //saves words, letters, and numbers to vectors in pairs
    void printResults();
};


#define ASSIGN7_PARSER_H

#include "parser.hpp"
#endif //ASSIGN7_PARSER_H
