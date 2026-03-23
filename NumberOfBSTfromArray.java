/*Number of BST From Array

You are given an integer array arr[] containing distinct elements.

Your task is to return an array where the ith element denotes the number of unique BSTs formed when arr[i] is chosen as the root.

Examples :

Input: arr[] = [2, 1, 3]
Output: [1, 2, 2]
Explanation: 
4
Input: arr[] = [2, 1]
Ouput: [1, 1]
Constraints:
1 ≤ arr.size() ≤ 6
1 ≤ arr[i] ≤ 15

 */

import java.util.*;

class Pair implements Comparable<Pair> {
    int key;
    int value;

    Pair(int key, int value) {
        this.key = key;
        this.value = value;
    }

    public int compareTo(Pair p) {
        if (this.key == p.key) {
            return Integer.compare(this.value, p.value);
        }
        return Integer.compare(this.key, p.key);
    }

    public boolean equals(Object p) {
        if (!(p instanceof Pair))
            return false;
        Pair temp = (Pair) p;
        return this.key == temp.key && this.value == temp.value;
    }

    public int hashCode() {
        return Objects.hash(key, value);
    }
}

class NumberOfBSTfromArray {
    public void factorial(int[] facto, int n) {
        facto[0] = 1;
        for (int i = 1; i <= (2 * n); i++) {
            facto[i] = i * facto[i - 1];
        }
        return;
    }

    public int catalan(int n, int[] facto) {
        return facto[2 * n] / (facto[n + 1] * facto[n]);
    }

    public ArrayList<Integer> countBSTs(int[] arr) {
        // Code here
        int n = arr.length;
        ArrayList<Pair> temp = new ArrayList<>();
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ans.add(0);
        }
        for (int i = 0; i < n; i++) {
            temp.add(new Pair(arr[i], i));
        }
        /*
         * Comparator<Pair> com = new Comparator<>(){
         * public int compare(Pair p1 , Pair p2){
         * if(p1.key > p2.key){
         * return 1;
         * }
         * else if(p1.key == p2.key){
         * return 0;
         * }
         * else{
         * return -1;
         * }
         * }
         * };
         * Collections.sort(temp,com);
         */
        Collections.sort(temp);
        int[] facto = new int[2 * n + 1];
        factorial(facto, n);
        for (int i = 0; i < n; i++) {
            int index = temp.get(i).value;
            int calc = catalan(i, facto) * catalan(n - i - 1, facto);
            ans.set(index, calc);
        }
        return ans;
    }
}
