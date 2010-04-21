CC = gcc
FLAG = -g -Wall

SRC = \
hello.c \
array.c\
binary_search.c\
check_value.c\
define.c\
enum.c\
environ.c\
funcPtr.c\
funcPtr2.c\
gameStructure.c\
int_test.c\
malloc_test.c\
memcpy_test.c\
memcpy_test2.c\
null_check.c\
print_tab.c\
ptr-increment.c\
read_file.c\
read_file2.c\
read_file3.c\
select.c\
shift.c\
string.c\
test.c\
test_struct.c\
test_struct2.c\
callback_func.c\
calloc_test.c\
calloc_struct_array.c\
test_mem_pool.c\

TARGET=${SRC:.c=}
DSYM=${SRC:.c=.dSYM}

all:$(TARGET)
hello:hello.c
	$(CC) $(FLAG) -o $@ $^

select:select.c
	$(CC) $(FLAG) -o $@ $^

array:array.c
	$(CC) $(FLAG) -o $@ $^

binary_search:binary_search.c
	$(CC) $(FLAG) -o $@ $^

check_value:check_value.c
	$(CC) $(FLAG) -o $@ $^

define:define.c
	$(CC) $(FLAG) -o $@ $^

enum:enum.c
	$(CC) $(FLAG) -o $@ $^

environ:environ.c
	$(CC) $(FLAG) -o $@ $^

funcPtr:funcPtr.c
	$(CC) $(FLAG) -o $@ $^

funcPtr2:funcPtr2.c
	$(CC) $(FLAG) -o $@ $^

int_test:int_test.c
	$(CC) $(FLAG) -o $@ $^

malloc_test:malloc_test.c
	$(CC) $(FLAG) -o $@ $^

memcpy_test:memcpy_test.c
	$(CC) $(FLAG) -o $@ $^

memcpy_test2:memcpy_test2.c
	$(CC) $(FLAG) -o $@ $^

null_check:null_check.c
	$(CC) $(FLAG) -o $@ $^

print_tab:print_tab.c
	$(CC) $(FLAG) -o $@ $^

ptr-increment:ptr-increment.c
	$(CC) $(FLAG) -o $@ $^

read_file:read_file.c
	$(CC) $(FLAG) -o $@ $^

read_file2:read_file2.c
	$(CC) $(FLAG) -o $@ $^

read_file3:read_file3.c
	$(CC) $(FLAG) -o $@ $^

shift:shift.c
	$(CC) $(FLAG) -o $@ $^

string:string.c
	$(CC) $(FLAG) -o $@ $^

test:test.c
	$(CC) $(FLAG) -o $@ $^

test_struct:test_struct.c
	$(CC) $(FLAG) -o $@ $^

test_struct2:test_struct2.c
	$(CC) $(FLAG) -o $@ $^

callback_func:callback_func.c
	$(CC) $(FLAG) -o $@ $^

calloc_test:calloc_test.c
	$(CC) $(FLAG) -o $@ $^

calloc_struct_array:calloc_struct_array.c
	$(CC) $(FLAG) -o $@ $^

test_mem_pool:test_mem_pool.c
	$(CC) $(FLAG) -o $@ $^

tags:
	etags *.[ch]

clean:
	$(RM) *~
	$(RM) TAGS
	$(RM) $(TARGET)
clean-dsym:
	-rm -rf $(DSYM)