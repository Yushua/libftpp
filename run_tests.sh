#!/bin/bash

# Define color codes for colored output
RED='\033[31m'
GREEN='\033[32m'
YELLOW='\033[33m'
CYAN='\033[36m'
MAGENTA='\033[35m'
RESET='\033[0m'

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

    check vector_2
    check vector_3
    check random_2D_coordinate_generator
    check perlin_2D
)

# Function to run a test and capture its output to a file
run_and_capture_output() {
    local testname=$1
    local outputfile=$2
    make TESTNAME=$testname run_test > $outputfile
}

# Iterate over each TESTNAME
for TESTNAME in "${TEST_NAMES[@]}"; do
    if [[ $TESTNAME != \#* ]]; then
        if [[ $TESTNAME == check* ]]; then
            # Remove "check" prefix and trim leading whitespace
            TESTNAME=${TESTNAME#check }
            TESTNAME=${TESTNAME## }

            echo -e "${YELLOW}Running test twice for: $TESTNAME to compare results${RESET}"

            # Create temporary files for output
            TMP_FILE1=$(mktemp)
            TMP_FILE2=$(mktemp)

            echo -e "${YELLOW}test files created${RESET}"
            # Run the test twice and capture the output
            run_and_capture_output $TESTNAME $TMP_FILE1
            run_and_capture_output $TESTNAME $TMP_FILE2

            # Compare the outputs
            if diff $TMP_FILE1 $TMP_FILE2 > /dev/null; then
                echo -e "${GREEN}Test $TESTNAME passed: Outputs are identical${RESET}"
            else
                echo -e "${RED}Test $TESTNAME failed: Outputs differ${RESET}"
                echo -e "${CYAN}Differences:${RESET}"
                diff $TMP_FILE1 $TMP_FILE2
            fi

            # Clean up temporary files
            rm -f $TMP_FILE1 $TMP_FILE2
        else
            echo -e "${CYAN}Running test for: $TESTNAME${RESET}"
            make TESTNAME=$TESTNAME run_test
        fi
        echo -e "${MAGENTA}Finished tests for: $TESTNAME${RESET}"
        echo "---------------------------------"
    fi
done