all: test
fclean: clean
re:
	$(MAKE) fclean
	$(MAKE) all

test: test_get_next_line_string_util_strlen.exe test_get_next_line_string_util_nl_pos.exe test_get_next_line_string_util_ln_len.exe test_get_next_line_string_util_copy_0.exe test_get_next_line_string_util_copy_nl.exe test_get_next_line_string_alloc_util_concat.exe test_get_next_line_string_alloc_util_before_newline.exe test_get_next_line_string_alloc_util_after_newline.exe test_get_next_line_string_alloc_util_strdup.exe
	find . -name "test_*.exe" -depth 1 -type f | xargs -L 1 sh -c
clean:
	find . -name "test_*.exe" -depth 1 -type f -delete
test_%.exe: %.c ../src/get_next_line.c ../src/get_next_line_utils.c
	$(CC) -Wall -Wextra -Werror -g -fsanitize=address -o $@ $^
