class Solution {
  public:
  int mini=INT_MAX;
    void solve(Node* root){
        if(root==nullptr){
            return;
        }
        mini=min(mini,root->data);
        solve(root->left);
    }
    int minValue(Node* root) {
        solve(root);
        return mini;
    }
};