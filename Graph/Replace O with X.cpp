class Solution{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, int n, int m){
        int delr[] = {-1, 0, +1, 0};
        int delc[] = {0, +1, 0, -1};
        vis[row][col] = 1;
        
        for(int i=0; i<4; i++){
            int newr = row + delr[i];
            int newc = col + delc[i];
            
            if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] &&  mat[newr][newc] == 'O'){
                dfs(newr, newc, vis, mat, n, m);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        for(int j=0; j<m; j++){
            if(!vis[0][j] && mat[0][j] == 'O'){
                dfs(0, j, vis, mat, n, m);
            }
            
            
            if(!vis[n-1][j] && mat[n-1][j] == 'O'){
                dfs(n-1, j, vis, mat, n, m);
            }
        }
        
        for(int i=0; i<n; i++){
            if(!vis[i][0] && mat[i][0] == 'O'){
                dfs(i, 0, vis, mat, n, m);
            }
            
            
            if(!vis[i][m-1] && mat[i][m-1] == 'O'){
                dfs(i, m-1, vis, mat, n, m);
            }
        }
        
        for (int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};
