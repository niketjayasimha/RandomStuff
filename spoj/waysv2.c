#define s(n) scanf("%d",&n)
typedef int I;a[14][14],t,n;I d(I m,I n){I s=a[m][n],k=(!m||!n)?1:(s?s:d(m-1,n)+d(m,n-1));s=k;return k;}main(){s(t);while(t--){s(n);printf("%d\n",d(n,n));}return 0;}
