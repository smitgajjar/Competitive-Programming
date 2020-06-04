class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum=0, two_n=costs.size();
        int take_back_costB[two_n];
        for(int i=0; i<two_n; i++)
        {
            sum+=costs[i][0];
            take_back_costB[i]=costs[i][1]-costs[i][0];
        }
        sort(take_back_costB, take_back_costB+two_n);
        for(int i=0; i<(two_n>>1); i++)
            sum+=take_back_costB[i];
        return sum;
    }
};