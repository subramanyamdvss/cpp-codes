
// NAME: DVSS SUBRAMANYAM ROLL NO: 15CS10013 MACHINE NUMBER :56 ,,QUESTION PAPER :EVEN

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

// NAME: DVSS SUBRAMANYAM ROLL NO: 15CS10013 MACHINE NUMBER :56 ,,QUESTION PAPER :EVEN



//if s[i] is sum of elements from 0 to i ,, and p[i] be the value which we want s[i] to be
//then s[i]=p[i] only if any of s[i-1]+a[i] or s[i-1]-b[i] is equal to p[i] so we can calculate the value of p[i-1] if we know which
//one whether a[i] or -b[i] is the right number


lli S(lli i,lli s[],lli *a ,lli *b, lli n , lli p[],lli ck[]){
    if(s[i]!=-1000000){
        return s[i];
    }
    if(i==0){

        return 0;
    }
    if(s[i]==-1000000){
        if(s[i-1]==-1000000){
            p[i-1]=p[i]-a[i];
            lli q=S(i-1,s,a,b,n,p,ck);
            if(q+a[i]==p[i]){

                ck[i]=0;
                s[i]=q+a[i];
            }
            p[i-1]=p[i]+b[i];
            q=S(i-1,s,a,b,n,p,ck);

            if(q-b[i]==p[i]){

                p[i-1]=p[i]+b[i];
                ck[i]=1;

                s[i]=q-b[i];
            }
            return s[i];
        }

        /*if(s[i-1]!=-1000000){
            error("qq");
            lli q=s[i-1];
            if(q+a[i]==p[i]){
                p[i-1]=p[i]-a[i];
                ck[i]=0;
                s[i]=q+a[i];
            }
            if(q-b[i]==p[i]){
                p[i-1]=p[i]+b[i];
                ck[i]=1;
                s[i]=q-b[i];
            }
            return s[i];
        }*/

    }
}


bool choiceexists(lli *a,lli *b, lli n,lli * ck){
    lli p[n];
    memset(p,0,sizeof(p));
    lli s[n];
    For(i,0,n-1){
        s[i]=-1000000;
    }

    p[n-1]=0;

    lli q=S(n-1,s,a,b,n,p,ck);
    if(q==0){

        return true;

    }
    else false;

}


void printchoice(lli *a,lli *b,lli n,lli * ck){
    lli suma=0,sumb=0;
    For(i,1,n-1){
        if(ck[i]==0){
            cout<<a[i]<<" ";
            suma+=a[i];
        }
        else{
            sumb+=b[i];
            cout<<-b[i]<<" ";
        }
    }
    cout<<endl;
    cout<<"\nsum of elements choosen from X is :"<<suma<<endl;
    cout<<"\nsum of elements choosen from Y is :"<<sumb<<endl;
    return;
}







int main(){
    lli n;
    cin>>n;
    lli a[n+1],b[n+1];
    cout<<"input a:\n";
    For(i,1,n){
        cin>>a[i];
    }
    a[0]=0;
    cout<<"input b:\n";
    For(i,1,n){
        cin>>b[i];
    }
    b[0]=0;
    lli ck[n+1];
    memset(ck,0,sizeof(ck));
    if(choiceexists(a,b,n+1,ck)){
        cout<<" yes the choice exists"<<endl;
        printchoice(a,b,n+1,ck);
    }
    else cout<<"  the choice doesnt exists"<<endl;

}






















