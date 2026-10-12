#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> values(7);
    int cnt;
    
    // Read 7 BST node values
    for (int i = 0; i < 7; i++) {
        cin >> values[i];
    }
    
    // Read the rank
    cin >> cnt;
    
    // Sort the values to get BST in-order traversal
    sort(values.begin(), values.end());
    
    // The k-th largest is the (7-k)-th element in sorted array (0-indexed)
    int result = values[7 - cnt];
    
    // Output result
    cout << result << endl;
    
    return 0;
}