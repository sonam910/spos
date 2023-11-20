#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, tq, remain, i, time, temps = 0, tavg = 0, wavg = 0; 
    cout<<"Enter the time quantum : ";
    cin>>tq;
    cout<<"Enter the number of process : ";
    cin>>n;

    int rt[n], tat[n], wt[n], at[n], bt[n];
    cout<<"Enter the arrival time and burst time of the processes;\n";
    for(int i = 0; i < n; i++){
        cin>>at[i]>>bt[i];
        rt[i] = bt[i];
    }

    remain = n;
    for(time = 0, i = 0;remain != 0;){
        if(rt[i] < tq && rt[i] > 0){
            time += rt[i];
            rt[i] = 0;
            temps = 1;
        }else if(rt[i] > 0){
            rt[i] -= tq;
            time += tq;
        }

        if(rt[i] == 0 && temps == 1){
            remain--;
            cout<<(i+1)<<"\t\t"<<time-at[i]<<"\t\t"<<time-bt[i]-at[i]<<endl;


            wt[i] = time-bt[i]-at[i];
            tat[i] = time-at[i];
            wavg += time-bt[i]-at[i];
            tavg += time-at[i];
            temps = 0;
        }
        if(i == n-1) i = 0;
        else if(at[i+1] <= time) i++;
        else i = 0;
    }

    cout<<"Average Wait time : "<<((float)wavg/(float)n);
    cout<<"Average Turn Around time : "<<((float)tavg/(float)n);
return 0;
}