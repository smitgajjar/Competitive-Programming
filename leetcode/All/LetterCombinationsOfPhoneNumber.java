import java.io.*;
import java.util.*;
import java.lang.*;

public class LetterCombinationsOfPhoneNumber {

    // Implement your solution by completing the below function

    List<String> ls = new ArrayList<>();
    String[] arr = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    public String func(String digits, int n) {
        String s="";
        for(int i = 0; i < digits.length(); i++) {
            for(int j = 0; j < arr[digits.charAt(i)-'0'-2].length(); j++) {
                
                if (i == (digits.length()-1))
                    s = arr[digits.charAt(i)-'0'-2].charAt(j)+"";
                else
                    s = arr[digits.charAt(i)-'0'-2].charAt(j) + func(digits.substring(i+1), n);
                if(s.length() == n)
                    ls.add(s);
            }
        }
        return s;
    }
    

    public List<String> letterCombinations(String digits) {
        
        List<String> ls1 = new ArrayList<>();
        int n = digits.length();
        int[] idxs = new int[digits.length()];
        String temp="";
        while (true) {
            temp="";
            for (int i=0; i<n ;i++) {
                temp += (arr[digits.charAt(i)-'0'-2].charAt(idxs[i])+"");
            }
            ls1.add(temp);
            int last = n-1;
            while(last>=0 && idxs[last]>=(arr[digits.charAt(last)-'0'-2].length()-1))
                last--;
            if(last < 0)
                break;
            idxs[last]++;

            for (int j=last+1; j<n; j++)
                idxs[j]=0;
        }
        return ls1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line = in.readLine();
        List<String> combinations = new LetterCombinationsOfPhoneNumber().letterCombinations(line);
        System.out.println("[");
        for (String cmbn : combinations)
            System.out.print("\'"+cmbn + "\',");
        System.out.println("]");
    }
}