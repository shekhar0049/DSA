class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> arr;
        int i = 0;
        int j = 0;

        int n = nums1.size();
        int m = nums2.size();

        while(i < n && j < m){
            if(nums1[i] > nums2[j]){
                arr.push_back(nums2[j]);
                j++;
            }
            else if(nums1[i] < nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }
            else{
                arr.push_back(nums1[i]);
                arr.push_back(nums2[j]);
                i++;
                j++;
            }
        }
        while(i < n){
            arr.push_back(nums1[i]);
            i++;
        }
        while(j < m){
            arr.push_back(nums2[j]);
            j++;
        }
        if((m+n) % 2 == 0){
            int x = (m+n) /2;
            double ans = (arr[x -1] + arr[x]) / 2.0;
            return ans;
        }
        else{
            int x = (m+n) / 2;
            return arr[x];
        }
    }
};