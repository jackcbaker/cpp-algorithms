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
  int result = jobSequencing(jobs, horizon);
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
  int result = jobSequencing(jobs, horizon);
  EXPECT_EQ(result, 60);
}


TEST(JobSequencingTest, AllDurationOne2) {
  std::vector<Job> jobs = {
    Job {1, 2, 1, 100},
    Job {2, 1, 1, 19},
    Job {3, 2, 1, 27},
    Job {4, 1, 1, 25},
    Job {4, 3, 1, 15},
  };
  int horizon = 3;
  int result = jobSequencing(jobs, horizon);
  EXPECT_EQ(result, 142);
}


TEST(JobSequencingTest, JobsPostHorizon) {
  std::vector<Job> jobs = {
    Job {1, 2, 1, 100},
    Job {2, 1, 1, 19},
    Job {3, 2, 1, 27},
    Job {4, 1, 1, 25},
    Job {4, 3, 1, 15},
  };
  int horizon = 2;
  int result = jobSequencing(jobs, horizon);
  EXPECT_EQ(result, 127);
}


TEST(JobSequencingTest, NoJobs) {
  std::vector<Job> jobs = {
  };
  int horizon = 2;
  int result = jobSequencing(jobs, horizon);
  EXPECT_EQ(result, 0);
}


TEST(JobSequencingTest, LongJobs) {
  std::vector<Job> jobs = {
    Job {1, 2, 2, 100},
    Job {2, 2, 2, 19},
    Job {3, 2, 4, 27},
    Job {4, 5, 3, 25},
    Job {4, 5, 1, 15},
  };
  int horizon = 5;
  int result = jobSequencing(jobs, horizon);
  EXPECT_EQ(result, 125);
}


TEST(JobSequencingTest, LongHorizon) {
  std::vector<Job> jobs = {
    Job {1, 2, 2, 100},
    Job {2, 2, 2, 19},
    Job {3, 2, 4, 27},
    Job {4, 5, 3, 25},
    Job {4, 5, 1, 15},
  };
  int horizon = 6;
  int result = jobSequencing(jobs, horizon);
  EXPECT_EQ(result, 125);
}