#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int bp,mp,invest,excost;
int cas1=1,cas2=1;
int view1=1,view2=1;
float tinvest=0,tcost=0,texcost=0;
float tmeal=0;
int n,i,j;
float totalmeal=0,tmeal_p_person[50];
char ch;
int d,t,dat,date=1;

void wait(int seconds)
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}
struct meals
{
    char name[256];
    char date[20];
    int mealc;
};
struct bazar
{
    char name[256];
    char date[20];
    int cost;
};
struct bazar baz1[100];
struct meals meal1[100];
void clock_copy();
void inputbaz();
void printbaz(struct bazar baz[100]);
void inputmeal();
void printmeal(struct meals meal[100]);
void input_invest();
void view_invest();
void input_Excost();
void view_Excost();
int main()
{
    system("cls");
    clock_copy();
    system("cls");
start:
        system("cls");
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printf(":=:=:=:=:\t Meal Management by RbShadow \t:=:=:=:=:\n");
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
    printf("\n");
    printf("1. Input Bazar\n");
    printf("2. Input Meals\n");
    printf("3. Input invest\n");
    printf("4. Input Extra cost\n");
    printf("5. View Bazar\n");
    printf("6. View Meal\n");
    printf("7. Total Cost\n");
    printf("8. Total investment and Remaining balance\n");
    printf("9. Meal Rate till today\n");
    printf("10. Total extra cost\n\n");
    printf("Enter your desire number : \n");
    scanf("%d",&n);
    if(n==1)
    {
        system("cls");
        inputbaz();
        system("cls");
        goto start;
        getch();
    }
    else if(n==2)
    {
        system("cls");
        inputmeal();
        system("cls");
        goto start;
        getch();
    }
    else if(n==3){
        system("cls");
        input_invest();
        system("cls");
        goto start;
        getch();
    }
    else if(n==4){
        system("cls");
        input_Excost();
        system("cls");
        goto start;
        getch();
    }
    else if(n==5){
        system("cls");
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printf(":=:=:=:=:=:        View Bazar     :=:=:=:=:=:\n");
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printbaz(baz1);
        getch();
        goto start;
    }
    else if(n==6){
        system("cls");
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printf(":=:=:=:=:=:        View Meals     :=:=:=:=:=:\n");
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printmeal(meal1);
        getch();
        goto start;
    }
    else if(n==7)
    {
        system("cls");
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printf(":=:=:=:=:=:        Total Cost     :=:=:=:=:=:\n");
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printf("\nTotal cost : %.2f\n\n",tcost);
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        getch();
        goto start;
    }
    else if(n==8)
    {
        system("cls");
        view_invest();
        getch();
        goto start;
    }
    else if(n==9)
    {
        system("cls");
        totalmeal = (tcost/tmeal);
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printf(":=:=:=:=:=:  Meal rate till today :=:=:=:=:=:\n");
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printf("\nTotal Meal : %.2f\n",tmeal);
        if(tmeal==0){
            printf("Calculation not possible.Enter meal please !\n\n");
        }
        else if(tmeal!=0){
            printf("Meal rate : %.2f\n\n",totalmeal);
        }
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        getch();
        goto start;
    }
    else if(n==10){
        system("cls");
        view_Excost();
        getch();
        goto start;
    }
    else
        system("cls");
        goto start;
}

void inputbaz()
{
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printf(":=:=:=:=:=:       Bazar Lists     :=:=:=:=:=:\n");
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        input:
        printf("Enter till date : ");
        scanf("%d",&bp);
        for(i=0;i<bp;i++){
        printf("\n\t==> %d <==\n",cas1++);
        printf("Enter Name : ");
        scanf("%s",&baz1[i].name);
        printf("Enter cost : ");
        scanf("%d",&baz1[i].cost);
        tcost+=baz1[i].cost;
        printf("\n");
        }
        printf("\nThank you !!!\n\n");
        printf("\n:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
}
/*       Bazar counter Function   */
void printbaz(struct bazar baz[100])
{
        int cas=1;
        int i;
        for(i=0;i<bp;i++){
        printf("\n%d.\t",view1++);
        printf("Name : %s\t",baz[i].name);
        printf(" Total Cost : %d\t\n",baz[i].cost);
        }
        printf("\n:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printf("\t\t\tGrand Total : %.2f\n",tcost);
        view1=1;
}


/*        Meal input function   */
void inputmeal()
{
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printf(":=:=:=:=:=:      Meal Counter     :=:=:=:=:=:\n");
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        inputm:
        printf("Enter persons number : ");
        scanf("%d",&mp);
        printf("Enter till date : ");
        scanf("%d",&dat);
        for(j=0;j<mp;j++){
        printf("\n\t==> %d <==\n",cas2++);
        printf("Enter Name : ");
        scanf("%s",&meal1[j].name);
        for(d=0;d<dat;d++){
            printf("For date : %d\t",date++);
            printf("Enter meal : ");
            scanf("%d",&meal1[d].mealc);
            tmeal_p_person[j]+=meal1[d].mealc;
            tmeal+=meal1[d].mealc;
        }
        date=1;
        printf("\n");
        }
        cas2=1;
        printf("\nThank you !!!\n\n");
        printf("\n:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
}

/*       Meal View Function   */
void printmeal(struct meals meal[100])
{
    int cas=1;
    int i,t;
    for(i=0;i<mp;i++){
        printf("\n%d.\t",view2++);
        printf("Name : %s\t",meal[i].name);
        printf("Total Meals : %.2f\t\n",tmeal_p_person[i]);
    }
    printf("\n:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
    printf("\t\t\tGrand Total : %.2f\n",tmeal);
    view2=1;
}

void input_invest()
{
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printf(":=:=:=:=:=:        Investment     :=:=:=:=:=:\n");
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printf("Enter amount (press 0 to terminate) : \n");
    for(i=0;;i++){
        scanf("%d",&invest);
        if(invest!=0){
        tinvest+=invest;
        }
        else
            break;
    }
}
void view_invest()
{
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printf(":=:=:=:=: Total investment & Remaining balance :=:=:=:=:=:\n");
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printf("\nTotal investment : %.2f\n",tinvest);
        printf("Remaining balance : %.2f\n\n",(tinvest-tcost)-texcost);
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
}

void input_Excost()
{
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printf(":=:=:=:=:=:       Extra cost      :=:=:=:=:=:\n");
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printf("Enter amount (press 0 to terminate) : \n");
    for(i=0;;i++){
        scanf("%d",&excost);
        if(excost!=0){
        texcost+=excost;
        }
        else
            break;
    }
}
void view_Excost()
{
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printf(":=:=:=:=:=:    Total Extra cost   :=:=:=:=:=:\n");
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
        printf("\nTotal Extra cost : %.2f\n\n",texcost);
        printf(":=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n");
}

void clock_copy()
{
  int n;
  wait(1);
  printf("\n================================================================================\n");
  printf("\t\t\t\t  Welcome to all\n");
  printf("\t\t\t   RbShadow Softwares Limited\n");
  printf("\n\t\t      **********************************");
  printf("\n\t\t      *     \"Meal Management System\"   *");
  printf("\n\t\t      **********************************\n");
  printf("\n================================================================================\n");
  wait(2);
 printf("\n\t\tPress ENTER to continue...");
  while(getch()!=13){}
}
