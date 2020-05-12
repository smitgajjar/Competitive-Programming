import java.io.*;
import java.util.*;

class SpiralMatrix {
    
    // Implement your solution by completing the below function
    public List<Integer> spiralOrder(int[][] matrix) {

        List<Integer> arr = new ArrayList<>();
        int rows = matrix.length;
        int cols = matrix[0].length;
        int ri=0, rf=rows-1, ci=0, cf=cols-1;
        while (ri<=rf && ci<=cf) {
            for(int i=ci; i<=cf; i++) {
                arr.add(matrix[ri][i]);
            }
            ri++;

            for(int i=ri; i<=rf; i++) {
                arr.add(matrix[i][cf]);
            }
            cf--;
            if(ri<=rf) {
                for(int i=cf; i>=ci; i--) {
                    arr.add(matrix[rf][i]);
                }
                rf--;
            }
            
            if(ci<=cf) {
                for(int i=rf; i>=ri; i--) {
                    arr.add(matrix[i][ci]);
                }
                ci++;
            }

        }
        return arr;
        
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[][] matrix = new int[n][m];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                matrix[i][j] = scanner.nextInt();
        scanner.close();

        List<Integer> result = new SpiralMatrix().spiralOrder(matrix);
        for (int i = 0; i < result.size(); ++i)
            System.out.printf("%d ", result.get(i));
    }
}
