NAME = libmx.a

SRC_DIR = src

OBJ_DIR = obj

INC_DIR = inc

# makes list of all files in dir src with .c expansion
# each record has the following format: src/<filename>.c
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# added prefix obj/ to all the records from SRC_FILES
# changed expansion from .c to .o
# result from src/<filename>.c to obj/<filename>.o
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:%.c=%.o)))

# makes list of all files in dir src with .h expansion
# each record has the following format: inc/<filename>.h
INC_FILES = $(wildcard $(INC_DIR)/*.h)

CC = clang

# add prefix -W to all the records
# -g - generates complete debug info
C_FLAGS = -std=c11 $(addprefix -W, all error extra pedantic) -g

# archive to make libtary
AR = ar

# flags for archive
AR_FLAGS = rcs

MKDIR = mkdir -p
RM = rm -rf

all: $(NAME)

print:
	@printf "$(OBJ_FILES)"
	@printf "\n\n"
	@printf "$(SRC_FILES)"

# aim depends on o-files creation time
# $@ - the file name of the target of the rule.
# if the target is an archive member, then $@ is the name of the archive file
# $^ - names of all the prerequisites, with spaces between them.
# a target has only one prerequisite on each other file it depends on,
# the value of $^ contains just one copy of the name
$(NAME): $(OBJ_FILES)
	@$(AR) $(AR_FLAGS) $@ $^
	@printf "\r\33[2K$@\t\033[32;1mcreated\033[0m\n"

# create a directory obj before o-files compilation (order-only prerequisite)
$(OBJ_FILES): | $(OBJ_DIR)

# compare final modification time  of each o-file
# with c-file and h-file to recompile only renewed ones
# in case of h-file all the files will be recompiled
# $< variable - The name of the first prerequisite
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@$(CC) $(C_FLAGS) -c $< -o $@ -I $(INC_DIR)
	@printf "\r\33[2K$(NAME)\033[33;1m\t compile \033[0m$(<:$(SRC_DIR)/%.c = %)\r"

# create obj directory
$(OBJ_DIR):
	@$(MKDIR) $@

#remove directory with o-files
clean:
	@$(RM) $(OBJ_DIR)
	@printf "$(OBJ_DIR) in $(NAME)\t \033[31;1mdeleted\033[0m\n"

# remove the result of makefile work
uninstall:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@printf "$(NAME)\t \033[31;1muninstalled\033[0m\n"

# delete and remake library
reinstall: uninstall all

# .PHONY is a clear point to the names of targets
# There are two reasons to use a phony target:
# to avoid a conflict with a file of the same name,
# and to improve performance
.PHONY: all uninstall clean reinstall
