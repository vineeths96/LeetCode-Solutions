/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int binarySearch(MountainArray &mountainArr, int target, int start, int end, int isDescending) {
        int index = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int midValue = mountainArr.get(mid);

            if (midValue == target) {
                index = mid;
                break;
            }

            if (isDescending ^ (midValue > target))
                end = mid - 1;
            else
                start = mid + 1;
        }

        return index;
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0;
        int right = mountainArr.length() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (mountainArr.get(mid) > mountainArr.get(mid + 1))
                right = mid;
            else
                left = mid + 1;
        }

        int mountainPeak = left;
        int leftSearch = binarySearch(mountainArr, target, 0, mountainPeak, false);
        if (leftSearch != -1) return leftSearch;
        int rightSearch = binarySearch(mountainArr, target, mountainPeak, mountainArr.length() - 1, true);
        if (rightSearch != -1) return rightSearch;

        return -1;
    }
};