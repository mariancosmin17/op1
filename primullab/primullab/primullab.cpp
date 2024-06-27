#include <iostream> 
#include<cstring>  
using namespace std; 
int functie(char p[]) 
{int i,nr=0; 
for(i=0;i<strlen(p);i++) 
{if(p[i]=='0') 
nr=nr*10+0; 
if(p[i]=='1') 
nr=nr*10+1; 
if(p[i]=='2') 
nr=nr * 10+2;
if(p[i]=='3') 
nr=nr * 10+3;
if(p[i]=='4') nr=nr * 10+4;
if(p[i]=='5') nr=nr * 10+5;
if(p[i]=='6') nr=nr * 10+6;
if(p[i]=='7') nr=nr * 10+7;
if(p[i]=='8') nr=nr * 10+8;
if(p[i]=='9') nr=nr * 10+9; }
return nr;  } 
int main() 
{char continut[20]; 
int numar,s=0;     
FILE *fp;     
fp=fopen("ini.txt","r");     
while(fgets(continut,20,fp)!=0)     
{numar=functie(continut);     
s=s+numar;     }     
cout<<s;     
fclose(fp);             
return 0; }