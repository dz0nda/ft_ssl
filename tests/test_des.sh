#!/bin/bash

TEST_DES_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

. "$TEST_DES_DIR/tools/checker.sh"

DES_PERSO="./ft_ssl des "
DES_ORIGIN="openssl des-ecb "

test_des_encode_key ()
{
	printf "des -> %s" "$1"
 
  (echo "$2" | eval ${DES_PERSO} -k "$3" -o my_des)
  (echo "$2" | eval ${DES_ORIGIN} -K "$3" -out origin_des)

	test_check my_des origin_des

	rm my_des
	rm origin_des
}

test_des_encode_pass ()
{
	printf "des -> %s" "$1"
 
  (echo "$2" | eval ${DES_PERSO} -p "$3" -s '16F7A4A5146BC9BE' -o my_des)
  (echo "$2" | eval ${DES_ORIGIN} -pass "pass:$3" -S '16F7A4A5146BC9BE' -out origin_des)

	test_check my_des origin_des

	rm my_des
	rm origin_des
}

test_des_encode_key 'des encode key' 'abcdefgh' '133457799BBCDFF1'
test_des_encode_key 'des encode key' 'abcdefghabcdefgh' '133457799BBCDFF1'
test_des_encode_key 'des encode key' 'abcdefghabcdefghe' '133457799BBCDFF1'
test_des_encode_key 'des encode key' 'abcdefgha' '133457799BBCDFF1'

test_des_encode_pass 'des encode pass' 'abcdefgh' 'dzonda'
test_des_encode_pass 'des encode pass' 'abcdefghabcdefgh' 'markus'
test_des_encode_pass 'des encode pass' 'abcdefghabcdefghe' 'dracaufeu'
test_des_encode_pass 'des encode pass' 'abcdefgha' 'pikachu'


# echo ""

# echo "0123456789" | openssl des-ecb -K 7F7432CA7CCE3D61 -S 488843243FBFF7D9
# echo ""
# echo "0123456789" | ./ft_ssl des-ecb -k 7F7432CA7CCE3D61 -s 488843243FBFF7D9
# echo ""
# echo "0123456789" > tmp; ./ft_ssl des-ecb -k 7F7432CA7CCE3D61 -s 488843243FBFF7D9 -i tmp
# echo ""
# echo "0123456789" | ./ft_ssl des-ecb -k 7F7432CA7CCE3D61 -s 488843243FBFF7D9 -o tmp; cat tmp
# echo ""