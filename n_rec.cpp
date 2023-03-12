#include<iostream>
#include <windows.h>
using namespace std;

const int N = 33554432;
double a[N];

void init ()
 {
 for  (int i = 0; i < N; i++)
    a[i]=10;
 }
  void recursion(long long n)
  {
     if (n == 1)
      return;
    else
    {
    for (int i = 0; i < n / 2; i++)
      a[i]+=a[n-i-1];
    n = n / 2;
    recursion(n);
    }
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

    // 开始计时
    LARGE_INTEGER freq, t1, t2;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&t1);



    recursion(m);




    // 结束计时
    QueryPerformanceCounter(&t2);
    double elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000000.0 / freq.QuadPart;

    cout << "The result is :" << endl;
    cout << a[0];

    cout << endl;
    cout << "Elapsed time: " << elapsed_time << "us" << endl;

    return 0;
}
