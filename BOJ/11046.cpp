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
const int MAX = 2020202; // PLZ CHK!

int N,A[MAX],P[MAX];

int main() {
    fio();
    cin>>N;
    A[0]=-1;
    for (int i=1,j=0; j<N; i+=2,j++) {
        cin>>A[i];
        A[i+1]=-1;
    }

    N=2*N+1;
    
    int r=-1, k=-1;
    for (int i=0; i<N; i++) {
        if (i<=r) P[i]=min(r-i, P[2*k-i]);
        while (i-P[i]-1>=0 && i+P[i]+1<N && A[i-P[i]-1]==A[i+P[i]+1]) P[i]++;
        if (r<i+P[i]) r=i+P[i], k=i;
    }

    int M;
    cin>>M;
    while (M--) {
        int l,r;
        cin>>l>>r;
        r--, l--;

        if (P[l+r+1]>=r-l+1) cout<<1<<endl;
        else cout<<0<<endl; 
    }

    return 0;
}