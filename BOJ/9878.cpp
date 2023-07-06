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

int main() {
    fio();
    int n;
    cin>>n;
    
    priority_queue<int,vector<int>,greater<int>> t,d;
    for (int i=0; i<n; i++) {
        char c; int x;
        cin>>c>>x;
        if (c=='T') t.push(x);
        else d.push(x);
    }
    d.push(1000);

    double cd=0.0, ct=0.0;
    int cv=1;

    while (!d.empty()) {
        bool okt=0;
        if (!t.empty()) {
            double nd=1.0*d.top(), nt=1.0*t.top();
            if (nt<(nd-cd)*1.0*cv+ct) okt=1;
        }

        if (okt) {
            double nt=1.0*t.top(); t.pop();
            cd+=(nt-ct)/(1.0*cv);
            ct=nt;  
        }
        else {
            double nd=1.0*d.top(); d.pop();
            ct+=(nd-cd)*1.0*cv;
            cd=nd;
        }
        cv++;
    }
    
    cout<<(int)(ct+0.5);
    return 0;
}