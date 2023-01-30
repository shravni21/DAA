/** tree data structure
 * 1. node - each component of the tree
 * 2. root - the root of the tree
 * 3. leaf - a node with no children or degree 0
 * 4. child - a node with a parent
 * 5. parent - a node with a child
 * 6. sibling - nodes at the same level
 * 7. ancestor - all nodes above a node
 * 8. descendant - subtree with the node as root
 * 9. degree - the number of children a node has
 * 10. Internal node - a node with degree > 0
 */

/** Application of tree data structure
 * 1. To represent hierarchical data
 *     a. Organizational structure
 *     b. Folder structure
 *     c. html/xml/json
 *     d. OOPs inheritance
 * 2. Binary Search Tree
 * 3. Binary Heap or Priority Queue
 * 4. B and B+ Tree in DBMS
 * 5. Spanning and Shortest Path Tree in Computer Network
 * 6. Parse Tree and Expression Tree in Compilers
 * 7. Trie - used to search words in a dictionary or prefix search
 * 8. Suffix Tree - used to fast search in a string
 * 9. Binary Indexed Tree - used for range query search
 * 10. Segment Tree - used for range query search
 */

// Binary tree - each node has at most 2 children

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

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
}
