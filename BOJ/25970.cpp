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

int B,N;
ll L[MAX], H[MAX];
string X[MAX],Y[MAX],D[MAX];

int main() {
    fio();
    cin>>B;

    for (int i=0; i<B; i++) {
        cin>>X[i];
        ll d=1;
        for (int j=0; j<sz(X[i]); j++) {
            if (X[i][j]=='1') L[i]+=d;
            d*=2ll;
        }
    }

    for (int i=0; i<B; i++) {
        cin>>Y[i];
        ll d=1;
        for (int j=0; j<sz(Y[i]); j++) {
            if (Y[i][j]=='1') H[i]+=d;
            d*=2ll;
        }
    }

    cin>>N;
    for (int i=0; i<N; i++) {
        string s; cin>>s;
        int lo=0, hi=0;
        
        for (int j=0; j<B; j++) {
            if (sz(s)<sz(X[j])) continue;

            ll cur=0, d=1;
            for (int k=0; k<sz(X[j]); k++) {
                if (s[k]=='1') cur+=d;
                d*=2ll;
            }
            d/=2ll;

            for (int k=1; k+sz(X[j])<=sz(s); k++) {
                if (cur==L[j]) lo++;
                cur>>=1ll;
                if (s[k+sz(X[j])-1]=='1') cur+=d;
            }
            if (cur==L[j]) lo++;
        }

        for (int j=0; j<B; j++) {
            if (sz(s)<sz(Y[j])) continue;

            ll cur=0, d=1;
            for (int k=0; k<sz(Y[j]); k++) {
                if (s[k]=='1') cur+=d;
                d*=2ll;
            }
            d/=2ll;

            for (int k=1; k+sz(Y[j])<=sz(s); k++) {
                if (cur==H[j]) hi++;
                
                cur>>=1ll;
                if (s[k+sz(Y[j])-1]=='1') cur+=d;
            }
            if (cur==H[j]) hi++;
        }

        if (lo==hi) cout<<"GOOD\n";
        else cout<<(hi>lo?"LOW ":"HIGH ")<<abs(lo-hi)<<endl;     
    }
    return 0;
}