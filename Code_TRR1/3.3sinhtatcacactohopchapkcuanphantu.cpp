#include<iostream>
using namespace std;
int a[25];
bool stop = false;
void create(int k){
    for(int i = 1; i <= k; i++){
        a[i] = i;
    }
}
void xuat(int k){
    for(int i = 1; i <= k; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
void sinhToHop(int k, int n){
    int i = k;
    while(i > 0 && a[i] == n-k+i){
        i = i-1;
    }
    if(i <= 0){
        stop =true;
    }
    else{
        a[i] = a[i] + 1;
        for(int j = i+1; j <=k; j++){
            a[j] = a[j-1] + 1;
        }
    }
}
void out(int k, int n){
    create(k);
    while(!stop){
        xuat(k);
        sinhToHop(k,n);
    }
}
int main(){
    int k,n;
    cin >> k >> n;
    out(k,n);
}
