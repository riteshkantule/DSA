class Solution {
  private:
    void dfs(int row, int col, vector<vector<int>>& grid, 
    vector<vector<int>>& vis, int n, int m, int delr[], int delc[],
    int baseR, int baseC, vector<pair<int,int>> &vec){
        
        vis[row][col] = 1;
        vec.push_back({row - baseR, col - baseC});
        
        for(int i=0; i<4; i++){
            int newr = row + delr[i];
            int newc = col + delc[i];
            
            if(newr>= 0 && newr<n && newc>=0 && newc <m && !vis[newr][newc] && grid[newr][newc] == 1){
                
                dfs(newr, newc, grid, vis, n, m, delr, delc, baseR, baseC, vec);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        set<vector<pair<int, int>>> set;
        
        int delr[] = {-1, 0, +1, 0};
        int delc[] = {0, +1, +0, -1};
        
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, vis, n, m, delr, delc, i, j, vec);
                    set.insert(vec);
                }
            }
        }
        
        return set.size();
    }
};
