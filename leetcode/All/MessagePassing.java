import java.io.*;
import java.util.*;
// Given a matrix and all coordinates of matrix representing strengths, while travelling in spiral order, find whether it is possible to reach to the end of spiral using all the strengths.
// travel matrix in spiral order as done in last problem.
// at every next coordinate (i, j),
//   current power=max(current power, matrix[i][j])
//   decrement the current power
//   if power is exhausted, break the loop abruptly
// if loop broken abruptly,
//   print yes
// else
//   print no

class MessagePassing  {

  // Complete the below function implementation
  // Print "Yes" for success and "No" for Failure
  public void messagePassTest(int n, int s, int m, int[][] matrix) {
    int rows = matrix.length;
    int cols = matrix[0].length;
    int ri=0, rf=rows-1, ci=0, cf=cols-1;
    int flag=1;
    while (ri<=rf && ci<=cf) {
        
        for(int i=ci; i<=cf; i++) {
            if(s>=0)
                s=Math.max(s, matrix[ri][i]);
            s--;
            // arr.add(matrix[ri][i]);
        }
        ri++;
        
        for(int i=ri; i<=rf; i++) {
            if(s>=0)
            s=Math.max(s, matrix[i][cf]);
            s--;
            // arr.add(matrix[i][cf]);
        }
        cf--;
        
        if(ri<=rf) {
            for(int i=cf; i>=ci; i--) {
                if(s>=0)
                s=Math.max(s, matrix[ri][i]);
                s--;
                // arr.add(matrix[rf][i]);
            }
            rf--;
        }
        
        if(ci<=cf) {
            for(int i=rf; i>=ri; i--) {
                if(s>=0)
                s=Math.max(s, matrix[i][ci]);
                s--;
                // arr.add(matrix[i][ci]);
            }
            ci++;
        }
        // if(s==-1) {
        //     flag=0;
        //     break;
        // }
    }
    if(s<-1)
        System.out.println("No");
    else
        System.out.println("Yes");
}

  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int s = scanner.nextInt();
    int m = scanner.nextInt();
    int[][] matrix = new int[n][n];

    for(int i = 0 ; i < m ; ++i) {
        int x , y , p;
        x = scanner.nextInt();
        y = scanner.nextInt();
        p = scanner.nextInt();
        matrix[x][y] = p;
    }
    scanner.close();
    new MessagePassing().messagePassTest(n,s,m,matrix);
  }
}
