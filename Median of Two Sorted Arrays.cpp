/*

而对于“Kth element in 2 sorted array”， 如下图，两个中位数 A[m/2] 和 B[n/2]， 可以将数组划分为四个部分。而丢弃哪一个部分取决于两个条件：
1， (m/2 + n/2)?k；2，A[m/2] ? B[n/2];

如果 (m/2 + n/2) > k，那么意味着，当前中位数取高了，正确的中位数要么在 Section 1或者Section3中。如果A[m/2] > B[n/2],
意味着中位数肯定不可能在Section 2里面，那么新的搜索可以丢弃这个区间段了。同理可以推断出余下三种情况，如下所示：

If (m/2+n/2+1) > k && am/2 > bn/2 , drop Section 2
If (m/2+n/2+1) > k && am/2 < bn/2 , drop Section 4
If (m/2+n/2+1) < k && am/2 > bn/2 ,  drop Section 3
If (m/2+n/2+1) < k && am/2 < bn/2 ,  drop Section 1
*/
class Solution {
public:
	double findMedianSortedArrays(const vector<int>& A, const vector<int>& B) {
		const int m = A.size();
		const int n = B.size();
		int total = m + n;
		if (total & 0x1)
			return find_kth(A.begin(), m, B.begin(), n, total / 2 + 1);
		else
			return (find_kth(A.begin(), m, B.begin(), n, total / 2) + find_kth(A.begin(), m, B.begin(), n, total / 2 + 1)) / 2.0;
	}
private:
	static int find_kth(vector<int>::const_iterator A, int m, vector<int>::const_iterator B, int n, int k) {
		if (m > n) return find_kth(B, n, A, m, k);
		if (m == 0) return *(B + k - 1);
		if (k == 1) return min(*A, *B);

		int ia = min(k / 2, m), ib = k - ia;
		if (*(A + ia - 1) < *(B + ib - 1))
			return find_kth(A + ia, m - ia, B, n, k - ia);
		else if (*(A + ia - 1) > *(B + ib - 1))
			return find_kth(A, m, B + ib, n - ib, k - ib);
		else
			return A[ia - 1];
	}
};
