import java.io.*;
import java.util.*;


class Pair {
    int first, second;
    Pair(int x, int y) {
        this.first = x;
        this.second = y;
    }
    Pair() {
        this.first = 0;
        this.second = 0;
    }
}

class MergeIntervals {
    // Implement your solution by completing the below function

    public int[][] merge(int[][] intervals) {
        
        Stack<Pair> st = new Stack<>();
        
        int n = intervals.length;
        Pair arr[] = new Pair[n];
        for(int i=0; i<n; i++) {
            Pair p = new Pair();
            p.first = intervals[i][0];
            p.second = intervals[i][1];
            arr[i] = p;
        }
        
        Arrays.sort(arr, new Comparator <Pair>() {
            public int compare(Pair a, Pair b) {
                if (a.first>b.first) return 1;
                if(a.first==b.first) return 0;
                return -1;
            }
        });
        st.push(arr[0]);
        for(int i=1; i<n; i++) {
            if(st.peek().second>=arr[i].first && st.peek().second<arr[i].second) {
                Pair top = st.pop();
                top.second =  arr[i].second;
                st.push(top);
            }
            else if(st.peek().second<arr[i].first){
                st.push(arr[i]);
            }
        }
        int[][] ans = new int[st.size()][2];
        ArrayList<Pair> al = new ArrayList<>();
        al.addAll(st);
        for(int i=0; i<st.size(); i++) {
            ans[i][0] = al.get(i).first;
            ans[i][1] = al.get(i).second;
        }
        return ans;
    }
    

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] nums = new int[n][2];
        for (int i = 0; i < n; i++) {
            nums[i][0] = scanner.nextInt();
            nums[i][1] = scanner.nextInt();
        }
        scanner.close();

        int[][] results = new MergeIntervals().merge(nums);
        for (int i = 0; i < results.length; ++i)
            System.out.println(String.valueOf(results[i][0]) + " " + String.valueOf(results[i][1]));
    }
}
