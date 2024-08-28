#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> uid(n);
    vector<int> bal(n);
    for(int i=0;i<n;i++){
        cin>>uid[i]>>bal[i];
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int f_uid,t_uid,amount;
        cin>>f_uid>>t_uid>>amount;
        int f_ind=-1;
        int t_ind=-1;
        for(int j=0;j<n;j++){
            if(uid[j]==f_uid){
                f_ind=j;
            }
            if(uid[j]==t_uid){
                t_ind=j;
            }
        }
        if(f_ind!=-1 && t_ind!=-1 && bal[f_ind]>=amount){
            bal[f_ind]=bal[f_ind]-amount;
            bal[t_ind]=bal[t_ind]+amount;
            cout<<"Success"<<endl;
        }
        else{
            cout<<"Failure"<<endl;
        }
   
    }
         cout<<"\n";
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if((bal[j]>bal[j+1]) || (bal[j]==bal[j+1] && uid[j]>uid[j+1])){
                swap(bal[j],bal[j+1]);
                swap(uid[j],uid[j+1]);
                
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<uid[i]<<" "<<bal[i]<<endl;
    }
    return 0;
}