#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Insert a value into BST
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    
    return root;
}

// Build BST by inserting values in the given order
TreeNode* buildBST(const vector<int>& values) {
    TreeNode* root = nullptr;
    for (int val : values) {
        root = insertIntoBST(root, val);
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
    
    // Read 7 BST node values
    for (int i = 0; i < 7; i++) {
        cin >> values[i];
    }
    
    // Read the rank
    cin >> cnt;
    
    // Build BST by inserting values in order
    TreeNode* root = buildBST(values);
    
    // Find k-th largest
    int result = findKthLargest(root, cnt);
    
    // Output result
    cout << result << endl;
    
    return 0;
}