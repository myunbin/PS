#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000001;
typedef long long ll;

vector<ll> v(MAXN+1);
int sp[MAXN+1];
void sv() {
        for (int i = 2; i < MAXN; i++) sp[i] = i;
        for (int i = 4; i < MAXN; i+=2) sp[i] = 2;
        for (ll i = 3; i*i < MAXN; i++) {
            if (sp[i] == i) {
                for (ll j = i*i; j < MAXN; j+=i)
                    if (sp[j] == j) sp[j] = i;
            }
        }
}

map<int, int> fct(int x) {
    map<int, int> ret;
    while (x != 1) {
        ret[sp[x]]++;
        x = x / sp[x];
    }
    return ret;
}

void init() {
    for (int i=1; i<MAXN; i++) {
        map<int,int> d=fct(i);
        ll s=1;
        for (auto [x,y]:d) {
            ll t=1ll;
            for (int i=0; i<=y; i++) t*=(1ll)*x;
            t-=1, t/=1ll*(x-1);
            s*=t;
        }
        s-=i;
        v[i]=s;
    }
}

void solve() {
    ll n;
    cin>>n;
    if (v[n]>n) cout<<"abundant\n";
    else if (v[n]<n) cout<<"deficient\n";
    else cout<<"perfect\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sv();
    init();

    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}
