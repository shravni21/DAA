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
#define ROW_1 4
#define COL_1 4

#define ROW_2 4
#define COL_2 4

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;

// Time Complexity: O(n^3)
// Generally Strassen’s Method is not preferred for practical applications for following reasons.
/* 1. The constants used in Strassen’s method are high and for a typical application Naive method works better.
   2.For Sparse matrices, there are better methods especially designed for them.
   3.The submatrices in recursion take extra space.
   4.Because of the limited precision of computer arithmetic on noninteger values,
 larger errors accumulate in Strassen’s algorithm than in Naive Method
*/

void print(string display, vvi matrix,
           int start_row, int start_column, int end_row,
           int end_column)
{
    cout << endl
         << display << " =>" << endl;
    for (int i = start_row; i <= end_row; i++)
    {
        for (int j = start_column; j <= end_column; j++)
        {
            cout << setw(10);
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return;
}

void add_matrix(vvi matrix_A,
                vvi matrix_B,
                vvi &matrix_C,
                int split_index)
{
    for (auto i = 0; i < split_index; i++)
        for (auto j = 0; j < split_index; j++)
            matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
}

vvi multiply_matrix(vvi matrix_A,
                    vvi matrix_B)
{
    int col_1 = matrix_A[0].size();
    int row_1 = matrix_A.size();
    int col_2 = matrix_B[0].size();
    int row_2 = matrix_B.size();

    if (col_1 != row_2)
    {
        cout << "\nError: The number of columns in Matrix "
                "A must be equal to the number of rows in "
                "Matrix B\n";
        return {};
    }

    vector<int> result_matrix_row(col_2, 0);
    vvi result_matrix(row_1,
                      result_matrix_row);

    if (col_1 == 1)
        result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
    else
    {
        int split_index = col_1 / 2;

        vector<int> row_vector(split_index, 0);
        vvi result_matrix_00(split_index,
                             row_vector);
        vvi result_matrix_01(split_index,
                             row_vector);
        vvi result_matrix_10(split_index,
                             row_vector);
        vvi result_matrix_11(split_index,
                             row_vector);

        vvi a00(split_index, row_vector);
        vvi a01(split_index, row_vector);
        vvi a10(split_index, row_vector);
        vvi a11(split_index, row_vector);
        vvi b00(split_index, row_vector);
        vvi b01(split_index, row_vector);
        vvi b10(split_index, row_vector);
        vvi b11(split_index, row_vector);

        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++)
            {
                a00[i][j] = matrix_A[i][j];
                a01[i][j] = matrix_A[i][j + split_index];
                a10[i][j] = matrix_A[split_index + i][j];
                a11[i][j] = matrix_A[i + split_index]
                                    [j + split_index];
                b00[i][j] = matrix_B[i][j];
                b01[i][j] = matrix_B[i][j + split_index];
                b10[i][j] = matrix_B[split_index + i][j];
                b11[i][j] = matrix_B[i + split_index]
                                    [j + split_index];
            }

        add_matrix(multiply_matrix(a00, b00),
                   multiply_matrix(a01, b10),
                   result_matrix_00, split_index);
        add_matrix(multiply_matrix(a00, b01),
                   multiply_matrix(a01, b11),
                   result_matrix_01, split_index);
        add_matrix(multiply_matrix(a10, b00),
                   multiply_matrix(a11, b10),
                   result_matrix_10, split_index);
        add_matrix(multiply_matrix(a10, b01),
                   multiply_matrix(a11, b11),
                   result_matrix_11, split_index);

        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++)
            {
                result_matrix[i][j] = result_matrix_00[i][j];
                result_matrix[i][j + split_index] = result_matrix_01[i][j];
                result_matrix[split_index + i][j] = result_matrix_10[i][j];
                result_matrix[i + split_index]
                             [j + split_index] = result_matrix_11[i][j];
            }

        result_matrix_00.clear();
        result_matrix_01.clear();
        result_matrix_10.clear();
        result_matrix_11.clear();
        a00.clear();
        a01.clear();
        a10.clear();
        a11.clear();
        b00.clear();
        b01.clear();
        b10.clear();
        b11.clear();
    }
    return result_matrix;
}

int main()
{
    vvi matrix_A = {{1, 1, 1, 1},
                    {2, 2, 2, 2},
                    {3, 3, 3, 3},
                    {2, 2, 2, 2}};

    vvi matrix_B = {{1, 1, 1, 1},
                    {2, 2, 2, 2},
                    {3, 3, 3, 3},
                    {2, 2, 2, 2}};

    vvi result_matrix(
        multiply_matrix(matrix_A, matrix_B));

    print("Result Array", result_matrix, 0, 0, ROW_1 - 1,
          COL_2 - 1);
}
