#include <bits/stdc++.h>
using namespace std;

/*

                   ___           !!!         |               ___          _   _        .      .
  `  _ ,  '       .|||.       `  _ _  '      |.===.        .'_#_`.       '\-//`     .  .:::.
 -  (o)o)  -      (o o)      -  (OXO)  -     {}o o{}       |[o o]|        (o o)        :(o o):  .
-ooO'(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-

*/

#define us unordered_set
#define mod 1000000007
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
#define V 4

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

//  time complexity- (v+e)logv using minheap else theta v square

vector<int> djikstra(int graph[V][V], int src)
{

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    vector<bool> fin(V, false);

    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;

        for (int i = 0; i < V; i++)
            if (!fin[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        fin[u] = true;

        for (int v = 0; v < V; v++)

            if (graph[u][v] != 0 && fin[v] == false)
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
    }
    return dist;
}

int main()
{
    int graph[V][V] = {
        {0, 50, 100, 0},
        {50, 0, 30, 200},
        {100, 30, 0, 20},
        {0, 200, 20, 0},
    };

    for (int x : djikstra(graph, 0))
    {
        cout << x << " ";
    }

    return 0;
}
