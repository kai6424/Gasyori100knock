# ファイル名が「answer.cpp」の場合、
# 以下のようにmakeを実行する。
# $ make PROGRAM=answer
PROGRAM = sample
OBJS = ${PROGRAM}.o

# c++でPython3を使用する際に、以下を有効にする。
INCLUDES = -I/usr/include/python3.8

# c++でPython3を使用する際に、上のLIBSを無効にし、下のLIBSを有効にする。
# LIBS = -lopencv_core -lopencv_imgcodecs -lopencv_highgui
LIBS = -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lpython3.8

.PHONY: all
all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) -o $(PROGRAM) $^ $(LIBS)

.cpp.o:
	$(CXX) $(INCLUDES) -c $<

.PHONY: clean
clean:
	$(RM) $(PROGRAM) $(OBJS)
