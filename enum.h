#include<math.h>

const int MAX_COMMAND_LEN = 2; //manually changed
#define MAX_COMMAND_LEN_PRINT "2"
const int TYPE_OF_FILE = 'GBUM';
const int START_BIAS   = 2;
const int REGISTOR_NUM = 4;
const int ACCURACY = 1000;
#define ACCURACY_PRINT "3"
const char *BINARY_HEADER = "";

const char * output_file_name = "a.out";
const char * output_file_name_2 = "b.out";


const int TERMINAL_SHIFT = 30;

const int MEM_KB = 10;

enum commands {

	#define DEF_FUNC(name, num, len, code, param_code, translator_code) CMD_##name = (num),
	#include"commands.h"
	#undef DEF_FUNC

};

enum registors{

	#define DEF_REG(name, num, trsl_num) REG_##name = (num),
	#include"registors.h"
	#undef DEF_REG
};
