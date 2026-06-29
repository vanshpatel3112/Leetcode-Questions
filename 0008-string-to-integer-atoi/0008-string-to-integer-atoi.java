class Solution {
    public int myAtoi(String s) {
        s=s.trim();
        if(s.isEmpty()) return 0;
        int i=0,sign=1;
        if(s.charAt(0)=='-'||s.charAt(0)=='+')
            sign=s.charAt(i++)=='-'?-1:1;
        long res=0;
        while(i<s.length()&&Character.isDigit(s.charAt(i))){
            res=res*10+(s.charAt(i++)-'0');
            if(res*sign>Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if(res*sign<Integer.MIN_VALUE) return Integer.MIN_VALUE;
        }
        return (int)(res*sign);
    }
}