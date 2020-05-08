#include<stdio.h>
#include<string.h>
int i,ch,j,l,addr=100;
char ex[10], exp[10] ,exp1[10],exp2[10],id1[5],op[5],id2[5];
void prime_mul()
{
    strrev(exp);
    j=l-i-1;
    strncat(exp1,exp,j);
    strrev(exp1);
    printf("Three address code:\ntemp=%s\ntemp1=%c%ctemp\n",exp1,exp[j+1],exp[j]);
}
void prime_div()
{
    strncat(exp1,exp,i+2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n",exp1,exp[i+2],exp[i+3]);
}
void prime_plus()
{
    strncat(exp1,exp,i+2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n",exp1,exp[i+2],exp[i+3]);
}
void main()
{
    printf("\nEnter the expression :");
    scanf("%s",ex);
    strcpy(exp,ex);
    l=strlen(exp);
    exp1[0]='\0';
    for(i=0;i<l;i++)
    {
        if(exp[i]=='+'||exp[i]=='-')
        {
            if(exp[i+2]=='/'||exp[i+2]=='*')
            {
                prime_mul();
                break;
            }
            else
            {
                prime_plus();
                break;
            }
        }
        else if(exp[i]=='/'||exp[i]=='*')
        {
            prime_div();
            break;
        }
    }

}

