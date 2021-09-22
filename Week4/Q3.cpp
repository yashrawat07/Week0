#include<stdio.h>
#include<malloc.h>
int Pivot(int *arr,int i,int j)
{
	int b = i-1,piv = j,temp,ti = i;
	for(;i<j;i++)
	{
		if(*(arr+i)<*(arr+piv))
		{
			b++;
			temp = *(arr+i);
			*(arr+i) = *(arr+b);
			*(arr+b) = temp;
		}
	}
	b++;
	temp = *(arr+i);
	*(arr+i) = *(arr+b);
	*(arr+b) = temp;
	return b;
}
int QS(int *arr, int n,int key)
{
	int ind,i=0,j=n-1;
	while(i<j)
	{
		ind = Pivot(arr,i,j);
		if(ind == key-1)
		return ind;
		if(key-1<ind)
		{
			j = ind-1;
		}
		else
		{
			i = ind+1;
		}
	}
}
int main()
{
	int noc,j,*key;
	scanf("%d",&noc);
	int **arr, *noe,i;
	arr = (int **)malloc(noc*sizeof(int *));
	noe = (int *)malloc(noc*sizeof(int *));
	key = (int *)malloc(noc*sizeof(int *));
	for(i=0;i<noc;i++)
	{
		scanf("%d",noe+i);
		*(arr+i) = (int *)malloc(*(noe+i)*sizeof(int));
		for(j=0;j<*(noe+i);j++)
		{
			scanf("%d",*(arr+i)+j);
		}
		scanf("%d",key+i);
	}
	for(i=0;i<noc;i++)
	{
		*(key+i) = QS(*(arr+i),*(noe+i),*(key+i));
	}
	for(i=0;i<noc;i++)
	{
		printf("\n%d",*(*(arr+i)+*(key+i)));
	}
	return 0;
}
