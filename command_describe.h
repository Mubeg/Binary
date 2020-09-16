//DEF_FUNC(name, num, len, code, param_code, translator_code)

#define PC (processor.pc)
#define PUSH(arg) stack_push(&(processor.stack), (arg))
#define ARG commands[++PC]
#define REG(num) processor.registors[num]
#define POP stack_pop(&processor.stack)
#define DROP(arg) arg
#define PUT(cmd)  stack_push(stack, cmd); (*pc)++;
#define OPER(arg) operative[(arg)]

#define IF(cond, arg) if(cond){arg;}
#define ELSE(arg) else{arg;}

#define CYCLE_START(size) for(int _ = 0; _ < size; _++){
#define CYCLE_END }
#define COUNTER _

#define TRSL(str) fprintf(file, str);
#define PC_INC(num) command_shift[*pc + 1] = command_shift[*pc] + (num); (*pc)++;
#define ARG_T(num) commands[*pc + (num)] 

#define DRAW_NEXT_OBJ(type, arg) printf("%" #type, arg);

#define JMP_do_param(cmd) \
	{\
\
	str arg = {};\
	if(!get_arg_str(line, &pos, &arg)){\
			correct = false;\
	}\
	else{\
		label label = {};\
		strcpy(label.label, arg.str);\
		label.num = -1;\
\
		int pos = find_label(labels, &label);\
\
		if(pos != -1){\
\
			PUT(cmd);\
			PUT(labels[pos].num);\
\
		}\
		else if(*label_counter == MAX_LABEL_NUM - 1){\
\
			fprintf(stderr, "Label overflow from label: %s\n", label.label);\
			correct = false;\
\
		}\
		else{\
			labels[(*label_counter)++] = label;\
			\
			PUT(cmd);\
			PUT(-1);\
		}\
	}\
\
}
 
DEF_FUNC(push, 10, 2, {PUSH(ARG);}, 

	int arg = 0;
	if(!get_arg_dec(line, &pos, &arg)){
		str arg_str = {};
		if(!get_arg_str(line, &pos, &arg_str)){
			correct = false;
		}
		else{

			if(arg_str.str[0] == '['){


				int temp_pos = 0;
				arg_str.str++;

				if(!get_arg_dec(&arg_str, &temp_pos, &arg)){

						arg_str.str[strlen(arg_str.str) - 1] == ']' ? arg_str.str[strlen(arg_str.str) - 1] = '\0' : 0;

						#define DEF_REG(name, num, trsl_num) else if(strcmp(#name, arg_str.str) == 0){\
										PUT(CMD_push_oper_reg);\
										PUT(REG_##name);\
										}

						if(false){return false;}
						#include"registors.h"
						else{fprintf(stderr, "No such registor %s\n", arg_str.str); return false;}
						#undef DEF_REG
				}
				else{	
					PUT(CMD_push_oper);
					PUT(arg);
				}
				

			}
			else{
			
				#define DEF_REG(name, num, trsl_num) else if(strcmp(#name, arg_str.str) == 0){\
								PUT(CMD_push_reg);\
								PUT(REG_##name);\
								}

				if(false){return false;}
				#include"registors.h"
				else return false;
				#undef DEF_REG
			}
		}
	}
	else{
		PUT(CMD_push);
		PUT(arg);
	},
	
	int arg = ARG_T(1);

	fprintf(file, "\x68");
	for(int i = 0; i < 4; i++){
		char byte = arg % 0x100;
		arg /= 0x100;
		fprintf(file, "%c", byte);
	}

	PC_INC(0)
	PC_INC(3)

)

DEF_FUNC(push_reg, 11, 2, {PUSH(REG(ARG));}, correct = false;, 
	
	int reg = ARG_T(1);
	char byte = 0x50;
	
	#define DEF_REG(name, num, trsl_num) else if(reg == num){\
						byte += trsl_num;\
						}

			if(false){return false;}
			#include"registors.h"
			else return false;
			#undef DEF_REG
	
	
	fprintf(file, "%hhx", byte);

	PC_INC(-1)
	PC_INC(0)
)


DEF_FUNC(push_oper, 12, 2, {OPER(ARG) = POP;}, correct = false;,

	int arg = ARG_T(1);
	
	char byte = 0;
	fprintf(file, "\x5f\x48\x89\x3C\x25");
	for(int i = 0; i < 4; i++){
		byte = arg % 0x100;
		arg /= 0x100;
		fprintf(file, "%c", byte);
	}

	PC_INC(0)
	PC_INC(7)
)


DEF_FUNC(push_oper_reg, 13, 2, {OPER(REG(ARG)) = POP;}, correct = false;,
	
	int reg = ARG_T(1);
	
	char byte = 0x38;
	fprintf(file, "\x5F\x48\x89");

	#define DEF_REG(name, num, trsl_num) else if(reg == num){\
						byte += trsl_num;\
						}

			if(false){return false;}
			#include"registors.h"
			else return false;
			#undef DEF_REG

	fprintf(file, "%hhx", byte);

	PC_INC(0)
	PC_INC(2)
	

)


DEF_FUNC(pop, 20, 1, {POP;}, 

	str arg_str = {};
	
 	if(get_arg_str(line, &pos, &arg_str)){
		
		if(arg_str.str[0] == '['){
			
			int arg = 0;
			int temp_pos = 0;
			arg_str.str++;		
	
			if(!get_arg_dec(&arg_str, &temp_pos, &arg)){

					arg_str.str[strlen(arg_str.str) - 1] == ']' ? arg_str.str[strlen(arg_str.str) - 1] = '\0' : 0;

					#define DEF_REG(name, num, trsl_num) else if(strcmp(#name, arg_str.str) == 0){\
									PUT(CMD_pop_oper_reg);\
									PUT(REG_##name);\
									}

					if(false){return false;}
					#include"registors.h"
					else {fprintf(stderr, "No such registor %s\n", arg_str.str); return false;}
					#undef DEF_REG
			}
			else{	
				PUT(CMD_pop_oper);
				PUT(arg);
			}


		}
		else{
		
			#define DEF_REG(name, num, trsl_num) else if(strcmp(#name, arg_str.str) == 0){\
							PUT(CMD_pop_reg);\
							PUT(REG_##name);\
							}

			if(false){return false;}
			#include"registors.h"
			else return false;
			#undef DEF_REG
		}
	}
	else{
		PUT(CMD_pop);	
	},

	fprintf(file, "\x5f");

	PC_INC(0)

)

DEF_FUNC(pop_reg, 21, 2, {REG(ARG) = POP;}, {correct = false;},

	int reg = ARG_T(1);
	char byte = 0x58;
	
	#define DEF_REG(name, num, trsl_num) else if(reg == num){\
						byte += trsl_num;\
						}

			if(false){return false;}
			#include"registors.h"
			else return false;
			#undef DEF_REG
	
	
	fprintf(file, "%hhx", byte);

	PC_INC(-1)
	PC_INC(0)

)


DEF_FUNC(pop_oper, 22, 2, {PUSH(OPER(ARG));}, {correct = false;},

	int arg = ARG_T(1);
	
	char byte = 0;
	fprintf(file, "\xff\x34\x25");
	for(int i = 0; i < 4; i++){
		byte = arg % 0x100;
		arg /= 0x100;
		fprintf(file, "%c", byte);
	}

	PC_INC(0)
	PC_INC(5)

)


DEF_FUNC(pop_oper_reg, 23, 2, {PUSH(OPER(REG(ARG)));}, {correct = false;},

	int reg = ARG_T(1);
	
	char byte = 0x30;
	fprintf(file, "\xFF");

	#define DEF_REG(name, num, trsl_num) else if(reg == num){\
						byte += trsl_num;\
						}

			if(false){return false;}
			#include"registors.h"
			else return false;
			#undef DEF_REG

	fprintf(file, "%hhx", byte);

	PC_INC(0)
	PC_INC(0)


)


DEF_FUNC(add, 30, 1, {PUSH(POP + POP);}, PUT(CMD_add), 

	fprintf(file, "\x5e\x5f\x48\x01\xfe\x56");

	PC_INC(4)
)


DEF_FUNC(jmp, 40, 2, { PC = ARG; PC --;}, JMP_do_param(CMD_jmp),

	fprintf(file, "\xeb");

	if(found_shifts){
		int arg = ARG_T(1);
		char byte = arg + command_shift[arg] - *pc - command_shift[*pc] - 2;
		fprintf(file, "%hhx", byte);
	}
	else{
		fprintf(file, "\x00");	//byte = dest - cur - 2
	}

	PC_INC(0)
	PC_INC(0)
)


DEF_FUNC(out, 50, 1, DRAW_NEXT_OBJ(d, POP);, PUT(CMD_out);, 

	fprintf(file, "\x48\xC7\xC7\x01\x00\x00\x00\x48\x89\xE6\x48\x83\xEE\x04\x52\x48\xC7\xC2\x01\x00\x00\x00\x50\x48\xC7\xC0\x01\x00\x00\x00\x0F\x05\x58\x5A");
	
	PC_INC(33)

)

DEF_FUNC(cout, 51, 1, DRAW_NEXT_OBJ(c, POP);, PUT(CMD_cout);, "none";)


DEF_FUNC(fout, 52, 1, printf("%." ACCURACY_PRINT "f", ((float) POP) / ACCURACY);, PUT(CMD_fout);, "none";)


DEF_FUNC(end, 0, 1, break;, PUT(CMD_end);, 

	fprintf(file, "\x48\xC7\xC0\x3C\x00\x00\x00\x48\xC7\xC7\x00\x00\x00\x00\x0F\x05");
	PC_INC(15)

)


DEF_FUNC(mul, 60, 1, PUSH(POP * POP);, PUT(CMD_mul);,

	fprintf(file, "\x48\x89\xC7\x58\x5E\x52\x48\xC7\xC2\x00\x00\x00\x00\x48\xF7\xEE\x5A\x50\x48\x89\xF8");

	PC_INC(20)
)


DEF_FUNC(fmul, 61, 1, PUSH((int) (((float) POP)/ACCURACY) * (((float) POP)/ACCURACY) * ACCURACY );, PUT(CMD_fmul);, "none";)


DEF_FUNC(ja,  41, 2, if(POP > POP) {PC = ARG; PC--;}else{DROP(ARG);}, JMP_do_param(CMD_ja ),

	fprintf(file, "\x77");

	if(found_shifts){
		int arg = ARG_T(1);
		char byte = arg + command_shift[arg] - *pc - command_shift[*pc] - 2;
		fprintf(file, "%hhx", byte);
	}
	else{
		fprintf(file, "\x00");	//byte = dest - cur - 2
	}

	PC_INC(0)
	PC_INC(0)

)


DEF_FUNC(jae, 42, 2, if(POP >= POP){PC = ARG; PC--;}else{DROP(ARG);}, JMP_do_param(CMD_jae),

	fprintf(file, "\x73");

	if(found_shifts){
		int arg = ARG_T(1);
		char byte = arg + command_shift[arg] - *pc - command_shift[*pc] - 2;
		fprintf(file, "%hhx", byte);
	}
	else{
		fprintf(file, "\x00");	//byte = dest - cur - 2
	}

	PC_INC(0)
	PC_INC(0)

)


DEF_FUNC(jb,  43, 2, if(POP < POP) {PC = ARG; PC--;}else{DROP(ARG);}, JMP_do_param(CMD_jb ),

	fprintf(file, "\x72");

	if(found_shifts){
		int arg = ARG_T(1);
		char byte = arg + command_shift[arg] - *pc - command_shift[*pc] - 2;
		fprintf(file, "%hhx", byte);
	}
	else{
		fprintf(file, "\x00");	//byte = dest - cur - 2
	}

	PC_INC(0)
	PC_INC(0)

)


DEF_FUNC(jbe, 44, 2, if(POP <= POP){PC = ARG; PC--;}else{DROP(ARG);}, JMP_do_param(CMD_jbe),

	fprintf(file, "\x76");

	if(found_shifts){
		int arg = ARG_T(1);
		char byte = arg + command_shift[arg] - *pc - command_shift[*pc] - 2;
		fprintf(file, "%hhx", byte);
	}
	else{
		fprintf(file, "\x00");	//byte = dest - cur - 2
	}

	PC_INC(0)
	PC_INC(0)

)


DEF_FUNC(je, 45, 2, if(POP == POP){PC = ARG; PC--;}else{DROP(ARG);}, JMP_do_param(CMD_je ),

	fprintf(file, "\x74");

	if(found_shifts){
		int arg = ARG_T(1);
		char byte = arg + command_shift[arg] - *pc - command_shift[*pc] - 2;
		fprintf(file, "%hhx", byte);
	}
	else{
		fprintf(file, "\x00");	//byte = dest - cur - 2
	}

	PC_INC(0)
	PC_INC(0)

)


DEF_FUNC(jne, 46, 2, if(POP != POP){PC = ARG; PC--;}else{DROP(ARG);}, JMP_do_param(CMD_jne),

	fprintf(file, "\x75");

	if(found_shifts){
		int arg = ARG_T(1);
		char byte = arg + command_shift[arg] - *pc - command_shift[*pc] - 2;
		fprintf(file, "%hhx", byte);
	}
	else{
		fprintf(file, "\x00");	//byte = dest - cur - 2
	}

	PC_INC(0)
	PC_INC(0)

)


DEF_FUNC(call, 70, 2, PUSH(PC + 2); PC = ARG; PC--;, JMP_do_param(CMD_call), "none";)


DEF_FUNC(return, 100, 1, PC = POP; PC--;, PUT(CMD_return), "none";)


DEF_FUNC(sub, 80, 1, {PUSH(POP - POP);}, PUT(CMD_sub), 

	fprintf(file, "\x5E\x5F\x48\x29\xFE\x56");

	PC_INC(5)
)


DEF_FUNC(in, 90, 1, {int temp = 0; scanf("%d", &temp); PUSH(temp);}, PUT(CMD_in), "none";)


DEF_FUNC(fin, 91, 1, {float temp = 0; scanf("%f", &temp); PUSH((int) (temp*ACCURACY) );}, PUT(CMD_fin), "none";)


DEF_FUNC(div , 110, 1, PUSH((int) ((float) POP) / ((float) POP) );, PUT(CMD_div);, "none";)


DEF_FUNC(fdiv, 111, 1, PUSH((int) ((((float) POP)/ACCURACY) / (((float) POP)/ACCURACY) * ACCURACY) );, PUT(CMD_fdiv);, "none";)


DEF_FUNC(sqrt, 120, 1, PUSH((int) (sqrt( ((float) POP)/ACCURACY) * ACCURACY) );, PUT(CMD_sqrt);, "none";)


DEF_FUNC(draw, 130, 1, CYCLE_START(TERMINAL_SHIFT) DRAW_NEXT_OBJ(c, '\n') CYCLE_END;
		       CYCLE_START(video_mem + 1) IF(COUNTER % width != 0, DRAW_NEXT_OBJ(c, OPER(COUNTER))) 
					          ELSE(DRAW_NEXT_OBJ(c, '\n'))  CYCLE_END, PUT(CMD_draw);, "none";)

DEF_FUNC(dump, 140, 1, processor_dump(&processor, __LOCATION__, true), PUT(CMD_dump), "none";)



