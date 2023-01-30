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
int top = -1;
void push(int stack[], int e, int n)
{
    if (top == n - 1)
    {
        cout << "stack is full.....overflow condition!" << nline;
    }
    else
    {
        top += 1;
        stack[top] = e;
    }
}
bool isempty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void pop()
{
    if (isempty())
    {
        cout << "stack is empty ......underflow condition!" << nline;
    }
    else
    {
        top -= 1;
    }
}
int size()
{
    return top + 1;
}
int topelement(int stack[])
{
    return stack[top];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cout << "enter the size of stack you want to enter initially" << nline;
    cin >> n;
    int stack[n];
    cout << "enter the elements" << nline;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        push(stack, temp, n);
    }
    cout << "current size of stack is " << size() << nline;

    // As the stack is full, further pushing will show an overflow condition.
    push(stack, 10, 3);
    cout << "current size of stack is " << size() << nline;

    // top element
    cout << "The current top element in stack is " << topelement(stack) << endl;

    // Removing all the elements
    for (int i = 0; i < n; i++)
    {
        pop();
    }
    cout << "current size of stack is " << size() << nline;

    // As the stack is empty , further popping will show an underflow condition.
    pop();
    return 0;
}