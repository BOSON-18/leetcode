class Solution {
    public int[] pivotArray(int[] nums, int pivot) {

        int n=nums.length;

        HashMap<Boolean,ArrayList<Integer>> mpp = new HashMap<>();
        mpp.put(true,new ArrayList<Integer>());
        mpp.put(false,new ArrayList<Integer>());
        ArrayList<Integer> pivotList = new ArrayList<>();

        for(int it:nums){
            if(it<pivot){
                mpp.get(true).add(it);
            }else if(it>pivot){
                mpp.get(false).add(it);
            }else{
                pivotList.add(it);
            }
        }

        int index=0;

        ArrayList<Integer> small = mpp.get(true);

        for(int it:small){
            nums[index]=it;
            index++;
        }

         for(int it:pivotList){
            nums[index]=it;
            index++;
        }

        ArrayList<Integer> large= mpp.get(false);

        for(int it:large){
            nums[index]=it;
            index++;
        }

        return nums;
    }
}