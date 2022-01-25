parsedFile::parsedFile() = default;


bool parsedFile::parse(string& line){
    tempNotAlphas.emplace_back("\\n"); //saves newline for each line
    if(!line.empty()) tokenize(line); //save words, numbers, and other characters
    return true;
}

bool parsedFile::contains(const vector<paired> &v, const string& s) {
    for(const auto& p : v){
        if(p.p.first == s){
            return true;
        }
    }
    return false;
}

void parsedFile::tokenize(string &s){
    
    int start = 0;
    int end;
    for (int i = 0; i <= s.length(); i++){
        if (!isalpha(s[i]) && !isdigit(s[i])){ //if not a letter separate token and pushback to vector
            end = i;
            if(s[i] != '\0') {
                string notAlpha = to_string(s[i]);
                //store and count non-alphanumeric characters
                tempNotAlphas.push_back(notAlpha);
              
            }
                string sub;
                sub.append(s, start, end - start);
                
                if(!sub.empty()) tempNumWordToken.push_back(sub);



            start = end + 1;
        }
    }


}

void parsedFile::splitWordNum(string &s){

    for(char &c : s){ //for string comparison
        c = tolower(c);
    }

    int start = 0;
    int end;
    string sub = s;
    for (int i = 0; i <= s.length(); i++){
        if (isdigit(s[i])){
            end = i;

            sub.assign(s, start, end - start);
            s.erase(remove_if(s.begin(), s.end(), [](char c) {return !isdigit(c);}),s.end());
            
            tempNums.push_back(s);

            start = end + 1;
        }
    }

   
    tempWords.push_back(sub);


}

void parsedFile::store(vector<paired> &v, const string &s){
    if(!contains(v, s)){
        item i;
        i.p = make_pair(s,1);
        i.priority = v.size() + 1;
        v.push_back(i);
    }else{
        for(auto &i : v){
            if(i.p.first == s) i.p.second ++;
        }
    }
}

void parsedFile::print(vector<paired> &v, const string& s){

    cout << "\tTop Ten " << s << endl;
    cout << setw(6) << left << "Index";
    cout << setw(8) << internal << "Item" <<
            setw(10) << "Number" <<
            setw(10)<< "Priority" <<endl;

    int max_count = 10;
    if(v.size() < max_count) max_count = v.size();
    for(int i = 0; i < max_count; i++){
        cout << "[" <<setw(4) << right << i << "]";
        cout << setw(14) << left << v[i].p.first;
        cout << setw(10) << v[i].p.second;
        cout << setw(10) << v[i].priority << endl;
    }

    cout << endl << endl;

}

void parsedFile::fixNotAlphnum() {
    for(auto &i : notAlphnum){
        if(i.p.first == "\\n"){
            characters.push_back(i);
            continue;
        }
        int c = 0;
        stringstream s(i.p.first);
        s >> c;
        if(c == 9) i.p.first = "\\t"; //ASCII decimal number for TAB is 09
        else if(isspace(c)) i.p.first = "space";
        else i.p.first = (char)c;

        characters.push_back(i);
    }
    notAlphnum.clear();
}

void parsedFile::storeTokens(){
    for(auto i : tempNumWordToken) splitWordNum(i);
    for(const auto& i : tempWords) store(words, i);
    for(const auto& i : tempNums) store(numbers, i);
    for(const auto& i : tempNotAlphas) store(notAlphnum, i);
}

bool parsedFile::sortWordNum(const paired &a, const paired &b){
    if(a.p.second == b.p.second) return a.priority < b.priority;
    return a.p.second > b.p.second;
}

bool parsedFile::sortChar(const paired &a, const paired &b){
    if(a.p.second == b.p.second) return a.p.first[0] < b.p.first[0];
    return a.p.second > b.p.second;
}

void parsedFile::printResults() {
    if(words.empty() && numbers.empty() && characters.empty()){
        cout << "No data to print." << endl;
    }else{
        fixNotAlphnum();

        sort(words.begin(), words.end(), sortWordNum);
        sort(numbers.begin(), numbers.end(), sortWordNum);
        sort(characters.begin(), characters.end(), sortChar);

        print(words, "Words");
        print(numbers, "Numbers");
        print(characters, "Characters");
    }

}




