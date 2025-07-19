class Solution {
public:
    int mySqrt(int x) {
        return binarySearch(0, x, x);
    }

private:
    int binarySearch(int left, int right, int x) {
        if (left > right) return right;

        int mid = left + (right - left) / 2;
        long long sq = 1LL * mid * mid;

        if (sq == x) return mid;
        if (sq < x)
            return binarySearch(mid + 1, right, x);
        else
            return binarySearch(left, mid - 1, x);
    }
};
