 #include <stdio.h>
 int main()
 {
         int i,w;
         for(;;)
         {
                 scanf("%d %d",&i,&w);
		 if(i==-1&&w==-1)
                 break;
  		else if(1000*w==37*i)
		printf("Y\n");
		else
		printf("N\n");
	}
	return 0;
}
