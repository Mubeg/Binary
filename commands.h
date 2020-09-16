//This is auto-generted file from commands.h, which is a raw output of g++ preprocessor for command_describe.h//
//
//
//
//
//
//
//
DEF_FUNC(push, 10, 2, {stack_push(&(processor.stack), (commands[++(processor.pc)]));},

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






      if(false){return false;}
//


else if(strcmp("ax", arg_str.str) == 0){ stack_push(stack, CMD_push_oper_reg); (*pc)++;; stack_push(stack, REG_ax); (*pc)++;; }
else if(strcmp("bx", arg_str.str) == 0){ stack_push(stack, CMD_push_oper_reg); (*pc)++;; stack_push(stack, REG_bx); (*pc)++;; }
else if(strcmp("cx", arg_str.str) == 0){ stack_push(stack, CMD_push_oper_reg); (*pc)++;; stack_push(stack, REG_cx); (*pc)++;; }
else if(strcmp("dx", arg_str.str) == 0){ stack_push(stack, CMD_push_oper_reg); (*pc)++;; stack_push(stack, REG_dx); (*pc)++;; }
else if(strcmp("rsp", arg_str.str) == 0){ stack_push(stack, CMD_push_oper_reg); (*pc)++;; stack_push(stack, REG_rsp); (*pc)++;; }
else if(strcmp("rbp", arg_str.str) == 0){ stack_push(stack, CMD_push_oper_reg); (*pc)++;; stack_push(stack, REG_rbp); (*pc)++;; }
else if(strcmp("rsi", arg_str.str) == 0){ stack_push(stack, CMD_push_oper_reg); (*pc)++;; stack_push(stack, REG_rsi); (*pc)++;; }
else if(strcmp("rdi", arg_str.str) == 0){ stack_push(stack, CMD_push_oper_reg); (*pc)++;; stack_push(stack, REG_rdi); (*pc)++;; }
//
      else{fprintf(stderr, "No such registor %s\n", arg_str.str); return false;}

    }
    else{
     stack_push(stack, CMD_push_oper); (*pc)++;;
     stack_push(stack, arg); (*pc)++;;
    }


   }
   else{






    if(false){return false;}
//


else if(strcmp("ax", arg_str.str) == 0){ stack_push(stack, CMD_push_reg); (*pc)++;; stack_push(stack, REG_ax); (*pc)++;; }
else if(strcmp("bx", arg_str.str) == 0){ stack_push(stack, CMD_push_reg); (*pc)++;; stack_push(stack, REG_bx); (*pc)++;; }
else if(strcmp("cx", arg_str.str) == 0){ stack_push(stack, CMD_push_reg); (*pc)++;; stack_push(stack, REG_cx); (*pc)++;; }
else if(strcmp("dx", arg_str.str) == 0){ stack_push(stack, CMD_push_reg); (*pc)++;; stack_push(stack, REG_dx); (*pc)++;; }
else if(strcmp("rsp", arg_str.str) == 0){ stack_push(stack, CMD_push_reg); (*pc)++;; stack_push(stack, REG_rsp); (*pc)++;; }
else if(strcmp("rbp", arg_str.str) == 0){ stack_push(stack, CMD_push_reg); (*pc)++;; stack_push(stack, REG_rbp); (*pc)++;; }
else if(strcmp("rsi", arg_str.str) == 0){ stack_push(stack, CMD_push_reg); (*pc)++;; stack_push(stack, REG_rsi); (*pc)++;; }
else if(strcmp("rdi", arg_str.str) == 0){ stack_push(stack, CMD_push_reg); (*pc)++;; stack_push(stack, REG_rdi); (*pc)++;; }
//
    else return false;

   }
  }
 }
 else{
  stack_push(stack, CMD_push); (*pc)++;;
  stack_push(stack, arg); (*pc)++;;
 },

 int arg = commands[*pc + (1)];

 fprintf(file, "\x68");
 for(int i = 0; i < 4; i++){
  char byte = arg % 0x100;
  arg /= 0x100;
  fprintf(file, "%c", byte);
 }

 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;
 command_shift[*pc + 1] = command_shift[*pc] + (3); (*pc)++;

)

DEF_FUNC(push_reg, 11, 2, {stack_push(&(processor.stack), (processor.registors[commands[++(processor.pc)]]));}, correct = false;,

 int reg = commands[*pc + (1)];
 char byte = 0x50;





   if(false){return false;}
//


else if(reg == 0){ byte += 0; }
else if(reg == 1){ byte += 3; }
else if(reg == 2){ byte += 1; }
else if(reg == 3){ byte += 2; }
else if(reg == 4){ byte += 4; }
else if(reg == 5){ byte += 5; }
else if(reg == 6){ byte += 6; }
else if(reg == 7){ byte += 7; }
//
   else return false;



 fprintf(file, "%hhx", byte);

 command_shift[*pc + 1] = command_shift[*pc] + (-1); (*pc)++;
 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;
)


DEF_FUNC(push_oper, 12, 2, {operative[(commands[++(processor.pc)])] = stack_pop(&processor.stack);}, correct = false;,

 int arg = commands[*pc + (1)];

 char byte = 0;
 fprintf(file, "\x5f\x48\x89\x3C\x25");
 for(int i = 0; i < 4; i++){
  byte = arg % 0x100;
  arg /= 0x100;
  fprintf(file, "%c", byte);
 }

 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;
 command_shift[*pc + 1] = command_shift[*pc] + (7); (*pc)++;
)


DEF_FUNC(push_oper_reg, 13, 2, {operative[(processor.registors[commands[++(processor.pc)]])] = stack_pop(&processor.stack);}, correct = false;,

 int reg = commands[*pc + (1)];

 char byte = 0x38;
 fprintf(file, "\x5F\x48\x89");





   if(false){return false;}
//


else if(reg == 0){ byte += 0; }
else if(reg == 1){ byte += 3; }
else if(reg == 2){ byte += 1; }
else if(reg == 3){ byte += 2; }
else if(reg == 4){ byte += 4; }
else if(reg == 5){ byte += 5; }
else if(reg == 6){ byte += 6; }
else if(reg == 7){ byte += 7; }
//
   else return false;


 fprintf(file, "%hhx", byte);

 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;
 command_shift[*pc + 1] = command_shift[*pc] + (2); (*pc)++;


)


DEF_FUNC(pop, 20, 1, {stack_pop(&processor.stack);},

 str arg_str = {};

  if(get_arg_str(line, &pos, &arg_str)){

  if(arg_str.str[0] == '['){

   int arg = 0;
   int temp_pos = 0;
   arg_str.str++;

   if(!get_arg_dec(&arg_str, &temp_pos, &arg)){

     arg_str.str[strlen(arg_str.str) - 1] == ']' ? arg_str.str[strlen(arg_str.str) - 1] = '\0' : 0;






     if(false){return false;}
//


else if(strcmp("ax", arg_str.str) == 0){ stack_push(stack, CMD_pop_oper_reg); (*pc)++;; stack_push(stack, REG_ax); (*pc)++;; }
else if(strcmp("bx", arg_str.str) == 0){ stack_push(stack, CMD_pop_oper_reg); (*pc)++;; stack_push(stack, REG_bx); (*pc)++;; }
else if(strcmp("cx", arg_str.str) == 0){ stack_push(stack, CMD_pop_oper_reg); (*pc)++;; stack_push(stack, REG_cx); (*pc)++;; }
else if(strcmp("dx", arg_str.str) == 0){ stack_push(stack, CMD_pop_oper_reg); (*pc)++;; stack_push(stack, REG_dx); (*pc)++;; }
else if(strcmp("rsp", arg_str.str) == 0){ stack_push(stack, CMD_pop_oper_reg); (*pc)++;; stack_push(stack, REG_rsp); (*pc)++;; }
else if(strcmp("rbp", arg_str.str) == 0){ stack_push(stack, CMD_pop_oper_reg); (*pc)++;; stack_push(stack, REG_rbp); (*pc)++;; }
else if(strcmp("rsi", arg_str.str) == 0){ stack_push(stack, CMD_pop_oper_reg); (*pc)++;; stack_push(stack, REG_rsi); (*pc)++;; }
else if(strcmp("rdi", arg_str.str) == 0){ stack_push(stack, CMD_pop_oper_reg); (*pc)++;; stack_push(stack, REG_rdi); (*pc)++;; }
//
     else {fprintf(stderr, "No such registor %s\n", arg_str.str); return false;}

   }
   else{
    stack_push(stack, CMD_pop_oper); (*pc)++;;
    stack_push(stack, arg); (*pc)++;;
   }


  }
  else{






   if(false){return false;}
//


else if(strcmp("ax", arg_str.str) == 0){ stack_push(stack, CMD_pop_reg); (*pc)++;; stack_push(stack, REG_ax); (*pc)++;; }
else if(strcmp("bx", arg_str.str) == 0){ stack_push(stack, CMD_pop_reg); (*pc)++;; stack_push(stack, REG_bx); (*pc)++;; }
else if(strcmp("cx", arg_str.str) == 0){ stack_push(stack, CMD_pop_reg); (*pc)++;; stack_push(stack, REG_cx); (*pc)++;; }
else if(strcmp("dx", arg_str.str) == 0){ stack_push(stack, CMD_pop_reg); (*pc)++;; stack_push(stack, REG_dx); (*pc)++;; }
else if(strcmp("rsp", arg_str.str) == 0){ stack_push(stack, CMD_pop_reg); (*pc)++;; stack_push(stack, REG_rsp); (*pc)++;; }
else if(strcmp("rbp", arg_str.str) == 0){ stack_push(stack, CMD_pop_reg); (*pc)++;; stack_push(stack, REG_rbp); (*pc)++;; }
else if(strcmp("rsi", arg_str.str) == 0){ stack_push(stack, CMD_pop_reg); (*pc)++;; stack_push(stack, REG_rsi); (*pc)++;; }
else if(strcmp("rdi", arg_str.str) == 0){ stack_push(stack, CMD_pop_reg); (*pc)++;; stack_push(stack, REG_rdi); (*pc)++;; }
//
   else return false;

  }
 }
 else{
  stack_push(stack, CMD_pop); (*pc)++;;
 },

 fprintf(file, "\x5f");

 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;

)

DEF_FUNC(pop_reg, 21, 2, {processor.registors[commands[++(processor.pc)]] = stack_pop(&processor.stack);}, {correct = false;},

 int reg = commands[*pc + (1)];
 char byte = 0x58;





   if(false){return false;}
//


else if(reg == 0){ byte += 0; }
else if(reg == 1){ byte += 3; }
else if(reg == 2){ byte += 1; }
else if(reg == 3){ byte += 2; }
else if(reg == 4){ byte += 4; }
else if(reg == 5){ byte += 5; }
else if(reg == 6){ byte += 6; }
else if(reg == 7){ byte += 7; }
//
   else return false;



 fprintf(file, "%hhx", byte);

 command_shift[*pc + 1] = command_shift[*pc] + (-1); (*pc)++;
 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;

)


DEF_FUNC(pop_oper, 22, 2, {stack_push(&(processor.stack), (operative[(commands[++(processor.pc)])]));}, {correct = false;},

 int arg = commands[*pc + (1)];

 char byte = 0;
 fprintf(file, "\xff\x34\x25");
 for(int i = 0; i < 4; i++){
  byte = arg % 0x100;
  arg /= 0x100;
  fprintf(file, "%c", byte);
 }

 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;
 command_shift[*pc + 1] = command_shift[*pc] + (5); (*pc)++;

)


DEF_FUNC(pop_oper_reg, 23, 2, {stack_push(&(processor.stack), (operative[(processor.registors[commands[++(processor.pc)]])]));}, {correct = false;},

 int reg = commands[*pc + (1)];

 char byte = 0x30;
 fprintf(file, "\xFF");





   if(false){return false;}
//


else if(reg == 0){ byte += 0; }
else if(reg == 1){ byte += 3; }
else if(reg == 2){ byte += 1; }
else if(reg == 3){ byte += 2; }
else if(reg == 4){ byte += 4; }
else if(reg == 5){ byte += 5; }
else if(reg == 6){ byte += 6; }
else if(reg == 7){ byte += 7; }
//
   else return false;


 fprintf(file, "%hhx", byte);

 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;
 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;


)


DEF_FUNC(add, 30, 1, {stack_push(&(processor.stack), (stack_pop(&processor.stack) + stack_pop(&processor.stack)));}, stack_push(stack, CMD_add); (*pc)++;,

 fprintf(file, "\x5e\x5f\x48\x01\xfe\x56");

 command_shift[*pc + 1] = command_shift[*pc] + (4); (*pc)++;
)


DEF_FUNC(jmp, 40, 2, { (processor.pc) = commands[++(processor.pc)]; (processor.pc) --;}, { str arg = {}; if(!get_arg_str(line, &pos, &arg)){ correct = false; } else{ label label = {}; strcpy(label.label, arg.str); label.num = -1; int pos = find_label(labels, &label); if(pos != -1){ stack_push(stack, CMD_jmp); (*pc)++;; stack_push(stack, labels[pos].num); (*pc)++;; } else if(*label_counter == MAX_LABEL_NUM - 1){ fprintf(stderr, "Label overflow from label: %s\n", label.label); correct = false; } else{ labels[(*label_counter)++] = label; stack_push(stack, CMD_jmp); (*pc)++;; stack_push(stack, -1); (*pc)++;; } }},

 fprintf(file, "\xeb");

 if(found_shifts){
  int arg = commands[*pc + (1)];
  char byte = arg + command_shift[arg] - *pc - command_shift[*pc] - 2;
  fprintf(file, "%hhx", byte);
 }
 else{
  fprintf(file, "\x00");
 }

 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;
 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;
)


DEF_FUNC(out, 50, 1, printf("%" "d", stack_pop(&processor.stack));;, stack_push(stack, CMD_out); (*pc)++;;,

 fprintf(file, "\x48\xC7\xC7\x01\x00\x00\x00\x48\x89\xE6\x48\x83\xEE\x04\x52\x48\xC7\xC2\x01\x00\x00\x00\x50\x48\xC7\xC0\x01\x00\x00\x00\x0F\x05\x58\x5A");

 command_shift[*pc + 1] = command_shift[*pc] + (33); (*pc)++;

)

DEF_FUNC(cout, 51, 1, printf("%" "c", stack_pop(&processor.stack));;, stack_push(stack, CMD_cout); (*pc)++;;, "none";)


DEF_FUNC(fout, 52, 1, printf("%." ACCURACY_PRINT "f", ((float) stack_pop(&processor.stack)) / ACCURACY);, stack_push(stack, CMD_fout); (*pc)++;;, "none";)


DEF_FUNC(end, 0, 1, break;, stack_push(stack, CMD_end); (*pc)++;;,

 fprintf(file, "\x48\xC7\xC0\x3C\x00\x00\x00\x48\xC7\xC7\x00\x00\x00\x00\x0F\x05");
 command_shift[*pc + 1] = command_shift[*pc] + (15); (*pc)++;

)


DEF_FUNC(mul, 60, 1, stack_push(&(processor.stack), (stack_pop(&processor.stack) * stack_pop(&processor.stack)));, stack_push(stack, CMD_mul); (*pc)++;;,

 fprintf(file, "\x48\x89\xC7\x58\x5E\x52\x48\xC7\xC2\x00\x00\x00\x00\x48\xF7\xEE\x5A\x50\x48\x89\xF8");

 command_shift[*pc + 1] = command_shift[*pc] + (20); (*pc)++;
)


DEF_FUNC(fmul, 61, 1, stack_push(&(processor.stack), ((int) (((float) stack_pop(&processor.stack))/ACCURACY) * (((float) stack_pop(&processor.stack))/ACCURACY) * ACCURACY));, stack_push(stack, CMD_fmul); (*pc)++;;, "none";)


DEF_FUNC(ja, 41, 2, if(stack_pop(&processor.stack) > stack_pop(&processor.stack)) {(processor.pc) = commands[++(processor.pc)]; (processor.pc)--;}else{commands[++(processor.pc)];}, { str arg = {}; if(!get_arg_str(line, &pos, &arg)){ correct = false; } else{ label label = {}; strcpy(label.label, arg.str); label.num = -1; int pos = find_label(labels, &label); if(pos != -1){ stack_push(stack, CMD_ja); (*pc)++;; stack_push(stack, labels[pos].num); (*pc)++;; } else if(*label_counter == MAX_LABEL_NUM - 1){ fprintf(stderr, "Label overflow from label: %s\n", label.label); correct = false; } else{ labels[(*label_counter)++] = label; stack_push(stack, CMD_ja); (*pc)++;; stack_push(stack, -1); (*pc)++;; } }},

 fprintf(file, "\x77");

 if(found_shifts){
  int arg = commands[*pc + (1)];
  char byte = arg + command_shift[arg] - *pc - command_shift[*pc] - 2;
  fprintf(file, "%hhx", byte);
 }
 else{
  fprintf(file, "\x00");
 }

 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;
 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;

)


DEF_FUNC(jae, 42, 2, if(stack_pop(&processor.stack) >= stack_pop(&processor.stack)){(processor.pc) = commands[++(processor.pc)]; (processor.pc)--;}else{commands[++(processor.pc)];}, { str arg = {}; if(!get_arg_str(line, &pos, &arg)){ correct = false; } else{ label label = {}; strcpy(label.label, arg.str); label.num = -1; int pos = find_label(labels, &label); if(pos != -1){ stack_push(stack, CMD_jae); (*pc)++;; stack_push(stack, labels[pos].num); (*pc)++;; } else if(*label_counter == MAX_LABEL_NUM - 1){ fprintf(stderr, "Label overflow from label: %s\n", label.label); correct = false; } else{ labels[(*label_counter)++] = label; stack_push(stack, CMD_jae); (*pc)++;; stack_push(stack, -1); (*pc)++;; } }},

 fprintf(file, "\x73");

 if(found_shifts){
  int arg = commands[*pc + (1)];
  char byte = arg + command_shift[arg] - *pc - command_shift[*pc] - 2;
  fprintf(file, "%hhx", byte);
 }
 else{
  fprintf(file, "\x00");
 }

 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;
 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;

)


DEF_FUNC(jb, 43, 2, if(stack_pop(&processor.stack) < stack_pop(&processor.stack)) {(processor.pc) = commands[++(processor.pc)]; (processor.pc)--;}else{commands[++(processor.pc)];}, { str arg = {}; if(!get_arg_str(line, &pos, &arg)){ correct = false; } else{ label label = {}; strcpy(label.label, arg.str); label.num = -1; int pos = find_label(labels, &label); if(pos != -1){ stack_push(stack, CMD_jb); (*pc)++;; stack_push(stack, labels[pos].num); (*pc)++;; } else if(*label_counter == MAX_LABEL_NUM - 1){ fprintf(stderr, "Label overflow from label: %s\n", label.label); correct = false; } else{ labels[(*label_counter)++] = label; stack_push(stack, CMD_jb); (*pc)++;; stack_push(stack, -1); (*pc)++;; } }},

 fprintf(file, "\x72");

 if(found_shifts){
  int arg = commands[*pc + (1)];
  char byte = arg + command_shift[arg] - *pc - command_shift[*pc] - 2;
  fprintf(file, "%hhx", byte);
 }
 else{
  fprintf(file, "\x00");
 }

 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;
 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;

)


DEF_FUNC(jbe, 44, 2, if(stack_pop(&processor.stack) <= stack_pop(&processor.stack)){(processor.pc) = commands[++(processor.pc)]; (processor.pc)--;}else{commands[++(processor.pc)];}, { str arg = {}; if(!get_arg_str(line, &pos, &arg)){ correct = false; } else{ label label = {}; strcpy(label.label, arg.str); label.num = -1; int pos = find_label(labels, &label); if(pos != -1){ stack_push(stack, CMD_jbe); (*pc)++;; stack_push(stack, labels[pos].num); (*pc)++;; } else if(*label_counter == MAX_LABEL_NUM - 1){ fprintf(stderr, "Label overflow from label: %s\n", label.label); correct = false; } else{ labels[(*label_counter)++] = label; stack_push(stack, CMD_jbe); (*pc)++;; stack_push(stack, -1); (*pc)++;; } }},

 fprintf(file, "\x76");

 if(found_shifts){
  int arg = commands[*pc + (1)];
  char byte = arg + command_shift[arg] - *pc - command_shift[*pc] - 2;
  fprintf(file, "%hhx", byte);
 }
 else{
  fprintf(file, "\x00");
 }

 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;
 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;

)


DEF_FUNC(je, 45, 2, if(stack_pop(&processor.stack) == stack_pop(&processor.stack)){(processor.pc) = commands[++(processor.pc)]; (processor.pc)--;}else{commands[++(processor.pc)];}, { str arg = {}; if(!get_arg_str(line, &pos, &arg)){ correct = false; } else{ label label = {}; strcpy(label.label, arg.str); label.num = -1; int pos = find_label(labels, &label); if(pos != -1){ stack_push(stack, CMD_je); (*pc)++;; stack_push(stack, labels[pos].num); (*pc)++;; } else if(*label_counter == MAX_LABEL_NUM - 1){ fprintf(stderr, "Label overflow from label: %s\n", label.label); correct = false; } else{ labels[(*label_counter)++] = label; stack_push(stack, CMD_je); (*pc)++;; stack_push(stack, -1); (*pc)++;; } }},

 fprintf(file, "\x74");

 if(found_shifts){
  int arg = commands[*pc + (1)];
  char byte = arg + command_shift[arg] - *pc - command_shift[*pc] - 2;
  fprintf(file, "%hhx", byte);
 }
 else{
  fprintf(file, "\x00");
 }

 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;
 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;

)


DEF_FUNC(jne, 46, 2, if(stack_pop(&processor.stack) != stack_pop(&processor.stack)){(processor.pc) = commands[++(processor.pc)]; (processor.pc)--;}else{commands[++(processor.pc)];}, { str arg = {}; if(!get_arg_str(line, &pos, &arg)){ correct = false; } else{ label label = {}; strcpy(label.label, arg.str); label.num = -1; int pos = find_label(labels, &label); if(pos != -1){ stack_push(stack, CMD_jne); (*pc)++;; stack_push(stack, labels[pos].num); (*pc)++;; } else if(*label_counter == MAX_LABEL_NUM - 1){ fprintf(stderr, "Label overflow from label: %s\n", label.label); correct = false; } else{ labels[(*label_counter)++] = label; stack_push(stack, CMD_jne); (*pc)++;; stack_push(stack, -1); (*pc)++;; } }},

 fprintf(file, "\x75");

 if(found_shifts){
  int arg = commands[*pc + (1)];
  char byte = arg + command_shift[arg] - *pc - command_shift[*pc] - 2;
  fprintf(file, "%hhx", byte);
 }
 else{
  fprintf(file, "\x00");
 }

 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;
 command_shift[*pc + 1] = command_shift[*pc] + (0); (*pc)++;

)


DEF_FUNC(call, 70, 2, stack_push(&(processor.stack), ((processor.pc) + 2)); (processor.pc) = commands[++(processor.pc)]; (processor.pc)--;, { str arg = {}; if(!get_arg_str(line, &pos, &arg)){ correct = false; } else{ label label = {}; strcpy(label.label, arg.str); label.num = -1; int pos = find_label(labels, &label); if(pos != -1){ stack_push(stack, CMD_call); (*pc)++;; stack_push(stack, labels[pos].num); (*pc)++;; } else if(*label_counter == MAX_LABEL_NUM - 1){ fprintf(stderr, "Label overflow from label: %s\n", label.label); correct = false; } else{ labels[(*label_counter)++] = label; stack_push(stack, CMD_call); (*pc)++;; stack_push(stack, -1); (*pc)++;; } }}, "none";)


DEF_FUNC(return, 100, 1, (processor.pc) = stack_pop(&processor.stack); (processor.pc)--;, stack_push(stack, CMD_return); (*pc)++;, "none";)


DEF_FUNC(sub, 80, 1, {stack_push(&(processor.stack), (stack_pop(&processor.stack) - stack_pop(&processor.stack)));}, stack_push(stack, CMD_sub); (*pc)++;,

 fprintf(file, "\x5E\x5F\x48\x29\xFE\x56");

 command_shift[*pc + 1] = command_shift[*pc] + (5); (*pc)++;
)


DEF_FUNC(in, 90, 1, {int temp = 0; scanf("%d", &temp); stack_push(&(processor.stack), (temp));}, stack_push(stack, CMD_in); (*pc)++;, "none";)


DEF_FUNC(fin, 91, 1, {float temp = 0; scanf("%f", &temp); stack_push(&(processor.stack), ((int) (temp*ACCURACY)));}, stack_push(stack, CMD_fin); (*pc)++;, "none";)


DEF_FUNC(div , 110, 1, stack_push(&(processor.stack), ((int) ((float) stack_pop(&processor.stack)) / ((float) stack_pop(&processor.stack))));, stack_push(stack, CMD_div); (*pc)++;;, "none";)


DEF_FUNC(fdiv, 111, 1, stack_push(&(processor.stack), ((int) ((((float) stack_pop(&processor.stack))/ACCURACY) / (((float) stack_pop(&processor.stack))/ACCURACY) * ACCURACY)));, stack_push(stack, CMD_fdiv); (*pc)++;;, "none";)


DEF_FUNC(sqrt, 120, 1, stack_push(&(processor.stack), ((int) (sqrt( ((float) stack_pop(&processor.stack))/ACCURACY) * ACCURACY)));, stack_push(stack, CMD_sqrt); (*pc)++;;, "none";)


DEF_FUNC(draw, 130, 1, for(int _ = 0; _ < TERMINAL_SHIFT; _++){ printf("%" "c", '\n'); };
         for(int _ = 0; _ < video_mem + 1; _++){ if(_ % width != 0){printf("%" "c", operative[(_)]);;}
               else{printf("%" "c", '\n');;} }, stack_push(stack, CMD_draw); (*pc)++;;, "none";)

DEF_FUNC(dump, 140, 1, processor_dump(&processor, __LOCATION__, true), stack_push(stack, CMD_dump); (*pc)++;, "none";)
