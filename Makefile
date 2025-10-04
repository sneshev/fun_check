NAME := fnchk

SRCS := $(wildcard src/*.c)

OBJDIR := obj
OBJS := $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

CC := cc
CFLAGS := -Wall -Werror -Wextra -g 

RM := rm -f 

all: $(NAME) $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJDIR)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re