TARGET=bin

mkdir ${TARGET}
cd ${TARGET}
cmake -G "Eclipse CDT4 - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_ECLIPSE_MAKE_ARGUMENTS="-j8 -std=c++11" ../src/
