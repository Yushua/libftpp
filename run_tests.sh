#!/bin/bash

# List of TESTNAMEs to run
TEST_NAMES=(
    # pool
    # data_buffer

    # memento
    # observer
    # singleton
    # state_machine

    # thread_safe_iostream
    # thread_safe_queue
    # thread
    # worker_pool
    # persistant_worker

    # vector_2
    # vector_3
    random_2D_coordinate_generator
    perlin_2D
)

# Iterate over each TESTNAME
for TESTNAME in "${TEST_NAMES[@]}"; do
    if [[ $TESTNAME != \#* ]]; then
        echo "Running tests for: $TESTNAME"
        make TESTNAME=$TESTNAME run_test
        echo "Finished tests for: $TESTNAME"
        echo "---------------------------------"
    fi
done