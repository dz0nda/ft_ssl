#!/bin/bash

TEST_DES_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

. "$TEST_DES_DIR/des/test_des_cbc.sh"
. "$TEST_DES_DIR/des/test_des_ecb.sh"

# DES_ECB_PERSO="./ft_ssl des "
# DES_ECB_ORIGIN="openssl des-ecb "

# DES_CBC_PERSO="./ft_ssl des-cbc "
# DES_CBC_ORIGIN="openssl des-cbc "

# test_des_ecb_key ()
# {
# 	printf "des-ecb key -> %s" "$1"
 
# 	echo -n "$2" > plaintext

#   eval ${DES_ECB_PERSO} -k "$3" -i plaintext -o my_des
#   eval ${DES_ECB_ORIGIN} -K "$3" -in plaintext -out origin_des

# 	test_check my_des origin_des

#   eval ${DES_ECB_PERSO} -d -k "$3" -i my_des -o my_plaintext
#   eval ${DES_ECB_ORIGIN} -d -K "$3" -in origin_des -out origin_plaintext

# 	test_check my_plaintext origin_plaintext

# 	rm plaintext
# 	rm my_des
# 	rm origin_des
# 	rm my_plaintext
# 	rm origin_plaintext
# }

# test_des_cbc_key ()
# {
# 	printf "des-cbc key -> %s" "$1"
 
# 	echo -n "$2" > plaintext

#   eval ${DES_CBC_PERSO} -k "$3" -v "$3" -i plaintext -o my_des
#   eval ${DES_CBC_ORIGIN} -K "$3" -iv "$3" -in plaintext -out origin_des

# 	test_check my_des origin_des

#   eval ${DES_CBC_PERSO} -d -k "$3" -v "$3" -i my_des -o my_plaintext
#   eval ${DES_CBC_ORIGIN} -d -K "$3" -iv "$3" -in origin_des -out origin_plaintext

# 	test_check my_plaintext origin_plaintext

# 	rm plaintext
# 	rm my_des
# 	rm origin_des
# 	rm my_plaintext
# 	rm origin_plaintext
# }

# test_des_ecb_pass ()
# {
# 	printf "des-ecb pass -> %s" "$1"
 
# 	echo -n "$2" > plaintext

#   eval ${DES_ECB_PERSO} -p "$3" -s '16F7A4A5146BC9BE' -i plaintext -o my_des
#   eval ${DES_ECB_ORIGIN} -md md5 -pass "pass:$3" -S '16F7A4A5146BC9BE' -in plaintext -out origin_des

# 	test_check my_des origin_des

#   eval ${DES_ECB_PERSO} -d -p "$3" -s '16F7A4A5146BC9BE' -i my_des -o my_plaintext
#   eval ${DES_ECB_ORIGIN} -d -md md5 -pass "pass:$3" -S '16F7A4A5146BC9BE' -in origin_des -out origin_plaintext

# 	test_check my_plaintext origin_plaintext

# 	rm plaintext
# 	rm my_des
# 	rm origin_des
# 	rm my_plaintext
# 	rm origin_plaintext
# }

# test_des_cbc_pass ()
# {
# 	printf "des-cbc pass -> %s" "$1"
 
# 	echo -n "$2" > plaintext

#   eval ${DES_CBC_PERSO} -p "$3" -s '16F7A4A5146BC9BE' -i plaintext -o my_des
#   eval ${DES_CBC_ORIGIN} -md md5 -pass "pass:$3" -S '16F7A4A5146BC9BE' -in plaintext -out origin_des

# 	test_check my_des origin_des

#   eval ${DES_CBC_PERSO} -d -p "$3" -s '16F7A4A5146BC9BE' -i my_des -o my_plaintext
#   eval ${DES_CBC_ORIGIN} -d -md md5 -pass "pass:$3" -S '16F7A4A5146BC9BE' -in origin_des -out origin_plaintext

# 	test_check my_plaintext origin_plaintext

# 	rm plaintext
# 	rm my_des
# 	rm origin_des
# 	rm my_plaintext
# 	rm origin_plaintext
# }

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