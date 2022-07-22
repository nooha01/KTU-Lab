#include <stdio.h>
#include <stdlib.h>
int main()
{
	int arr[10], burst[10], burst2[10], temp[10], p[10], opt, i, prior, w[10], t[10], count = 0, n, flag = 0, x, k, prev;
	float avgwt, avgtt, wt = 0, tt = 0, time, end, tmp;
	printf("\nEnter no of Processes:");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("\nProcesses %d", i + 1);
		printf("\nEnter Arrival Time:\t");
		scanf("%d", &arr[i]);
		printf("Enter Burst Time:\t");
		scanf("%d", &burst[i]);
		printf("Enter priority:\t");
		scanf("%d", &p[i]);
		temp[i] = burst[i];
		burst2[i] = burst[i];
	}
	p[9] = 9999;

	while (1)
	{
		printf("\n Enter option 1.pre emptive 2.non preemprive else.exit   :   ");
		scanf("%d", &opt);
		for (i = 0; i < n; i++)
		{
			w[i] = 0;
			t[i] = 0;
		}
		switch (opt)
		{
		case 1:
			wt = 0;
			tt = 0;
			count = 0;
			flag = 0;
			printf("\nGantt chart:\n");
			for (time = 0; count != n; time++)
			{
				prior = 9;
				for (i = 0; i < n; i++)
				{
					if (arr[i] <= time && p[i] < p[prior] && burst[i] > 0)
					{
						prior = i;
					}
				}
				if (prior == 9)
					continue;
				if (flag == 0)
				{

					printf("%d ", arr[prior]);
					printf(" p%d ", prior + 1);
					x = prior;
				}
				flag = 1;

				burst[prior]--;

				if (burst[prior] == 0)
				{
					count++;
					end = time + 1;
					wt = wt + end - arr[prior] - temp[prior];

					w[prior] += end - arr[prior] - temp[prior];
					tt = tt + end - arr[prior];
					t[prior] += end - arr[prior];
				}
				if (prior != x)
				{
					printf(" %d ", (int)time);
					printf(" p%d ", prior + 1);
					x = prior;
				}
			}
			printf(" %d ", (int)end);
			for (i = 0; i < n; i++)
			{
				printf("\np%d wt=%d  tt=%d", i + 1, w[i], t[i]);
			}
			avgwt = wt / n;
			avgtt = tt / n;
			printf("\n\nAverage Waiting Time:%f\n", avgwt);
			printf("Average Turnaround Time:%f\n", avgtt);
			printf("Throughput:%f\n", n / end);
			break;

		case 2:
			flag = 0;
			count = 0;
			wt = 0;
			tt = 0;
			printf("\nGantt chart:\n");
			for (time = 0; count != n; time++)
			{
				prior = 9;
				for (i = 0; i < n; i++)
				{
					if (arr[i] <= time && p[i] < p[prior] && burst2[i] > 0)
					{
						prior = i;
					}
				}
				if (prior == 9)
					continue;
				if (flag == 0)
				{

					printf("%d ", arr[prior]);
				}
				flag = 1;
				while (burst2[prior] > 0)
				{

					burst2[prior]--;

					time++;
					for (k = 0; k < n; k++)
					{
						if (burst2[k] != 0 && k != prior)
						{
							w[k]++;
						}
					}
				}

				if (burst2[prior] == 0)
				{
					time--;
					count++;
					end = time + 1;
					wt = wt + end - arr[prior] - temp[prior];

					tt = tt + end - arr[prior];
				}

				printf(" p%d ", prior + 1);
				printf(" %d ", (int)time + 1);
			}
			for (i = 0; i < n; i++)
			{
				printf("\np%d wt=%d  tt=%d", i + 1, w[i] - arr[i], w[i] - arr[i] + temp[i]);
			}
			avgwt = wt / n;
			avgtt = tt / n;
			printf("\n\nAverage Waiting Time:%f\n", avgwt);
			printf("Average Turnaround Time:%f\n", avgtt);
			printf("Throughput:%f\n", n / end);
			break;
		default:
			exit(0);
		}
	}
	return 0;
}