// class Solution {
// public:
// 	int hIndex(vector<int>& citations) {
// 		int index;
// 		sort(citations.begin(),citations.end(),greater<int>());
// 		int n=citations.size();
// 		for (index = 0;index<n;index++){
// 			if(index>=citations[index])break;
// 		}
// 		return index;
// 	}
// };

class Solution
{
public:
	int hIndex(vector<int> &citations)
	{
		int n = citations.size();
		vector<int> count(n + 1, 0);

		for (int citation : citations)
		{
			if (citation >= n)
			{
				count[n]++;
			}
			else
			{
				count[citation]++;
			}
		}

		int total = 0;
		for (int i = n; i >= 0; i--)
		{
			total += count[i];
			if (total >= i)
			{
				return i;
			}
		}

		return 1;
	}
};
