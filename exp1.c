#include<stdio.h>

int main() {
    int n, choice, i, j, bt[10], st[10], wt2[10], tat[10], count = 0, swt = 0, stat = 0, temp, sq = 0, tq;
    float arrv[10] = {
      0
    }, bur[10], t, u, tlast, wt;
    int procno[10], priority[10];
    float awt = 0.0, atat = 0.0;
    do {
      printf("Enter the choice \n");
      printf(" 1) FCFS\n\n 2) Priority\n 3) Round Robin\n 4)EXIT\n ");

          scanf("%d", & choice);
          switch (choice) {
          case 1:

            printf("The no. of processes for implementing the scheduling algorithm - FCFS\n ");

            scanf("%d", & n);
            printf("enter the Arrival time and Burst time for each process: \n ");
            for (i = 0; i <= n - 1; i++)
                scanf("%f%f", & arrv[i], & bur[i]);
                for (i = 0; i <= n - 2; i++)
                    for (j = i + 1; j <= n - 1; j++)
                        if (arrv[i] > arrv[j]) {
                            t = arrv[i];
                            u = bur[i];
                            arrv[i] = arrv[j];
                            bur[i] = bur[j];
                            arrv[j] = t;
                            bur[j] = u;
                        }
                    printf("Arrival time\tWait time\tTurnround time\n"); 
                    tlast = 0; 
                    wt = 0;
                    for (i = 0; i <= n - 1; i++) {
                        printf("%f\t%f\t%f\n", arrv[i], wt, wt + bur[i]);
                        tlast = tlast + bur[i];
                        wt = tlast - arrv[i + 1];
                    }
                    break;

                    case 2:
                        printf("Enter the no. of processes in Priority scheduling algorithm\n ");
                        scanf("%d", & n); 
                        printf("enter the priority and Burst time for each process:\n ");
                        for (i = 0; i <= n - 1; i++)
                            scanf("%d%f", & priority[i], & bur[i]);

                        for (i = 0; i <= n - 2; i++)
                            for (j = i + 1; j <= n - 1; j++)
                                if (priority[i] > priority[j]) {
                                    t = bur[i];
                                    u = priority[i];
                                    bur[i] = bur[j];
                                    priority[i] = priority[j];
                                    bur[j] = t;
                                    priority[j] = u;
                                }

                        printf("Priority\tWait time\tTurnround time\n"); tlast = 0; wt = 0;
                        for (i = 0; i <= n - 1; i++) {
                            printf("%d\t%f\t%f\n", priority[i], wt, wt + bur[i]);
                            tlast = tlast + bur[i];
                            wt = tlast - arrv[i + 1];
                        }
                        break;

                      case 3:
                        printf("Enter number of processes in Round Robin Algorithm: ");
                        scanf("%d", & n); printf("Enter burst time for sequences:");
                        for (i = 0; i < n; i++) {
                            scanf("%d", & bt[i]);
                            st[i] = bt[i];
                        }
                        printf("Enter time slice:"); scanf("%d", & tq);
                        while (1) {
                            for (i = 0, count = 0; i < n; i++) {
                                temp = tq;
                                if (st[i] == 0) {
                                count++;
                                continue;
                                }
                                if (st[i] > tq)
                                st[i] = st[i] - tq;
                                else
                                if (st[i] >= 0) {
                                temp = st[i];
                                st[i] = 0;
                                }
                                sq = sq + temp;
                                tat[i] = sq;
                            }
                            if (n == count)

                                break;
                        }
                        for (i = 0; i < n; i++) {
                            wt2[i] = tat[i] - bt[i];
                            swt = swt + wt2[i];
                            stat = stat + tat[i];
                        }
                        awt = (float) swt / n; atat = (float) stat / n; printf("Process_no\tBurst time\tWait time\tTurn around time\n ");
                          for (i = 0; i < n; i++)
                            printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt2[i], tat[i]); printf("Avg wait time is %f,\nAvg turn around time is %f ",awt,atat);
                            break;
                          }
                        }
                        while (choice != 4);
                      }