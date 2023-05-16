#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, amount;
    cout << "Enter amount : ";
    cin >> amount;

    cout << "Enter total number of coins : ";
    cin >> n;

    int coins[n];
    cout << "Enter coins : ";
    for(int i = 0;i < n;i++) cin >> coins[i];

    int row = n + 1, col = amount + 1;

    int arr[row][col];
    for(int i = 0;i < row;i++) arr[i][0] = 0;
    for(int j = 1;j < col;j++) arr[0][j] = amount + 1;

    for(int i = 1;i < row;i++){
        for(int j = 1;j < col;j++){
            if(j - coins[i - 1] < 0) arr[i][j] = arr[i - 1][j];
            else arr[i][j] = min(arr[i - 1][j], arr[i][j - coins[i - 1]] + 1);
        }
    }

    cout << "Minimum numbers of coins needed : " << arr[row - 1][col - 1] << endl;

    vector<int> ans;
    row--, col--;
    while(row > 0 && col > 0){
        if(arr[row][col] == arr[row - 1][col]) row--;
        else{
            ans.push_back(coins[row - 1]);
            col -= coins[row - 1];
        }
    }

    cout << "Coins selected : ";
    for(auto x : ans){
        cout << x << " ";
    }

    return 0;
}

