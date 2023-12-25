	class Solution {
	public:
		int hIndex(vector<int>& citations) {
			int index;
			sort(citations.begin(),citations.end(),greater<int>());
			int n=citations.size();
			for (index = 0;index<n;index++){
				if(index>=citations[index])break;
			}
			return index;
		}
	};