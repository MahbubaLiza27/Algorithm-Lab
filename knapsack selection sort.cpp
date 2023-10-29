#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) (v).begin(),(v).end()

struct item{
    int name, weight, price;
};

int main() {

   int sz, n;
    cin >> sz >> n;

    item arr[n + 1];
    for(int i = 1; i <= n; i++) cin >> arr[i].name >> arr[i].weight >> arr[i].price;

    int row = n+1;
    int col = sz+1;

    int knapsack[row][col];
    memset(knapsack, 0, sizeof(knapsack));

    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            if(j - arr[i].weight < 0) knapsack[i][j] = knapsack[i-1][j];
            else knapsack[i][j] = max(knapsack[i-1][j], knapsack[i-1][j-arr[i].weight]+arr[i].price);
        }
    }

    cout << knapsack[row-1][col-1] << endl;

    row--, col--;
    vector<int> ans;
    while(row>0 && col>0){
        if(knapsack[row][col] == knapsack[row-1][col]) row--;
        else{
            ans.push_back(arr[row].name);
            col -= arr[row].weight;
            row--;
        }
    }
    reverse(all(ans));

    cout << "Selected Items : " << endl;
    for(auto u:ans) cout << u << " ";
        cout << endl;

}

