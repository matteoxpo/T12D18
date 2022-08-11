.PHONY: print_module documentation_module bst_create_test bst_insert_test bst_traverse_test
CC =gcc
CFLAGS = -Wall -Werror -Wextra -c
QFLAG = -D QUEST
Q1_SOURCES = print_module.c main_module_entry_point.c
Q1_OBJECTS = $(Q1_SOURCES:.c=.o)

Q2_SOURCES = documentation_module.c main_module_entry_point.c
Q2_OBJECTS = $(Q2_SOURCES:.c=.o)

Q3_SOURCES = bst.c bst_create_test.c
Q3_OBJECTS = $(Q3_SOURCES:.c=.o)

Q4_SOURCES = $(Q3_SOURCES)
Q4_OBJECTS = $(Q3_OBJECTS)

Q5_SOURCES = $(Q3_SOURCES)
Q5_OBJECTS = $(Q3_OBJECTS)

OBJECTS = $(Q3_OBJECTS) $(Q2_OBJECTS) 

EXECUTABLE = main
BQUEST = ../Build/Quest_
QUEST = Quest_
QUESTS = $(QUEST)1 $(QUEST)2 $(QUEST)3 $(QUEST)4 $(QUEST)5
BQUESTS = $(BQUEST)1 $(BQUEST)2 $(BQUEST)3 $(BQUEST)4 $(BQUEST)5

print_module: $(Q1_OBJECTS)
	# $(CC) $(Q1_OBJECTS) -o $(QUEST)1
	$(CC) $(Q1_OBJECTS) -o $(BQUEST)1
	-rm *.o

documentation_module: $(Q2_OBJECTS)
	# $(CC) $(Q2_OBJECTS) -o $(QUEST)2
	$(CC) $(Q2_OBJECTS) -o $(BQUEST)2
	-rm *.o

bst_create_test: $(Q3_OBJECTS)
	# $(CC) $(Q3_OBJECTS) -o $(QUEST)3
	$(CC) $(Q3_OBJECTS) -o $(BQUEST)3
	-rm *.o

bst_insert_test: $(Q4_OBJECTS)
	# $(CC) $(Q4_OBJECTS) -o $(QUEST)4
	$(CC) $(Q4_OBJECTS) -o $(BQUEST)4
	-rm *.o

bst_traverse_test: $(Q5_OBJECTS)
	# $(CC) $(Q5_OBJECTS) -o $(QUEST)5
	$(CC) $(Q5_OBJECTS) -o $(BQUEST)5
	-rm *.o

$(Q1_OBJECTS):
	$(CC) $(QFLAG)1 $(CFLAGS) -c print_module.c -o print_module.o
	$(CC) $(QFLAG)1 $(CFLAGS) -c main_module_entry_point.c -o main_module_entry_point.o

$(Q2_OBJECTS):
	$(CC) $(QFLAG)2 $(CFLAGS) -c documentation_module.c -o documentation_module.o
	$(CC) $(QFLAG)2 $(CFLAGS) -c main_module_entry_point.c -o main_module_entry_point.o

$(Q3_OBJECTS):
	$(CC) $(QFLAG)3 $(CFLAGS) -c bst.c  -o bst.o
	$(CC) $(QFLAG)3 $(CFLAGS) -c bst_create_test.c -o bst_create_test.o

$(Q4_OBJECTS):
	$(CC) $(QFLAG)4 $(CFLAGS) -c bst.c  -o bst.o
	$(CC) $(QFLAG)4 $(CFLAGS) -c bst_create_test.c -o bst_create_test.o

$(Q5_OBJECTS):
	$(CC) $(QFLAG)5 $(CFLAGS) -c bst.c  -o bst.o
	$(CC) $(QFLAG)5 $(CFLAGS) -c bst_create_test.c -o bst_create_test.o

clean:
	-rm *.o
