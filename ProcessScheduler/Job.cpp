#include "Job.h"
//������ʱ��������
int jobSortArrivalTime(Job& left, Job& right) {
    return left.arrivalTime < right.arrivalTime ? -1 : 1;
}
