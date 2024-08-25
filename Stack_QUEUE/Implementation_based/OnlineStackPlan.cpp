#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class StockSpanner
{
private:
    stack<pair<int, int>> st; // Stack to store pairs of (price, span)

public:
    StockSpanner()
    {
        // Constructor doesn't need any initialization for this problem.
    }

    int next(int price)
    {
        int span = 1; // Initial span is 1 for the current day
        // Pop elements from the stack while the current price is greater than or equal to the price at the top of the stack
        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second; // Add the span of the top element to the current span
            st.pop();                // Remove the top element
        }

        // Push the current price and its span onto the stack
        st.push({price, span});
        cout << "price :- " << price << " --> " << "Span :- " << span << endl;
        return span; // Return the calculated span
    }
};

int main()
{
    StockSpanner *obj = new StockSpanner();
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85}; // Sample input prices
    vector<int> result;                                 // To store the output spans

    for (int price : prices)
    {
        result.push_back(obj->next(price));
    }

    // Output the result
    cout << endl
         << "Stock spans for the given prices: ";
    for (int span : result)
    {
        cout << span << " ";
    }
    cout << endl;

    delete obj; // Clean up memory
    return 0;
}
