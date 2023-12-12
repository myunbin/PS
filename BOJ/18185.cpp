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
const int MAX = 10101; // PLZ CHK!

int N;
ll A[MAX],B=3,C=2,ans;
ll X[MAX],Y[MAX];

int main() {
    fio();
    cin>>N;
    for (int i=1; i<=N; i++) cin>>A[i];

    if (B<=C) {
        for (int i=1; i<=N; i++) ans+=A[i]*B;
        cout<<ans;
        return 0;
    }

    for (int i=1; i<=N; i++) {
        ans+=A[i]*B;
        if (i+1<=N) {
            ll mn=min(A[i],A[i+1]);
            ans+=mn*C;
            A[i+1]-=mn;
            X[i]+=mn;
        }
        if (1<=i-1 && i+1<=N) {
            ll mn=min(X[i-1],A[i+1]);
            ans+=mn*C;
            A[i+1]-=mn;
        }
    }

    cout<<ans;
    return 0;
}