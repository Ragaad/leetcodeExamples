void reverseArray(vector<char> & word){
    int head=0; 
    int tail=chars.size()-1;
    while(head<tail){
        swap(chars[head], chars[tail]);
        head++;
        taill--;
    }

    struct TreeNode{
        int val;
        treeNode* left;
        treeNode* right;
        treeNode(): val(0), ;eft(nullptr), right(nullptr)
    }

    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> res;
        if ( !root) return {};

        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            int size =q.size();
            vector<int> temp;
            for ( int i=1; i<q.size();i++)
            {
                TreeNode* node=q.fron();
                q.pop(); temp.push_back(node->val);
                if(node->left) node=node->left;
                if (node->right) node=node->right;
            }
        }
        ret.push_back(temp);
    }
}
