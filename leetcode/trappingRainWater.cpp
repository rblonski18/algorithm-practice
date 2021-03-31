/*  LC 42 - Trapping Rain Water

suppose we have some array like: 

[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]

where the integers represent an elevation map 
where the width of each bar is one, compute
how much water it can trap after raining. 

this becomes a much easier problem once you
can visualize what's going on, so I recommend heading
over to lc to check out the visual if you havent
seen it yet. */

class Solution {
public:
    int trap(vector<int>& height) {
       
        int l = 0;
        int r = height.size()-1;
        int water = 0;
        int minHeight = 0;
        
        while(l < r) {
            
            while(l < r && height[l] <= minHeight) {
                water += minHeight - height[l];
                l++;
            }
            
            while(l < r && height[r] <= minHeight) {
                water += minHeight - height[r];
                r--;
            }
            
            minHeight = min(height[l], height[r]);
            
        }
        
        return water;
    }
};