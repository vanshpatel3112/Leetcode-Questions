class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> set=new HashSet<>();
        int l=0,max=0;
        for(int r=0;r<s.length();r++){
            while(set.contains(s.charAt(r)))
                set.remove(s.charAt(l++));
            set.add(s.charAt(r));
            max=Math.max(max,r-l+1);
        }
        return max;
    }
}