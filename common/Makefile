# ファイル名が「answer.cpp」の場合、
# 以下のようにmakeを実行する。
# $ make PROGRAM=answer
PROGRAM = sample
MYCV = mycv

OBJS = ${PROGRAM}.o ${MYCV}.o

PATH_MYCV = ${MYCV}.cpp

# c++でPython3を使用する際に、以下を有効にする。
# INCLUDES = -I/usr/include/python3.7

LIBS = -lopencv_core -lopencv_imgcodecs -lopencv_highgui
# c++でPython3を使用する際に、上のLIBSを無効にし、以下を有効にする。
# LIBS = -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lpython3.7

.PHONY: all
all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) -o $(PROGRAM) $^ $(LIBS)

.cpp.o:
	$(CXX) $(INCLUDES) -c $< ${PATH_MYCV}

.PHONY: clean
clean:
	$(RM) $(PROGRAM) $(OBJS)
