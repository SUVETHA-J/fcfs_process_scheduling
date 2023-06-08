#include<stdio.h>
int main()
{
    int n;
    printf("Number of process:");
    scanf("%d",&n);
    int arr[n],bt[n],ct[n],i=0,j,p[n],tat[n],wt[n];
    int s=0,end=0,tot1=0,tot2=0;
    float avg1,avg2;
    for(i=0;i<n;i++)
    {
        printf("\n process:%d",i+1);
        printf("\n arrival time:");
        scanf("%d",&arr[i]);
        printf("\n burst time:");
        scanf("%d",&bt[i]);
    }
    while(s!=n)
    {
        if(arr[s]<=end)
        {
            end=end+bt[s];
            ct[s]=end;
        }
        else
        {
            end=end+(arr[s]-end)+bt[s];
        ct[s]=end;
        }
        s++;
    }
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-arr[i];
        tot1=tot1+tat[i];
        wt[i]=tat[i]-bt[i];
        tot2=tot2+wt[i];

    }
    avg1=(float)tot1/n;
    avg2=(float)tot2/n;

    printf("process\t\tarrival time\t\t burst time\t\t CT\t\tTAT\t\tWT\n");
    for(i=0;i<n;i++)
{
    printf("%d\t\t%d\t\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,arr[i],bt[i],ct[i],tat[i],wt[i]);

}
printf("%.2f\n%.2f",avg1,avg2);

}
