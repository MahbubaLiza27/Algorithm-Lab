#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dl;

#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fraction() cout.unsetf( ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define mem(a, b) memset(a, b, sizeof(a) );
#define endl '\n'

int main()
{
    optimize();

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();
    int arr[n + 1][m + 1];
    int tracker[n + 1][m + 1];
    mem( arr, 0 );

    for(int i = 0; i<= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            cout << arr[n][m] << " ";
        }
        cout << endl;
    }
    cout << endl;


    for( int i = 1; i <= n; i++)
    {
        for( int j = 1; j <= m; j++)
        {
            if( s1[i - 1] == s2[j - 1] )
            {
                arr[i][j] = arr[i - 1][j - 1] + 1;
                tracker [i][j] = 'D';
            }
            else
            {
                if( arr[i - 1][j] >= arr[i][j - 1] )
                {
                    arr[i][j] = arr[i - 1][j];
                    tracker[i][j] = 'U';
                }
                else
                {
                    arr[i][j] = arr[i][j - 1];
                    tracker[i][j] = 'L';
                }
            }
        }
    }


    cout << endl;

    int i = n, j = m;
    vector <char> v;
    while( i > 0 && j > 0 )
    {
        if( tracker[i][j] == 'U' ) i--;
        else if( tracker[i][j] == 'L') j--;
        else if( tracker[i][j] == 'D' )
        {
            v.push_back( s1[i - 1] );
            i--;
            j--;
        }
    }
    reverse( v.begin(), v.end() );
    for( int i = 0; i < v.size(); i++ ) cout << v[i];

    cout << endl;

    cout << arr[n][m] << endl;


    return 0;
}


/*
abcbdab
bdcaba
*/

