# define ssd
class Solution {
public:

    vector<string>ans;

       void _genarate_parenthese(string &s ,int  first,int second){
            if(first==0 && second==0){
                ans.push_back(s);
                return ;
            }

            if(first>0){
                s.push_back('(');
                _genarate_parenthese(s,first-1,second);
                s.pop_back();
            }

            if(second>0){
                if(second>first){
                    s.push_back(')');
                    _genarate_parenthese(s,first,second-1);
                    s.pop_back();
                }
            }
        }
    
    vector<string> generateParenthesis(int n) {
        string s;
        _genarate_parenthese(s,n,n);
        return ans;
    }
};