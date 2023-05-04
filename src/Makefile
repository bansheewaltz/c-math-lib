CONFIG ?= debug
### many variables are stored in a shared makefile
include Makefile.common
include Makefile.misc
# build parameters
ifeq ($(CONFIG), debug)
	DBGFLAGS := -g
	CFLAGS := $(DBGFLAGS) $(WFLAGS) $(STDFLAG) $(INCFLAGS)
endif
ifeq ($(CONFIG), release)
	CFLAGS := -O3 $(INCFLAGS)
endif
ifeq ($(OS), Alpine)
	CFLAGS := $(DBGFLAGS) $(INCFLAGS)
endif
CFLAGS ?= $(DBGFLAGS) $(WFLAGS) $(STDFLAG) $(INCFLAGS)
# Makefile search paths
vpath %.c $(SRC) $(UTL)
vpath lib%.a $(LIB)
export


.PHONY: all
all:
ifeq ($(OS), )
	$(warning warning: it looks like this Makefile is not fully adapted to your OS)
endif
	$(MAKE) lib
ifneq ($(shell pkg-config --libs check 2> /dev/null), )
	$(MAKE) test
ifneq ($(shell which gcovr 2> /dev/null), )
	$(MAKE) gcov_report
endif
ifneq ($(shell which valgrind), )
	$(MAKE) memcheck
endif
endif

s21_math.a: $(OBJS)
	ar -rsc $@ $^
	cp $(INC)/$(LIBNAME).h .

$(OBJ)/%.o: %.c $(HDRS) | $(OBJ)
	$(CC) -c $(CFLAGS) -o $@ $<
# directory
$(OBJ):
	@$(MK) $@

.PHONY: test ftest gcov_report
ftest: fclean test
test gcov_report: lib
	@$(MAKE) -s -f Makefile.unit_testing $@

.PHONY: clean
clean:
	$(RM) $(BUILD)

.PHONY: fclean# full clean
fclean: clean
	$(RM) $(REPORTS)
	$(RM) $(LIBNAME).a
	$(RM) $(LIBNAME).h

.PHONY: tclean# temp files clean
tclean:
	$(RM) *.out*
	$(RM) temp.c

.PHONY: re
re: fclean
	$(MAKE) all


# helper targets
.PHONY: check
check:
	command -v 

.PHONY: prep
prep:
ifeq ($(KERNEL), Linux)
	sudo apt install -y pkg-config check gcovr
endif
ifeq ($(KERNEL), Darwin)
	yes | brew install pkg-config check gcovr
endif

.PHONY: lib
lib: libs21_math.a
libs21_math.a: s21_math.a
	$(MK) $(LIB)
	cp $< $(LIB)/$@

.PHONY: memcheck
memcheck: lib
ifeq (, $(shell which valgrind))
	$(error "valgrind" should be installed)
endif
	@$(MAKE) -s -f Makefile.memcheck $@

.PHONY: asan
asan: lib
ifeq ($(ARCHITECTURE), arm64)
	$(error adress sanitizers work only on x64 at the time)
endif
	@$(MAKE) -s -f Makefile.asan $@

.PHONY: linter linter_check
linter_check: LINTFLAG := -n
linter linter_check:
	$(LINT) $(LINTFLAG) $(shell find . -type f -name '*.h' -o -name '*.c')

.PHONY: tidy
tidy:
	clang-tidy $(shell find . -type f -name '*.c') -- -Ilib/headers -Iinclude

.PHONY: miniverter
miniverter: fclean
	cd $(SCRIPTS) && bash run_miniverter_test.sh

.PHONY: container
container:
ifeq (, $(shell which docker))
	$(error "docker" should be installed)
endif
	$(MAKE) clean_build
	bash $(SCRIPTS)/run_docker_image.sh

.PHONY: brew
brew:
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
