#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define size 100
char* replace_str(char *s, char *T1, char *T2,int keyT1,int keyT2,int keyS){
	int i=0,j=0,k=0,back=0,forward=0,lens=keyS,t,eq,count=0;
	while(s[i]!='\0'){
	 	for(j=0;s[i]==T1[j];){
	 		i++;
	 		j++;
		}
		if(j==keyT1){
			count++;
			t=i-keyT1;
			j=0;
			for(; keyT1==keyT2 && T2[k]!='\0';){
				s[t]=T2[k];
				t++;
				k++;
			}
			if(keyT1>keyT2){
				forward=keyT1-keyT2;
				for(k=0;T2[k]!='\0';){
					s[t]=T2[k];
					t++;
					k++;
				}
				for(;s[t]!='\0';t++)
				   s[t]=s[t+forward];
			}
			if(keyT1<keyT2){
				back=keyT2-keyT1;
				for(;lens>=i;lens--){
					s[lens-1+back]=s[lens-1];
					if(lens-1+back>=size-1){
					  printf("Ìæ»»Ê§°Ü");
					  break;
				    }
				}
				for(t=i-keyT1,k=0;T2[k]!='\0';){
					s[t]=T2[k];
					t++;
					k++;
				}
			}
		}
		else
	        i++;
	}
	if(count==0){
		printf("\nSÖÐÎ´Æ¥Åäµ½T1\n"); 
	}
	return s;
} 
int main(){
	char s[size],T1[size],T2[size];
	int e;
	for(e=0;s[e]!='\0';e++)
	   s[e]=0;
	int keyT1=0,keyT2,keyS;
	int i=0,j=0,k=0;
	gets(s);
	gets(T1);
	gets(T2);
    while(s[i]!='\0'){
		i++;
	}
	keyS=i;
	while(T1[j]!='\0'){
		j++;
	}
	keyT1=j;
	while(T2[k]!='\0'){
		k++;
	}
	keyT2=k;
	if(j<i && j!=0){
		if(k>j){
			printf("\n"); 
		}
		else if(k==j){
			printf("\n");
		}
		else{
			printf("\n");
		}
        replace_str(s,T1,T2,keyT1,keyT2,keyS);
	    printf("Ìæ»»ºó£º%s\n",s);
    	
	}
	else
	   printf("SÖÐÆ¥Åä²»µ½T1");
	return 0;
}