class Solution {
public:
    int reverse(int x) {
        bool neg=false;
        if(x<0)
        {
            neg=true;
            if(x==INT_MIN) return 0;
            x=-x;
        }
        long ans=0;
        while(x>0) {
            ans=(ans*10)+(x%10);
            if(ans>INT_MAX) return 0;
            x/=10;
        }
        if(neg)
            return -ans;
        return ans;
    }
};