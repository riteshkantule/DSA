class Solution {

    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int m = grid.size();    // number of rows
	    int n = grid[0].size(); // number of columns
	    vector<vector<int>> vis(m, vector<int> (n, 0));
	    vector<vector<int>> ans(m, vector<int> (n, 0));
	    queue<pair<pair<int, int>, int>> q;
	    int delr[] = {-1, 0, +1, 0};
	    int delc[] = {0, +1, 0, -1};

	    for (int i=0; i<m; i++){
	        for(int j =0; j<n; j++){
	            
	            if(grid[i][j] == 1){
	                q.push({{i, j}, 0});
	                vis[i][j] = 1;
	            }
	            else vis[i][j] = 0;
	        }
	    }
	    
	    while (!q.empty()){
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int d = q.front().second;
	        ans[r][c] = d;
	        q.pop();
	        
	        for(int i=0; i<4; i++){
                int newr = r + delr[i];
                int newc = c + delc[i];
                
                if(newr>= 0 && newr<m && newc>=0 && newc<n && vis[newr][newc] == 0){
                    vis[newr][newc] = 1;
                    q.push({{newr, newc}, d+1});
                    
                }
	        }
	        
	    }
	    return ans;
	}
};
