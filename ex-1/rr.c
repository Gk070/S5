# include <stdio.h>

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
}p[10], temp;

void main()
{
    int np, i, j, quantam, rp, it = 0, totaltat = 0, totalwt = 0;

    printf("Enter no:of process : ");
    scanf("%d", &np);

    printf("Enter time quantam : ");
    scanf("%d", &quantam);

    rp = np;

    for(i = 0; i < np; i++)
    {
        p[i].pid = i + 1;
        printf("Enter Arrival Time P[%d] : ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter Burst Time P[%d] : ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
    }

    for(i = 0; i < np; i++)
    {
        for(j = 0; j < np - i - 1; j++)
        {
            if(p[j].at > p[j + 1].at)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    if(p[0].at > it)
    {
        it = p[0].at;
    }

    while(rp > 0)
    {
        for(i = 0; i < np; i++)
        {
            if(p[i].rt > 0)
            {
                if(p[i].rt > quantam)
                {
                    it += quantam;
                    p[i].rt -= quantam;
                }
                else
                {
                    it += p[i].rt;
                    p[i].ct = it;
                    p[i].rt = 0;
                    rp--;
                }
            }
        }
    }

    for(i = 0; i < np; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        totaltat += p[i].tat;
        p[i].wt = p[i].tat - p[i].bt;
        totalwt += p[i].wt;
    }

    printf("---------------------------------------------------------------------------------------\n");
    printf("| PID | ARRIVAL TIME | BURST TIME | COMPLETION TIME | TURN AROUND TIME | WAITING TIME |\n");
    printf("---------------------------------------------------------------------------------------\n");
    for(i = 0; i < np; i++)
    {
        printf("| %d   | %3d          | %3d        | %3d             | %3d              | %3d          |\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("---------------------------------------------------------------------------------------\n");

    printf("\nTOTAL TURN AROUND TIME IS : %d\n", totaltat);
    printf("\nAVERAGE TURN AROUND TIME IS : %f\n", totaltat * 1.0 / np);
    printf("\nTOTAL WAITING TIME IS : %d\n", totalwt);
    printf("\nAVERAGE WAITING TIME IS : %f\n", totalwt * 1.0 / np);
}