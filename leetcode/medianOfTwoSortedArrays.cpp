// Find the median of two sorted arrays
//
// I couldn't figure this one out on my own. I had 
// some ideas about how the solution might work, 
// but in the end I had to walk through the solution
// from a video, but hey - we learned something new 
// today. A brute force solution is to merge arrays and
// find the median, and this is O(m + n), but optimal
// is O(log(m + n)) (if i'm correct). place partitions
// in array such that 1. elements to the left of the 
// partitions (in both arrays) equals elements to the
// right of the partitions, and 2. max element in 
// left section of array 1 is less than min element
// in right section of array 2, max element in left
// section of array 2 is less than min element in 
// right section of array 1. Find difference between
// max of left sections and min of right sections, /2.  
// if odd # of elements in total, allow left section 
// to contain an additional element. 

class Solution {
public:
	double medianOfTwoSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
        int n = nums2.size();
        
        if(m > n) {
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        
        while(iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            
            if(i < iMax && nums2[j-1] > nums1[i]) iMin = i+1;
            else if(i > iMin && nums1[i-1] > nums2[j]) iMax = i-1;
            else {
                int maxLeft = 0;
                if(i == 0) maxLeft = nums2[j-1];
                else if(j == 0) maxLeft = nums1[i-1];
                else maxLeft = max(nums1[i-1], nums2[j-1]);
                
                if((m+n) % 2 == 1) return maxLeft; 
                
                int minRight = 0;
                if(i == m) minRight = nums2[j];
                else if(j == n) minRight = nums1[i];
                else minRight = min(nums2[j], nums1[i]);
                
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
	}
}