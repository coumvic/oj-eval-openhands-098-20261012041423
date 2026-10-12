#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Build complete binary tree from level order array
TreeNode* buildCompleteBinaryTree(const vector<int>& values) {
    if (values.empty()) return nullptr;
    
    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* current = q.front();
        q.pop();
        
        // Left child
        if (i < values.size()) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
            i++;
        }
        
        // Right child
        if (i < values.size()) {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
            i++;
        }
    }
    
    return root;
}

// Find k-th largest element using reverse in-order traversal
int kthLargest = 0;
int count = 0;

void reverseInOrder(TreeNode* root, int k) {
    if (root == nullptr || count >= k) return;
    
    // Traverse right subtree first (larger elements)
    reverseInOrder(root->right, k);
    
    // Process current node
    count++;
    if (count == k) {
        kthLargest = root->val;
        return;
    }
    
    // Traverse left subtree (smaller elements)
    reverseInOrder(root->left, k);
}

int findKthLargest(TreeNode* root, int k) {
    count = 0;
    kthLargest = 0;
    reverseInOrder(root, k);
    return kthLargest;
}

int main() {
    vector<int> values(7);
    int cnt;
    
    // Read 7 BST node values in level order
    for (int i = 0; i < 7; i++) {
        cin >> values[i];
    }
    
    // Read the rank
    cin >> cnt;
    
    // Build complete binary tree (which should be a BST according to problem)
    TreeNode* root = buildCompleteBinaryTree(values);
    
    // Find k-th largest
    int result = findKthLargest(root, cnt);
    
    // Output result
    cout << result << endl;
    
    return 0;
}