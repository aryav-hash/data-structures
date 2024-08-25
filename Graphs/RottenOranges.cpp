int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> vis(m, vector<int>(n, 0));
    queue<pair<pair<int, int>, int>> q;
    int cnt = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == 2){
                vis[i][j] = 1;
                q.push({{i, j}, 0});
            }
            if (grid[i][j] == 1){
                cnt++;
            }
        }
    }
    
    int time = 0;
    int cnt1 = 0;
    while (!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        time = max(t, time);
        int delrow[] = {1, 0, -1, 0};
        int delcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc] != 1 && grid[nr][nc] == 1){
                cnt1++;
                q.push({{nr, nc}, t+1});
            }
        }
    }
    if (cnt == cnt1){
        return -1;
    }
    return time;
}
