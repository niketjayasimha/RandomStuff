#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int n, flag;
	char a[120];
	char b[120];
	int x, carry;
	int i,j,len;
	char t;
	while(scanf("%s",a)!=EOF)
	{
		j=0;
		carry=0;
		len=strlen(a);
		if(len==1)
		{
			if(atoi(a)==1)
				n=1;
			else
				n=2*atoi(a)-2;
			printf("%d\n",n);
		}
		else
		{
			for(i=len-1;i>=0;i--)
			{
				x=a[i]-'0';
				x=2*x;
				b[j++]=('0'+(x%10)+carry);
				carry=0;
			
				//if(i!=0)
				//	b[j++]=('0'+(x%10))+('0'+carry);
				if(x>=10)
					carry=x/10;
				if(i==0)
				{
					b[j++]=carry+'0';
					b[j]='\0';
				}
			}
			//printf("%s\n",b);
			
			// subtract 2
			flag=-2;
			for(i=0;i<strlen(b);i++)
			{
				//flag=0;
				if((b[i]-'0')+flag<0)
				{
					//flag=-2
					b[i]='0'+10+flag;
					flag=-1;
				}
				else
				{
					b[i]=b[i]+flag;
					break;
				}
			}
			for(i=0;i<strlen(b)/2;i++)
			{
				t=b[i];
				b[i]=b[strlen(b)-i-1];
				b[strlen(b)-i-1]=t;
			}
			for(i=0;i<strlen(b);i++)
			{
				if(i==0)
				{
					if(b[i]!=0+'0')
						printf("%c",b[i]);
				}
				else
					printf("%c",b[i]);
			}
			printf("\n");
		
				
		}
	}
	return 0;
}
