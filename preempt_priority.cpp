/*
p_no->process no.
tat->turnaround time
wt->waiting time
*/
#include<iostream>
#include<queue>
using namespace std;
struct schedule{
    int p_no;
    int arrival;
    int cpu_burst;
    int priority;
    int tat;
    int wt;
};
class myComparator{
    public:
    int operator() (struct schedule a, struct schedule b){
        return a.priority>b.priority;
    }

};
int main(){
    cout<<"Enter the number of process :- ";
    int n,end_time=0;
    cin>>n;
    schedule process[n];
    cout<<"Enter arrival time and CPU Burst process by process :-\n";
    for(int i=0;i<n;i++){
        cin>>process[i].arrival>>process[i].cpu_burst>>process[i].priority;
        process[i].p_no=i;
        end_time+=process[i].cpu_burst;
    }
    priority_queue<struct schedule, vector<struct schedule>, myComparator> ready;
    int time,count_p=0,j,i;
    for(time=0;time<=end_time && count_p!=n;time++){
        for(j=count_p;j<n;j++){
            if(time>=process[j].arrival){
                ready.push(process[j]);
                count_p++;
            }
        }
        struct schedule temp=ready.top();
        ready.pop();
        if(temp.cpu_burst==1)
            process[temp.p_no].tat=time-process[temp.p_no].arrival+1;
        else{
            temp.cpu_burst--;
            ready.push(temp);
        }
}
    while(!ready.empty()){
        struct schedule temp=ready.top();
        int pn=temp.p_no;
        time+=temp.cpu_burst;
        process[pn].tat=time-process[pn].arrival;
        ready.pop();
    }
    int ta_time=0,wt_time=0;
    for(int i=0;i<n;i++){
        process[i].wt=process[i].tat-process[i].cpu_burst;
        ta_time+=process[i].tat;
        wt_time+=process[i].wt;
    }
    cout<<"Avg. Turnaround time is :- "<<(float)ta_time/n<<endl;
    cout<<"Avg. Waiting time is :- "<<(float)wt_time/n<<endl;
}

