ROOT_DIR = /home/chitroda/Desktop/UdemyTrain/Practise/Advanced_C/storageClass/externType
ROOT_NAME = main
SRC_NAME = add

ROOT_FILE = $(ROOT_DIR)/$(ROOT_NAME).c
SRC_FILE = $(ROOT_DIR)/$(SRC_NAME).c
ROOT_OBJ = $(ROOT_DIR)/$(ROOT_NAME).o
SRC_OBJ = $(ROOT_DIR)/$(SRC_NAME).o
STATIC_LIB = $(ROOT_DIR)/lib$(SRC_NAME).a
ROOT_BIN = $(ROOT_DIR)/$(ROOT_NAME)

target:	$(ROOT_OBJ) $(SRC_OBJ)
	gcc $(ROOT_OBJ) -o $(ROOT_BIN) -L. $(STATIC_LIB)

$(ROOT_OBJ): $(ROOT_FILE)
	gcc -c $< -o $@

$(SRC_OBJ): $(SRC_FILE)
	gcc -c $< -o $@
	ar rcs $(STATIC_LIB) $(SRC_OBJ)

clean:
	rm -rf $(ROOT_OBJ) $(SRC_OBJ) $(STATIC_LIB) $(ROOT_BIN)
