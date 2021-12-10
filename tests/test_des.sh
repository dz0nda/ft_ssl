#!/bin/bash

TEST_DES_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

. "$TEST_DES_DIR/des/test_des_cbc.sh"
. "$TEST_DES_DIR/des/test_des_ecb.sh"

test_des_ecb_key 'less than block size string' 'abcdefg' '133457799BBCDFF1'
test_des_ecb_key 'block size string' 'abcdefgh' '133457799BBCDFF1'
test_des_ecb_key 'block size string + 1' 'abcdefgha' '133457799BBCDFF1'
test_des_ecb_key 'double block size string' 'abcdefghabcdefgh' '133457799BBCDFF1'
test_des_ecb_key 'double block size string + 1' 'abcdefghabcdefghe' '133457799BBCDFF1'

test_des_ecb_pass 'less than block size string' 'abcdefg' 'dzonda'
test_des_ecb_pass 'block size string' 'abcdefgh' 'carapuce'
test_des_ecb_pass 'block size string + 1' 'abcdefgha' 'pikachu'
test_des_ecb_pass 'double block size string' 'abcdefghabcdefgh' 'markus'
test_des_ecb_pass 'double block size string + 1' 'abcdefghabcdefghe' 'dracaufeu'

test_des_cbc_key 'less than block size string' 'abcdefg' '133457799BBCDFF1'
test_des_cbc_key 'bock size string' 'abcdefgh' '133457799BBCDFF1'
test_des_cbc_key 'block size string + 1' 'abcdefgha' '133457799BBCDFF1'
test_des_cbc_key 'double block size string' 'abcdefghabcdefgh' '133457799BBCDFF1'
test_des_cbc_key 'double block size string + 1' 'abcdefghabcdefghe' '133457799BBCDFF1'

test_des_cbc_pass 'less than block size string' 'abcdefg' 'dzonda'
test_des_cbc_pass 'block size string' 'abcdefgh' 'carapuce'
test_des_cbc_pass 'block size string + 1' 'abcdefgha' 'pikachu'
test_des_cbc_pass 'double block size string' 'abcdefghabcdefgh' 'markus'
test_des_cbc_pass 'double block size string + 1' 'abcdefghabcdefghe' 'dracaufeu'