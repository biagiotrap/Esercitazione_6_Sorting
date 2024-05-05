#include<iostream>
#include<chrono>
#include<unistd.h>
#include<vector>
#include<algorithm>
#include<sstream>
#include"SortingAlgorithm.hpp"
using namespace std;
using namespace SortLibrary;



int main(int argc, char **argv)
{
    std::chrono::steady_clock::time_point t_begin = std::chrono::
        steady_clock::now();
    std::chrono::steady_clock::time_point t_end = std::chrono::
        steady_clock::now();
    int s=10;
    int n=0;
    double duration=0;
    vector<double> tempi={};
    istringstream conv(argv[1]);
    conv>>n;
    vector<double> v1(n);
    vector<double> v2(n);
    for(int m=0;m<10;m++){
        s=10;
        generate(v1.begin(), v1.end(), [&s] () {return s--;});
        for(int i=0; i<n;i++){
            v1[i]=rand() %100;
            v2[i]=v1[i];
        }
        t_begin = std::chrono::steady_clock::now();
        MergeSort(v1);
        t_end = std::chrono::steady_clock::now();
        duration=std::chrono::duration_cast<std::chrono::microseconds>
                   (t_end-t_begin).count();
        tempi.push_back(duration);
        t_begin = std::chrono::steady_clock::now();
        BubbleSort(v2);
        t_end = std::chrono::steady_clock::now();
        duration=std::chrono::duration_cast<std::chrono::microseconds>
                   (t_end-t_begin).count();
        tempi.push_back(duration);
    }
    double tempiM=0;
    double tempiB=0;
    unsigned int num=tempi.size();
    for(unsigned int c=0;c<num;c+=2){
        tempiM+=tempi[c];
        tempiB+=tempi[c+1];
    }
    tempiM=tempiM/(num/2);
    tempiB=tempiB/(num/2);
    cout<<tempiM<<endl;
    cout<<tempiB<<endl;
    return 0;
}

