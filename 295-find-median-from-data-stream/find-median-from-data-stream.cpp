#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class MedianFinder {
public:
    int ct ;
    ordered_set<pair<int,int>>m;
    MedianFinder() {
        ct = 0;
    }
    
    void addNum(int num) {
        
        m.insert({num,ct++});
    }
    
    double findMedian() {
        int n = m.size() ;
        if(n&1){
            double ans = (double)(*m.find_by_order(n/2)).first;
            return ans;
        }else{
            double ans = ((*m.find_by_order(n/2)).first + (*m.find_by_order(n/2 - 1)).first)/2.0;
            return ans;
        }
        return -1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


