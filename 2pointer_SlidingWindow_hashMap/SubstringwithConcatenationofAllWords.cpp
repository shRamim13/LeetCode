class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty())
            return result;

        int wordLength = words[0].size();
        int numWords = words.size();
        int totalLength = wordLength * numWords;

        if (s.size() < totalLength)
            return result;

        unordered_map<string, int> wordCount;

        for (const string& word : words) {
            wordCount[word]++;
        }

        // Sliding window over all possible word alignments
        for (int k = 0; k < wordLength; k++) {
            int left = k;
            int right = k;
            unordered_map<string, int> seenWords;
            int wordsInWindow = 0;

            while (right + wordLength <= s.size()) {
                string word = s.substr(right, wordLength);
                right += wordLength;

                if (wordCount.find(word) != wordCount.end()) {
                    seenWords[word]++;
                    wordsInWindow++;

                    // If we have more instances of this word than allowed,
                    // slide the window
                    while (seenWords[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLength);
                        seenWords[leftWord]--;
                        left += wordLength;
                        wordsInWindow--;
                    }

                    if (wordsInWindow == numWords) {
                        result.push_back(left);
                    }
                } else {
                  
                    seenWords.clear();
                    wordsInWindow = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
