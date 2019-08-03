#include <iostream>

using namespace std;

int main()
{
    int process_no[100],brust_time[100],copyBrusttime[100],totalBrusttime=0,completetime[100],waitingtime[100],timequantum,temp=0,i=0,n;
    cout<<"enter the process_no:"<<endl;
    cin>>n;
    cout<<"elements are:"<<endl;
    for(i=1;i<=n;i++){
        cin>>process_no[i]>>brust_time[i];
    }
    cout<<"enter the time quantum:"<<endl;
    cin>>timequantum;
    for(i=1;i<=n;i++){
        copyBrusttime[i]=brust_time[i];
    }
    for(i=1;i<=n;i++){
        totalBrusttime=totalBrusttime+brust_time[i];
    }
    while(totalBrusttime!=0){
            if(i==n+1){
                i=1;
            }
        if(brust_time[i]>=timequantum){
            temp=temp+timequantum;
            completetime[i]=temp;
            totalBrusttime=totalBrusttime-timequantum;
            brust_time[i]=brust_time[i]-timequantum;
        }
        else if(brust_time[i]<timequantum && brust_time[i]!=0){
            temp=temp+brust_time[i];
            completetime[i]=temp;
            totalBrusttime=totalBrusttime-brust_time[i];
            brust_time[i]=0;
        }
         i++;
    }

    for(i=1;i<=n;i++){
        waitingtime[i]=completetime[i]- copyBrusttime[i];
    }

    cout<<"process_no"<<"\t"<<"brust_time"<<"\t"<<"complete_time"<<"\t"<<"waiting_time"<<endl;
    for(i=1;i<=n;i++){
        cout<<process_no[i]<<"\t\t"<<copyBrusttime[i]<<"\t\t"<<completetime[i]<<"\t\t"<<waitingtime[i]<<endl;
    }
    return 0;
}
