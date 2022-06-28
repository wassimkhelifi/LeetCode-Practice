class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool exists = false;
        for (auto& word : wordList) {
            if (word == endWord) exists = true;
        }
        if (!exists) return 0;
        
        wordList.push_back(beginWord);
        map<string, vector<string>> patternToWords;
        for (auto& word : wordList) {
            for (int i = 0; i < word.size(); i++) {
                string pattern = word;
                pattern[i] = '*';
                patternToWords[pattern].push_back(word);
            }
        }
        
        queue<string> traversalQueue;
        traversalQueue.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        int length = 0;
        while (!traversalQueue.empty()) {
            length++;
            queue<string> adjacentWords;
            while (!traversalQueue.empty()) {
                string currentWord = traversalQueue.front();
                traversalQueue.pop();
                if (currentWord == endWord) return length;
                for (int i = 0; i < currentWord.size(); i++) {
                    string pattern = currentWord;
                    pattern[i] = '*';
                    for (auto& adjacentWord : patternToWords[pattern]) {
                        if (!visited.count(adjacentWord)) {
                            visited.insert(adjacentWord);
                            adjacentWords.push(adjacentWord);
                        }
                    }
                }
            }
            
            traversalQueue = adjacentWords;
        }
        
        return 0;
    }
};