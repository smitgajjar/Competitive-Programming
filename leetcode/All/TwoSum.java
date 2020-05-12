import java.io.*;
import java.util.*;

public class TwoSum {
    // Implement your solution by completing the below function	
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        int n=nums.length;
        for(int i=0; i<n ;i++) {
            hm.put(nums[i], i);
        }
        int[] arr = new int[2];
        for(int i=0; i<n; i++) {
            if(hm.containsKey(target-nums[i]) && i!=hm.get(target-nums[i])) {
                arr[0]=i;
                arr[1]=hm.get(target-nums[i]);
                break;
            }
        }
        return arr;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] numbers = new int[scanner.nextInt()];
        for (int i = 0; i < numbers.length; i++)
            numbers[i] = scanner.nextInt();
        int target = scanner.nextInt();
        scanner.close();

        int[] complements = new TwoSum().twoSum(numbers, target);
        System.out.print(complements[0] + " " + complements[1]);
    }
}
