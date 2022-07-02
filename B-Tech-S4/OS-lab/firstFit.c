#include<stdio.h>
 
void main()
{
int m_size[10], p_size[10], m, n, flags[10], allocation[10], i, j;
 
for(i = 0; i < 10; i++)
{
flags[i] = 0;
allocation[i] = -1;
}
printf("Enter no. of memory partitions : ");
scanf("%d", &m);
printf("\nEnter size of each partitions : ");
for(i = 0; i < m; i++)
scanf("%d", &m_size[i]);
 
printf("\nEnter no. of processes : ");
scanf("%d", &n);
printf("\nEnter size of each process : ");
for(i = 0; i < n; i++)
scanf("%d", &p_size[i]);
for(i = 0; i < n; i++)        
for(j = 0; j < m; j++)
if(flags[j] == 0 && m_size[j] >= p_size[i])
{
allocation[j] = i;
flags[j] = 1;
break;
}
printf("\nPartition no.\tM_size\t\tProcess_no.\t\tProcess_size\n");
for(i = 0; i < m; i++)
{
printf("\n%d\t\t%d\t\t", i+1, m_size[i]);
if(flags[i] == 1)
printf("%d\t\t\t%d\n",allocation[i]+1,p_size[allocation[i]]);
else
printf("Not allocated");
}
}