#include "job_sequencing.h"

#include <vector>
#include <algorithm>
#include <iostream>

// This dynamic programming algorithm solves the job sequencing problem.
// We have N jobs with deadline d, duration p, and profit v.
// A job only receives profit if completed before the deadline.
// The aim is to complete the correct jobs in order to maximise profit.
//
// The recursive solution is to proceed backwards from the job with the largest deadline.
// First we would sort the jobs descending by deadline. Let n be the number of jobs left on this list.
// Let h be the time horizon. We have:
// V(n, h) = max{V(n-1, h) + V(n-1, min(h - p, d - p) + v}
// where p, d, v are the processing time, deadline and value for job n respectively.
// To reduce storage and complexity we proceed in a bottom up way.
// The complexity is O(ND), where D is the max deadline of the jobs.


bool deadlineComparator(const Job& lhs, const Job& rhs) {
    return lhs.deadline < rhs.deadline;
}


int jobSequencing(std::vector<Job> jobs, int horizon) {
    // jobs not passed by ref as need to sort later.
    int nJobs = jobs.size();
    std::vector<std::vector<int>> V(
        nJobs + 1,
        std::vector<int>(horizon + 1)
    );
    // Sort by deadline
    std::sort(jobs.begin(), jobs.end(), &deadlineComparator);
    for (int j = 0; j <= nJobs; j++) {
        for (int h = 0; h <= horizon; h++) {
            if (j == 0 || h == 0) {
                V[j][h] = 0;
                continue;
            }
            Job job = jobs[j - 1];
            if (h > job.deadline) {
                V[j][h] = V[j][h-1];
            }
            else if ((job.duration <= h)) {
                // min(h - d, D_j - d)
                V[j][h] = std::max(
                    V[j - 1][h],
                    V[j - 1][std::min(h, job.deadline) - job.duration] + job.profit
                );
            }
            else {
                V[j][h] = V[j - 1][h];
            }
        }
    }
    return V[nJobs][horizon];
}