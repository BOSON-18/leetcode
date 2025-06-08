class ProductOfNumbers {

    ArrayList<Integer> nums;

    public ProductOfNumbers() {
        this.nums = new ArrayList<Integer>();
    }
    
    public void add(int num) {
        nums.add(num);
    }
    
    public int getProduct(int k) {
        int i=nums.size()-1;
    int ans=1;
        while(k>0){
            ans*=nums.get(i);
            i--;
            k--;
        }

        return ans;
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */