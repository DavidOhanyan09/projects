all:main
BUILD_DIR = build
TEST_DIR = test
INCLUDE_DIR = include
CFLAGS = -g -Isrc -Itest -Iinclude -Wall -Wextra -Wpedantic -Wunreachable-code -Wunreachable-code-loop-increment -Wunreachable-code-return

main:$(BUILD_DIR)/test.o  $(INCLUDE_DIR)/linkedlist.h
	clang++ $(CFLAGS) $(TEST_DIR)/test.cpp  -o $(TEST_DIR)/main -lgtest_main -lgtest -lpthread
$(BUILD_DIR)/test.o:$(TEST_DIR)/test.cpp $(INCLUDE_DIR)/linkedlist.h
	clang++ -c $(CFLAGS)  $(TEST_DIR)/test.cpp -o $(BUILD_DIR)/test.o 
test:$(BUILD_DIR)/test.o
	./$(TEST_DIR)/main

clean:
	rm $(BUILD_DIR)/*.o  $(TEST_DIR)/main

.PHONY: all clean test