#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

int hm;
clock_t start, stop;
double t;

int main()
{
    cout << "This program is to practice dynamic memory allocation" << endl;
    cout<<"The program will compare how fast we can operate on arrays with and without references/pointers."<<endl;
    cout<<"How many number in array (recommended 10e10):"<<endl;
    cin>>hm;

    int *table;
    table = new int [hm];

    start=clock();

    for(int i=0; i<hm; i++)
    {
        table[i]=i;
        table[i]+=50;
    }

    stop = clock();

    t=(double)(stop-start)/ CLOCKS_PER_SEC;
    cout<<"Saving time without reference: "<<t<<endl;

    delete[]table;


    table = new int[hm];
    int *p = table;
    start = clock();

    for(int i=0; i<hm; i++)
    {
        *p = i;
        *p += 50;
        p++;
    }

    stop=clock();
    t=(double)(stop-start)/ CLOCKS_PER_SEC;
    cout<<"Saving time with reference: "<<t<<endl;

    delete [] table;

    cout<<"Press any key to exit"<<endl;
    getchar();
    getchar();

    return 0;
}
