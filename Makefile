all: test
.PHONY: all

.PHONY: clean fclean re
clean fclean re:
	cd src && $(MAKE) $@

.PHONY: dev
dev: compile_commands.json

.PHONY: compile_commands.json
compile_commands.json:
	find src -name "*.c" | xargs -L 1 -I {} clang -Wall -Wextra -Werror -std=c99 -pedantic -c "{}" -o "{}.o" -MJ "{}.part.json"
	(echo "[" && find src -name "*.part.json" | xargs cat && echo "]") > $@
	$(MAKE) clean_dev

.PHONY: clean_dev
clean_dev:
	find . -name "*.part.json" -delete

.PHONY: fclean_dev
fclean_dev:
	rm -f compile_commands.json
