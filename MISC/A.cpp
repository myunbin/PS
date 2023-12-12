#include <bits/stdc++.h>
using namespace std;

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

int N,K;
pii go(int s, vector<int> &A) {
    int p=s,sum=0,cnt=0;
    while (sum<5) sum+=A[p], p=(p+1)%N, cnt++;
    if (sum==5) {
        while (sum<8) sum+=A[p], p=(p+1)%N, cnt++;
        if (sum==8) {
            while (sum<12) sum+=A[p], p=(p+1)%N, cnt++;
        }
        else {
            while (sum<17) sum+=A[p], p=(p+1)%N, cnt++;
        }
    }
    else {
        while (sum<10) sum+=A[p], p=(p+1)%N, cnt++;
        if (sum==10) {
            while (sum<17) sum+=A[p], p=(p+1)%N, cnt++;
        }
        else {
            while (sum<21) sum+=A[p], p=(p+1)%N, cnt++;
        }
    }

    return {p,cnt};
}

void solve() {
    cin>>N>>K;

    vector<int> A(N);
    vector<ll> V(N,-1),J(N,0);
    for (int &x:A) cin>>x;

    ll mv=0,ans=0; int cur=0;
    V[0]=0;
    for (int i=0; i<N; i++) {
        auto [nxt,jmp]=go(cur,A);
        if (mv+jmp>1ll*N*K) break;
        ans++;
        mv+=jmp;

        if (V[nxt]!=-1) {
            ll per=mv-V[nxt], cnt=ans-J[nxt];
            ans+=(1ll*N*K-mv)/per*cnt;
            mv+=(1ll*N*K-mv)/per*per;
        }
        
        V[nxt]=mv;
        J[nxt]=ans;
        cur=nxt;
    }

    cout<<ans<<endl;
}

int main() {
    fio();
    int T;
    cin>>T;
    for (int i=1; i<=T; i++) {
        cout<<"Case #"<<i<<endl;
        solve();
    }

    return 0;
}