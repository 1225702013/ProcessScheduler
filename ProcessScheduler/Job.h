#pragma once
struct Job {
    //��ҵID
    unsigned int jobId;
    //����ʱ��
    unsigned int arrivalTime;
    //ִ��ʱ��
    unsigned int executionTime;
    //����Ȩ
    unsigned int priority;
};

//������ʱ��������
int jobSortArrivalTime(Job&, Job&);
