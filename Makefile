###############################################################################
###               University of Hawaii, College of Engineering
###               Lab 3 - wc - SRE - Spring 2023
###
### Build and test a Word Counting program
###
### @see     https://www.gnu.org/software/make/manual/make.html
###
### @file    Makefile
### @author  Vinton Sistoza <sistozav@hawaii.edu>
###############################################################################


TARGET = wc

all: $(TARGET)

CC     = gcc
CFLAGS = -Wall -Wextra $(DEBUG_FLAGS)

debug: DEBUG_FLAGS = -g -DDEBUG
debug: clean $(TARGET)

wc: wc.c
	$(CC) $(CFLAGS) -o $(TARGET) wc.c

test: wc
	./wc /etc/passwd

clean:
	rm -f $(TARGET) *.o
