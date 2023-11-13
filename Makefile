CC = gcc
CFLAGS = -Wall -Werror

SRCDIR = src
OBJDIR = obj

SRC := $(wildcard $(SRCDIR)/**/*.c $(SRCDIR)/*.c)
OBJ := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

TARGET = chess-engine

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(@D)
	$(CC) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
