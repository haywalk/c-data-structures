# makefile for linked list test
# 2023-02-11

CC = gcc
CFLAGS = -std=c89


all : list.c arrstack.c
	$(CC) $(CFLAGS) -o list list.c
	$(CC) $(CFLAGS) -o arrstack arrstack.c

clean :
	rm list