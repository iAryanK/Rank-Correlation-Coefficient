// Rank Correlation Coefficient
// 25-04-2022 12:39 AM

#include <bits/stdc++.h>
using namespace std;

void getData(float arr[], int n) {
    for (int i=0;i<n;i++)
    cin>>arr[i];
}

int main(){

    cout<<"\n\tRank Correlation\n";
    cout<<"\t----------------\n";
    cout<<"1. When ranks are given\n";
    cout<<"2. When ranks are not given\n";
    cout<<"3. When items or rank repeat in data\n\n";
    cout<<"Enter your choice:";
    int choice;cin>>choice;

    cout<<"Enter size of each data set:";
    int n;cin>>n;

    float x[n];
    float y[n];
    float temp[n];
    float sum=0, rho;
    
    switch (choice) {

        case 1:
        
        cout<<"Enter first set of data: ";
        getData(x,n);
        cout<<"Enter second set of data: ";
        getData(y,n);

        for (int i=0;i<n;i++) {
            x[i]=abs(x[i]-y[i]);
            x[i]*=x[i];
            sum+=x[i];
        }
        rho=1-(6*sum)/(n*n*n-n);
        cout<<rho;
        break;

        case 2:

        cout<<"Enter first set of data: ";
        getData(x,n);
        cout<<"Enter second set of data: ";
        getData(y,n);

        copy(x,x+n,temp);
        sort(temp,temp+n);
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (temp[i]==x[j])
                x[j]=i+1;
            }
        }

        copy(y,y+n,temp);
        sort(temp,temp+n);
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (temp[i]==y[j])
                y[j]=i+1;
            }
        }

        for (int i=0;i<n;i++) {
            x[i]=abs(x[i]-y[i]);
            x[i]*=x[i];
            sum+=x[i];
        }

        rho=1-(6*sum)/(n*n*n-n);
        cout<<rho;
        break;

        case 3:

        cout<<"Enter first set of data: ";
        getData(x,n);
        cout<<"Enter second set of data: ";
        getData(y,n);

        copy(x,x+n,temp);
        sort(temp,temp+n);

        int k;
        float msum; msum=0.0;

        for (int i=0;i<n;i++) {
            int count=1, idxSum=i+1, prevIdx=i, flag=0,idx=i+2;
            k=i;
            while (temp[k]==temp[k+1]) {
                flag=1;
                idxSum+=idx;
                count++;
                idx++;
                k++;
            }
            if (flag==1) {
                msum+=((pow(count,3)-count)/12.0);

                float rank=(float)idxSum/count;
                for (int j=prevIdx;j<prevIdx+count;j++) {
                    for (int l=0;l<n;l++) {
                        if (temp[j]==x[l])
                        x[l]=rank;
                    }
                }
                i=i+count-1;
            }
            else {
                for (int l=0;l<n;l++) {
                    if (temp[prevIdx]==x[l])
                    x[l]=prevIdx+1;
                }
            }
        }

        copy(y,y+n,temp);
        sort(temp,temp+n);

        for (int i=0;i<n;i++) {
            int count=1, idxSum=i+1, prevIdx=i, flag=0, idx=i+2;
            k=i;
            while (temp[k]==temp[k+1]) {
                flag=1;
                idxSum+=idx;
                idx++;
                count++;
                k++;
            }
            if (flag==1) {
                msum+=((pow(count,3)-count)/12.0);

                float rank=(float)idxSum/count;
                for (int j=prevIdx;j<prevIdx+count;j++) {
                    for (int l=0;l<n;l++) {
                        if (temp[j]==y[l])
                        y[l]=rank;
                    }
                }
                i=i+count-1;
            }
            else {
                for (int l=0;l<n;l++) {
                    if (temp[prevIdx]==y[l])
                    y[l]=prevIdx+1;
                }
            }
        }

        for (int i=0;i<n;i++) {
            x[i]=abs(x[i]-y[i]);
            x[i]*=x[i];
            sum+=x[i];
        }

        rho=1-6*(sum+msum)/((n*n*n)-n);
        cout<<rho;
        break;

        default:
        cout<<"ERROR: Invalid input!";
    }
    return 0;
}