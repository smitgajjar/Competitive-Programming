class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n=A.size();
        if(n==1) return A[0];
        int max_sum, min_sum, max_ans, min_ans, total_sum;
        max_sum=min_sum=max_ans=min_ans=total_sum=A[0];
        for(int i=1; i<n; i++)
        {
            max_sum=max(max_sum+A[i], A[i]);
            min_sum=min(min_sum+A[i], A[i]);
            max_ans=max(max_ans, max_sum);
            if(i!=n-1)
                min_ans=min(min_ans, min_sum);
            total_sum+=A[i];
        }
        int last_ele_sub_min=A[n-1], last_ele_sub_sum=A[n-1];
        for(int i=n-2; i>0; i--)
        {
            last_ele_sub_min=min(last_ele_sub_min, last_ele_sub_sum);
            last_ele_sub_sum+=A[i];
        }
        min_ans=min(min_ans, last_ele_sub_min);
        return max(max_ans, total_sum-min_ans);
    }
};