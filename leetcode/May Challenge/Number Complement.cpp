class Solution {
public:
    int findComplement(int num) {
        long val=1;
        while(val<=num)
            val<<=1;
        int mask=val;
        while(val!=(1LL<<32))
        {
            mask|=val;
            val<<=1;
        }
        return (~mask)&(~num);
    }
};