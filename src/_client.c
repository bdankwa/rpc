/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "interface.h"
#include <time.h>
#include <stdlib.h>

typedef enum {
	DATETIME,
	MERGE,
	REV_ECHO,
	LISTDIR,
	ADD_MAT,
	QUIT
} operation_t;

typedef struct {
	operation_t operation;
	char* list1[256];
	int list1_len;
	char* list2[256];
	int list2_len;
}command_t;

void parseStdIO(char* line, command_t* cmd){

	const char* date_command = "rdate";
	const char* merge_command = "rmerge";
	const char* echo_command = "recho";
	const char* rdir_command = "rdir";
	const char* addmat_command = "raddmat";
	const char* quit_command = "q";

	int i, j;


	if(!strncmp(line, date_command, 5)){
		//printf("you entered data command \n %s", line);
		cmd->operation = DATETIME;

	}
	else if(!strncmp(line, merge_command, 6)){

		cmd->list1[0] = "ak";
		cmd->list1[1] = "bf";
		cmd->list2[0] = "ak";
		cmd->list2[1] = "ct";

		cmd->list1_len = 2;
		cmd->list2_len = 2;

		cmd->operation = MERGE;
		
	}
	else if(!strncmp(line, echo_command, 5)){
        		
		cmd->list1[0] = "dead beef";
		/*cmd->list1[1] = "e";
		cmd->list1[2] = "a";
		cmd->list1[3] = "d";
		cmd->list1[4] = " ";
		cmd->list1[5] = "b";
		cmd->list1[6] = "e";
		cmd->list1[7] = "e";
		cmd->list1[8] = "f"; */
		cmd->list1_len = 9;
		cmd->operation = REV_ECHO;
	}
	else if(!strncmp(line, rdir_command, 4)){

	}
	else if(!strncmp(line, addmat_command, 7)){

		for(i=0; i<4; i++){
			cmd->list1[i] = "1";
			cmd->list2[i] = "25";
		}
		cmd->operation = ADD_MAT;
		cmd->list1_len = 4;
		cmd->list2_len = 4;
	}
	else if(!strncmp(line, quit_command, 1)){
		cmd->operation = QUIT;
	}
	else{

	}

}


void
interface_progs_1(char *host)
{
	CLIENT *clnt;
	dir_res  *result_1;
	directoryName_t  read_dir_1_arg;
	matrix_t  *result_2;
	matrix_t  add_matrix_1_arg;
	text_t  *result_3;
	text_t  reverse_echo_1_arg;
	set_t  *result_4;
	set_t  merge_list_1_arg;
	u_int  *result_5;
	char *get_time_1_arg;
	int i, j;
	set_t* slp;

	command_t cmd;
	char line[1024];


#ifndef	DEBUG
	clnt = clnt_create (host, INTERFACE_PROGS, DIR_PROG_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	while(1){
		printf("RPC> ");
		while(fgets(line, sizeof(line), stdin) != NULL){
			parseStdIO(line, &cmd);
			switch(cmd.operation){
			case DATETIME:
				result_5 = get_time_1((void*)&get_time_1_arg, clnt);
				if (result_5 == (u_int *) NULL) {
					clnt_perror (clnt, "call failed 1");
				}
				printf("Time on server: %s \n", ctime((time_t*)result_5));
				break;
			case MERGE:
				merge_list_1_arg.text1 = strdup(cmd.list1[0]);
				merge_list_1_arg.text2 = strdup(cmd.list1[1]);
				merge_list_1_arg.text3 = strdup(cmd.list2[0]);

				result_4 = merge_list_1(&merge_list_1_arg, clnt);
				if (result_4 == (set_t *) NULL) {
					clnt_perror (clnt, "call failed 2");
				}
				printf("Merged list : ");
				printf("%s ", result_4->text1);
				if(result_4->num_of_objects > 1){
					printf("%s ", result_4->text2);
				}
				if(result_4->num_of_objects > 2){
					printf("%s ", result_4->text3);
				}
				printf("\n");

				/*for(i=0; i<result_4->first_len; i++){
					printf("%s ", result_4->elements[i]);
				}
				printf("\n");*/
				break;
			case REV_ECHO:
				/*for(i=0; i<cmd.list1_len; i++){
					reverse_echo_1_arg.elements[i] = (char)*cmd.list1[i];
					reverse_echo_1_arg.elements = strdup(cmd.list1);
				}*/
				//reverse_echo_1_arg.elements = list1[0];
				reverse_echo_1_arg.elements = strdup(cmd.list1[0]);
				reverse_echo_1_arg.num_of_chars = cmd.list1_len;

				result_3 = reverse_echo_1(&reverse_echo_1_arg, clnt);
				if (result_3 == (text_t *) NULL) {
					clnt_perror (clnt, "call failed 3");
				}
				printf("reversed string: %s \n", result_3->elements);
				
				break;
			case LISTDIR:
				result_1 = read_dir_1(&read_dir_1_arg, clnt);
				if (result_1 == (dir_res *) NULL) {
					clnt_perror (clnt, "call failed 4");
				}
				break;
			case ADD_MAT:
				for(i=0; i<cmd.list1_len; i++){
					add_matrix_1_arg.elements[i] = atoi(cmd.list1[i]);
					//printf("mat A[%i] = %i \n ", i, add_matrix_1_arg.elements[i]);
				}
				add_matrix_1_arg.m = 2;
				for(i=0; i<cmd.list2_len; i++){
					add_matrix_1_arg.elements[4+i] = atoi(cmd.list2[i]);
					//printf("mat B[%i] = %i \n ", i, add_matrix_1_arg.elements[4+i]);
				}
				add_matrix_1_arg.n = 2;
				add_matrix_1_arg.num_of_matrices = 2;

				result_2 = add_matrix_1(&add_matrix_1_arg, clnt);
				if (result_2 == (matrix_t *) NULL) {
					clnt_perror (clnt, "call failed 5");
				};
				printf("Sum of matrices: \n");
				for(i=0; i< result_2->m; i++){
					for(j=0; j< result_2->n; j++){
						printf("%i ",result_2->elements[i*result_2->n + j]);
					}
					printf("\n");					
				}
				printf("\n");
				break;
			case QUIT:
				return;
			default:
				break;
			}
			cmd.operation = 99; // reset command
			break;
		}
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	interface_progs_1 (host);
exit (0);
}
