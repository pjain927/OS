/*
Tat->Turnaround time
wt->waiting time
*/
#include<iostream>
using namespace std;
struct schedule{
    int arrival;
    int cpu_burst;
    int tat;
    int wt;
};
int main(){
    cout<<"Enter the number of process :- ";
    int n;
    cin>>n;
    schedule process[n];
    cout<<"Enter arrival time and CPU Burst process by process :-\n";
    for(int i=0;i<n;i++)
        cin>>process[i].arrival>>process[i].cpu_burst;
    int ta_time=0,wt_time=0,fre=process[0].cpu_burst;
    for(int i=0;i<n;i++){
        process[i].tat=fre-process[i].arrival;
        if(i!=n-1)
            fre+=process[i+1].cpu_burst;
    }
    for(int i=0;i<n;i++)
        process[i].wt=process[i].tat-process[i].cpu_burst;
    for(int i=0;i<n;i++){
        ta_time+=process[i].tat;
        wt_time+=process[i].wt;
    }
    cout<<"Avg. Turnaround time is :- "<<(float)ta_time/n<<endl;
    cout<<"Avg. Waiting time is :- "<<(float)wt_time/n<<endl;
    return 0;
}
