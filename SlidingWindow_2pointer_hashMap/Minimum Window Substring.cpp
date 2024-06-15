class Solution
{
public:
    string minWindow(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        if (m < n)
        {
            return "";
        }

        // Frequency map for characters in t
        unordered_map<char, int> mp;
        for (auto x : t)
        {
            mp[x]++;
        }

        int l = 0, r = 0; // Initialize left and right pointers
        int minLen =
            INT_MAX; // To keep track of the minimum length of the window
        int startIdx =
            0;                   // To keep track of the starting index of the minimum window
        int required = t.size(); // Number of characters needed to match t

        while (r < m)
        { // Expand the window with the right pointer
            if (mp[s[r]] > 0)
            {               // If character s[r] is in t and still needed
                required--; // We have matched one more character
            }
            mp[s[r]]--; // Decrease the count in the map (even if it goes
                        // negative)

            // When the window contains all characters of t
            while (required == 0)
            {
                if (minLen >
                    (r - l + 1))
                {                       // Check if the current window is smaller
                    minLen = r - l + 1; // Update the minimum length
                    startIdx =
                        l; // Update the starting index of the minimum window
                }

                mp[s[l]]++; // Increase the count in the map
                if (mp[s[l]] > 0)
                {               // If we now need this character again
                    required++; // Increase the number of required characters
                }
                l++; // Shrink the window from the left
            }
            r++; // Expand the window from the right
        }
        // Return the minimum window or an empty string if no such window exists
        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};
