class FirstUnique {
public:
    map<int ,int> m1, m2;
    int len;
    FirstUnique(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        len=0;
        for(int i=0; i<nums.size(); i++)
        {
            add(nums[i]);
        }
    }
    
    int showFirstUnique() {
        if(m2.size())
            return m2.begin()->second;
        else
            return -1;
    }
    
    void add(int value) {
        len++;
        if(m1[value]==0)
        {
            m2[len]=value;
            m1[value]=len;
        }
        else if (m1[value] != -1)
        {
            m2.erase(m1[value]);
            m1[value]=-1;
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */