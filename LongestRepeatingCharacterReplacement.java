/*Longest Repeating Character Replacement

Given a string s of length n consisting of uppercase English letters and an integer k, you are allowed to perform at most k operations.  In each operation, you can change any character of the string to any other uppercase English letter.

Determine the length of the longest substring that can be transformed into a string with all identical characters after performing at most k such operations.

Examples:

Input: s = "ABBA", k = 2 
Output: 4 
Explanation: The string "ABBA" can be fully converted into the same character using at most 2 changes. By replacing both 'A' with 'B', it becomes "BBBB". Hence, the maximum length is 4.
Input: s = "ADBD", k = 1
Output: 3
Explanation: In the string "ADBD", we can make at most 1 change. By changing 'B' to 'D', the string becomes "ADDD", which contains a substring "DDD" of length 3.
Constraints:
1 ≤ n, k ≤ 105
s consists of only uppercase English letters.

 */

import java.util.*;

public class LongestRepeatingCharacterReplacement {
     public boolean check(HashMap<Character,Integer> mp, int n, int k){
        if(k >= n) return true;
        for(Map.Entry<Character,Integer> e : mp.entrySet()){
            if(e.getValue() >= (n-k)) return true;
        }
        return false;
    }
    public int longestSubstr(String s, int k) {
        // code here
        HashMap<Character , Integer> mp = new HashMap<>();
        int n = s.length();
        int ans = 1;
        int left = 0, right = 1;
        mp.put(s.charAt(0),1);
        if(n>=2){
            mp.put(s.charAt(1), mp.getOrDefault(s.charAt(1),0) + 1);
        }
        while(left < n && right < n){
            if(check(mp,(right - left + 1),k)){
                ans = Math.max(ans , (right - left + 1));
                right++;
                if(right < n)
                mp.put(s.charAt(right),mp.getOrDefault(s.charAt(right),0) + 1);
            }
            else{
                mp.put(s.charAt(left),mp.get(s.charAt(left)) - 1);
                if(mp.get(s.charAt(left)) == 0){
                    mp.remove(s.charAt(left));
                }
                left++;
            }
        }
        return ans;
    }
}































