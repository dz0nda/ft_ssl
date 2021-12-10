#!/bin/bash

TEST_BASE64_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

. "$TEST_BASE64_DIR/base64/test_base64_encode.sh"
. "$TEST_BASE64_DIR/base64/test_base64_decode.sh"

BASE64_PERSO="./ft_ssl base64 "
BASE64_ORIGIN="openssl base64 "

# test_base64_encode 'simple string 0' 'easy'
# test_base64_encode 'simple string 1' 'This test contain 48 bytes so I made it biggerr' 
# test_base64_encode 'simple string 2' 'Hello'
# test_base64_encode 'simple string 3' 'Hello Darkness' 
# test_base64_encode 'simple string 4' 'Hello Darkness my old friend' 
# test_base64_encode_file 'simple file 0' 'easy'
# test_base64_encode_file 'simple file 1' 'This test contain 48 bytes so I made it biggerr' 
# test_base64_encode_file 'simple file 2' 'Hello'
# test_base64_encode_file 'simple file 3' 'Hello Darkness' 
# test_base64_encode_file 'simple file 4' 'Hello Darkness my old friend' 

# test_base64_decode 'simple string 0' 'ZWFzeQo='
# test_base64_decode 'simple string 1' 'VGhpcyB0ZXN0IGNvbnRhaW4gNDggYnl0ZXMgc28gSSBtYWRlIGl0IGJpZ2dlcnIK' 
# test_base64_decode 'simple string 2' 'SGVsbG8K'
# test_base64_decode 'simple string 3' 'SGVsbG8gRGFya25lc3MK' 
# test_base64_decode 'simple string 4' 'SGVsbG8gRGFya25lc3MgbXkgb2xkIGZyaWVuZAo=' 
# test_base64_decode_file 'simple file 0' 'ZWFzeQo='
# test_base64_decode_file 'simple file 1' 'VGhpcyB0ZXN0IGNvbnRhaW4gNDggYnl0ZXMgc28gSSBtYWRlIGl0IGJpZ2dlcnIK' 
# test_base64_decode_file 'simple file 2' 'SGVsbG8K'
# test_base64_decode_file 'simple file 3' 'SGVsbG8gRGFya25lc3MK' 
# test_base64_decode_file 'simple file 4' 'SGVsbG8gRGFya25lc3MgbXkgb2xkIGZyaWVuZAo='

# test_base64_decode 'error string 0' 'U2FsdX'
# test_base64_decode 'error string 1' 'AB#'
# test_base64_decode 'error string 2' 'AB#C'

test_base64_decode_file 'tricky file 0' 'ABCR'
# test_base64_decode 'tricky string 0' 'CCC'
