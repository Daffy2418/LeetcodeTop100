class Solution:  
    # @return a float  
    def findMedianSortedArrays(self, A, B):  
        m = len(A)  
        n = len(B)  
        total = m + n  
        if total & 0x01:  
            return self.find_kth(A, m, B, n, total // 2 + 1)  
        else:  
            return (self.find_kth(A, m, B, n, total // 2) +   
                    self.find_kth(A, m, B, n, total // 2 + 1)) / 2.0  
      
    def find_kth(self, A, m, B, n, k):  
        if m > n:  
            return self.find_kth(B, n, A, m, k)  
        if m == 0:  
            return B[k - 1]  
        if k == 1:  
            return min(A[0], B[0])  
          
        pa = min(k // 2, m)  
        pb = k - pa  
        if A[pa - 1] < B[pb - 1]:  
            return self.find_kth(A[pa:], m - pa, B, n, k - pa)  
        elif A[pa - 1] > B[pb - 1]:  
            return self.find_kth(A, m, B[pb:], n - pb, k - pb)  
        else:  
            return A[pa - 1]  
