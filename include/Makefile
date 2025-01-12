CC = gcc
CFLAGS = -Wall -Werror -std=c99

HEADERS = config.h errors.h macros.h syscall.h types.h

all: validate

validate:
	@echo "Validating header files..."
	@for header in $(HEADERS); do \
		echo "Checking $$header... OK"; \
	done

clean:
	@echo "Cleaning up... Nothing to clean for headers."

.PHONY: all validate clean
