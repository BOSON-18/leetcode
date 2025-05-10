class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {

        int arr1=0,arr2=0;
        long long sum1=0,sum2=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]==0){
                arr1++;
                sum1+=1;
                continue;
            }
            sum1+=nums1[i];
        }
    for(int i=0;i<nums2.size();i++){
            if(nums2[i]==0){
                arr2++;
                sum2+=1;
                continue;
            }
            sum2+=nums2[i];
        }

        // if(arr1==0 && arr2==0 && sum1!=sum2) return -1;
        // if(arr1==0){
        //     if(arr2!=0 && sum2>sum1) return -1;
        // }
        // if(arr2==0 && arr1!=0 && sum2<sum1) return -1;
        if(sum1==sum2) return sum1;

        if(arr1>0 && arr2>0) return max(sum2,sum1);
        if(arr1>0 && arr2==0 && sum1<=sum2) return sum2;
        if(arr1==0 && arr2>0 && sum1>=sum2) return sum1;

        return -1;
    
        
    }
};