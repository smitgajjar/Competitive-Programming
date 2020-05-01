class Solution {
public:
    int f[31];
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        f[0]=0;
        f[1]=1;
        for(int i=2; i<31; i++){
            f[i]=f[i-1]+f[i-2];
        }
    }
    int fib(int N) {
        return f[N];
    }
};