/*Minimum Increment or Double Operations to Convert

Given an array arr[]. Initially, you have another array containing only 0s.
In one operation, you may either:

Choose any one element and increase its value by 1, or
Double the values of all elements in the array simultaneously.
Find the minimum number of operations required to transform the initial all-zero array into the given array arr[].

Examples:

Input: arr[] = [16, 16, 16]
Output: 7
Explanation: 
First, increase each element to make the array [1, 1, 1] (3 steps).
Then, multiply the whole array by 2 four times:
[1,1,1] -> [2,2,2] -> [4,4,4] -> [8,8,8] -> [16,16,16]
Total steps = 3 + 4 = 7.
Input: arr[] = [2, 3]
Output: 4
Explanation: 
Start from [0, 0].
Increase both elements to get [1, 1] (2 steps)
Multiply once: [2, 2] (1 step)
Increase second element once: [2, 3] (1 step)
Total steps = 2 + 1 + 1 = 4.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 109 */

public class Minimum_Increment_Or_Double_Operations_To_Convert {
    /*
     * class State{
     * int [] arr;
     * int ops;
     * State(int [] arr, int ops){
     * this.arr = arr;
     * this.ops = ops;
     * }
     * }
     */

    class Solution {
        public int countMinOperations(int arr[]) {
            // code here
            /*
             * int n = arr.length;
             * int [] nums = new int [n];
             * Set<String> visited = new HashSet<>();
             * Queue<State> q = new LinkedList<>();
             * q.offer(new State(nums.clone(),0));
             * visited.add(Arrays.toString(nums));
             * while(!q.isEmpty()){
             * State temp = q.poll();
             * if(Arrays.equals(temp.arr,arr)){
             * return temp.ops;
             * }
             * nums = temp.arr.clone();
             * for(int i=0; i<n; i++){
             * nums[i] += 1;
             * if(nums[i] > arr[i]){
             * nums[i] -= 1;
             * continue;
             * }
             * String s = Arrays.toString(nums);
             * if(!visited.contains(s)){
             * visited.add(s);
             * q.offer(new State(nums.clone(),(temp.ops + 1)));
             * }
             * nums[i] -= 1 ;
             * }
             * boolean brk = false;
             * for(int i=0; i<n; i++){
             * nums[i] = 2*nums[i];
             * if(nums[i] > arr[i]){
             * brk = true;
             * break;
             * }
             * }
             * String s = Arrays.toString(nums);
             * if(!brk && !visited.contains(s)){
             * visited.add(s);
             * q.offer(new State(nums.clone(),(temp.ops + 1)));
             * }
             * }
             * return -1;
             */

            int ops = 0;
            int n = arr.length;
            int[] nums = arr.clone();
            while (true) {
                int xeros = 0;
                for (int i = 0; i < n; i++) {
                    if ((nums[i] & 1) != 0) {
                        nums[i] -= 1;
                        ops++;
                    }
                    if (nums[i] == 0)
                        xeros++;
                }
                if (xeros == n)
                    break;
                xeros = 0;
                for (int i = 0; i < n; i++) {
                    nums[i] /= 2;
                    if (nums[i] == 0)
                        xeros++;
                }
                ops++;
                if (xeros == n)
                    break;
            }
            return ops;
        }
    }
}
