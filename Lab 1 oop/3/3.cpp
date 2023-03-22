
//DA SE DOPISIT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


#include <stdio.h>
#include <string.h>

typedef struct Employee {
    char name[100];
    char embg[100];
    char oddel[100];
    int plata;
}vraboten;

typedef struct Company{
    char name[100];
    vraboten vraboteni[100];
    int n;
}kompanija;

void print_bellow(kompanija *comp,int numcompanies){
    int i,j;
    int prosek=0;
    for(i=0;i<numcompanies;i++){
        prosek=0;
        for(j=0;i<comp[i].n;j++){
            prosek+=comp[i].vraboteni[j].plata;
        }
        prosek/=comp[i].n;
        for(j=0;j<comp[i].n;j++){

        }
    }
}

void print_highest(kompanija *comp,int num,char *department){
    int i,j;
    printf("Employees with highest salaries for given department:\n");
    int indi,indj;
    int max=0;
    for(i=0;i<num;i++){
        indi=0;indj=0;max=0;
        for(j=0;j<comp[i].n;j++){
            if(strcmp(department,comp[i].vraboteni[j].oddel)==0){
                if(comp[i].vraboteni[j].plata > max){
                    max = comp[i].vraboteni[j].plata;
                    indi = i;
                    indj = j;
                }
            }
        }
        printf("%s %s %s %d\n",comp[indi].vraboteni[indj].name,
               comp[indi].vraboteni[indj].embg,comp[indi].vraboteni[indj].oddel,comp[indi].vraboteni[indj].plata);
    }

}

int main(){
    int n,i;
    kompanija oddel[100];
    char department[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf ("%s %d",oddel[i].name,&oddel[i].n);
        for (int j=0;j<oddel[i].n;j++){
            scanf("%s %s %s %d",oddel[i].vraboteni[j].name,oddel[i].vraboteni[j].embg,oddel[i].vraboteni[j].oddel,&oddel[i].vraboteni[j].plata);
        }
    }
    scanf("%s",department);
    print_highest(oddel,n,department);


}



