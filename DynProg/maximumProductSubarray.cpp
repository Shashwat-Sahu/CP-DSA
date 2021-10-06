// ****   MAXIMUM PRODUCT SUBARRAY   **** //

//Given an integer array 'A', find a contiguous non-empty subarray within the array
// that has the largest product, and return the product.

int maxProduct(vector<int> A)
{
    int n = A.size(), res = A[0], l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        l = (l ? l : 1) * A[i];
        r = (r ? r : 1) * A[n - 1 - i];
        res = max(res, max(l, r));
    }
    return res;
}
