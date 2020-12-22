#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char* norepeats(char *s)
{
    char s1[60], lw[60], *sn;
    int i=0;
    strcpy(s1,s);
    char *p=strtok(s1," .");
    while (p != NULL)
    {
        strcpy(lw,p);
        p=strtok(NULL," .");
    }
    if(strrchr(s,'.') != NULL)
    {
        i=1;
    }
    p=strtok(s," .");
    sn=(char*) malloc(60*sizeof(char));
    strcpy(sn,"");
    while (p != NULL)
    {
        if(strcmp(p,lw) != 0)
        {
                strcat(sn,p);
                strcat(sn," ");
        }
        p=strtok(NULL," .");
    }
    p=strrchr(sn,' ');
    if(i==1)
    {
        if(strcmp(sn,"") == 0)
         {
             return ".";
         }
        *p='.';
    }
    else
    {
        if(strcmp(sn,"") == 0)
         {
             return "";
         }
        *p='\0';
    }
    return sn;
}
char* Delete(char *s,char c)
{
    char *p;
    while(strchr(s,c) != NULL)
    {
        *strchr(s,c)='_';
    }
    if(strchr(s,'_') != NULL)
    {
        *strchr(s,'_')=c;
    }
    return s;
}
char* task(char *s)
{
    char *sn,*pn;
    int i=0;
    sn=(char*) malloc(60*sizeof(char));
    pn=(char*) malloc(60*sizeof(char));
    strcpy(s,norepeats(s));
    if(strrchr(s,'.') != NULL)
    {
        i=1;
    }
    char *p=strtok(s," .");
    strcpy(sn,"");
    while(p != NULL)
    {
        strcat(sn,Delete(p,*(p+strlen(p)-1)));
        strcat(sn," ");
        p=strtok(NULL," .");
    }
    p=strtok(sn,"_");
    strcpy(pn,"");
    while(p != NULL)
    {
        {
            strcat(pn,p);
        }
        p=strtok(NULL,"_");
    }
    p=strrchr(pn,' ');
    if(i==1)
    {
        if(strcmp(pn,"") == 0)
         {
             return ".";
         }
        *p='.';
    }
    else
    {
        if(strcmp(pn,"") == 0)
         {
             return "";
         }
        *p='\0';
    }
    return pn;
}
int main()
{
    char s[60],sn[60],f[60],F[60];
    printf("Введите имя файла для чтения\n");
    gets(f);
    printf("Введите имя файла для записи\n");
    gets(F);
    FILE *fp=fopen(f,"r");
    if(fp==NULL)
    {
        printf("Не удается открыть файл");
        return 1;
    }
    FILE *FP=fopen(F,"w");
    if(FP==NULL)
    {
        printf("Не удается открыть файл");
        return 1;
    }
    fread(s,sizeof(char),60,fp);
    printf("Вот исходная строка:%s",s);
    strcpy(sn,task(s));
    fwrite(sn,sizeof(char),strlen(sn),FP);
    fclose(fp);
    fclose(FP);
    return 0;
}
