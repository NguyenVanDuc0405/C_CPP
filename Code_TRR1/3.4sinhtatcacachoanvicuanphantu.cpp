#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int a[100];
bool check = true;
void Input(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        a[i] = i;
    }
}
void out(){
    for(int i = 1; i<= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void sinh(){
    int t = n;
    int ok = 1;
    int pos;
    while(t-1>=1){
        if(a[t-1] < a[t]){
            ok = 0;
            pos = t-1;
            break;
        }
        else{
            t--;
        }
    }
    if(ok == 1){
        check = false;
    }
    else{
        vector<int>arr;
        int x = a[pos];
        for(int i = pos+1; i<=n; i++){
            arr.push_back(a[i]);
        }
        sort(arr.begin(),arr.end());
        int size = 0;
        for(int i = pos+1; i<= n; i++){
            a[i] = arr[size++];
        }
        for(int i = pos+1; i<= n; i++){
            if(a[i] > a[pos]){
                swap(a[i],a[pos]);
                break;
            }
        }
    }
}
void Solve(){
    while(check == true){
        out();
        sinh();
    }
    check = true;
}
int main(){
    Input();
    Solve();
    return 0;
}
