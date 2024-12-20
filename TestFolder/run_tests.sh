#!/bin/bash

# List of TESTNAMEs to run
TEST_NAMES=(
    pool
    data_buffer
    # server
    # memento
    # observer
    # perlin_2D
    # persistant_worker
    # random_2D_coordinate_generator
    # singleton
    # state_machine
    # thread
    # thread_safe_iostream
    # thread_safe_queue
    # vector_2
    # vector_3
    # worker_pool
)

# Iterate over each TESTNAME
for TESTNAME in "${TEST_NAMES[@]}"; do
    echo "Running tests for: $TESTNAME"
    make TESTNAME=$TESTNAME
    make TESTNAME=$TESTNAME run
    echo "Finished tests for: $TESTNAME"
    echo "---------------------------------"
done
