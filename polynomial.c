/****************************************
* PROGRAM -> OPERATIONS ON POLYNOMIALS  *
* PROGRAMMED BY -> PRAVEEN MALOO        *
*                                       *
*****************************************/

#include <stdio.h>

struct node
{
 float coeff;
 float power;                 //a node holds the power and coefficient of one term
 struct node *next;
};

struct node *pf,*ps,*pt;      

int menu();
void input_conditions();
void take_input(int call);
void append(struct node **,float,float);
void add_or_sub_poly(struct node *,struct node *,struct node **,int decide);
void mult_poly(struct node *,struct node *,struct node**);
void mult_arrange(float,float,struct node **);
void der_poly(struct node *,struct node**);
void find_value(struct node *);
void display(struct node *);
void arrange_output(int choice);
int choice;
float x,value;

main()
{
 int i=1;
 
  printf("\n\n          WELCOME !! This program allows you to perform various operations on polynomials.... \n");
 input_conditions(); 
do
 {
   choice=menu();
   pf=ps=pt=NULL;
       if(choice==1 || choice==2 || choice==3)
       {
          printf("\n                                       FIRST POLYNOMIAL :           \n");
          printf("################################################################################################\n");           
          take_input(1);
          printf("\n\n                                       SECOND POLYNOMIAL :        \n");
          printf("###############################################################################################\n");
	  take_input(2);
       }
       else 
       {
            if(choice==4 || choice==5)
	    {
             printf("\n\n                                    ENTER THE  POLYNOMIAL :    \n");
             printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");       
             take_input(1);
	    }
        }	 
       if(choice==1 || choice==2)
       {
        add_or_sub_poly(pf,ps,&pt,choice);
	arrange_output(choice);
       }
       if(choice==3)
       {
        mult_poly(pf,ps,&pt);
	arrange_output(choice);
       }
       if(choice==4)
       {
        der_poly(pf,&pt);
        arrange_output(choice); 	
       }
       if(choice==5)
       {
        printf("\n    The polynomial you have entered is -->  \n\n");
	display(pf);
        printf("\n\n     ## Enter the value of 'x' for the entered  polynomial  -->  ");
	scanf("%f",&x);
	find_value(pf);
	printf("\n\n     ** The value of the polynomial you have entered is %.2f .",value);
	}  
  }while(choice!=6);  

}

//*************************************BEGIN MENU()**************************************

int menu()
{
  printf("\n\n                                           # MENU #                  \n");
  printf("                   ######################################################\n");
  printf("                   #                                                    #\n");
  printf("                   #    1  -->  ADD TWO POLYNOMIALS                     #\n");
  printf("                   #    2  -->  SUBSTRACT TWO POLYNOMIALS               #\n");
  printf("                   #    3  -->  MULTIPLY TWO POLYNOMIALS                #\n");
  printf("                   #    4  -->  FIND THE DERIVATIVE OF A POLYNOMIAL     #\n");
  printf("                   #    5  -->  FIND THE VALUE OF AN ENTERED POLYNOMIAL #\n");
  printf("                   #    6  -->  QUIT THE PROGRAM                        #\n");
  printf("                   #                                                    #\n");
  printf("                   ######################################################\n\n\n");
 
  printf("                   $$     Enter your choice -->   ");
  scanf("%d",&choice);
  return (choice);
 }

//***************************************END MENU()*************************************

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@BEGIN INPUT_CONDITIONS()@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

void input_conditions()
{
  printf("\n                                    @ INPUT CONDITIONS @               \n");
  printf("                   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  printf("                   @                                                    @\n");
  printf("                   @   * *  -->  THE TERMS OF THE POLYNOMIAL SHOULD BE  @\n");
  printf("                   @             ENTERED IN ASCENDING ORDER             @\n");
  printf("                   @                                                    @\n");
  printf("                   @   * *  -->  TO END THE POLYNOMIAL INPUT '0'        @\n");
  printf("                   @                                                    @\n");
  printf("                   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
} 

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@END INPUT_CONDITIONS()@@@@@@@@@@@@@@@@@@@@@@@@@@@


//++++++++++++++++++++++++++++++++++++++BEGIN APPEND()++++++++++++++++++++++++++++++++

void append(struct node **p,float x,float y)
{
 
 struct node *temp;
 temp=*p;

     if(*p==NULL)
     {
      *p=(struct node *)malloc(sizeof(struct node));
      temp=*p;
     }

     else
     {
            while(temp->next!=NULL)
            temp=temp->next;
  
            temp->next=(struct node *)malloc(sizeof(struct node));
            temp=temp->next;
      }

  temp->coeff=x;
  temp->power=y;
  temp->next=NULL;
  }
  
//+++++++++++++++++++++++++++++++++++++END APPEND()++++++++++++++++++++++++++++++++++++

//************************************BEGIN DISPLAY()**********************************

void  display(struct node *d)
{
       while(d!=NULL)
       {
           if(d->next!=NULL)
            printf(" (%.1f)x^(%.1f) +",d->coeff,d->power);
           else
            printf(" (%.1f)x^(%.1f) " ,d->coeff,d->power);
         d=d->next;
       }
	   
}
//************************************END DISPLAY()**************************************

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~BEGIN TAKE INPUT()~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 TAKES POLYNOMIAL AS THE INPUT FROM THE USER AND APPENDS IT IN A LINKED LIST THROUGH APPEND()
     CALL IS THE PARAMETER WHICH DETERMINES INPUT OF WHICH POLYNOMIAL IS TO BE TAKEN 
     CALL =1->FIRST POLYNOMIAL;CALL=2->SECOND POLYNOMIAL
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/    

void take_input(int call)
 {
  float cf=1,pow;
  int i=1;
       while(cf!=0)
       {
	printf("\n    Enter respectively the value of the 'COEFFICIENT' and 'POWER' of the term  no. %d  -->  ",i);
	scanf("%f%f",&cf,&pow);
	     if(cf==0 && call==1 && i==1)
	     append(&pf,cf,pow);
	     else if(cf==0 && call==2 && i==1)
	     append(&ps,cf,pow);
	     if(cf!=0)
	     {
	             if(call==1)
	             append(&pf,cf,pow);
		     else if(call==2)
		     append(&ps,cf,pow);
              i++;
	     }   
        }
 }	     

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END TAKE INPUT()~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*+++++++++++++++++++++++++++++++BEGIN ADDITION/SUBSTRACTION----------------------------

+++++++++++++DECIDE IS THE PARAMETER WHICH DETERMINES ADDITION OR SUBSTRACTION----------
++++++++++++++++++++++++DECIDE=1->ADDITION... DECIDE=2->SUBSTRACTION-------------------*/

 void add_or_sub_poly(struct node *x,struct node *y,struct node **s,int decide)
 {
  struct node *za;
     if(x==NULL && y==NULL)
       return;

     while(x!=NULL && y!=NULL)
     {
           if(*s==NULL)
           {
	    *s=(struct node *)malloc(sizeof(struct node ));
	    za=*s;
	   } 
	   else
           {
	    za->next=(struct node *)malloc(sizeof(struct node));
	    za=za->next;
	   }
	   if(x->power<y->power)
	   {
	    za->power=x->power;
	    za->coeff=x->coeff;
	    x=x->next;
	   }
	   else
	   {
	       if(y->power<x->power)
	       {    
	            za->power=y->power;
		    if(decide==1)                            //ADDITION
	             za->coeff=y->coeff;
		    else
		    { 
		        if(decide==2)
		        za->coeff=-(y->coeff);               //SUBSTRACTION
		    }    
	         y=y->next;
	       }
	       else
	       {
	             if(x->power==y->power)
	             {
	              za->power=x->power;
		        if(decide==1)                          //ADDITION
	                za->coeff=x->coeff + y->coeff;
			else if(decide==2)
			za->coeff=x->coeff - y->coeff;       //SUBSTRACTION
	              x=x->next;
	              y=y->next;
	             }
	       }   
            }
     }

     while(x!=NULL)
     {
   
           if(*s==NULL)
           {
            *s=(struct node *)malloc(sizeof(struct node));
            za=*s;
           }
           else
           {
            za->next=(struct node *)malloc(sizeof(struct node));
            za=za->next;
           }

        za->power=x->power;
        za->coeff=x->coeff;
        x=x->next;
     }

     while(y!=NULL)
     {
      
            if(*s==NULL)
            {
	     *s=(struct node *)malloc(sizeof(struct node));
	     za=*s;
	    }
	    else
	    {
	     za->next=(struct node *)malloc(sizeof(struct node));
	     za=za->next;
	    }
       za->power=y->power;
       if(decide==1)                    //ADDITION
       za->coeff=y->coeff;
       else if(decide==2)               //SUBSTRACTION
       za->coeff=-(y->coeff);
       y=y->next;
     }
  za->next=NULL;
}
//++++++++++++++++++++++++++++++++++END ADDITION/SUBSTRACTION--------------------------

//#####################################BEGIN MULTIPLICATION#############################

void mult_poly(struct node *m,struct node *n,struct node **o)
{
 struct node *m1=m;
 float cof,exp;
 if(m==NULL && n==NULL)
 return;
 if(m==NULL)
 *o=m;
 else
 {
    if(n==NULL)
    *o=n;
    else
    {
 
       while(n!=NULL)
       {
           while(m!=NULL)
	   {
             cof=(n->coeff)*(m->coeff);
             exp=(n->power) + (m->power);
             m=m->next;
	     mult_arrange(cof,exp,o);
           }   
          n=n->next;
          m=pf;
        }
     } 
  }
  
}

//###################################END MULTIPLICATION##############################

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@BEGIN MULT_ARRANGE()@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//???????????????????????????????ARRANGE IN ASCENDING ORDER??????????????????????????
//~~~~~~~~~~~~~~~~~TAKING TOGETHER ALL THE TERMS WITH THE SAME EXPONENT~~~~~~~~~~~~~~

void mult_arrange(float c,float e,struct node **s)
{
 struct node *r,*temp=*s;
   if(*s==NULL || e<(*s)->power)                              //add at start
  {
   *s=r=(struct node *)malloc(sizeof(struct node));
   (*s)->coeff=c;
   (*s)->power=e;
   (*s)->next=temp;
  }
  else
  {
      while(temp!=NULL)
      {
          if(temp->power==e)
          {
           temp->coeff=(temp->coeff)+c;
           return;
          }
          if(temp->power<e&&(temp->next==NULL||temp->next->power>e))
          {
	   r=(struct node *)malloc(sizeof(struct node));
           r->coeff=c;
	   r->power=e;
	   r->next=temp->next;
	   temp->next=r;
	   return;
          }
       temp=temp->next;
      }
      r->next=NULL;
      temp->next=r;
   }
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@END MULT_ARRANGE()@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//************************************BEGIN DERIVATIVE*******************************

void der_poly(struct node *f,struct node **g)
{
struct node *zd;
  if(f==NULL)
  return;
  
  while(f!=NULL)
  {
      if(*g==NULL)
      {
       *g=(struct node *)malloc(sizeof(struct node));
       zd=*g;
      }
      else
      {
       zd->next=(struct node *)malloc(sizeof(struct node));
       zd=zd->next;
      }

      zd->coeff=(f->coeff)*(f->power);
      zd->power=f->power-1;
      f=f->next;
   }  

   zd->next=NULL;
 }
 
//**************************************END DERIVATIVE*********************************     
 
//::::::::::::::::::::::::FIND THE VALUE OF THE GIVEN POLYNOMIAL::::::::::::::::::::::: 

void find_value(struct node *st)
{
 struct node *trav=st;
 int i;
 float p;
 value=0;
   while(trav!=NULL)
   {
     p=1;
       for(i=(trav->power);i>0;i--)
       {
	p=p*x;
       }
        p=p*(trav->coeff);
	value=value+p;
     trav=trav->next;
    }
 }

 //::::::::::::::::::::::::::::::::::::END FIND_VALUE()::::::::::::::::::::::::::::::::

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^BEGIN ARRANGE_OPUTPUT^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//!!!!!!!!!!!!!!!!!!!!!!!ARRANGES TTHE OUPUT FOR BETTER VISUALITY!!!!!!!!!!!!!!!!!!!!!!  

void arrange_output(int choice)
{
    if(choice==1 || choice==2 || choice==3)
    {
      printf("\n\n    The two polynomials you have entered are as following  ->  \n\n");
      printf("\n    FIRST  POLYNOMIAL  ->  ");
      display(pf);
      printf("\n\n    SECOND  POLYNOMIAL ->  ");
      display(ps); 

      printf("\n\n                               THE REQUIRED RESULT IS   -> \n");
      printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
      printf("     [");
      display(pf);
      printf(" ]");
	if(choice==1)
	 printf(" + ");
	else if(choice==2)
	 printf(" - ");
	else printf(" * ");
      printf("["); 
      display(ps);
      printf("]"); 
      printf("\n\n     =  ");
      display(pt);
    }
    else 
    {
        if(choice==4)
        {
         der_poly(pf,&pt);
  	 printf("\n\n      d");
 	 printf("\n     --- [");
	 display(pf);
	 printf("]     ");
	 printf("\n      dx\n\n");
	 printf("       = ");
	 display(pt);
        }
     }
 }
