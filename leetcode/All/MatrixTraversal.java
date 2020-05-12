import java.io.*;
import java.util.*;

class MatrixTraversal  {

  // complete the below function implementation
  boolean isOutOfBounds(int n, int steps, int curr) {
    if(curr+steps >= n)
      return true;
    return false;
  }
  
  public List<Integer> valueAtNewPosition(int[][] matrix, int currX, int currY, int dir, int steps) {
    List<Integer> lst = new ArrayList<Integer>();
    int rows = matrix.length;
    int cols = matrix[0].length;
// 1. Given mat[][], direction, steps
// 2. curr_x=given_x
    int rNum = currX;
    int cNum = currY;
// 3. curr_y=given_y
// 4. int dir[] = {"", "r", "d", "l", "u"}; //denoting direction to the numeric symbol
    char dire[] = {' ', 'r', 'd', 'l', 'u'}; //denoting direction to the numeric symbol
// 5. arraylist ans[n]
// 6. if dir[direction]==some_dir, 
//      loop steps times in some_dir
//        ans.add(mat_value)
    if (dire[dir] == 'r') {
      if (isOutOfBounds(cols, steps, cNum)) {
        lst.add(-1);
      }
      else {
        int c=cNum+1;
        while(c<=cNum+steps) {
          lst.add(matrix[rNum][c++]);
        }
      }
    }
    else if (dire[dir] == 'l') {
      if (isOutOfBounds(0, -steps, cNum)) {
        lst.add(-1);
      }
      else {
        int c=cNum-1;
        while(c>=cNum-steps) {
          lst.add(matrix[rNum][c--]);
        }
      }
    }
    else if (dire[dir] == 'd') {
      if (isOutOfBounds(rows, steps, rNum)) {
        lst.add(-1);
      }
      else {
        int r=rNum+1;
        while(r<=rNum+steps) {
          lst.add(matrix[r++][cNum]);
        }
      }
    }
    else if (dire[dir] == 'u') {
      if (isOutOfBounds(0, -steps, rNum)) {
        lst.add(-1);
      }
      else {
        int r=rNum-1;
        while(r>=rNum-steps) {
          lst.add(matrix[r--][cNum]);
        }
      }
    }
// 7. return ans
    return lst;
  }

  public static void main(String args[]) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int m = scanner.nextInt();
    int[][] matrix = new int[n][m];

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        matrix[i][j] = scanner.nextInt();
      }
    }
    int currPosX = scanner.nextInt();
    int currPosY = scanner.nextInt();
    int dirToMove = scanner.nextInt();
    int stepsToMove = scanner.nextInt();

    scanner.close();
     List<Integer> result = new MatrixTraversal().valueAtNewPosition(matrix, currPosX, currPosY, dirToMove, stepsToMove);

    for (int i = 0; i < result.size(); ++i) {
      System.out.printf("%d ", result.get(i));
    }
  }
}

// in matrix,
// go right n-1 steps,
// go down m-1 steps,
// go left n-1 steps,
// go up m-2 steps,

// go right n-2 steps,
// go down m-3 steps,
// go left n-3 steps,
// go up m-4 steps,

// continue this till every element is traversed i.e n-i becomes 0.

// We just have to traverse the matrix in spiral order, taking care of bounds.

// INPUT:
// 1 1
// 1
// OUTPUT:
// 1