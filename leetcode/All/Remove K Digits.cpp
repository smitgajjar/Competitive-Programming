class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        if(n==k)
            return "0";
        string::iterator it=num.begin();
        bool done=0;
        while(it!=num.end() and next(it)!=num.end()) {
            if(*it>*next(it)) {
                if(*it!='0')
                    k--;
                num.erase(it);
                if(k==0) {
                    done=1;
                    break;
                }
                if(it!=num.begin()) it=prev(it);
            }
            else
                it++;
        }
        it=num.begin();
        while(*it=='0')
            num.erase(it);
        if(num=="")
            return "0";
        if(done)
            return num;        
        return num.substr(0, num.length()-k);
        
    }
};