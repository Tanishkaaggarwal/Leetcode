class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_count = 0; // Acts as our stack size
        int ans = 0;
        
        for (char c : s) {
            if (c == '(') {
                open_count++; // Push to "stack"
            } else {
                if (open_count > 0) {
                    open_count--; // Pop from "stack"
                } else {
                    ans++; // Unmatched closing parenthesis
                }
            }
        }
        
        // Add the remaining unmatched opening parentheses to the answer
        return ans + open_count; 
    }
};