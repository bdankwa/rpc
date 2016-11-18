/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */
#include <dirent.h>
#include <errno.h>
#include "interface.h"

dir_res *
read_dir_1_svc(directoryName_t *argp, struct svc_req *rqstp)
{
	static dir_res  result;

	/*
	 * insert server code here
	 */
	DIR *dirp;
    struct dirent *d;

    fileList_t nl;
    fileList_t *nlp;

    dirp = opendir(*argp);
    if (dirp == NULL)
    {
    	result.err = errno;
        return (&result);
    }

    /* Free previous result */

    xdr_free(xdr_dir_res, &result);

    nlp = &result.dir_res_u.list;
    while (d = readdir(dirp))
    {
        nl = *nlp = (directoryNode *) malloc(sizeof(directoryNode));
        nl->name = strdup(d->d_name);
        nlp = &nl->next;
    }
    *nlp = NULL;

    /* Return the result */

    result.err = 0;
    closedir(dirp);

	return &result;
}

matrix_t *
add_matrix_1_svc(matrix_t *argp, struct svc_req *rqstp)
{
	static matrix_t  result;
	int i, j, n, m;

	/*
	 * insert server code here
	 */
	m = argp->m;
	n = argp->n;

	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			result.elements[i*n+j] = argp->elements[i*n+j] + argp->elements[n*m + i*n+j];
		}
	}
	result.m = m;
	result.n = n;

	return &result;
}

text_t *
reverse_echo_1_svc(text_t *argp, struct svc_req *rqstp)
{
	static text_t  result;
	int i, n;

	/*
	 * insert server code here
	 */
	n = strlen(argp->elements);
	result.elements = (char*)malloc(strlen(argp->elements));
	for(i=0; i<n; i++){
		result.elements[i] = (char)argp->elements[n-i-1];
	}
	result.num_of_chars = n;

	return &result;
}

set_t *
merge_list_1_svc(set_t *argp, struct svc_req *rqstp)
{
	static set_t  result;
	int i, j, k;

	/*
	 * insert server code here
	 */
	result.num_of_objects = 0;
	result.text1 = strdup("empty");
	result.text2 = strdup("empty");
	result.text3 = strdup("empty");

	result.text1 = strdup(argp->text1);
	result.num_of_objects++;
	if(strcmp(argp->text2, result.text1)){
		result.text2 = strdup(argp->text2);
		result.num_of_objects++;		
	}
	if(result.num_of_objects > 1){
		if(strcmp(argp->text3, result.text1) && strcmp(argp->text3, result.text2) ){
			result.text3 = strdup(argp->text3);
			result.num_of_objects++;		
		}
	}
	else if(strcmp(argp->text3, result.text1)){
		result.text2 = strdup(argp->text3);
		result.num_of_objects++;		
	}
	else{} 
	
	/*k = 1;
	for(i=1; i<10; i++){
		for(j=0; j<i; j++){			
			if(!strcmp(argp->text[i],result.text[j])){
				continue;
			}
		}
		result.text[k] = strdup(argp->text[i]);
		k++;
	}*/ 


	return &result;
}
/*dataSet_t *
merge_list_1_svc(dataSet_t *argp, struct svc_req *rqstp)
{
	static dataSet_t  result;


	int i, j, k, m, n;

	m = argp->first_len;
	n = argp->second_len;

	result.elements[0] = (dataSet_t*)malloc(256);
	result.elements[0] = "something";
	strcpy(result.elements[0],argp->elements[0]);
	k = 1;
	for(i=1; i<m+n; i++){
		for(j=0; j<i; j++){			
			if(!strcmp(argp->elements[i],result.elements[j])){
				continue;
			}
		}
		result.elements[k] = (dataSet_t*)malloc(256);
		strcpy(result.elements[k],argp->elements[i]);
		k++;
	}

	result.first_len = k;
	result.second_len = 0;
	result.num_of_sets = 1;

	return &result;
}
*/
u_int *
get_time_1_svc(void *argp, struct svc_req *rqstp)
{
	static u_int  result;

	/*
	 * insert server code here
	 */
	result = time(NULL);

	return &result;
}
