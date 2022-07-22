#include <stdio.h>
#include <stdlib.h>
int main()
{
      int i, n, opt, time = 0, x, counter = 0, q;
      int wt = 0, tt = 0, burst[10], temp[10];
      float avgwt, avgtt, throughput;
      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &n);
      x = n;
      for (i = 0; i < n; i++)
      {
            printf("\nEnter Details of Process %d\n", i + 1);
            printf("Burst Time:\t");
            scanf("%d", &burst[i]);
            temp[i] = burst[i];
      }
      while (1)
      {
            printf("\nchoose Time Quantum 1)2ms  2)4ms  3)8ms  4)10ms else)exit:\t");
            scanf("%d", &opt);
            switch (opt)
            {
            case 1:
                  q = 2;
                  break;
            case 2:
                  q = 4;
                  break;
            case 3:
                  q = 8;
                  break;
            case 4:
                  q = 10;
                  break;
            default:
                  exit(0);
            }
            counter = 0;
            wt = 0;
            tt = 0;
            x = n;
            printf("Gantt chart:\n 0");
            for (i = 0; i < n; i++)
            {
                  temp[i] = burst[i];
            }
            for (time = 0, i = 0; x != 0;)
            {
                  if (temp[i] <= q && temp[i] > 0)
                  {
                        time = time + temp[i];
                        temp[i] = 0;
                        counter = 1;
                        printf(" p%d %d", i + 1, time);
                  }
                  else if (temp[i] > 0)
                  {
                        temp[i] = temp[i] - q;
                        time = time + q;
                        printf(" p%d %d", i + 1, time);
                  }

                  if (temp[i] == 0 && counter == 1)
                  {
                        x--;
                        wt = wt + time - burst[i];
                        tt = tt + time;
                        counter = 0;
                  }
                  if (i == n - 1)
                  {
                        i = 0;
                  }
                  else
                  {
                        i++;
                  }
            }
            avgwt = wt * 1.0 / n;
            avgtt = tt * 1.0 / n;
            printf("\n\nAverage Waiting Time:\t%f", avgwt);
            printf("\nAvg Turnaround Time:\t%f\n", avgtt);
            throughput = (n * 1.0) / time;
            printf("\nThroughput:\t%f\n", throughput);
      }
      return 0;
}