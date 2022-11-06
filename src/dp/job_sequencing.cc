#include "job_sequencing.h"

#include <vector>
#include <iostream>


int job_sequencing(std::vector<Job> jobs, int horizon) {
    int nJobs = jobs.size();
    std::vector<std::vector<int>> V(
        nJobs + 1,
        std::vector<int>(horizon + 1)
    );
    for (int j = 0; j <= nJobs; j++) {
        for (int h = 0; h <= horizon; h++) {
            if (j == 0 || h == 0) {
                V[j][h] = 0;
                continue;
            }
            Job job = jobs[j - 1];
            int deadline = job.deadline;
            if (deadline <= horizon) {
                V[j][h] = std::max(
                    V[j - 1][h],
                    V[j - 1][h - job.duration] + job.profit
                );
            }
            else {
                V[j][h] = V[j - 1][h];
            }
        }
    }
    return V[nJobs][horizon];
}