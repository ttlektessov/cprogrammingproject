#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int a=0; //index
struct information{
  char *name;
  char *number;
  char *bdate;
};
void registration(struct information **in1);
void del(struct information **in1);
void fbb(struct information **in1);
void show(struct information **in1);
void reg(struct information **in1);
int main(void) {
  struct information **inf;
  int i;
  int max_num,d;
  printf("Max_num:");
  scanf("%d", &max_num);
  inf=(struct information**)malloc(max_num*sizeof(struct information*));
  for(d=0;d<max_num;d++){
    inf[d]=(struct information*)malloc(100*sizeof(struct information));
  }
  while(i!='6'){
    printf("*****Menu*****\n");
    printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.RegFromFile><6.Exit>\n");
    printf("Enter_the_menu_number:");
    scanf("%d",&i);
    if(i==6)
        FILE *fp=fopen("PHONE_BOOK.txt", "w"); //if '6' pressed, creating or rewriting text file with user information
        for(d=0;d<a;d++){
            fprintf(fp, "%s %s %s\n", inf[d]->name, inf[d]->number, inf[d]->bdate);
        }
        for(d=0;d<a;d++){
            free(inf[d]);
        }
        free(inf);
        break;} //if user enters '5', program shuts down
    if(i==1){
        if(a>=max_num){
            printf("OVERFLOW\n");
            continue;
        }
        registration(inf); //if pressed '1', function registatrion is called
        printf("<<%d>>\n",a+1); //printing number of registered users
        a++;} //index
    if(i==2){
        show(inf); //if '2' pressed, calling function showall
        }
    if(i==3){
        if(a==0){ //if no user information is stored, printing no member and returning to menu
            printf("NO MEMBER\n");
            continue;
        }
        else del(inf); //if user information is stored, calling fucntion deletebyname
        }
    if(i==4){
        fbb(inf); //if '4' pressed, calling function findbybirth
        }
    if(i==5){
        reg(inf);
        }
    }
    return 0;
    }
void registration(struct information **in1){
  int j=0, i=0,q;
  char te[100];
  char t[100];
  printf("Name:");
  scanf("%s", te);
  in1[a]->name=(char*)malloc((strlen(te)+1)*sizeof(char));
  strcpy(in1[a]->name,te);
  printf("Phone_number:");
  scanf("%s", te);
  in1[a]->number=(char*)malloc((strlen(te)+1)*sizeof(char));
  strcpy(in1[a]->number,te);
  printf("Birth:");
  scanf("%s", te); //getting name, phone number and birthdate
  in1[a]->bdate=(char*)malloc((strlen(te)+1)*sizeof(char));
  strcpy(in1[a]->bdate,te);
  if(a>=1){
    for(j=0;j<a;j++){ //sorting users by names
      for(i=1;i<=a;i++){
      q=strcmp(in1[j]->name,in1[i]->name);
      if(q>0){ //comparing names and then sorting their informations
        strcpy(t,in1[j]->name);
        strcpy(in1[j]->name,in1[i]->name);
        strcpy(in1[i]->name,t);
        strcpy(t,in1[j]->number);
        strcpy(in1[j]->number,in1[i]->number);
        strcpy(in1[i]->number,t);
        strcpy(t,in1[j]->bdate);
        strcpy(in1[j]->bdate,in1[i]->bdate);
        strcpy(in1[i]->bdate,t);
        }
      }
    }

  }
}
void show(struct information **in1){ //showall function
  int i;
  for(i=0;i<a;i++){
    printf("%s %s %s\n", in1[i]->name, in1[i]->number, in1[i]->bdate);
  }
}
void del(struct information **in1){ //deletebyname function
  int i,t;
  char tem[21];
  printf("Name:");
  scanf("%s",tem); //storing name
  for(i=0;i<a;i++){
    if(strcmp(in1[i]->name,tem)==0){ //comparing each names with 'tem', if same are found
      t=i; //t becomes user index
    for(i=t;i<a;i++){ //shifting next user information to the found one
      strcpy(in1[t]->name,in1[t+1]->name);
      strcpy(in1[t]->number,in1[t+1]->number);
      strcpy(in1[t]->bdate,in1[t+1]->bdate);
    }
    free(in1[a]->name);
    free(in1[a]->number);
    free(in1[a]->bdate);
    a--; //reducing index
    break;
    }
  }
}
void fbb(struct information **in1){ //findbybirth function
     int i,temp,q;
    char tt[10], d[3];
    if(a!=0){ //if user informations are stored, continue
        printf("Birth:");
        scanf("%d", &q);//getting month
        for(i=0;i<a;i++){
            strcpy(tt,in1[i]->bdate);
            d[0]=tt[4];
            d[1]=tt[5];
            d[2]='\0'; //user birthdate is being copied, then storing each month letter in another variable
            temp=(d[0]-'0')*10+(d[1]-'0'); //converting chars into integers
            if(q==temp){//if birthdate are same, printing user
              printf("%s %s %s\n", in1[i]->name,in1[i]->number,in1[i]->bdate);
            }
        }
    }
}
void reg(struct information **in1){
    char ara[10][100], temp[3][100];
    int i=0, j,k,m=0, l,s;
    FILE *fp=fopen("PHONE_BOOK.txt", "r");//opening our file in reading mode
    while(1){
        k=0;
        char w=(char)fgetc(fp);
        while(w!='\n'&&!feof(fp)){
            ara[i][k++]=w; //storing in array until pressing enter
            w=(char)fgetc(fp);
        }
        ara[i][k]='\0';
        if(feof(fp)){ //making last character null and checking for EOF
            break;
        }
        i++;
    }
    l=i;
    while(l>0){
        j=0; s=0;
        for(i=0;i<=(strlen(ara[m]));i++){
            if(ara[m][i]==' '||ara[m][i]=='\0'){
                temp[s][j]='\0';
                s++;
                j=0;
            }
            else{
                temp[s][j]=ara[m][i];
                j++;
            }
        }
        in1[a]->name=(char*)malloc((strlen(temp[0])+1)*sizeof(char)); //allocating memory for name, number and bdate
        in1[a]->number=(char*)malloc((strlen(temp[1])+1)*sizeof(char));
        in1[a]->bdate=(char*)malloc((strlen(temp[2])+1)*sizeof(char));
        strcpy(in1[a]->name, temp[0]); //copy information into structure
        strcpy(in1[a]->number,temp [1]);
        strcpy(in1[a]->bdate, temp[2]);
        l--;
        m++;
        a++;
    }
    }
