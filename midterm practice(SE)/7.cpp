#include <stdio.h>
int main(){
	int n=0,m=0,k=0;
	int mata[50][50]={0};
	int matb[50][50]={0};
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			scanf("%d",&mata[i][j]);
		}
	} 
	for (int i=0;i<m;i++){
		for (int j=0;j<k;j++){
			scanf("%d",&matb[i][j]);
		}
	}
	int matc[50][50]={0};
	for (int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			for(int u=0;u<m;u++){
				matc[i][j]+=mata[i][u]^matb[u][j];
			}
		}
	}
	for (int i=0;i<n;i++){
		for(int j=0;j<k;j++){
		    if(j==k-1){
			    printf("%d\n",matc[i][j]);
		    }
		    else{
		        printf("%d ",matc[i][j]);	
			}
	    }
	}
	return 0;
}
