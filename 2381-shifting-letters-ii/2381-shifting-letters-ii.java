class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length();
        int[] shift = new int[n+1];
        String strr = "abcdefghijklmnopqrstuvwxyz";

        for(int[] it: shifts){
            int l = it[0], r = it[1], dir = it[2];
            shift[l] += (dir == 1 ? 1: -1);
            if(r+1 < n){
                shift[r+1] -= (dir == 1 ? 1: -1);
            }
        }
        // int[] shift = new int[n];
        for(int i=1;i<n;i++){
            shift[i] += shift[i-1];
        }

        StringBuilder result = new StringBuilder();
        for(int i=0;i<n;i++){
            int netshift = (shift[i]%26 + 26)%26;
            char ori = s.charAt(i);
            char shifted = (char) ('a' + (ori - 'a' + netshift)%26 );
            // result += strr[netshift%26];
            result.append(shifted);
        }

        return result.toString();


    }
}