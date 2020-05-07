class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n=nums.size()/2;
        for(auto i: nums)
            mp[i]++;
        for(auto i: mp)
        {
            if(i.second>n)
                return i.first;
        }
        return 0;
    }
};