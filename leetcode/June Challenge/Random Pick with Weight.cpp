class Solution {
public:
    vector<int> s;
    Solution(vector<int>& w) {
        for (int i: w)
        {
            if(s.empty())
                s.push_back(i);
            else
                s.push_back(i+s.back());
        }
    }
    
    int pickIndex() {
        int index=rand()%s.back();
        auto it = upper_bound(s.begin(), s.end(),index);
        return it - s.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */