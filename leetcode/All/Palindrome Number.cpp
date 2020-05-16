class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int temp=x, cnt=0, reverse=0;
        while(temp>0)
        {
            temp/=10;
            cnt++;
        }
        for(int i=0; i<cnt/2; i++)
        {
            reverse=reverse*10+(x%10);
            x/=10;
        }
        if(cnt&1) x/=10;
        while(x>0)
        {
            if((x%10)!=(reverse%10))
                return false;
            x/=10;
            reverse/=10;
        }
        return true;
    }
};