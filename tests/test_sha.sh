#!/bin/bash

TEST_SHA_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

. "$TEST_SHA_DIR/tools/checker.sh"

check_test "$TEST_SHA_DIR/sha/test_md5.sh"
check_test "$TEST_SHA_DIR/sha/test_sha1.sh"
check_test "$TEST_SHA_DIR/sha/test_sha224.sh"
check_test "$TEST_SHA_DIR/sha/test_sha256.sh"
check_test "$TEST_SHA_DIR/sha/test_sha384.sh"
check_test "$TEST_SHA_DIR/sha/test_sha512.sh"
check_test "$TEST_SHA_DIR/sha/test_sha512224.sh"
check_test "$TEST_SHA_DIR/sha/test_sha512256.sh"
