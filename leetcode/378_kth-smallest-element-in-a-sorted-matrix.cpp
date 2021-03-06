//Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
//
//Note that it is the kth smallest element in the sorted order, not the kth distinct element.
//
//Example:
//
//    matrix = [
//        [ 1,  5,  9],
//        [10, 11, 13],
//        [12, 13, 15]
//    ],
//    k = 8,
//
//    return 13.
//Note:
//    You may assume k is always valid, 1 ≤ k ≤ n^2.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution_378 {
public:
    // 1. Binary Search
    // Exp: https://discuss.leetcode.com/topic/52865/my-solution-using-binary-search-in-c
    // Time:	O(nlog(n)log(max-min))
    // Space:	O(1)
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1];
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            int total = 0, max_v = INT_MIN;
            for (auto &row : matrix) {
                auto pos = upper_bound(row.begin(), row.end(), mid);
                max_v = max(max_v, pos == row.end() ? row[n - 1] : *(pos - 1));
                int num = pos - row.begin();
                total += num;
            }
            if (total == k) return max_v;
            if (total < k)
                low = max_v + 1;
            else
                high = max_v;
        }
        return -1;
    }


    // 2. Heap
    // Exp: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/85173/Share-my-thoughts-and-Clean-Java-Code
    // Time:    O(klog(n))
    // Space:   O(n)
    struct Cmp {
        bool operator()(const vector<int>& ele1, const vector<int>& ele2) {
            return ele1[2] < ele2[2];
        }
    };

    int kthSmallest1(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        priority_queue<vector<int>, vector<vector<int>>, Cmp> min_heap;
        for (int i = 0; i < n; i++) min_heap.push({0, i, matrix[0][i]});
        for (int i = 0; i < k - 1; i++) {
            auto& ele = min_heap.top();
            min_heap.pop();
            if (ele[0] == n - 1) continue;
            min_heap.push({ele[0] + 1, ele[1], matrix[ele[0]+1][ele[1]]});
        }
        return min_heap.top()[2];
    }
};