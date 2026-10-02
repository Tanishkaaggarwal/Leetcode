class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string current_str, int open_count, int close_count, int max) {
        // Base case: if the current string has reached the maximum length (n * 2)
        if (current_str.length() == max * 2) {
            result.push_back(current_str);
            return;
        }

        // If we can still add an open parenthesis, add it and recurse
        if (open_count < max) {
            backtrack(result, current_str + "(", open_count + 1, close_count, max);
        }
        
        // If there are more open parentheses than close ones, we can add a close parenthesis
        if (close_count < open_count) {
            backtrack(result, current_str + ")", open_count, close_count + 1, max);
        }
    }
};