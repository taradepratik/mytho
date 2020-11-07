#include <iostream>

int add(int a, int b)
{
    return (a+b);
}

int subtract(int a, int b){
    return (a-b);
}

int multiply(int a, int b)
{
    return (a*b);
}

int divide(int a, int b)
{
    return (a/b);
}

int facto(int n)
{
    int ans=1;
    for(int i=1; i<=n; i++)
        ans= ans*i;
    return ans;
}

int npr(int n, int r)
{
    return facto(n)/facto(n-r);
}

int ncr(int n, int r)
{
    int ans =1;
    for(int i=1; i<=r; i++)
        ans = ans*(n-r+i)/i;
    return ans;
}

int max(int a, int b){
    return a>b?a:b;
}

int mini(int a, int b){
    return a<b?a:b;
}

int b_search(int a[], int n, int key)
{
    int s=0;
    int e= n;
    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid]==key){
            return mid+1;
        }
        else if(a[mid]>key){
            e= mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}

int isprime(int n)
{
    for(int i=2; i*i<=n; i++)
        if(n%i==0){
            return 0;
        }
    return 1;
}

void sort_b(int a[], int n)
{
    int temp;
    for(int j=0; j<n-1; j++){
        for(int i=0; i<n-j-1; i++){
            if(a[i]>a[i+1]){
                temp=a[i];
                a[i]= a[i+1];
                a[i+1] = temp;
            }
        }
    }
}

void merge(int a[], int l, int m, int r, int n)
{
    int i=l;
    int j=m+1;
    int k= l;
    int temp[n];
    while(i<=m &&j<=r){
        if(a[i]<=a[j])
            temp[k++]= a[i++];
        else
            temp[k++]= a[j++];
    }
    while(i<=m)
        temp[k++]= a[i++];
    while(j<=r)
        temp[k++]= a[j++];

    for(int p=l; p<=r; p++)
        a[p]= temp[p];
}

void mergesort(int a[], int l, int r, int n)
{
    if(l<r){
        int m= (l+r)/2;
        mergesort(a, l, m, n);
        mergesort(a, m+1, r, n);
        merge(a, l, m, r, n);
    }
}

void sort_m(int a[], int n)
{
    mergesort(a, 0, n-1, n);
}


double power(int  x, int n){
    double ans = 1.0;
    long long nn = n;
    if(nn<0) nn= nn*-1;
    while(nn){
        if(nn%2){
            ans = ans * x;
            nn= nn -1;
        }
        else{
            x= x*x;
            nn/= 2;
        }
    }
    if(n<0) ans = 1/ ans;
    return ans;
}

int kadane_algo(int a[], int n)
{
    int msf=a[0], meh=0;
    for(int i=0; i<n; i++){
        meh+= a[i];
        if(msf<meh)
            msf= meh;
        if(meh<0)
            meh=0;
    }
    return msf;
}

int voating_algo(int a[], int n)
{
    int candidate = a[0];
    int count =0;
    for(int i=0; i<n; i++){
        if(count==0)
            candidate = a[i];
        if(candidate== a[i])
            count++;
        else
            count--;
    }
    return candidate;
}




