#include<bits/stdc++.h>
using namespace std;
int k,n;
int a[25];

void output(){
    for(int i = 1; i <= k; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void tohop(int i){
    for(int j = a[i-1]+1; j<= n-k+i; j++){
        a[i] = j;
        if(i == k){
            output();
        }
        else{
            tohop(i+1);
        }
    }
}
int main(){
    cin>>n>>k;
    tohop(1);
    return 0;
}
