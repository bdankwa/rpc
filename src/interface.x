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

union dir_res switch (int err){
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

typedef string line_t<>;
typedef struct text text_t;

struct text
{
	line_t elements;
	int num_of_chars;
};

/****************************************************
* Protocol for MERGE_LIST
*****************************************************/
typedef struct  set set_t;

struct set
{
	line_t text1;
	line_t text2;
	line_t text3;
	int num_of_objects;
};

/* strng_res switch (int err){
	case 0:
		stringList_t list;
	default:
		void;
}; */


/*typedef string data_t<256>;
typedef struct set dataSet_t;

struct set
{
	data_t elements[100];
	int num_of_sets;
	int first_len;
	int second_len;	
}; */

/****************************************************
* Interface
*****************************************************/

program INTERFACE_PROGS {
	version DIR_PROG_VERS{
		dir_res READ_DIR(directoryName_t) = 1;
		matrix_t ADD_MATRIX(matrix_t) = 2;	
		text_t REVERSE_ECHO(text_t) = 3;
		set_t MERGE_LIST(set_t) = 4;
		unsigned int GET_TIME(void) = 5;
	} = 1;
} = 0x21111111;
