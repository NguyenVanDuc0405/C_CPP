#include<bits/stdc++.h>
using namespace std;
int a[20]={0};
int n;

void output(){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void nhiphan(int i){
    for(int j = 0; j <= 1; j++){
        a[i] = j;
        if(i == n- 1){
            output();
        }
        else{
            nhiphan(i+1);
        }
    }
}
int main(){
    cin>>n;
    nhiphan(0);
    return 0;
}
