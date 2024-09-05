JAVAC = javac
JAVA = java

CLIENT_SRC = Client.java
DISPLAY_SRC = Display.java

CLIENT_CLASS = Client.class
DISPLAY_CLASS = Display.class

all: $(CLIENT_CLASS) $(DISPLAY_CLASS)

$(CLIENT_CLASS): $(CLIENT_SRC)
	$(JAVAC) $(CLIENT_SRC)

$(DISPLAY_CLASS): $(DISPLAY_SRC)
	$(JAVAC) $(DISPLAY_SRC)

run: all
	$(JAVA) Client

clean:
	rm -f *.class

.PHONY: all run clean
