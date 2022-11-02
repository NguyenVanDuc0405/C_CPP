#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <stack>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
string s;
void test () {
    cin >> s;
    stack <string> st;
    for (auto i:s) {
        if (i == '-' || i == '+' || i == '*' || i == '/' || i == '%' || i == '^') {
            string fi = st.top(); st.pop();
            string se = st.top(); st.pop();
            string temp = i + se + fi;
            st.push(temp);
        }
        else    st.push(string(1, i));
    }
    cout << st.top() << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}