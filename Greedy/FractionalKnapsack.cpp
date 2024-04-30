#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    double fractionalKnapsack(int w, vector<int> &values, vector<int> &weights)
    {
        int n = values.size(); // Number of items

        // Create a vector of pairs to store the value-to-weight ratios along with item indices
        vector<pair<double, int>> valueWeightRatio(n);

        // Calculate the value-to-weight ratios for each item
        for (int i = 0; i < n; i++)
        {
            valueWeightRatio[i] = {(double)values[i] / weights[i], i};
        }

        // Sort items based on their value-to-weight ratio in non-ascending order
        sort(valueWeightRatio.begin(), valueWeightRatio.end(), [](const auto &a, const auto &b)
             {
                 return a.first > b.first; // Sort in non-ascending order based on value-to-weight ratio
             });

        double totalValue = 0.0; // Initialize totalValue to 0

        // Loop through the sorted items
        for (int i = 0; i < n; i++)
        {
            int idx = valueWeightRatio[i].second; // Get the index of the item

            // If the weight of the current item is less than or equal to the remaining capacity
            if (weights[idx] <= w)
            {
                // Take the entire item
                totalValue += values[idx];
                w -= weights[idx];
            }
            else
            {
                // Take a fraction of the item
                totalValue += (double)values[idx] / weights[idx] * w;
                break; // Break from the loop
            }
        }

        return totalValue; // Return the maximum total value obtained
    }
};
