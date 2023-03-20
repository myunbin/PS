#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

#define fileio() freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define allr(x) x.rbegin(), x.rend()
#define cmprs(x) sort(all(x)),x.erase(unique(all(x)),x.end())
#define endl "\n"
#define sp " "
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define rz resize
#define sz(a) (int)(a.size())
#define clr(a) a.clear()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;

const ll MOD = 2000003;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

priority_queue<ll, vector<ll>, greater<ll>> pq;

void sv() {
    vector<ll> ip(MOD+1,1);
    ip[0]=ip[1]=0;
    for (ll i=2; i*i<=MOD; i++) {
        if (!ip[i]) continue;
        for (ll j=i*i; j<=MOD; j+=i) ip[j]=0;       
    }
    for (ll i=2; i<=MOD; i++) if (ip[i]) pq.push(i);
}

int main() {
    fio();
    sv();
    int n;
    cin>>n;
    
    ll ans=1;
    for (int i=0; i<n; i++) {
        ll t=pq.top(); pq.pop();
        ans=(ans*t)%MOD;
        if (ans==0) break;

        pq.push(t*t);
    }

    cout<<ans;
    
    return 0;
}