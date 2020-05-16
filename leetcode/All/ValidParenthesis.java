import java.io.*;
import java.util.*;

public class ValidParenthesis {
    // Implement your solution by completing the below function
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for(char c: s.toCharArray()) {
            if(c=='(' || c=='{' || c=='[') st.push(c);
            else if(!st.empty()) {
                else if(c==')') {
                    if(st.peek()=='(') st.pop();
                    else return false;
                }
                else if(c=='}') {
                    if(st.peek()=='{') st.pop();
                    else return false;
                }
                else if(c==']') {
                    if(st.peek()=='[') st.pop();
                    else return false;
                }
            }
            else
                return false;
        }
        if(st.empty()) return true;
		return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String parenthesis = in.readLine();
        boolean result = new ValidParenthesis().isValid(parenthesis);
        System.out.print(String.valueOf(result));
    }
}
