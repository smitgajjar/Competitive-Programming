class Solution {
public:
    bool isPowerOfTwo(int x) {
        return (x>0 and !(x&(x-1)));
    }
};