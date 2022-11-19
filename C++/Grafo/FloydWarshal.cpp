const int MAXN = (int) 1e3;
vector<pair<int, int>> adj[MAXN];

for(int i=0; i<qntA; i++) {
    int org, dest, w;
    cin >> org >> dest >> w;
    adj[org][dest] = w;
    adj[dest][org] = w;
}
int dists[n + 1][n + 1];

for(int i=1; i<n+1; i++) {
    for(int j=1; j<n+1; j++) {
        if (i == j) {
            dists[i][j] = 0;
            continue;
        }
        if (adj[i][j]) {
            dists[i][j] = adj[i][j];
            continue;
        }
        dists[i][j] = (int) 1e5;
    }
}

for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dists[i][j] = min(dists[i][k] + 
                              dists[k][j],
                              dists[i][j]);
        }
    }
}

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        cout << dists[i][j] << ' ';
    }
    cout << '\n';
}