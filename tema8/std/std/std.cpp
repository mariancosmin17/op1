#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>
#include <queue>
#include <cctype>
#include <string>

using namespace std;

class WordFreq {
public:
    string word;
    int frequency;
    WordFreq(string c,int b) {
        word = c;
        frequency = b;
    }
    bool operator< (const WordFreq& other) const {
        if (frequency != other.frequency)
            return frequency < other.frequency; 
        else
            return word > other.word; 
    }
};

int main()
{
    ifstream nameFileout("fraza.txt");
    if (!nameFileout.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    string phrase;
    while (getline(nameFileout, phrase)) {
        cout << phrase << endl;
    }

    string separators = " ,?!.";
    map<string, int> word_map;
    while (phrase.size() != 0)
    {
        int real_word_pos = phrase.find_first_not_of(separators);
        phrase = phrase.substr(real_word_pos, phrase.size());

        int currentPos = phrase.find_first_of(separators);
        string currentString = phrase.substr(0, currentPos);
        phrase = phrase.substr(currentPos + 1, phrase.size());

        transform(currentString.begin(), currentString.end(), currentString.begin(),
            [](unsigned char c) { return tolower(c); });
        word_map[currentString]++;
    }
    priority_queue<WordFreq> pq;
    for (auto it : word_map)
    {
        WordFreq wf(it.first,it.second);
        pq.push(wf);
    }
    while (!pq.empty()) {
        cout << pq.top().word << " => " << pq.top().frequency << endl;
        pq.pop();
    }

    return 0;
}
