#! /bin/sh

exec `dirname $0`/configure "$@" --disable-cpp --enable-utf8 --enable-unicode-properties --disable-shared CFLAGS="-O2 -g"
