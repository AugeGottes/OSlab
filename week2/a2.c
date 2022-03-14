#include<stdio.h>
struct process
{
    int waiting_time,arrival_time,burst_time,turn_around_time;
};

struct process a[10];

int main()
{
    int n,temp[10];
    int count=0,t=0,short_P;
    float total_WT=0, total_TAT=0,Avg_WT,Avg_TAT;
    printf("Enter the number of the process\n");
    scanf("%d",&n);
    printf("Enter the arrival time and burst time of the process\n");
    
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].arrival_time,&a[i].burst_time);
        
        
        temp[i]=a[i].burst_time;
    }
  
    a[9].burst_time=10000;
    
    for(t=0;count!=n;t++)
    {
         
        short_P=9;
        for(int i=0;i<n;i++)
        {
            if(a[i].burst_time<a[short_P].burst_time && (a[i].arrival_time<=t && a[i].burst_time>0))
            {
                short_P=i;
            }
            
        }
        
        a[short_P].burst_time=a[short_P].burst_time-1;
        
        if(a[short_P].burst_time==0)
        {
          
            count++;
            a[short_P].waiting_time=t+1-a[short_P].arrival_time-temp[short_P];
            a[short_P].turn_around_time=t+1-a[short_P].arrival_time;
            
            total_WT=total_WT+a[short_P].waiting_time;
            total_TAT=total_TAT+a[short_P].turn_around_time;
        }
        
        
        
    }
    Avg_WT=total_WT/n;
    Avg_TAT=total_TAT/n;
    
    printf("Id waiting_time turn_around_time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\n",i+1,a[i].waiting_time,a[i].turn_around_time);
    }
    printf("Avg waiting time of the process is %f\n",Avg_WT);
    printf("Avg turn around time of the process %f\n",Avg_TAT);
    
}
