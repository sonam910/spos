#include<bits/stdc++.h>

using namespace std;

struct process{
    int at, bt, pid;
};

void findWaitingTime(process proc[], int n, int wt[]){
    int rt[n];

    for(int i = 0; i < n; i++){
        rt[i] = proc[i].bt;
    }

    int finish_time, complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0;
    bool check = false;

    while(complete != n){
        for(int j = 0; j < n; j++){
            if((proc[j].at <= t) && (rt[j] < minm) && (rt[j] > 0)){
                shortest = j;
                minm = rt[j];
                check = true;
            }
        }

        if(check == false){
            t++;
            continue;
        }

        rt[shortest]--;

        minm = rt[shortest];

        if(minm == 0) minm = INT_MAX;

        if(rt[shortest] == 0){
            complete++;
            check = false;

            finish_time = t+1;
            wt[shortest] = finish_time - proc[shortest].at - proc[shortest].bt;

            if(wt[shortest] < 0) wt[shortest] = 0;
        }
        t++;
    }
}

void findTurnAroundTime(process proc[], int n, int tat[], int wt[]){
    for(int i = 0; i < n; i++){
        tat[i] = proc[i].bt + wt[i];
    }
}

void findAvgTime(process proc[], int n){
    int tat[n], wt[n];

    findWaitingTime(proc, n, wt);

    findTurnAroundTime(proc, n, tat, wt);

    int wavg = 0, tavg = 0;
    cout<<"Process no"<<" Arrival time "<<" Burst time "<<" Wait time "<<" Turn Around time "<<endl;

    for(int i = 0; i < n; i++){
        wavg += wt[i];
        tavg += tat[i];

        cout<<proc[i].pid<<"\t\t"<<proc[i].at<<"\t\t"<<proc[i].bt<<"\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }
    cout<<"Average Waiting time : "<<((float)wavg/(float)n)<<endl;
    cout<<"Average turn around time : "<<((float)tavg/(float)n);
}

int main(){
    int n;
    cout<<"Enter the number of process: ";
    cin>>n;

    process proc[n];
    cout<<"Enter the Arrival time and burst time of the process";
    for(int i = 0; i < n; i++){
        cin>>proc[i].at>>proc[i].bt;
        proc[i].pid = (i+1);
    }

    findAvgTime(proc, n);
return 0;
}