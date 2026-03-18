class Solution {
    public int change(int amount, int[] coins) {
       int n = coins.length;
       int[] a=new int[amount+1];
       for(int i=0;i<=amount;i++){
        a[i]=0;
       }
       a[0]=1;
       for(int i:coins){
        for(int j=i;j<=amount;j++){
            if(j-i>=0){a[j]+=a[j-i];}
        }
       }

       return a[amount];
    }
}