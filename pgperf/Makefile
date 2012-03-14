# Copyright (C) 1989 Free Software Foundation, Inc.
# written by Douglas C. Schmidt (schmidt@ics.uci.edu)
# 
# This file is part of GNU GPERF.
# 
# GNU GPERF is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 1, or (at your option)
# any later version.
# 
# GNU GPERF is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with GNU GPERF; see the file COPYING.  If not, write to
# the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. 

CC = gcc
DFLAGS= -DLO_CAL -DGATHER_STATISTICS #-DRLIMIT_STACK 
OFLAGS= -O -g
CFLAGS= $(DFLAGS) $(OFLAGS)
OBJS = options.o iterator.o main.o perfect.o keylist.o listnode.o xmalloc.o \
       hashtable.o boolarray.o readline.o stderr.o version.o getopt.o
SOURCES = options.c iterator.c main.c perfect.c keylist.c listnode.c xmalloc.c \
       hashtable.c boolarray.c readline.c stderr.c version.c getopt.c

all: gperf

gperf: $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

clean: 
	-rm -f *.o core *~ #*#

realclean: clean
	-rm -f gperf

Makefile.d:
	gcc -MM $(SOURCES) -o $@
-include Makefile.d