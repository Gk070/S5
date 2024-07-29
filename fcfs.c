# include <stdio.h>

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
}p[10], temp;

int main()
{
    int n, i, j, totaltat = 0, totalwt= 0;

    printf("Enter no:of process: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter arrival time of P[%d] : ", i + 1);
        scanf(" %d", &p[i].at);
        printf("Enter burst time of P[%d] : ", i + 1);
        scanf(" %d", &p[i].bt);
    }

    for(i = 0; i < n; i++)
    {
        for(j = 1; j < n - i - 1; j++)
        {
            if(p[j].at > p[j+1].at)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1]= temp;   
            }
        }
    }

    p[0].wt = 0;
    p[0].tat = p[0].wt + p[0].bt;

    for(i= 0; i < n; i++)
    {
        p[i].ct = p[i - 1].ct + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        totaltat += p[i].tat;
        p[i].wt = p[i].tat - p[i].bt;
        totalwt += p[i].wt;
    }

    printf("---------------------------------------------------------------------------------------\n");
    printf("| PID | ARRIVAL TIME | BURST TIME | COMPLETION TIME | TURN AROUND TIME | WAITING TIME |\n");
    printf("---------------------------------------------------------------------------------------\n");
    for(i = 0; i < n; i++)
    {
        printf("| %d   | %3d          | %3d        | %3d             | %3d              | %3d          |\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("---------------------------------------------------------------------------------------\n");

    printf("\nTOTAL TURN AROUND TIME IS : %d\n", totaltat);
    printf("\nAVERAGE TURN AROUND TIME IS : %f\n", totaltat * 1.0 / n);
    printf("\nTOTAL WAITING TIME IS : %d\n", totalwt);
    printf("\nAVERAGE WAITING TIME IS : %f\n", totalwt * 1.0 / n);

    return 0;
}