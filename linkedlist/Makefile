all:main
BUILD_DIR = build
SOURCE_DIR = src
TEST_DIR = test
INCLUDE_DIR = include
CFLAGS = -g -Isrc -Itest -Iinclude -Wall -Wextra -Wpedantic -Wunreachable-code -Wunreachable-code-loop-increment -Wunreachable-code-return

main:$(TEST_DIR)/test.o $(BUILD_DIR)/linkedlist.o $(INCLUDE_DIR)/node.h $(INCLUDE_DIR)/linkedlist.h
	clang++ $(CFLAGS) $(TEST_DIR)/test.cpp -o $(TEST_DIR)/main -lgtest_main -lgtest -lpthread
$(TEST_DIR)/test.o:$(TEST_DIR)/test.cpp $(SOURCE_DIR)/linkedlist.cpp  $(INCLUDE_DIR)/node.h $(INCLUDE_DIR)/linkedlist.h
	clang++ -c $(CFLAGS)  $(TEST_DIR)/test.cpp -o $(TEST_DIR)/test.o 
$(BUILD_DIR)/linkedlist.o:$(SOURCE_DIR)/linkedlist.cpp  $(INCLUDE_DIR)/node.h $(INCLUDE_DIR)/linkedlist.h
	clang++ -c $(CFLAGS) $(SOURCE_DIR)/linkedlist.cpp -o $(BUILD_DIR)/list.o
test:$(BUILD_DIR)/linkedlist.o  $(TEST_DIR)/test.o
	./$(TEST_DIR)/main

clean:
	rm $(BUILD_DIR)/*.o  $(TEST_DIR)/*.o $(TEST_DIR)/main

.PHONY: all clean test