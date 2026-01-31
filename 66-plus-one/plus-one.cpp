class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;

        for(int i=digits.size()-1;i>=0;i--){
            digits[i]+=carry;
           
                carry=digits[i]/10;
                digits[i]=digits[i]%10;
                
            
        }
          vector<int>ans;
        if(carry>0){
            ans.push_back(carry);
        }


        for(auto i:digits){
            ans.push_back(i);
        }
        return ans;
       
        
    }
};