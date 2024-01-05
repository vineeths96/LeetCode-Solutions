class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int firstPointer = m - 1;
        int secondPointer = n - 1;

        int index = nums1.size() - 1;
        while (firstPointer >= 0 && secondPointer >= 0) {
            if (nums1[firstPointer] < nums2[secondPointer])
                nums1[index] = nums2[secondPointer--];
            else
                nums1[index] = nums1[firstPointer--];

            index--;
        }

        while (firstPointer >= 0)
            nums1[index--] = nums1[firstPointer--];
        
        while (secondPointer >= 0)
            nums1[index--] = nums2[secondPointer--];
    }
};