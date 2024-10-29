class Solution
{
public:
    string reverseVowels(string s)
    {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        unordered_map<char, int> mp;
        mp['a'] = 1;
        mp['e'] = 1;
        mp['i'] = 1;
        mp['o'] = 1;
        mp['u'] = 1;
        mp['A'] = 1;
        mp['E'] = 1;
        mp['I'] = 1;
        mp['O'] = 1;
        mp['U'] = 1;

        while (i < j)
        {
            if (mp[s[i]] != 1)
            {
                i++;
            }
            else if (mp[s[j]] != 1)
            {
                j--;
            }
            else
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};

/*

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'A' || c == 'e' || c == 'E' ||
               c == 'i' || c == 'I' || c == 'o' || c == 'O' ||
               c == 'u' || c == 'U';
    }

    string reverseVowels(string s) {
        int n = s.length();
        int left = 0;
        int right = n - 1;

        while (left < right) {
            // Move the left pointer to the next vowel
            while (left < right && !isVowel(s[left])) {
                left++;
            }

            // Move the right pointer to the previous vowel
            while (left < right && !isVowel(s[right])) {
                right--;
            }

            // Swap the vowels
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};


*/

// #include <unordered_set>
// #include <string>
// using namespace std;

// class Solution {
// public:
//     string reverseVowels(string s) {
//         unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
//         int left = 0, right = s.length() - 1;

//         while (left < right) {
//             // Move left pointer to the next vowel
//             while (left < right && vowels.find(s[left]) == vowels.end()) {
//                 left++;
//             }
//             // Move right pointer to the previous vowel
//             while (left < right && vowels.find(s[right]) == vowels.end()) {
//                 right--;
//             }
//             // Swap the vowels
//             if (left < right) {
//                 swap(s[left], s[right]);
//                 left++;
//                 right--;
//             }
//         }
//         return s;
//     }
// };

