int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int rows = A.size();
    int columns = A[0].size();
    int r = 0;
    int c = columns - 1;

    while (r < rows && c >= 0) {
        int mid = A[r][c];

        if (B == mid) {
            return 1;
        } else if (B < mid) {
            c--;
        } else {
            r++;
        }
    }

    return 0;
}
