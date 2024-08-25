#include<bits/stdc++.h>
using namespace std;

int bfs(int x, int y, int N, vector<vector<int>>&vis, vector<vector<char>>&cake){
    queue<pair<int, int>> q;
    q.push({x, y});
    int delrow[] = {1, 0, -1, 0};
    int delcol[] = {0, 1, 0, -1};
    int num = 0;
    while (!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if (vis[r][c]) continue;

        vis[r][c] = 1;
        num++;
        for (int i = 0; i < 4; i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];
            if (nr >= 0 && nc >= 0 && nr < N && nc < N && vis[nr][nc] == 0 && cake[nr][nc] == '1'){
                q.push({nr, nc});
            } 
        }
    }
    return num;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int N;
        cin >> N;
        vector<vector<char>> cake (N, vector<char>(N));
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                cin >> cake[i][j];
            }
        }
        int count = 0;
        vector<vector<int>> vis(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (cake[i][j] == '1'){
                    int temp = 0;
                    temp = bfs(i, j, N, vis, cake);
                    count = max(count, temp);
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
