#include "private.h"
#include "vector.h"


void VectorDestroy(Vector ** vec_ptr) {
    Vector * vec = *vec_ptr;

    vec->liberator(vec->content, vec->moreContext);
    vec->liberator(vec, vec->moreContext);

    *vec_ptr = NULL;
}
