#include <bits/stdc++.h>
using namespace std;

typedef  long long lli;
typedef vector< long long int > vi;
typedef  double d;
typedef  pair<lli,pair<lli,lli> >  pipii;
#define bg begin()
#define rbg rbegin()
#define ren rend()
#define en end()
#define f first
#define s second
#define For(ii,aa,bb) for(lli ii=aa;ii<=bb;++ii)
#define Rof(ii,aa,bb) for(lli ii=aa;ii>=bb;--ii)
#define pb push_back
#define minf(a,b,c) min(min(a,b),c)
#define maxf(a,b,c) max(max(a,b),c)
#define mp make_pair
#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }

vector<string> split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return move(v);
}

void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
	err(++it, args...);
}

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;
///////////////////////////////////////////////////////////BULL SHIT CODE/////////////////////////////////////////////////////////////
lli backstep(lli i,lli a[]){
    lli curr=i;
    if(i==0) return -1;
    while(--curr>=0){  
        //if(curr==0) error(curr);
        if(a[curr]<=a[i]){
            return curr;
        }
    }
    if(curr==-1) return -1;
}

lli lis(lli n,lli a[],lli ans[],lli ck[]){
    ans[0]=1;

    For(i,1,n-1){
        lli maxi=INT_MIN;
        lli j=i;
        while((j=backstep(j,a))!=-1){
            //error(j);
            //error(j);
            if(maxi<1+ans[j]){
                ck[i]=j;
                maxi=1+ans[j];
            }
        }
        if(backstep(j,a)==-1) ans[i]=1;
        else ans[i]=maxi;   
    }
    lli maxi=INT_MIN,k;
    For(i,0,n-1){
        if(maxi<ans[i]){
            maxi=ans[i];
            k=i;
        }
    }
    return k;
}

int main(){
    lli n;
    cin>>n;
    lli a[n];
    lli ans[n];
    lli ck[n];
    ck[0]=-1;
    For(i,0,n-1) cin>>a[i];
    lli k=lis(n,a,ans,ck);
    For(i,0,n-1) error(i,ck[i],a[i],ans[i]);
    //cout<<a[k]<<endl;
    lli curr=k;
    list<lli> ls;
    while(1){
        if(curr==-1) break;
        ls.push_back(a[curr]);
        curr=ck[curr];
    }
    for(auto i:ls) cout<<i<<" ";
    cout<<endl;
}