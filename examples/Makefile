CC  = g++ -std=c++0x -g
#OPT = -Werror -O3
OPT = -Werror
EX  = abi constants context dataflow functions hello linker fncall_label

all: $(EX)

abi: abi.cc
	$(CC) $(OPT) abi.cc -I../ ../lib/libx64asm.a -o abi

constants: constants.cc
	$(CC) $(OPT) constants.cc -I../ ../lib/libx64asm.a -o constants

context: context.cc
	$(CC) $(OPT) context.cc -I../ ../lib/libx64asm.a -o context

dataflow: dataflow.cc
	$(CC) $(OPT) dataflow.cc -I../ ../lib/libx64asm.a -o dataflow

functions: functions.cc
	$(CC) $(OPT) functions.cc -I../ ../lib/libx64asm.a -o functions

hello: hello.cc
	$(CC) $(OPT) hello.cc -I../ ../lib/libx64asm.a -o hello

linker: linker.cc
	$(CC) $(OPT) linker.cc -I../ ../lib/libx64asm.a -o linker

fncall_label : fncall_label.cc
	$(CC) $(OPT) fncall_label.cc -I../ ../lib/libx64asm.a -o fncall_label

clean:
	rm -f $(EX)
