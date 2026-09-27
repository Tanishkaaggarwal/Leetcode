class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<n;i++){
            bool alive=true;
            int curr=asteroids[i];
            while(!st.empty() && curr<0 && st.top()>0){
                if(st.top() < abs(curr)){
                    st.pop();
                    // st.push(curr);
                }
                else if (st.top() == abs(curr)) {
                    // Both asteroids explode
                    st.pop();
                    alive = false;
                    break;
                }
                else{
                    alive=false;
                    break;
                }
            }
            if(alive) st.push(curr);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};