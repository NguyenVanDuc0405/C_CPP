#include<bits/stdc++.h>
using namespace std;
int chuaxet[100];
int n;
int c[20][20];
int x[100];
int s = 0;
int MIN = 100000;

struct danhdau{
    vector<int>hoanvi;
    int min;
};
struct danhdau a[100];
int size = 0;
void nhap(){
    cin >> n;
    for(int i =1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
        }
    }
}
void TryH(int i){
    for(int j = 1; j <= n; j++){
        if(chuaxet[j] == 1){
            x[i] = j;
            chuaxet[j] = 0;
            s = s+ c[x[i-1]][x[i]];
            if(i == n){
                if(MIN > s+c[x[n]][x[1]]){
                    MIN = s+c[x[n]][x[1]];
                    a[size].min = MIN;
                    for(int k = 1; k<= n; k++){
                        a[size].hoanvi.push_back(x[k]);
                    }
                    size++;
                }
            }
            else{
                TryH(i+1);
            }
            chuaxet[j] = 1;
            s = s- c[x[i-1]][j];
        }
    }
}
int main(){
    
    for(int i = 0; i < 100; i++){
        chuaxet[i] = 1;
    }
    chuaxet[1] = 0;
    x[1] = 1;
    nhap();
    TryH(2);
    for(int i = 0; i< size; i++){
        if(a[i].min == MIN){
            cout << MIN << ".0" << endl;
            for(int j = 0; j < a[i].hoanvi.size(); j++){
                cout << a[i].hoanvi[j] << " ";
            }
            cout << "1";
            break;
        }
    }
    return 0;
}
