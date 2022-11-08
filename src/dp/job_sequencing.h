#ifndef JOB_SEQUENCING_H
#define JOB_SEQUENCING_H

#include <vector>


struct Job
{
    int id {};
    int deadline {};
    int duration {};
    int profit {};
};


int jobSequencing(std::vector<Job> jobs, int horizon);


#endif