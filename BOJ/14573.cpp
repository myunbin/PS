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
const int MAX = 1010101; // PLZ CHK!

int Q;
ll A[MAX],P[MAX];

void init() {
    A[1]=1, A[2]=1;
    P[1]=1, P[2]=2;
    ll t=2;
    for (int i=3; i<MAX; i++) {
        A[i]=(t+2ll)*A[i-1]%MOD;
        P[i]=(P[i-1]+A[i])%MOD;
        t=(t*2ll)%MOD;
    }
}

int main() {
    fio();
    init();

    cin>>Q;
    while (Q--) {
        int op; cin>>op;
        if (op==1) {
            ll k; int i,j;
            cin>>k>>i>>j;
            cout<<k*A[min(i,j)]%MOD<<endl;
        }
        if (op==2) {
            ll k; int i,j;
            cin>>k>>i>>j;

            int cnt=0;
            while (k%2==0) {
                k/=2;
                cnt++;
            }

            cout<<(cnt+(max(i,j)<3?0:max(i,j)-1))%MOD<<endl;
        }
        if (op==3) {
            ll k; int i,j;
            cin>>k>>i>>j;
            cout<<k*(P[j]-P[i-1]+MOD)%MOD<<endl;
        }
        if (op==4) {
            ll k; int i;
            cin>>k>>i;
            cout<<k*A[i]%MOD<<endl;
        }
    }
    return 0;
}