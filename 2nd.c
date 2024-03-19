#include<stdio.h>
char str[100],pat[100],rep[100],ans[100];
int c=0,m=0,i=0,j=0,k ,flag = 0;
void stringmatch()
{
while ( str[c] != '\0')
{
if ( str[m] == pat[i] )
{
i++;
m++;
if (pat[i] == '\0')
{
flag=1;
for(k= 0; rep[k] != '\0';k++, j++)
ans[j] =rep[k];
i= 0;
c=m;
}
}
else 
{
ans[j] =str[c];
j++;
c++;
i = 0;
m=c;
}
}
ans[j]='\0';
}
void main()
{
printf("Enter the MAIN string: \n");
gets(str);
printf("Enter a PATTERN string: \n");
gets(pat);
printf("Enter a REPLACE string: \n");
gets(rep);
stringmatch();
if(flag==1)
printf("\n resultant string is :\t%s\n",ans);
else
printf("\n pattern string is not found");
} 
