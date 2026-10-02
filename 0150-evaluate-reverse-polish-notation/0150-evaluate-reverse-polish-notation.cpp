class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (const string& token : tokens) {
            // Check if the token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); 
                st.pop();
                int a = st.top(); 
                st.pop();
                
                // Explicitly perform the math based on the operator string
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b);
            } else {
                // If it's not an operator, it's a number. Convert and push.
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
};