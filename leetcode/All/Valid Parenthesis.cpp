class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s) {
            if(c=='(' or c=='{' or c=='[')
                st.push(c);
            else if(!st.empty()){
                if(c==')') {
                    if(st.top()=='(')
                        st.pop();
                    else
                        return false;
                }
                else if(c=='}') {
                    if(st.top()=='{')
                        st.pop();
                    else
                        return false;
                }
                else if(c==']') {
                    if(st.top()=='[')
                        st.pop();
                    else
                        return false;
                }
            }
            else
                return false;
        }
        if(st.empty())
            return true;
        return false;
    }
};