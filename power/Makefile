CC = gcc
CFLAGS = -Wall -Werror -std=c99

SRCS = energy_monitor.c power_nodes.c sleep.c
OBJS = $(SRCS:.c=.o)
LIB = libpower.a

all: $(LIB)

$(LIB): $(OBJS)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIB)

.PHONY: all clean
