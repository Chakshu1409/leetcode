// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int traverse2(TreeNode* root){
//         if(root == NULL){
//             return 0;
//         }
//         return root->val + traverse2(root->left) + traverse2(root->right);
//     }
//     int traverse3(TreeNode* root){
//         if(root == NULL){
//             return 0;
//         }
//         return 1 + traverse3(root->left) + traverse3(root->right);
//     }

//     void transferFromRightToRoot(TreeNode* root, int num, int& count, int level){
//         queue<TreeNode*> q;
//         q.push(root);

//         while(!q.empty() && num!=0){
//             int size=q.size();
//             while(size-- && num!=0){
//                 TreeNode* front=q.front();
//                 q.pop();

//                 if(num>=front->val){
//                     num-=front->val;
//                     count+=level*front->val;
//                     front->val=0;
//                 }
//                 else{
//                     front->val=front->val-num;
//                     count+= level * num;
//                     num=0;
//                 }

//                 if(front->left!=NULL){
//                     q.push(front->left);
//                 }
//                 if(front->right!=NULL){
//                     q.push(front->right);
//                 }

//             }
//             level++;
//         }

        
//     }


//     void traverse(TreeNode* root, int& count){

//         if(root==NULL){
//             return;
//         }
//         int leftCoins=traverse2(root->left);
//         int rightCoins=traverse2(root->right);
//         int rootCoins=root->val;

//         int numLeftNodes=traverse3(root->left);
//         int numRightNodes=traverse3(root->right);
//         // return;
//         // cout<<count<<endl;
//         if(numRightNodes!=0 && rightCoins > numRightNodes){
//             cout<<"R "<<endl;
//             cout<<"1 "<<count<<endl;
//             transferFromRightToRoot(root->right,rightCoins-numRightNodes,count,1);
//             cout<<"2 "<<count<<endl;
//             rootCoins += rightCoins-numRightNodes;
//             count+=rootCoins-1;
//             cout<<"3 "<<count<<endl;
//             if(rootCoins > 1){
//                 root->left->val += rootCoins-1;
                
//             }
//         }
//         else if(numLeftNodes!=0 && leftCoins > numLeftNodes){
//             cout<<"L "<<endl;
//             cout<<"1 "<<count<<endl;
//             transferFromRightToRoot(root->left,leftCoins-numLeftNodes,count,1);
//             cout<<"2 "<<count<<endl;
//             rootCoins += leftCoins-numLeftNodes;
//             count+=rootCoins-1;
//             cout<<"3 "<<count<<endl;
//             if(rootCoins > 1){
//                 root->right->val += rootCoins-1;
//             }
//         }
//         else{
//             cout<<"M "<<endl;
//             cout<<"1 "<<count<<endl;
//             count+= numLeftNodes-leftCoins  +  numRightNodes-rightCoins;
//             cout<<"2 "<<count<<endl;
//             root->val -= numLeftNodes-leftCoins  +  numRightNodes-rightCoins;
//             // if(root->val != 1){
//             //     cout<<"gadbad"<<endl;
//             // }
//             if(root->right!=NULL){
//                 root->right->val = root->right->val + numRightNodes-rightCoins;
//             }
//             if(root->left!=NULL){
//                 root->left->val = root->left->val + numLeftNodes-leftCoins;
//             }
//         }


//         traverse(root->left,count);
//         traverse(root->right,count);
//     }

//     int distributeCoins(TreeNode* root) {
//         int count=0;
//         traverse(root,count);

//         return count;
//     }
// };

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        TreeNode dummy;
        return dfs(root, &dummy);
    }
    
private:
    int dfs(TreeNode* cur_node, TreeNode* parent) {
        if (cur_node == nullptr) {
            return 0;
        }
        int moves = dfs(cur_node->left, cur_node) + dfs(cur_node->right, cur_node);
        int from_this = cur_node->val - 1;
        parent->val += from_this;
        moves += abs(from_this);
        return moves;
    }
};