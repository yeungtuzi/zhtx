#!/bin/ksh
/usr/bin/tar cf - ./user ./login ./room ./cloth ./weapon | /usr/local/bin/gzip > zh2.data.$1.tgz
