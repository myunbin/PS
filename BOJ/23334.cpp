#include <bits/stdc++.h>
using namespace std;

struct dd{int a,b,c; string s;};

int main() {
    int n;
    cin>>n;
    vector<dd> v(n);
    for (auto &[a,b,c,d]:v) {
        cin>>a>>b>>c;
        cin.ignore();
        getline(cin, d);   
    }
    
    sort(v.begin(), v.end(), [](dd x, dd y) {
        if (x.a==y.a) {
            if (x.b==y.b) return x.c<y.c;
            return x.b<y.b;
        }
        return x.a<y.a; 
    });

    cout<<v.back().s;
    return 0;
}