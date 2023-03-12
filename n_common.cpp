#include<iostream>

#include <windows.h>
using namespace std;

const int N = 33554432.7;
double sum,a[N];

void init ()
 {
 for  (int i = 0; i < N; i++)
    a[i]=10;
 }
int main()
{
    int n;
    long long m;
    cin >> n;
    m=1;
    for(int i=1;i<=n;i++)
    m*=2;

    init();
    sum = 0.0;
    // 开始计时
    LARGE_INTEGER freq, t1, t2;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&t1);



    for (int i = 0; i < m; i++)
               sum += a[i] ;


    // 结束计时
    QueryPerformanceCounter(&t2);
    double elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000000.0 / freq.QuadPart;

    cout << "The result is :" << endl;
    cout << sum;

    cout << endl;
    cout << "Elapsed time: " << elapsed_time << "us" << endl;

    return 0;
}
