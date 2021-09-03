//Sondos Aabed
//1190652
//Dr. Wahbeh Eid lab2
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
int size=0;
int flag=0;
void displayMainMenu();
void addBook( int  [], double  [],int  []);   	
void updateDataFile(int [], double [], int []);    	
void uploadDataFile ( int [], double [],int []);     
void removeBook(int [], double [], int []);  	
void searchForBook(int [], double [], int []); 	 
void printBooks (int [], double [], int[]);

int main() {  
 
    int bins[MAXSIZE] ;
    double prices[MAXSIZE];
    int status[MAXSIZE];
    int choice;
    printf("Welcome to my Bookstore Management System:\n");
    uploadDataFile( bins , prices , status ); 
    displayMainMenu();
    scanf("%d",&choice);
     while (choice != 5) {
       switch (choice)
        {
           case 1: addBook( bins , prices , status ); break;
           case 2: removeBook(  bins , prices , status ); break;
           case 3: searchForBook( bins , prices , status ); break;
           case 4: printBooks( bins , prices , status ); break; 
            default:printf("No such Operation! Please try again.\n");
        }
      displayMainMenu();
      scanf("%d",&choice); 
    
    
     }
     if (choice== 5) {  //updateDataFile(bins,prices,status);
                   printf("the book information is updated\n");
                   printf("Thank you for using My BookStore Management System. GoodBye\n"); }
 }

void displayMainMenu() {
    printf("Please Select an Operation (1-5):\n");
    printf("1- Add a book\n");
    printf("2- remove a book\n");
    printf("3- search for a book\n");
    printf("4- Print Book List\n");
    printf("5- Exit System\n");
}
void uploadDataFile ( int bins[], double  prices[],int status[]) {   
    FILE*A;
    int n=0,val,bin;
    int flag=0; 
    double price; 
    A=fopen("books.txt","r" );
    if (A == NULL) 
    {
    printf("error while reading the file"); 
    exit(0);
    }
    printf("Uploading Data File ...\n");
    val=fscanf(A,"%d%lf" , &bin , &price);
    while(val!=EOF)
    {
      bins[n]=bin;
      prices[n]=price;
      flag=1;
      status[n]=flag;
       
      n++;
      val=fscanf(A,"%d%lf" , &bin , &price);
    }
    size= n;
    printf("Data File uploaded\n ");
 } 
void addBook( int bins[], double prices[],int status[]) {
    int bin;
    int price;
    int flag,i;
    int position;
    if(size<MAXSIZE)
    {
      printf("enter bin number for book\n");
      scanf("%d",&bin); 
      flag=status[i] ;
      for (int i=0;i<size;i++)
      { 
        
        if (flag==1&&bin==bins[i]) 
         {
           printf( "book already exists\n" );
           break;
          }
        else if (flag==0&&bin==bins[i])
         { flag=1;}                             
        else if (flag==1&&bin!=bins[i])
         {  printf("enter price of book\n");
            scanf("%lf",&price );
            position= size;
            bins[position]=bins[i] ;
            prices[i]=prices[position];
            flag=status[size];
            size++; 
            printf("book has been added\n" );
          }
      } 
                    
    }
    
} 
void removeBook(int bins[], double prices[], int status[]) {
  int i;
  int bin;
  int flag ; 
  status[i]=flag; 
  if(size>0&&size<MAXSIZE)
  { 
    printf("enter bin number for book to remove");
    scanf("%d",&bin);
    for(int i=0;i<size;i++)
      {
        if(bin==bins[i]&&status[i]==1){flag=0;
          printf("Book with bin %d has been removed\n",bin );
        }  
        else if(bin!=bins[i]){printf("book with bin %d does not exist\n",bin);}
      }
    
    
    
  }
    
}  
void searchForBook(int bins[], double prices[], int  status[]) {
  int bin;
  int i=0;
  int flag;
  flag=status[i];
  if (size>0)
  { printf("enter bin number for book to search for\n");
    scanf("%d",&bin);
    for(int i=0;i<size;i++)
      {
        if (bin!=bins[i]&&flag==0 ) 
          {printf("book with bin number %d is not found\n",bin);}
        else if(bin==bins[i]&&flag==1 )
          {printf("bin#= %d\t price=%lf\n",bins[i],prices[i]);} 
      }
  }
 
}
void updateDataFile(int bins[], double prices[], int  status[]) {
    int i=0;
    int bin;
    double price;
    int flag;
    bin =bins[i];
    price=prices[i];
    flag=status[i];
    
    FILE*A;
    A=fopen("books.txt","w");  
    
    while (flag==1&&i<size){
    fprintf(A,"%d%lf", bin , price );}
    fclose(A);
 
    printf("Updating Data File ...\n");
    printf("Data File updated\n ");
    
}
void printBooks (int bins[], double prices[], int  status[]){ 
  int i;
  if(status[i]==1){
    for(i;i<size;i++)
    {printf("the book bin#=%d\t the price of the book =%lf\n",bins[i],prices[i]);}
                  }
} 



