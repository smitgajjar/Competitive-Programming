import java.io.*;
import java.util.*;
class TrappingRainWater {

    // complete the below function implementation
    public int trap(int[] height) {
        int n=height.length;
        int leftMax[] = new int[n];
        int rightMax[] = new int[n];
        int maxx=Integer.MIN_VALUE;
        for(int i=0; i<n; i++) {
            if(height[i]>maxx) {
                maxx=height[i];
                leftMax[i]=height[i];
            }
            else
            {
                leftMax[i]=maxx;
            }
        }
        maxx=Integer.MIN_VALUE;
        for(int i=n-1; i>=0; i--) {
            if(height[i]>maxx) {
                maxx=height[i];
                rightMax[i]=height[i];
            }
            else
            {
                rightMax[i]=maxx;
            }
        }
        int sum=0;
        for(int i=1; i<n-1; i++) {
            sum+=(Math.min(leftMax[i], rightMax[i])-height[i]);
        }
        return sum;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int height[] = new int[n];
        for(int i = 0 ; i < n ; i++) {
            height[i] = scanner.nextInt();
        }
        scanner.close();
        int result = new TrappingRainWater().trap(height);
        System.out.println(result);
    }
}
