#include <bits/stdc++.h>

using namespace std;

// global variables
vector< vector<string> > allLines;
set<string> ignored;

struct KeyWord {
    int lineNumber, wordPostition;

    KeyWord(int lineNumber, int wordPostition) 
        :lineNumber(lineNumber), wordPostition(wordPostition) 
        {}

    bool operator<(const KeyWord& other) const {
        if (allLines[lineNumber][wordPostition] != allLines[other.lineNumber][other.wordPostition])
            return allLines[lineNumber][wordPostition] < allLines[other.lineNumber][other.wordPostition];
    
        if (lineNumber != other.lineNumber) return lineNumber < other.lineNumber;

        return wordPostition < other.wordPostition; 
    }
};

vector<KeyWord> keyWords;

void generateKeywords(const string& line){
    istringstream in(line);

    string word;
    int pos = 0;
    int lineNumber = allLines.size();
    allLines.push_back(vector<string>());

    while (in >> word){
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        
        allLines[lineNumber].push_back(word);

        if (ignored.find(word) == ignored.end())
            keyWords.push_back(KeyWord(lineNumber, pos));

        pos++;
    }
}

void printKeyWord(const KeyWord& keyWord){
    vector<string> line = allLines[keyWord.lineNumber];

    for (int i=0; i<line.size(); i++){
        if (i) cout << " ";
        if (keyWord.wordPostition == i){
            string word = line[i];
            transform(word.begin(), word.end(), word.begin(), ::toupper);
            cout << word;
        } else 
            cout << line[i];
        
    }

    cout << "\n";
}

int main(){
    string line;
    while(cin >> line and line != "::")
        ignored.insert(line);

    cin.ignore();
    while(getline(cin, line))
        generateKeywords(line);
    
    sort(keyWords.begin(), keyWords.end());

    for (auto keyWord : keyWords)
        printKeyWord(keyWord);
    return 0;
    
}