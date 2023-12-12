#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

#define fileio() freopen("herding.in","r",stdin); freopen("herding.out","w",stdout)
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

int N,A[MAX];
int main() {
    fio();

    cin>>N;
    for (int i=0; i<N; i++) cin>>A[i];
    sort(A,A+N);
    
    int mn=N-1;

    for (int i=0; i<N; i++) {
        int j=ub(A,A+i,A[i]-N+1)-A-1;
        if (j<0 || A[i]-N+1<1) continue;
        if (A[j]==A[i]-N+1) {
            mn=min(mn, N-1-i+j);
        }
        else {
            mn=min(mn, N-1-i+j+1);
        }
    }

    if (A[N-1]-A[1]==N-2 && A[1]-A[0]>2) mn=2;
    if (A[N-2]-A[0]==N-2 && A[N-1]-A[N-2]>2) mn=2;

    cout<<mn<<endl<<max(A[N-2]-A[0], A[N-1]-A[1])-N+2;
    return 0;
}