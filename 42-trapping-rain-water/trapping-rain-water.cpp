class Solution {
public:
    int trap(vector<int>& height) {
        int size=height.size();
        vector<int> left(size,0);
        vector<int> right(size,0);
        int maxi=INT_MIN;
        for(int i=0; i<size; i++){
            left[i]=max(maxi,height[i]);
            maxi=max(height[i],maxi);
        }
        maxi=INT_MIN;
        for(int i=size-1; i>=0; i--){
            right[i]=max(maxi,height[i]);
            maxi=max(maxi,height[i]);
        }
        // return 0;
        int ans=0;
        for(int i=0; i<size; i++){
            int mini=min(left[i],right[i]);
            ans+=mini-height[i];
        }

        return ans;
    }
};