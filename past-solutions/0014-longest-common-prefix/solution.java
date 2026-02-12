class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs);
        String s1=strs[0];
        String s2=strs[strs.length-1];
        String s3="";
        int len=Math.min(s1.length(),s2.length());

        for(int i=0;i<len;i++){
            if(s1.charAt(i)!=s2.charAt(i)){
                break;
            }
            s3=s3+s2.charAt(i);
        }
    return s3;

    }     
}
