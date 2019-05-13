#!/bin/sh

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

echo "\n*********************************************"
echo "******   Deletion of last generation   ******"
echo "*********************************************"
rm -rf $DIR/c/mavlink/* $DIR/c++/mavlink/* $DIR/scripts/mavlink.py

echo "\n*********************************************"
echo "******           C generation          ******"
echo "*********************************************"
mavgen.py --lang C -o $DIR/c/mavlink --error-limit 5 --wire-protocol 1.0 $DIR/roadrunner.xml

# Cannot generate C++11 if using MAVLink1.0
# echo "\n*********************************************"
# echo "******         C++11 generation        ******"
# echo "*********************************************"
# mavgen.py --lang C++11 -o $DIR/c++/mavlink --error-limit 5 --wire-protocol 1.0 $DIR/roadrunner.xml

echo "\n*********************************************"
echo "******        Python generation        ******"
echo "*********************************************"
mavgen.py --lang Python -o $DIR/scripts/mavlink --error-limit 5 --wire-protocol 1.0 $DIR/roadrunner.xml

sed -i 's/from ...generator.mavcrc import x25crc/from mavcrc import x25crc/g' $DIR/scripts/mavlink.py
