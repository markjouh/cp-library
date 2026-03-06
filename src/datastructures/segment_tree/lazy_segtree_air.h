template<class T,auto op,auto e,class U,auto mp,auto cp,auto ie>
struct LST{
int n,L,S;vector<T>s;vector<U>z;
void ap(int i,U v){s[i]=mp(s[i],v);if(i<S)z[i]=cp(z[i],v);}
void ps(int i){ap(2*i,z[i]);ap(2*i+1,z[i]);z[i]=ie();}
void pl(int i){s[i]=op(s[2*i],s[2*i+1]);}
#define PD for(int _=L;_;_--)ps(l>>_),ps(r-1>>_);
#define PU for(int _=1;_<=L;_++){if(l>>_<<_!=l)pl(l>>_);if(r>>_<<_!=r)pl(r-1>>_);}
LST(){}
LST(int n,T v=e()):LST(vector<T>(n,v)){}
LST(vector<T>a):n(a.size()),L(__lg(n-1)+1),S(1<<L),s(2*S,e()),z(S,ie()){copy(all(a),s.begin()+S);for(int i=S;--i;)pl(i);}
void set(int p,T v){int l=p+S,r=l+1;PD s[l]=v;PU}
void upd(int p,U v){upd(p,p,v);}
void upd(int l,int r,U v){l+=S;r+=S+1;PD for(int a=l,b=r;a<b;a>>=1,b>>=1){if(a&1)ap(a++,v);if(b&1)ap(--b,v);}PU}
T get(int p){return qry(p,p);}
T qry(int l,int r){l+=S;r+=S+1;PD T a=e(),b=e();for(int x=l,y=r;x<y;x>>=1,y>>=1){if(x&1)a=op(a,s[x++]);if(y&1)b=op(s[--y],b);}return op(a,b);}
#undef PD
#undef PU
};
