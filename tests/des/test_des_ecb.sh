#!/bin/bash

TEST_DES_ECB_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
. "$TEST_DES_ECB_DIR/../tools/checker.sh"

DES_ECB_PERSO="./ft_ssl des "
DES_ECB_ORIGIN="openssl des-ecb "

test_des_ecb_key ()
{
	printf "des-ecb key -> %s" "$1"
 
	echo -n "$2" > plaintext

  eval ${DES_ECB_PERSO} -k "$3" -i plaintext -o my_des
  eval ${DES_ECB_ORIGIN} -K "$3" -in plaintext -out origin_des

	test_check my_des origin_des

  eval ${DES_ECB_PERSO} -d -k "$3" -i my_des -o my_plaintext
  eval ${DES_ECB_ORIGIN} -d -K "$3" -in origin_des -out origin_plaintext

	test_check my_plaintext origin_plaintext

	rm plaintext
	rm my_des
	rm origin_des
	rm my_plaintext
	rm origin_plaintext
}

test_des_ecb_pass ()
{
	printf "des-ecb pass -> %s" "$1"
 
	echo -n "$2" > plaintext

  eval ${DES_ECB_PERSO} -p "$3" -s '16F7A4A5146BC9BE' -i plaintext -o my_des
  eval ${DES_ECB_ORIGIN} -md md5 -pass "pass:$3" -S '16F7A4A5146BC9BE' -in plaintext -out origin_des

	test_check my_des origin_des

  eval ${DES_ECB_PERSO} -d -p "$3" -s '16F7A4A5146BC9BE' -i my_des -o my_plaintext
  eval ${DES_ECB_ORIGIN} -d -md md5 -pass "pass:$3" -S '16F7A4A5146BC9BE' -in origin_des -out origin_plaintext

	test_check my_plaintext origin_plaintext

	rm plaintext
	rm my_des
	rm origin_des
	rm my_plaintext
	rm origin_plaintext
}