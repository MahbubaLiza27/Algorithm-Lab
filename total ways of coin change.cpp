#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dl;

#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fraction() cout.unsetf( ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define mem(a, b) memset(a, b, sizeof(a) );
#define endl '\n'

int main(){
    optimize();

    int n, amount;
    cin >> n >> amount;

    int coins[n];
    for(int i = 0; i < n; i++) cin >> coins[i];

    int row = n, col = amount + 1;
    int arr[row][col];
    for(int i = 0; i < row; i++) arr[i][0] = 1;

    for(int i = 0; i < row; i++){
        for(int j = 1; j < col; j++){
           if(i == 0) {
                if(j % coins[i] != 0) arr[i][j] = 0;
                else arr[i][j] = 1;
            }
            else if(j - coins[i] < 0) arr[i][j] = arr[i - 1][j];
            else arr[i][j] = arr[i - 1][j] + arr[i][j - coins[i]];
        }
    }
    cout << "Number of Ways : " << arr[row - 1][col - 1] << endl;


    return 0;
}


/*
3 5
1 2 3
*/
