#include <iostream>
#include <windows.h>
using namespace std;

const int N = 10240;
double b[N][N] , sum[N],a[N];

void init (int n)
 {
 for (int i = 0; i < N; i++)
 for (int j = 0; j < N; j++)
 b[ i ] [ j ] = i + j ;
 for  (int i = 0; i < N; i++)
    a[i]=i;
 }
int main()
{
    int n;
    cin >> n;
    init(n);

    // 开始计时
    LARGE_INTEGER freq, t1, t2;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&t1);

    for (int i = 0; i < n; i++)
        {
          sum[ i ] = 0.0;
          for (int j = 0; j < n; j++)
               sum[ i ] += b[j][i]*a[j] ;
         }

    // 结束计时
    QueryPerformanceCounter(&t2);
    double elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000.0 / freq.QuadPart;

    cout << "The result is :" << endl;

    for (int i = 0; i < n; i++) {
        cout << sum[i] << " ";
    }
    cout << endl;
    cout << "Elapsed time: " << elapsed_time << "ms" << endl;

    return 0;
}
