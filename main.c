#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main()
 {
    LOAD();
     //print the file
    /*printf("*%d*\n",Num_photos);
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
printf("************load sucssfully****************** \n");
//DP>>>>>>>>>>
for(int i=0 ; i<2 ; i++){
    for(int j=0 ; j<100000 ; j++){
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
     //for(int i=0;i<Num_photos;i++){

        arrange(488);
                    int k =0 ;

                    numOfUsed--;
        for(k;k<Num_photos;k++)
        {

       if(!photos[k].f_used&&photos[k].type!='N')
       {
        photos[k].f_used=1;
        ans[0][numOfUsed]=photos[k].id1;
        numOfUsed++;
        printf("oooo\n");

       }
                    }
       // zero();
     //}
     //int x =max_score();
     int z=0;
     int co=0;
     FILE*fptr;
     fptr=fopen("new_bfileOutput.txt","w+");
    while(z!=numOfUsed){
        printf("%d",ans[0][z]);
        fprintf(fptr,"%d",ans[0][z]);
        co++;
        if(photos[ans[0][z]].type=='V'){
            printf(" %d\n",photos[ans[0][z]].id2);
            fprintf(fptr," %d\n",photos[ans[0][z]].id2);

        }
        else{
            printf("\n");
            fprintf(fptr,"\n");

        }
        z++;
     }

     printf("---------------------\n");
     printf("%d\n",--co);
     fseek(fptr,0,SEEK_SET);
    fprintf(fptr,"%d\n",co);


     printf("-----------scores----------\n");
    //for(int m =0;m<score_count;m++){
        printf("%d\n",ans_score);
        //printf("max is :::%d\n",ans_score[x]);
     //}
     fclose(fptr);



return 0;
}

