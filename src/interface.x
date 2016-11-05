/****************************************************
* Protocol for READ_DIR
*****************************************************/

typedef string directoryName_t<255>;
typedef struct directoryNode *fileList_t;

struct directoryNode
{
	directoryName_t name;
	fileList_t next;
};

union dir_res switch (int errno){
	case 0:
		fileList_t list;
	default:
		void;
};

/****************************************************
* Protocol for ADD_MATRIX
*****************************************************/

typedef int elements_t[100];
typedef struct matrices matrix_t;

struct matrices
{
	elements_t elements;
	int num_of_matrices;
	int m;
	int n;
};

/****************************************************
* Protocol for REVERSE_ECHO
*****************************************************/

typedef string text_t<100>;

/****************************************************
* Protocol for MERGE_LIST
*****************************************************/

typedef opaque data_t[100];
typedef struct set dataSet_t;

struct set
{
	data_t elements;
	int num_of_sets;
	int first_len;
	int second_len;	
};

/****************************************************
* Interface
*****************************************************/

program INTERFACE_PROGS {
	version DIR_PROG_VERS{
		dir_res READ_DIR(directoryName_t) = 1;
		matrix_t ADD_MATRIX(matrix_t) = 2;	
		text_t REVERSE_ECHO(text_t) = 3;
		dataSet_t MERGE_LIST(dataSet_t) = 4;
		unsigned int GET_TIME(void) = 5;
	} = 1;
} = 0x21111111;
