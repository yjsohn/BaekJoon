#include <iostream>

using namespace std;

int N;
int bamboo[501][501];
int dp[501][501];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void dfs(int y, int x, int day){
    if(dp[y][x] >= day)
        return;
    dp[y][x] = day;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N)
            continue;
        if(bamboo[ny][nx] <= bamboo[y][x])
            continue;
        if(dp[ny][nx] >= day + 1)
            continue;
        dfs(ny, nx, day + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> bamboo[i][j];
        }
    }
    fill_n(dp, sizeof(dp), 1);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dfs(i, j, 1);
        }
    }

    int K = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            K = (dp[i][j] > K ? dp[i][j] : K);
        }
    }
    cout << K << "\n";

    return 0;
}