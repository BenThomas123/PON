CC = gcc
CFLAGS = -Wall -Werror -std=c99

SRCS = authentication.c encryption.c key_store.c secure_boot.c tls.c
OBJS = $(SRCS:.c=.o)
LIB = libsecurity.a

all: $(LIB)

$(LIB): $(OBJS)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIB)

.PHONY: all clean
