class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        // Step 1: Precompute the prefix XOR array
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];

        // Compute prefix XOR
        for (int i = 1; i < n; ++i)
        {
            prefix[i] = prefix[i - 1] ^ arr[i];
        }

        // Step 2: Process each query
        vector<int> result;
        for (const auto &query : queries)
        {
            int L = query[0]; // left index
            int R = query[1]; // right index

            // XOR of the subarray [L, R]
            if (L == 0)
            {
                result.push_back(prefix[R]);
            }
            else
            {
                result.push_back(prefix[R] ^ prefix[L - 1]);
            }
        }

        return result; // Return the results of all queries
    }
};
