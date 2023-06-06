#include<iostream>
#include<vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class Solution {
    struct Sum{
        double sum;
        int num_nodes;

        Sum():sum(0),num_nodes(0){}
    };
    vector<Sum*> means;

    int depth_of_tree(TreeNode* node,int depth){
        if(!node){
            return depth;
        }
        depth++;
        return max(depth_of_tree(node->right,depth),depth_of_tree(node->left,depth));
    }
    void append_sum_nodes_to_means(int depth){
        for(int i=0;i<depth;i++){
            Sum* sum = new Sum();
            means.push_back(sum);
        }
    }

    void traversal(TreeNode*curr,int depth){
        if(curr){
            means.at(depth)->sum +=curr->data; 
            means.at(depth)->num_nodes++;

            depth++;
            traversal(curr->left,depth);
            traversal(curr->right,depth);
        }
    }

public:
    vector<double> averageOfLevels(TreeNode* root) {
        append_sum_nodes_to_means(depth_of_tree(root,0));
        traversal(root,0);
        vector<double> avg(means.size());
        
        for(int i=0; i<means.size(); i++){
            avg.at(i) = means.at(i)->sum / means.at(i)->num_nodes;
        }
        return avg;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
