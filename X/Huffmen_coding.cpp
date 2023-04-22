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

#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

struct TreeNode
{
    char data;
    int freq;
    TreeNode *left;
    TreeNode *right;

    TreeNode(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        this->left = nullptr;
        this->right = nullptr;
    }

    bool isLeaf() const
    {
        return left == nullptr && right == nullptr;
    }
};

struct Compare
{
    bool operator()(TreeNode *left, TreeNode *right)
    {
        return left->freq > right->freq;
    }
};

void encode(TreeNode *root, string str, unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->isLeaf())
    {
        huffmanCode[root->data] = str != "" ? str : "1";
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void decode(TreeNode *root, int &index, string str)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->isLeaf())
    {
        cout << root->data;
        return;
    }

    index++;

    if (str[index] == '0')
    {
        decode(root->left, index, str);
    }
    else
    {
        decode(root->right, index, str);
    }
}

void buildHuffmanTree(string text)
{
    unordered_map<char, int> freqMap;
    for (char ch : text)
    {
        freqMap[ch]++;
    }

    priority_queue<TreeNode *, vector<TreeNode *>, Compare> pq;

    for (auto pair : freqMap)
    {
        pq.push(new TreeNode(pair.first, pair.second));
    }

    while (pq.size() > 1)
    {
        TreeNode *left = pq.top();
        pq.pop();
        TreeNode *right = pq.top();
        pq.pop();

        TreeNode *parent = new TreeNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    unordered_map<char, string> huffmanCode;
    encode(pq.top(), "", huffmanCode);

    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode)
    {
        cout << pair.first << " " << pair.second << endl;
    }

    cout << "Original text: " << text << endl;

    string encodedText = "";
    for (char ch : text)
    {
        encodedText += huffmanCode[ch];
    }

    cout << "Encoded text: " << encodedText << endl;

    int index = -1;
    cout << "Decoded text: ";
    while (index < (int)encodedText.size() - 2)
    {
        decode(pq.top(), index, encodedText);
    }
}

int main()
{
    string text = "Hello I am shravni wakde.";

    buildHuffmanTree(text);

    return 0;
}
