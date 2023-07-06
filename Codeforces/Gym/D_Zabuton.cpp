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

const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 5050; // PLZ CHK!

int main() {
    fio();
    int n;
    cin>>n;
    
    pll v[MAX]; v[0]={0,0};
    ll d[MAX]; d[0]=0;
    for (int i=1; i<=n; i++) {
        cin>>v[i].S>>v[i].F;
        d[i]=LINF;
    }
    sort(v+1, v+n+1, [](pll a, pll b){
        return a.F+a.S<b.F+b.S;
    });

    for (int i=1; i<=n; i++) {
        for (int j=n; j>=1; j--) {
            if (d[j-1]<=v[i].S) {
                d[j]=min(d[j], d[j-1]+v[i].F);
            }
        }
    }

    int ans=0;
    for (int i=n; i>=1; i--) {
        if (d[i]<LINF) {
            cout<<i;
            break;
        }
    }
    return 0;
}