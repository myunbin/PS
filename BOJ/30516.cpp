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
const int MAX = 1010; // PLZ CHK!

int N,A[MAX];

int main() {
    fio();
    cin>>N;
    for (int i=1; i<=N; i++) cin>>A[i];

    if (N==2 && A[1]>0) {
        cout<<-1;
        return 0;
    }    
    
    vector<int> C;
    vector<vector<int>> B;
    for (int i=1; i<=N;) {
        int j;
        for (j=i; j<N && !(A[j]&&(A[j]==A[j+1])); j++);
        C.pb(j-i+1);
        i=j+1;
    }
    
    for (int i=0,j=1; i<sz(C); i++) {
        int x=C[i]; B.pb({});
        for (int k=j;x;x--,k++,j++) B.back().pb(A[k]);
    }

    if (sz(C)==2 && B[0][0]==B[1].back() && B[0][0]>0) {
        cout<<3<<endl;
        cout<<1<<sp<<C[0]-1<<sp<<C[1]<<endl;
        cout<<3<<sp<<2<<sp<<1;
    }
    else {
        cout<<sz(C)<<endl;
        for (int x:C) cout<<x<<sp; cout<<endl;
        for (int i=sz(C); i>=1; i--) cout<<i<<sp;
    }
    return 0;
}