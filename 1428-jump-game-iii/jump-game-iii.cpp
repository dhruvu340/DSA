class Solution {
public:
    bool solve(vector<int>&arr,int i){
        if(i>=arr.size()||i<0){
            return false;
        }

        if(arr[i]==0){
            return true;
        }
        int idx=arr[i];
        
        if(arr[i]!=-1){
            arr[i]=-1;
            return solve(arr,i+idx) || solve(arr,i-idx);
            
        }else{
            return false;
        }
    }
    bool canReach(vector<int>& arr, int start) { return solve(arr, start); }
};