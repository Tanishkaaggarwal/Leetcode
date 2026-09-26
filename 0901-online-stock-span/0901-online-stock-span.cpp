class StockSpanner {
    stack<pair<int,int>> st;
    // int front;
    // int count;
public:

    StockSpanner() {
        // front=-1
    }
    
    int next(int price) {
        int span=1;
        // stack<int> st1;
        while(!st.empty() && st.top().first<=price){
            span+=st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */