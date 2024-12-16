#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstdio>
#include <fstream>
#include <stack>
#include <algorithm>
#include <chrono>
#include <climits>
#define limit 100000
#define cutoff 5000
using namespace std;
using namespace std::chrono;
int ar[limit + 2], tmp[limit + 2];
int Partition(int l, int r)
{
    int pivot = l;
    while (l <= r)
    {
        while (ar[l] <= ar[pivot])
            l++;
        while (r > pivot && ar[r] >= ar[pivot])
            r--;
        if (l < r)
            swap(ar[l], ar[r]);
    }
    swap(ar[r], ar[pivot]);
    return r;
}
void qsort(int l = 0, int r = limit - 1)
{
    if (r <= l)
        return;
    int pivot = l;
    swap(ar[l], ar[pivot]);
    int k = Partition(l, r);
    qsort(l, k - 1);
    qsort(k + 1, r);
    return;
}

void qsort_median(int l = 0, int r = limit - 1)
{
    if (r <= l)
        return;
    int pivot = (l + r) / 2;
    swap(ar[l], ar[pivot]);
    int k = Partition(l, r);
    qsort_median(l, k - 1);
    qsort_median(k + 1, r);
    return;
}

void qsort_median_insertion(int l = 0, int r = limit - 1)
{
    if (r <= l)
        return;
    if (r - l <= cutoff)
    {
        sort(ar + l, ar + r + 1);
        return;
    }
    int pivot = (l + r) / 2;
    swap(ar[l], ar[pivot]);
    int k = Partition(l, r);
    qsort_median_insertion(l, k - 1);
    qsort_median_insertion(k + 1, r);
    return;
}
void qsort_median_insertion_reduced_recursion(int l = 0, int r = limit - 1)
{
    while (r - l >= cutoff)
    {
        int pivot = (l + r) / 2;
        swap(ar[l], ar[pivot]);
        int k = Partition(l, r);
        qsort_median_insertion_reduced_recursion(l, k - 1);
        l = k + 1;
    }
    sort(ar + l, ar + r + 1);
    return;
}
int main()
{
    srand(time(0));
    for (int i = 0; i < limit; i++)
        ar[i] = tmp[i] = rand() % 100;
    ar[limit] = tmp[limit] = INT_MAX;

    cout << "original        : ";
    auto start = high_resolution_clock::now();
    qsort();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count()/1000.0 << " ms"
         << "\n";

    for (int i = 0; i <= limit; i++)
        ar[i] = tmp[i];
    cout << "(a)             : ";
    start = high_resolution_clock::now();
    qsort_median();
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << duration.count()/1000.0 << " ms"
         << "\n";

    for (int i = 0; i <= limit; i++)
        ar[i] = tmp[i];
    cout << "(a) + (b)       : ";
    start = high_resolution_clock::now();
    qsort_median_insertion();
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << duration.count()/1000.0 << " ms"
         << "\n";

    for (int i = 0; i <= limit; i++)
        ar[i] = tmp[i];
    cout << "(a) + (b) + (c) : ";
    start = high_resolution_clock::now();
    qsort_median_insertion_reduced_recursion();
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << duration.count()/1000.0 << " ms"
         << "\n";

    return 0;
}