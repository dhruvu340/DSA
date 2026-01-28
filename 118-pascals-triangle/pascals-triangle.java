class Solution {
    public List<List<Integer>> generate(int n) {
        List<List<Integer>> li = new ArrayList<>();
        
         li.add( Arrays.asList(1));
        for(int i=2;i<=n;i++){
             List<Integer> lit = new ArrayList<>();
            for(int j=1;j<=i;j++){
                if(j==1||j==i){
                    lit.add(1);
                }else{
                    List<Integer> prev=li.get(li.size()-1);
                    int t=prev.get(j-2)+prev.get(j-1);
                    lit.add(t);
                }
            }
            li.add(lit);
        }


        return li;
    }
}