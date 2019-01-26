CFLAGS := $(shell pkg-config lua --cflags)
CFLAGS += -fPIC -fmax-errors=1 -Isrc
LDLIBS := $(shell pkg-config lua --libs)
LDLIBS += -lringnoise

LUA_VERSION	:= $(shell lua -e "_,_,v=string.find(_VERSION,'Lua (.+)');print(v)")
ifeq ($(LUA_VERSION),)
	LUA_VERSION := 5.3
endif
LUA_LIBDIR := /usr/lib/lua/$(LUA_VERSION)

SOURCES=$(wildcard src/*.c)
OBJECTS=$(patsubst %.c, %.o, $(SOURCES))
OUTFILE=ringnoise.so

$(OUTFILE): $(OBJECTS)
	gcc -shared -o $(OUTFILE) $(OBJECTS) $(LDLIBS)

$(OBJECTS): src/%.o: src/%.c
	gcc $(CFLAGS) -c $< -o $@

install:
	mkdir -p $(LUA_LIBDIR)
	cp $(OUTFILE) $(LUA_LIBDIR)

uninstall:
	rm -f $(LUA_LIBDIR)/$(OUTFILE)

clean:
	rm -f $(OUTFILE) src/*.o
