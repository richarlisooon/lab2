#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab.h"

void create(mt ** arr,int *n){
	printf("n= ");
	scanf("%d",n);
	if (*n<=0)
		return;
	*arr=(mt*)calloc(*n,sizeof(mt));
	for (int i=0;i<*n;i++){
		printf("type= ");
		scanf("%s",(*arr)[i].type);
		printf("country= ");
		scanf("%s",(*arr)[i].country);
		printf("amount= ");
		scanf("%d",&(*arr)[i].amount);
	}
}
void read(mt **arr,int *n){
	FILE *fp=fopen("file.txt","r");
	if (!fp)
		return;
	if  (fscanf(fp,"%d",n)!=1){
		fclose(fp);
		return;
	}
	if (*n<=0){
		fclose(fp);
		return;
	}
	*arr=(mt *)calloc(*n,sizeof(mt));
	for (int i=0;i<*n;i++)
		fscanf(fp,"%s %s %d",(*arr)[i].type,(*arr)[i].country,&(*arr)[i].amount);
	fclose(fp);
}
void write(mt *arr,int n){
	if (n<=0)
		return;
	FILE *fp=fopen("file.txt","w");
	if (!fp)
		return;
	fprintf(fp,"%d\n",n);
	for (int i=0;i<n;i++){
		fprintf(fp,"%s %s %d\n",arr[i].type,arr[i].country,arr[i].amount);
	}
	fclose(fp);
	
}
void search(mt *arr,int n, int crit){
	char scountry[40];
	char stype[40];
	int samount;
	switch(crit){
		case 1:
			printf("what type do you need? ");
			scanf("%s",stype);
			while (getchar()!='\n'){
				for (int i=0;i<n;i++){
					if (!strcmp(arr[i].type, stype))
						printf("%s %s %d\n",arr[i].type,arr[i].country,arr[i].amount);
				}
			}
			break;
		case 2:
			printf("What country you want? ");
			scanf("%s",scountry);
			while (getchar()!='\n'){
				for (int i=0;i<n;i++){
					if (!strcmp(arr[i].country, scountry))
						printf("%s %s %d\n",arr[i].type,arr[i].country,arr[i].amount);
				}
			}
			break;
		case 3:
			printf("What amount do you need? ");
			scanf("%d",&samount);
			for (int i=0;i<n;i++){
				if (samount==arr[i].amount)
					printf("%s %s %d\n",arr[i].type,arr[i].country,arr[i].amount);
			}
			break;
		default:
			printf("error");
			break;
	}
}
