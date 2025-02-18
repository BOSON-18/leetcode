class Solution {
    public String smallestNumber(String pattern) {

        int n=pattern.length();

        StringBuilder result= new StringBuilder();
        Stack<Character> st =new Stack<>();
        int count=1;

        for(int i=0;i<=n;i++){
            st.push((char) ('0'+count));
            count++;

            if(i==n || pattern.charAt(i)=='I'){
                while(!st.isEmpty()){
                    result.append(st.pop());
                }
            }
        }
        return result.toString();       
    }
}