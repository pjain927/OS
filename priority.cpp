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
    int n;
    cin>>n;
    schedule process[n];
    cout<<"Enter arrival time and CPU Burst process by process :-\n";
    for(int i=0;i<n;i++){
        cin>>process[i].arrival>>process[i].cpu_burst>>process[i].priority;
        process[i].p_no=i;
    }
    priority_queue<struct schedule, vector<struct schedule>, myComparator> ready;
    int time=0,count_p=0,j,i;
    for(i=0;i<n && count_p!=n;i++){
        for(j=count_p;j<n;j++){
            if(time>=process[j].arrival){
                ready.push(process[j]);
                count_p++;
            }
        }
        struct schedule temp=ready.top();
        int pn=temp.p_no;
        time+=temp.cpu_burst;
        process[pn].tat=time-process[pn].arrival;
        process[pn].wt=process[pn].tat-process[pn].cpu_burst;
        ready.pop();
    }
    while(!ready.empty()){
        struct schedule temp=ready.top();
        int pn=temp.p_no;
        time+=temp.cpu_burst;
        process[pn].tat=time-process[pn].arrival;
        process[pn].wt=process[pn].tat-process[pn].cpu_burst;
        ready.pop();
    }
    int ta_time=0,wt_time=0;
    for(int i=0;i<n;i++){
        ta_time+=process[i].tat;
        wt_time+=process[i].wt;
    }
    cout<<"Avg. Turnaround time is :- "<<(float)ta_time/n<<endl;
    cout<<"Avg. Waiting time is :- "<<(float)wt_time/n<<endl;
}
