UNAME := $(shell uname -s)

CXX=g++
CXXFLAGS=-c -pedantic -Wall -Wextra -Wshadow -Wconversion -Wunreachable-code -std=c++17
LDFLAGS=-lm  -lgtest -lpthread

DEBUG ?= 0

ifeq ($(DEBUG),1)
	CXXFLAGS+=-g
	CXXFLAGS+=-DDEBUG
else
	CXXFLAGS+=-Werror
endif

MAINSRC=main.cc
MAINOBJ=$(MAINSRC:.cc=.o)
TESTSRC=tests.cc
TESTOBJ=$(TESTSRC:.cc=.o)
SRC=$(filter-out $(MAINSRC) $(TESTSRC) my_tests/tests_main.cc, model/filereader/filereader.cc)
OBJ=$(SRC:.cc=.o)

LCOVEXEC=$(EXECUTABLE).info
REPORTDIR=report

TESTDIR=test_build
BUILDDIR=build
EXECUTABLE=result_file
ifeq ($(UNAME), Linux)	
TMPEXECUTABLE=3D_Viewer
else ifeq ($(UNAME), Darwin)
TMPEXECUTABLE=3D_Viewer.app/Contents/MacOS/3D_Viewer
endif

DOCUMENTS_DIR=manual
DOCUMENT_FILE=manual
CONTAINER_DIR=3dviewer_2.0

.PHONY: all build install uninstall dvi dist tests gcov_report style leaks clean rebuild

all: build

build:
	mkdir -p $(BUILDDIR)
	cd $(BUILDDIR) && \
	qmake ../ && \
	make
	ln -sf $(BUILDDIR)/$(TMPEXECUTABLE) $(EXECUTABLE)

install: build dvi
	mkdir -p $(CONTAINER_DIR)
	cp $(BUILDDIR)/$(TMPEXECUTABLE) $(CONTAINER_DIR)/$(EXECUTABLE)
	mkdir -p $(CONTAINER_DIR)/view/shaders
	cp view/shaders/* $(CONTAINER_DIR)/view/shaders
	mkdir -p $(CONTAINER_DIR)/$(DOCUMENTS_DIR)
	cp $(DOCUMENT_FILE).pdf $(CONTAINER_DIR)/$(DOCUMENTS_DIR)

uninstall:
	rm -rf $(CONTAINER_DIR)

dvi:
	rubber --pdf $(DOCUMENTS_DIR)/$(DOCUMENT_FILE).tex

dist: install
	rm -rf $(CONTAINER_DIR)/config.bin
	tar -cvf $(CONTAINER_DIR).tar $(CONTAINER_DIR)

tests: LDFLAGS+=-lgtest
tests: $(TESTOBJ) $(OBJ)
	$(CXX) $^ -o $(EXECUTABLE) $(LDFLAGS)
	./$(EXECUTABLE)
	mkdir -p $(TESTDIR)
	cd $(TESTDIR) && qmake ../my_tests/tests.pro && make && ./tests

gcov_report: CXXFLAGS+=--coverage
gcov_report: LDFLAGS+=--coverage
gcov_report: tests
	lcov -t $(EXECUTABLE) -o $(LCOVEXEC) -c -d .
	lcov -r $(LCOVEXEC) "/usr*" -o $(LCOVEXEC)
	genhtml -o $(REPORTDIR) $(LCOVEXEC)

%.o: %.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

style:
	cppcheck --std=c++17 --enable=all --suppress=missingInclude --suppress=unusedFunction -i ./$(BUILDDIR)/ -i ./QtGifImage/ -i ./my_tests/ ./
	python3 ../materials/linters/cpplint.py --extensions=cc,h --recursive --exclude=./$(BUILDDIR)/ --exclude=./QtGifImage/ --exclude=./my_tests/ ./

leaks: tests
	CK_FORK=no valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(EXECUTABLE)

clean:
	rm -rf $(BUILDDIR) $(TESTDIR) $(MAINOBJ) $(TESTOBJ) $(OBJ) $(EXECUTABLE) $(shell find . -name "*.gcno") $(shell find . -name "*.gcda") *.gcov $(LCOVEXEC) $(REPORTDIR) $(DOCUMENT_FILE).* $(CONTAINER_DIR) *.tar

rebuild: clean all
