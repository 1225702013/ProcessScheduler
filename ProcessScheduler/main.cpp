#include <iostream>
#include <fstream>
#include "Job.h"
#include "LinkList.cpp"  //ģ���࣬��Ҫ����Դ�ļ�cpp������ͷ�ļ�h�᲻ͨ��
using namespace std;

int main() {
    ifstream file("data.txt", ios::in);
    if(!file.is_open()) {
        cout << "data.txt can't open for read!" << endl;
        system("pause");
        exit(1);
    }
    char str[45];
    //�����ж���
    file.getline(str, 45);

    //��ҵ��
    NodeList<Job> jobs;
    jobs.SetCompareFunction(jobSortArrivalTime);

    Job job;
    while(file >> job.jobId) {
        file >> job.arrivalTime;
        file >> job.executionTime;
        file >> job.priority;
        jobs.Insert(jobs.GetLength(), job, true);
    }
    file.close();
    jobs.Print(cout);
    system("pause");
    return 0;
}
