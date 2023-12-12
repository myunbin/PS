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
const int MAX = 101010; // PLZ CHK!

string S;
int N,K,Z[MAX];

void z() {
    int p=1;
    for (int i=2; i<=N; i++) {
        if (i<=Z[p]+p-1) Z[i]=min(Z[p]+p-i,Z[i-p+1]);
        for (; i+Z[i]<=N && S[i+Z[i]]==S[Z[i]+1]; Z[i]++);
        if (p+Z[p]<i+Z[i]) p=i;
    }
}

int main() {
    fio();
    cin>>N>>K>>S;
    
    if (N<=K) {
        cout<<N;
        return 0;
    }

    S="?"+S;
    z();

    for (int i=N; i>=2; i--) {
        if (Z[i]==N-i+1 && 0<=2*(i-1)-N && 2*(i-1)-N<=K) {
            cout<<i-1;
            return 0;
        }
    }
    
    cout<<0;
    return 0;
}