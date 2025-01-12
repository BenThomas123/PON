CC = gcc
CFLAGS = -Wall -Werror -std=c99

SRCS = driver_tests.c kernel_tests.c memory_tests.c network_test.c scheduler_tests.c
OBJS = $(SRCS:.c=.o)
TARGETS = driver_tests kernel_tests memory_tests network_test scheduler_tests

all: $(TARGETS)

driver_tests: driver_tests.o
	$(CC) $^ -o $@

kernel_tests: kernel_tests.o
	$(CC) $^ -o $@

memory_tests: memory_tests.o
	$(CC) $^ -o $@

network_test: network_test.o
	$(CC) $^ -o $@

scheduler_tests: scheduler_tests.o
	$(CC) $^ -o $@

clean:
	rm -f $(OBJS) $(TARGETS)

.PHONY: all clean
