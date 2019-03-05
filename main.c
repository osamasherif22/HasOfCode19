#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main()
{
    LOAD();
    /* //print the file
    printf("*%d*\n",Num_photos);
for (int i=0;i<Num_photos;i++)
{
    //printf("%d",i);
    printf("%c %d ",photos[i].type,photos[i].num_tags);
    for(int j=0;j<photos[i].num_tags;j++)
    {
    printf("[%s]",photos[i].tags[j]);
    }
    printf("\n");
}*/
for(int i=0 ; i<10000 ; i++){
    for(int j=0 ; j<10000 ; j++){
        ans[i][j]=-1;
    }
}
    /* // try factor
    printf("0 factor 1 is %d\n",factor(0,1));
     printf("1 factor 2 is %d\n",factor(1,3));
     printf("0 factor 2 is %d\n",factor(0,3));
    arr(1);
     int z=0;
     while(ans[1][z]!=-1){
        printf(" %d\n",ans[1][z]);
        if(photos[ans[1][z]].type=='V'){
            printf(" %d\n",photos[ans[1][z]].id2);
        }
        z++;
     }
     z++;
     printf(" %d\n",ans_score[score_count]);*/
     for(int i=0;i<Num_photos;i++){
        arr(i);
        zero();
     }
     int x =max_score();
     int z=0;
     int co=0;
     FILE*fptr;
    fptr=fopen("b_out.out","w+");
     while(ans[x][z]!=-1){
        fprintf(fptr,"%d",ans[x][z]);
        co++;
        if(photos[ans[x][z]].type=='V'){
            fprintf(fptr," %d\n",photos[ans[x][z]].id2);
        }
        else{
            fprintf(fptr,"\n");
        }
        z++;
     }
     fprintf(fptr,"---------------------\n");
     fprintf(fptr," %d",co);
     //printf("-----------close please----------\n");



return 0;
}

