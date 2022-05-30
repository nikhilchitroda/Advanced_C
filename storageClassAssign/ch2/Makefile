ROOT_DIR = /home/chitroda/Desktop/UdemyTrain/Practise/Advanced_C/storageClassAssign/ch2
ROOT_NAME = main

ROOT_FILE = $(ROOT_DIR)/$(ROOT_NAME).c
ROOT_OBJ = $(ROOT_DIR)/$(ROOT_NAME).o
ROOT_BIN = $(ROOT_DIR)/$(ROOT_NAME)

#default make will start to build from first mentioned target.
$(ROOT_BIN): $(ROOT_FILE)
	gcc $< -o $@

clean:
	rm -rf $(ROOT_OBJ) $(ROOT_BIN)
