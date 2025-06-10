class ProductOfNumbers {

    List<Integer> nums;
    private int n;
    public ProductOfNumbers() {
        this.nums = new ArrayList<Integer>();
        
    }
    
    public void add(int num) {

        if(num==0){
            nums.clear();
            n=0;
        }else{
            if(n!=0){
                nums.add(num*nums.get(n-1));
            }else{
                nums.add(num);
            }
            n++;
        }
        
    }
    
    public int getProduct(int k) {

        if(k==n) return nums.get(n-1);
        if(k>n) return 0;

        return nums.get(n-1)/nums.get(n-1-k);
        
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */