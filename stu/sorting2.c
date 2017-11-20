#include "stu.h"
void sorting2(void)
{
    STUDENT stu[RECS],t;
    FILE *fp1,*fp2;
    int i,j,k,n=0;
    if((fp1=fopen("allstudent","rb+"))==NULL)
    {
        puts("ERROR.");
        return ;
    }
    if((fp2=fopen("temp","wb"))==NULL)
    {
        puts("ERROR.");
        return ;
    }

    while(!feof(fp1))
    {
        fread(&stu[n],sizeof(STUDENT),1,fp1);
        n++;
    }

    for(i=n-1-1;i>=1;i--)
    {
        k=i;
        for(j=i-1;j>=0;j--)
            if(stu[k].sum>stu[j].sum)
                t=stu[j],stu[j]=stu[k],stu[k]=t;
    }

    for(i=0;i<=n-1-1;i++)
        fwrite(&stu[i],sizeof(STUDENT),1,fp2);
    fclose(fp1);
    fclose(fp2);
    if((remove("allstudent")==0) && (rename("temp","allstudent")==0))
        printf("OK.\n");
    else
        printf("排序失败.\n");
    return ;
}
