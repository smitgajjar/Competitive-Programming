class StockSpanner {
public:
    int n, prev_large;
    bool flag;
    stack<pair<int, int>> s;
    StockSpanner() {
        n=-1;
    }
    
    int next(int price) {
        // [100, 80, 60, 70, 60, 75, 85]
        flag=0;
        while(!s.empty() and price>=s.top().second)
        {
            s.pop();
            flag=1;
        }
        n++;
        if(!s.empty())
            prev_large=s.top().first;
        s.push({n, price});
        if(s.size()==1)
            return n+1;
        if(!flag) return 1;
        return n-prev_large;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */