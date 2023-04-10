#include <bits/stdc++.h>
using namespace std;

/*

                   ___           !!!         |               ___          _   _        .      .
  `  _ ,  '       .|||.       `  _ _  '      |.===.        .'_#_`.       '\-//`     .  .:::.
 -  (o)o)  -      (o o)      -  (OXO)  -     {}o o{}       |[o o]|        (o o)        :(o o):  .
-ooO'(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-

*/

#define us unordered_set
#define mod 1000007
#define sp ' '
#define nline "\n"
#define mp make_pair
#define us unordered_set
#define bpc __builtin_popcount

#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)

#define all(v) v.begin(), v.end()
#define lb(a, X) lower_bound(all(a), X) - a.begin()
#define ub(a, X) upper_bound(all(a), X) - a.begin()
#define rfor(i, a, b) for (ll i = a; i >= b; i--)
#define sfor(i, a, b) for (ll i = a; i < b; i++)
#define rot(a, x)          \
    for (auto &a : x)      \
    {                      \
        cout << it << " "; \
    }
#define max_ele(a) *max_element(a.begin(), a.end())
#define min_ele(a) *min_element(a.begin(), a.end())
#define take_vector(a) \
    for (auto &x : a)  \
        cin >> x;
#define take_array(a, n)        \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> a[i];            \
    }
#define ssort(v) sort(v.begin(), v.end())
#define rsort(v) sort(v.begin(), v.end(), greater<>())

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

int parent[mod];
int rank_[mod];

// find parent of a node (with path compression)
int find(int u)
{
    if (parent[u] != u)
    {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

// union two sets
void unite(int u, int v)
{
    int parent_u = find(u);
    int parent_v = find(v);

    if (rank_[parent_u] > rank_[parent_v])
    {
        parent[parent_v] = parent_u;
    }
    else
    {
        parent[parent_u] = parent_v;
        if (rank_[parent_u] == rank_[parent_v])
        {
            rank_[parent_v]++;
        }
    }
}

int main()
{
    int n, m; // number of nodes and edges
    cin >> n >> m;

    // initializing parent and rank arrays
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        rank_[i] = 0;
    }

    // initializing edges
    vector<pair<int, pair<int, int>>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, {u, v}};
    }

    // sort edges in increasing order of weight
    sort(edges.begin(), edges.end());

    // run Kruskal's algorithm
    int mst = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < m; i++)
    {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int weight = edges[i].first;

        if (find(u) != find(v))
        {
            unite(u, v);
            mst += weight;
            pq.push({u, v});
        }
    }

    // print the minimum spanning tree
    cout << mst << endl;
    while (!pq.empty())
    {
        int u = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        cout << u << " " << v << nline;
    }

    return 0;
}
