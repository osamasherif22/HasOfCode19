#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int id1;
  int id2;
  char type;
  int num_tags;
  char tags[100][20];
  int f_used ;
}photo;
photo photos[100000];
int ans[10000][10000];
int ans_score[100000];
int score_count=0;


id1=-1;  id2=-1; int Num_photos=0;   int J =0;


//int id1=0,c=0,min=0,max=0,;

/*************** LOAD FUNCTION ****************/
// important the two vertical have a gap in the array with type N
void LOAD ()
{
    int flagl=0;
    int f=0;
    system("cls");
    FILE *fRptr ;
    fRptr = fopen("b_lovely_landscapes.txt","r");
    if (fRptr == NULL)
    {
        printf("\n");
    }
    else
    {
        while(!feof(fRptr))
        {
            if (flagl==0){
            fscanf(fRptr,"%d\n",&Num_photos);
            }
            else
            {
                /* loading records from file **/
             photos[J].id1=J;
             fscanf(fRptr,"%c\t%d\t",&photos[J].type,&photos[J].num_tags);

             int happen =0;
             int save;
             if(photos[J].type=='V'){
                if(f==0){
                   save=J;
                   f=1;
                }
                else{
                   // photos[save].type ='H'; istopped it to know when we print that there are two pics
                   photos[J].type='N';
                    int previous = photos[save].num_tags;
                    photos[save].num_tags=photos[save].num_tags+photos[J].num_tags;
                    for (int i=0;i<photos[save].num_tags-previous;i++)
                    {
                        fscanf(fRptr,"\t%s",photos[save].tags[previous+i]);
                    }
                    f=0;
                    photos[save].id2=J;
                    //J--;
                    happen=1;
                    //Num_photos--;
                }
             }
             if(!happen){
             for (int i=0;i<photos[J].num_tags;i++)
            {
              fscanf(fRptr,"\t%s",photos[J].tags[i]);
            }
             }
            J++;
            fscanf(fRptr,"\n");
            }
            flagl=1;
         }
    }
            fclose(fRptr);
}
//---------------------------------------------------------------
/*********************************factor function********************************/
int factor(int photo1,int photo2 )
{
    //printf("photo %d tag is %s\n",0,photos[photo1].tags[0]);
        //printf("photo %d tag is %s\n",1,photos[photo2].tags[0]);
    int i,kom=0,s1s2=0,s2s1=0,flag = -1;
    int k;
    for(i=0;i< photos[photo1].num_tags;i++)
        {
            for(k=0;k< photos[photo2].num_tags;k++)
                {
                    //printf("pic  %d with  %d\n",photo1,photo2);

                    if(!(strcmp(photos[photo1].tags[i] , photos[photo2].tags[k])))
                    {
                                           // printf("i  is %d k is %d\n",i,k);

                       // printf("%s %s\n", photos[photo1].tags[i],photos[photo2].tags[k]);
                        kom++;
                        //printf("com is %d\n",kom);
                        flag =1;
                        break;

                    }else
                        s1s2++;
                }
        }

        flag = -1;
    for(k=0;k< photos[photo2].num_tags;k++)
        {

            for(i=0;i< photos[photo1].num_tags;i++)
                {

                    if(!strcmp(photos[photo1].tags[k] , photos[photo2].tags[i]))
                    {
                        flag =1;
                        break;
                    }
                    else
                        s2s1++;
                }
        }
       if(kom < s1s2 && kom < s2s1)
	{
		return kom;
	}
	else if(s1s2 < s2s1)
	{
		return s1s2;
	}
	else
	{
		return s2s1;
	}

}
//------------------------------------------------------
/******************arrange with start***************/
void arr(int start){
    int counter=0;
    int score=0;
    int next;
    ans[start][counter]=photos[start].id1;
    counter++;
    for(int i =start ; counter<Num_photos;){
            int f=0;
        for(int j=0;j<Num_photos;j++){
            if(i==j){
                continue;
            }
            if(factor(i,j)>f && photos[j].f_used==0){
                f=factor(i,j);
                next = j;
            }
        }
        if(f==0 && i!=start){
            break;
        }
        photos[i].f_used=1;
        photos[next].f_used=1;
        ans[start][counter]=photos[next].id1;
        counter++;
        i=next;
        score=score+f;
    }
    counter++;
     ans_score[score_count]=score;


}
//-------------------------------------------------------------------------
/*************************************find maximum score***********************************/
int max_score(){
   int  maximum = ans_score[0];
    int c;
  for ( c = 1; c < score_count; c++)
  {
    if (ans[c] > maximum)
    {
       maximum  = ans_score[c];

    }

  }
 // printf("###############%d",maximum);
  return c;
}
//-----------------------------
/**************set used to zero**************/
void zero(){
    for(int i=0;i<Num_photos;i++){
        photos[i].f_used=0;
    }

}






#endif // FUNCTIONS_H_INCLUDED
