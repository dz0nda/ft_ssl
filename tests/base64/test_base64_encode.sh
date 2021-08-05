#!/bin/bash

TEST_BASE64_ENCODE_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
. "$TEST_BASE64_ENCODE_DIR/../tools/checker.sh"

test_base64_encode ()
{
	printf "base64 -> %s" "$1"
 
  (echo "$2" | eval ${BASE64_PERSO}) > my_base64
  (echo "$2" | eval ${BASE64_ORIGIN}) > origin_base64

	test_check my_base64 origin_base64

	rm my_base64
	rm origin_base64
}

test_base64_encode_file ()
{
	printf "base64 -> %s" "$1"
 
	echo "$2" > tmp

	eval ${BASE64_PERSO} -i tmp -o my_base64
	eval ${BASE64_ORIGIN} -in tmp -out origin_base64

	test_check my_base64 origin_base64

	rm tmp
	rm my_base64
	rm origin_base64
}