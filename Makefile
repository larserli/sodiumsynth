
INCLUDE=-Iinclude
INCLUDEDIR=-Iinclude
SOURCEDIR=src
OBJDIR=obj
CC=g++
LD=g++
FLAGS=-std=c++20 -fPIC -O2 -Wall
DEBUGFLAGS=-std=c++20 -fpic -O0 -D _DEBUG -Wall
TARGET=libsodiumsynth.so
TARGET_DEBUG=libsodiumsynthd.so
SOURCES=$(wildcard $(SOURCEDIR)/*.cpp)
OBJS=$(SOURCES:$(SOURCEDIR)/%.cpp=$(OBJDIR)/%.o)

.PHONY:all

clean:
	@rm -rf $(OBJDIR)

objs:

all:$(TARGET) $(TARGET_DEBUG)
	@echo $(SOURCES)
	@echo $(OBJS)

$(OBJS): $(OBJDIR)/%.o: $(SOURCEDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) -c $(INCLUDE) $(FLAGS) $< -o $@

$(TARGET):$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@ -shared

$(TARGET_DEBUG): $(OBJS)
	$(CC) $(DEBUGFLAGS) $(OBJS) -o $@ -shared
