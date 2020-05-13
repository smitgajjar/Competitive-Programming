import java.io.*;
import java.util.*;

class StringToIntegerAtoi {
    // Implement your solution by completing the below function
    public int myAtoi(String str) {
        char arr[] = str.toCharArray();
        int i=0;
        int n=arr.length;
        while(i<n && arr[i]==' ')
            i++;
        if (i==n)
            return 0;
        boolean neg=false;
        long num=0, maxx=Integer.MAX_VALUE;
        if(arr[i]=='-') {
            neg=true;
            i++;
        }
        else if(arr[i]=='+') i++;
        else if(!Character.isDigit(arr[i])) return 0;
        while(i<n && Character.isDigit(arr[i])) {
            int c=arr[i]-'0';
            num = num*10+c;
            if(num>maxx)
            {
                if(neg)
                    return Integer.MIN_VALUE;
                else
                    return Integer.MAX_VALUE;
            }
            i++;
        }
        if(neg) return -(int)num;
        else return (int)num;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        scanner.close();

        int result = new StringToIntegerAtoi().myAtoi(str);
        System.out.println(result);
    }
}
