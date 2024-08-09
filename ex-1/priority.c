# include <stdio.h>

struct priority
{
    int pid;
    int at;
    int bt;
    int pr;
    int ct;
    int tat;
    int wt;
} p[10], temp;

void main()
{
    int np, i, j, t = 0, totaltat = 0, totalwt = 0;

    printf("Enter the no:of process : ");
    scanf("%d", &np);

    for(i = 0; i < np; i++)
    {
        p[i].pid = i + 1;
        printf("Enter Arrival Time of P[%d] : ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter Burst Time of P[%d] : ", i + 1);
        scanf("%d", &p[i].bt);
        printf("Enter Priority of P[%d] : ", i + 1);
        scanf("%d", &p[i].pr);
    }

    for(i = 0; i < np; i++)
    {
        for(j = 0; j < np - i - 1; j++)
        {
            if(p[j].at > p[j + 1].at || (p[j].at == p[j + 1].at && p[j + 1].pr < p[j].pr))
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    for(i = 0; i < np; i++)
    {
        if(t < p[i].at)
        {
            t += p[i].at;
        }
        for(j = i + 1; j < np; j++)
        {
            if(t >= p[j].at && p[j].pr < p[i].pr)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;                
            } 
        }
        t += p[i].bt;
    }

    p[0].wt = 0;
    p[0].tat = p[0].wt + p[0].bt;

    for(i = 0; i < np; i++)
    {
        p[i].ct = p[i - 1].ct + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        totaltat += p[i].tat;
        p[i].wt = p[i].tat - p[i].bt;
        totalwt += p[i].wt;
    }
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("| PID | ARRIVAL TIME | BURST TIME | PRIORITY | COMPLETION TIME | TURN AROUND TIME | WAITING TIME |\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    for(i = 0; i < np; i++)
    {
        printf("| %d   | %3d          | %3d        | %2d       | %3d             | %3d              | %3d          |\n", p[i].pid, p[i].at, p[i].bt, p[i].pr, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("--------------------------------------------------------------------------------------------------\n");

    printf("\nTOTAL TURN AROUND TIME IS : %d\n", totaltat);
    printf("\nAVERAGE TURN AROUND TIME IS : %f\n", totaltat * 1.0 / np);
    printf("\nTOTAL WAITING TIME IS : %d\n", totalwt);
    printf("\nAVERAGE WAITING TIME IS : %f\n", totalwt * 1.0 / np);
}