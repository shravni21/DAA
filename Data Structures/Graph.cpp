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

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

bool A[10][10];

void initialize()
{
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            A[i][j] = false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y, nodes, edges;
    initialize(); // Since there is no edge initially
    cin >> nodes; // Number of nodes
    cin >> edges; // Number of edges
    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y;
        A[x][y] = true; // Mark the edges from vertex x to vertex y
    }
    if (A[3][4] == true)
        cout << "There is an edge between 3 and 4" << endl;
    else
        cout << "There is no edge between 3 and 4" << endl;

    if (A[2][3] == true)
        cout << "There is an edge between 2 and 3" << endl;
    else
        cout << "There is no edge between 2 and 3" << endl;

    return 0;
}