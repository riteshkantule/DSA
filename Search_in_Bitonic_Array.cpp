int binarySearch(vector<int> &A, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (A[mid] == x)
            return mid;

        if (A[mid] > x)
            return binarySearch(A, l, mid - 1, x);

        return binarySearch(A, mid + 1, r, x);
    }

    return -1;
}

int binarySearch2(vector<int> &A, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (A[mid] == x)
            return mid;

        if (A[mid] > x)
            return binarySearch2(A, mid + 1, r, x);

        return binarySearch2(A, l, mid - 1, x);
    }

    return -1;
}

int bitonic_Search(vector<int> &A, int l, int r) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (A[mid] > A[mid + 1] && A[mid] < A[mid - 1])
            return mid;

        if (A[mid] > A[mid + 1])
            return bitonic_Search(A, l, mid - 1);

        return bitonic_Search(A, mid + 1, r);
    }

    return -1;
}

int Solution::solve(vector<int> &A, int B) {
    int N = A.size();
    int r = N - 1;
    int l = 0;

    int Mid_of_Bitonic = bitonic_Search(A, 0, N - 1);

    int result1 = binarySearch(A, 0, Mid_of_Bitonic, B);
    int result2 = binarySearch2(A, Mid_of_Bitonic, N - 1, B);

    if (result1 == -1 && result2 == -1)
        return -1;
    else
        return result1 + result2 + 1;
}
