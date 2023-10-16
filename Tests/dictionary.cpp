#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

set<WordMean> Dictionary::getWords() const {
	return words;
}

void Dictionary::addWord(WordMean wm)  {
    words.insert(wm);
}


//=============================================================================
// Exercise 1: Dictionary
//=============================================================================
//TODO
bool WordMean::operator< (const WordMean& wm2) const {
    return (this->word < wm2.word);
}

//=============================================================================
// Subexercise 1.1: Create Dictionary
//=============================================================================
//TODO
void Dictionary::readFile(ifstream &f) {
    string word, meaning;
    while (!f.eof()) {
        getline(f, word);
        getline(f, meaning);
        this->addWord(WordMean{word, meaning});
    }
}

//=============================================================================
// Subexercise 1.2: Print Dictionary
//=============================================================================
//TODO
bool Dictionary::update(string w1, string m1) {
    auto it = words.lower_bound(WordMean(w1, ""));
    if ((it)->getWord() == w1) {
        words.erase(it);
        this->addWord(WordMean(w1, m1));
        return true;
    }
    this->addWord(WordMean(w1, m1));
    return false;
}

//=============================================================================
// Subexercise 1.3: Consult Dictionary
//=============================================================================
//TODO
string Dictionary::consult(string w1, WordMean& previous, WordMean& next) const {
    auto it = words.lower_bound(WordMean(w1, ""));
    if ((it)->getWord() == w1) return (it)->getMeaning();
    else {
        previous = WordMean("word=""","meaning""");
        next = WordMean("word=""","meaning""");
        if ((it)!=words.end()) next = *it;
        if ((it)!=words.begin()) previous = *(--it);
        return "word not found";
    }
}

//=============================================================================
// Subexercise 1.4: Update Dictionary
//=============================================================================
//TODO
void Dictionary::print() const {
    for (WordMean wm: words) {
        cout << wm.getWord() << endl << wm.getMeaning() << endl;
    }
}
