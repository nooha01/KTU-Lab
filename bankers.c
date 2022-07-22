#include <stdio.h>
int main()
{
	int n, m, i, j, k; 
	m = 3; 
	int alloc[10][10],max[10][10],avail[10];
	printf("\nEnter the number of processes:\n");
	scanf("%d",&n);
	printf("\nEnter the allocated spaces;\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("\nEnter the maximum space;\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("\nEnter the available space;\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&avail[i]);
	}
	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) 
	{
		f[k] = 0;
	}
	printf("NEED:\n");
	int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
		{	
			{
				need[i][j] = max[i][j] - alloc[i][j];
				printf("%d\t",need[i][j]);
			}
			
		}
		printf("\n");

	}
	int y = 0;
	for (k = 0; k < 5; k++) {
		for (i = 0; i < n; i++)
		{
			if (f[i] == 0) {
				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	int flag = 1;
	for(int i=0;i<n;i++)
	{
		if(f[i]==0)
		{
			flag=0;
			printf("The following system is not safe");
			break;
		}
	}
	
	if(flag==1)
	{
	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d", ans[n - 1]);
	}
	printf("\n");
	return (0);
}
