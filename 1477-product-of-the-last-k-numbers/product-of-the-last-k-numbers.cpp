class ProductOfNumbers {
public:
vector<int> arr;
vector<int> prefix;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        arr.push_back(num);
        for(int i=0;i<arr.size()-1;i++){
            arr[i]*=num;
        }
    }
    
    int getProduct(int k) {

        int n=arr.size();
        // int product=1;
        // for(int i=n-1;i>=n-k;i--){
        //     product*=arr[i];
        // }
        // return product;

        return arr[n-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */