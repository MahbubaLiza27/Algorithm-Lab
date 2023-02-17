#include<bits/stdc++.h>
using namespace std;
#define ll long long


struct activity{
    int start_time, end_time;
};

bool cmp(activity x1, activity x2){
    return (x1.end_time < x2.end_time);
}

int main(){

    int n;
    cin >> n;

    activity arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i].start_time >> arr[i].end_time;
    }

    sort(arr, arr + n, cmp);

    int cnt = 1;
    int temp = arr[0].end_time;
    for(int i = 0;i < n;i++){
        cout << arr[i].start_time << " " << arr[i].end_time << endl;
    }

    cout << "Activities selected : " << 1 << " ";

    for(int i = 1;i < n;i++){
        if(arr[i].start_time >= temp){
            cout << i + 1 << " ";
            cnt++;
            temp = arr[i].end_time;
        }
    }

    cout << endl;

    cout << "Total activities : " <<  cnt << endl;

    return 0;
}

