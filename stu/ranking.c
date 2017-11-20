#include "stu.h"
void ranking(void)
{
    FILE *fp;
    int i,j,n=0,y;
    STUDENT stu[RECS];
    if((fp=fopen("allstudent","rb+"))==NULL)
    {
        puts("ERROR.");
        return ;
    }
    while(!feof(fp))
    {
        fread(&stu[n],sizeof(STUDENT),1,fp);
        n++;
    }
    for(i=0;i<=n-1-1;i++)
    {
        y=1;
        for(j=0;(j<=n-1-1);j++)
            if((stu[i].sum<stu[j].sum)&&(j!=i))
                y++;
        stu[i].order=y;
    }
    rewind(fp);
    for(i=0;i<=n-1-1;i++)
        fwrite(&stu[i],sizeof(STUDENT),1,fp);
    fclose(fp);
    return;
}
