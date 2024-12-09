#include <deque>
#include <string>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        deque<int> radiant, dire;

        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R')
                radiant.push_back(i);
            else
                dire.push_back(i);
        }

        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front();
            int d = dire.front();
            radiant.pop_front();
            dire.pop_front();
            if (r < d)
                radiant.push_back(r + n);
            else
                dire.push_back(d + n);
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};
