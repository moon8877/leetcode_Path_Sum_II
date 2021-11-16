/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> pathSum;
        vector<int> pathTemp;
        vector<vector<int>> pathRecord;
        vector<vector<int>> answer;
        int count=0;
        if(!root){
            return answer;
        }
        dfs(root,pathSum,pathTemp,pathRecord,count);
        for(int i=0;i<pathSum.size();++i){
            if(pathSum[i]==targetSum){
                answer.push_back(pathRecord[i]);
            }
        }
        return answer;
    }
private:
    void dfs(TreeNode* root,vector<int>& pathSum,vector<int>& pathTemp,vector<vector<int>>& pathRecord,int count){
        if(root->left==nullptr && root->right==nullptr){
            pathSum.push_back(count+root->val);
            pathTemp.push_back(root->val);
            pathRecord.push_back(pathTemp);
            pathTemp.pop_back();
            return;
        }
        if(root->left){
            pathTemp.push_back(root->val);
            dfs(root->left,pathSum,pathTemp,pathRecord,count+(root->val));
            pathTemp.pop_back();
        }
        if(root->right){
            pathTemp.push_back(root->val);
            dfs(root->right,pathSum,pathTemp,pathRecord,count+(root->val));
            pathTemp.pop_back();
        }
    }
};
