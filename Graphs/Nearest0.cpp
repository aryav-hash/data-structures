vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<bool>>vis(n, vector<bool>(m, true));
    vector<vector<int>>ans(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mat[i][j] == 0){
                vis[i][j] = true;
                q.push({{i, j}, 0});
            }
        }
    }
    int delrow[] = {1, 0, -1, 0};
    int delcol[] = {0, 1, 0, -1};
    while (!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int d = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                vis[nr][nc] != true){
                vis[nr][nc] = true;
                q.push({{nr, nc}, d+1});
                ans[nr][nc] = d+1;
            }
        }
    }
    return ans;
}
