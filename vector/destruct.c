#include "private.h"
#include "vector.h"


void VectorDestroy(Vector ** vec_ptr) {
    Vector * vec = *vec_ptr;

    vec->liberate(vec->content, vec->moreContext);
    vec->liberate(vec, vec->moreContext);

    *vec_ptr = NULL;
}
