/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "interface.h"

bool_t
xdr_directoryName_t (XDR *xdrs, directoryName_t *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, objp, 255))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_fileList_t (XDR *xdrs, fileList_t *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)objp, sizeof (struct directoryNode), (xdrproc_t) xdr_directoryNode))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_directoryNode (XDR *xdrs, directoryNode *objp)
{
	register int32_t *buf;

	 if (!xdr_directoryName_t (xdrs, &objp->name))
		 return FALSE;
	 if (!xdr_fileList_t (xdrs, &objp->next))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_dir_res (XDR *xdrs, dir_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->errno))
		 return FALSE;
	switch (objp->errno) {
	case 0:
		 if (!xdr_fileList_t (xdrs, &objp->dir_res_u.list))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_elements_t (XDR *xdrs, elements_t objp)
{
	register int32_t *buf;

	 if (!xdr_vector (xdrs, (char *)objp, 100,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_matrix_t (XDR *xdrs, matrix_t *objp)
{
	register int32_t *buf;

	 if (!xdr_matrices (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_matrices (XDR *xdrs, matrices *objp)
{
	register int32_t *buf;

	 if (!xdr_elements_t (xdrs, objp->elements))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->num_of_matrices))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->m))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->n))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_line_t (XDR *xdrs, line_t objp)
{
	register int32_t *buf;

	 if (!xdr_opaque (xdrs, objp, 100))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_text_t (XDR *xdrs, text_t *objp)
{
	register int32_t *buf;

	 if (!xdr_text (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_text (XDR *xdrs, text *objp)
{
	register int32_t *buf;

	 if (!xdr_line_t (xdrs, objp->elements))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->num_of_chars))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_data_t (XDR *xdrs, data_t objp)
{
	register int32_t *buf;

	 if (!xdr_opaque (xdrs, objp, 100))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_dataSet_t (XDR *xdrs, dataSet_t *objp)
{
	register int32_t *buf;

	 if (!xdr_set (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_set (XDR *xdrs, set *objp)
{
	register int32_t *buf;

	 if (!xdr_data_t (xdrs, objp->elements))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->num_of_sets))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->first_len))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->second_len))
		 return FALSE;
	return TRUE;
}
