#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int>a;
bool check = true;
void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        a.push_back(0);
    }
}
void out(){
    for(int i:a){
        cout << i << ' ';
    }
    cout << endl;
}
void Handle(){
    int k = n-1;
    while(k >=0){
        if(a[k] == 0){
            a[k] = 1;
            break;
        }
        else {
            a[k] = 0;
            k--;
        }
    }
    if(k < 0){
        check = false;
    }
}
void solve(){
    while(check == true){
        out();
        Handle();
    }
    a.clear();
    check = true;
}
int main(){
    input();
    solve();
}
