CC = gcc
CFLAGS = -Wall -Werror -std=c99

SRCS = math.c stdio.c stdlib.c string.c
OBJS = $(SRCS:.c=.o)
LIB = libmylib.a

all: $(LIB)

$(LIB): $(OBJS)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIB)
