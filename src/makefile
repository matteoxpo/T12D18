.PHONY: print_module documentation_module bst_create_test
CC =gcc
CFLAGS = -Wall -Werror -Wextra -c
QFLAG = -D QUEST
Q1_SOURCES = print_module.c main_module_entry_point.c
Q1_OBJECTS = $(Q1_SOURCES:.c=.o)

Q2_SOURCES = documentation_module.c main_module_entry_point.c
Q2_OBJECTS = $(Q2_SOURCES:.c=.o)

Q3_SOURCES = bst.c main_module_entry_point.c
Q3_OBJECTS = $(Q3_SOURCES:.c=.o)

EXECUTABLE = main
BQUEST = ../Build/Quest_
QUEST = Quest_
QUESTS = $(BQUEST)1 $(BQUEST)2 $(BQUEST)3
all: print_module documentation_module

print_module: clean $(Q1_OBJECTS)
	$(CC) $(Q1_OBJECTS) -o $(QUEST)1
	$(CC) $(Q1_OBJECTS) -o $(BQUEST)1

documentation_module: clean $(Q2_OBJECTS)
	$(CC) $(Q2_OBJECTS) -o $(QUEST)2
	$(CC) $(Q2_OBJECTS) -o $(BQUEST)2

bst_create_test: 

$(Q1_OBJECTS):
	$(CC) $(QFLAG)1 $(CFLAGS) -c print_module.c -o print_module.o
	$(CC) $(QFLAG)1 $(CFLAGS) -c main_module_entry_point.c -o main_module_entry_point.o

$(Q2_OBJECTS):
	$(CC) $(QFLAG)2 $(CFLAGS) -c documentation_module.c -o documentation_module.o
	$(CC) $(QFLAG)2 $(CFLAGS) -c main_module_entry_point.c -o main_module_entry_point.o

clean:
	# -rm $(EXECUTABLE)
	# -rm $(Q1_OBJECTS) $(Q2_OBJECTS) $(Q3_OBJECTS)
	# -rm $(QUESTS)
	-rm *.o
