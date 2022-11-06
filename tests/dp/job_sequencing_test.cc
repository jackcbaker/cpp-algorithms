#include "job_sequencing.h"

#include <gtest/gtest.h>

#include <vector>
#include <iostream>


TEST(JobSequencingTest, Basic) {
  std::vector<Job> jobs = {
    Job {1, 2, 1, 4},
    Job {1, 2, 2, 5},
  };
  int horizon = 2;
  int result = job_sequencing(jobs, horizon);
  EXPECT_EQ(result, 5);
}


TEST(JobSequencingTest, AllDurationOne) {
  std::vector<Job> jobs = {
    Job {1, 4, 1, 20},
    Job {2, 1, 1, 10},
    Job {3, 1, 1, 40},
    Job {4, 1, 1, 30},
  };
  int horizon = 4;
  int result = job_sequencing(jobs, horizon);
  EXPECT_EQ(result, 60);
}