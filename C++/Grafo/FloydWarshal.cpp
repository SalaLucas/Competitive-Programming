#include <bits/stdc++.h>
using namespace std;
#define sws                           \
    ios_base::sync_with_stdio(false); \
    cout.tie(NULL);                   \
    cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dbg(msg, x) cout << msg << " " << x << endl;
#define output(x)         \
    for (auto c : x)      \
    {                     \
        cout << c << " "; \
    }                     \
    cout << " ";
#define ff first
#define ss second
typedef vector<int> vi;
typedef pair<int, int> pii;
const int MAXN = (int)1e3;
vector<pii> adj[MAXN];

int main()
{
    sws int n, qtdA;
    cin >> n >> qtdA;
    int adj[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adj[i][j] = 0;
        }
    }
    rep(i, 0, qtdA)
    {
        int org, dest, w;
        cin >> org >> dest >> w;

        adj[org][dest] = w;
        adj[dest][org] = w;
    }

    int dists[n + 1][n + 1];


    rep(i, 1, n + 1)
    {
        rep(j, 1, n + 1)
        {
            if (i == j)
            {
                dists[i][j] = 0;
                continue;
            }
            if (adj[i][j])
            {
                dists[i][j] = adj[i][j];
                continue;
            }
            dists[i][j] = (int)1e5;
        }
    }


    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dists[i][j] = min(dists[i][k] + dists[k][j], dists[i][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dists[i][j] << " ";
        }
        cout << endl;
    }
}