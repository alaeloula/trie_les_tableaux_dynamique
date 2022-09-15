#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getInt(){
	char line[100];
	int num;
	while(1){
	
	fgets(line,100,stdin);
		if(sscanf(line,"%d ",&num)!=1)
		{
			puts("error");
		}else break;
	}
	return num;
}



int* initialiser(int* a,int b){
	return	a = (int *)malloc(b * sizeof(int));
}
void ajoutercase(int* a,int *b,int val){
	
		a = (int *)realloc(a,++(*b));
	    *(a+*b-1)=val;
}
void insererelement(int* a,int b){
	int i;
	for(i=0;i<b;i++){
		printf("enter la valeur de la case %d : ",i+1);
		a[i]=getInt();
		
	}
}

void affichage(int *p,int b){
	int i;
	for(i=0;i<b;i++){
		printf("%d\n",*(p+i));
	}
}
void triparselection(int *a,int b){
	int c,i,j;
	for(i=0;i<b-1;i++){
		for(j=i+1;j<b;j++){
			if(a[j]>a[i]){
			c=a[j];
			a[j]=a[i];
			a[i]=c;	
			}
		}
	}
	affichage(a,b);
}


void triparbull(int *a,int SIZE){
	int i, j, tmp;
	for (i=0 ; i < SIZE-1; i++)
  {
    for (j=0 ; j < SIZE-i-1; j++)
    {
      
      if (a[j] > a[j+1]) 
      {
        tmp = a[j];
        a[j] = a[j+1];
        a[j+1] = tmp;
      }
    }
  }
  printf("bull\n ");
  affichage(a,SIZE);
}

  void triparinsertion(int *tab,int SIZE){
  	//int SIZE=(sizeof(tab)/sizeof(int));
  	//printf("Pppppppppppppp %d",SIZE);
  	int i, j, tmp; 
	  for (i=1 ; i <= SIZE-1; i++) {
       j = i;
 
    while (j > 0 && tab[j-1] > tab[j]) {
      tmp = tab[j];
      tab[j] = tab[j-1];
      tab[j-1] = tmp;
 
      j--;
    }
  }
    printf("\n******** tableau trie par ordre croissant ********\n");
 
  affichage(tab,SIZE);
  }
 



int main()
{
	int i=0,a,*p=NULL,c;
	
   printf("saisir la dimension du tableau : ");
   a=getInt();
   p=initialiser(p,a);
   insererelement(p,a);


 
	affichage(p,a);
	
	printf("\n******************************\n");
	printf("pour utilsee le tri par selection taper 1 \n");
	printf("pour utilsee le tri par bull taper 2 \n");
	printf("pour utilsee le tri par selection taper 3 \n");
	c=getInt();
	switch(c){
		case 1:triparselection(p,a);break;
		case 2:triparbull(p,a);break;
		case 3:triparinsertion(p,a);break;
	}
	
//	triparbull(p,a);
//	printf("******************** ");
//	triparselection(p,a);
//	printf("******************** ");
	
//	printf("******************** ");
//	triparinsertion(p,a);
	return 0;
}
