class ProductOfNumbers {
public:
    vector<long long>v;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(v.size() == 0 && num != 0){
            v.push_back(num);
            return ;
        }else if(v.size() == 0 && num == 0){
            return ;
        }


        int toAdd = num * v[v.size() - 1];
        if(toAdd == 0)v.clear();
        else v.push_back(toAdd); 

    }
    
    int getProduct(int k) {
        int n = v.size();
        if( n<k )return 0;
        if(n == k)return v[n-1];

        return v[n-1] / v[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */