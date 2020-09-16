#define BEGIN if(false){return true;}
#define END

#include "ionegin"
#include "enum.h"


typedef int Elem_t; 

const char default_binary_file_name[] = "assembled.mubeg";
const int ASSEMBLE_ROUNDS = 2;
const int UNRESOLVED_COMMAND = 2;


bool check_compatibility(Elem_t * commands);


int translate_to_file(Elem_t * commands, int size, FILE * file, int *command_shift, bool found_shifts);

