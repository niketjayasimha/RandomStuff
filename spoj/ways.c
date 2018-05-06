#define S(z) scanf("%d",&z);
int f(int n){return n<2?2:f(n-1)*(4*n-2)/n;}
int main(){int t,m;S(t)while(t--){S(m)printf("%d\n",f(m));}return 0;}
