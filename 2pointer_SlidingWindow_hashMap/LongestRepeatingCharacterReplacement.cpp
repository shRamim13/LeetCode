class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int l = 0, r = 0, n = s.size();
        int maxlen = 0, maxElement = 0;
        unordered_map<char, int> mp;
        while (r < n)
        {
            mp[s[r]]++;
            maxElement = max(mp[s[r]], maxElement);
            while ((r - l + 1) - maxElement > k)
            {
                mp[s[l]]--;
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};

/*
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int left = 0, right = 0;

        vector<int> freq(26, 0);  // stores char frequency
        int maxFreq = 0;
        int maxLen = 0;

        while (right < n) {
            freq[s[right] - 'A']++;  // increment frequency
            maxFreq = max(maxFreq, freq[s[right] - 'A']);  // update maxFreq

            // when changes required is > k
            if (( (right - left + 1) - maxFreq ) > k) {   // *** Remark , we use if instead of while as it's more efficient
                freq[s[left] - 'A']--;
                left++;
                maxFreq = *max_element(freq.begin(), freq.end());  // find the new max frequency
            }

            if ((right - left + 1) - maxFreq <= k) {
                maxLen = max(maxLen, right - left + 1);
            }

            right++;
        }

        return maxLen;
    }
};


*/