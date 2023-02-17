#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dl;

#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fraction() cout.unsetf( ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define mem(a, b) memset(a, b, sizeof(a) );
#define endl '\n'


struct item{
    string name;
    int weight, price;
    double unit_price;
};

bool cmp(item a, item b){
    return a.unit_price > b.unit_price;
}

void bubbleSort(item arr[], int n){
       for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i -1; j++){
            if(arr[j].unit_price < arr[j+1].unit_price){
                swap( arr[j], arr[j+1] );
            }
        }
    }
}

void selectionSort( item arr[], int n ){
       for(int i = 0; i < n-1; i++){
            int max_idx = i;
            for(int j = i+1; j < n; j++){
                if(arr[max_idx].unit_price < arr[j].unit_price){
                    max_idx = j;
                }
            }
            if(max_idx != i){
                swap(arr[max_idx],arr[i]);
            }
       }
}
int main()
{
    optimize();

    int n;
    int bag;
    cin >> n >> bag;

    item arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i].name >> arr[i].weight >> arr[i].price;
    for(int i = 0; i < n; i++){
        arr[i].unit_price = arr[i].price / arr[i].weight;
    }

    bubbleSort( arr, n);
     for(int i = 0; i < n; i++) cout << arr[i].name << " " << arr[i].weight << " " << arr[i].price << " " << arr[i].unit_price << endl;

    int profit = 0;
    for(int i = 0; i < n; i++){
        int x = 0;
        if( bag != 0 ){
            x = min ( arr[i].weight, bag );
            bag -= x;
            arr[i].weight -= x;
            profit += (arr[i].unit_price * x);
            arr[i].price -= ( arr[i].unit_price * x );
        }
        else break;
    }
    cout << profit << endl;
    //for(int i = 0; i < n; i++) cout << "after stealing" << " " << arr[i].name << " " << arr[i].weight << " " << arr[i].price << " " << arr[i].unit_price << endl;

    return 0;
}


