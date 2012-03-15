// package
#include "functions.h" 
// free_var
#include "utils.h" 
// register_function
#include "bf_register.h"
// str_dup
#include "storage.h"

static package bf_chr(Var arglist, Byte next, void *vdata, Objid progr) {
    Var r;
    char str[2];

    if (!is_wizard(progr)) {
        free_var(arglist);
        return make_error_pack(E_PERM);
    }

    switch (arglist.v.list[1].type) {
    case TYPE_INT:
        if ((arglist.v.list[1].v.num < 1) || (arglist.v.list[1].v.num > 255)) {
            free_var(arglist);
            return make_error_pack(E_INVARG);
        }
        str[0] = (char) arglist.v.list[1].v.num;
        str[1] = '\0';
        r.type = TYPE_STR;
        r.v.str = str_dup(str);
        break;
    case TYPE_STR:
        if (!(r.v.num = (int) arglist.v.list[1].v.str[0])) {
            free_var(arglist);
            return make_error_pack(E_INVARG);
        }

        r.type = TYPE_INT;
        break;
    default:
        free_var(arglist);
        return make_error_pack(E_TYPE);
        break;
    }

    free_var(arglist);
    return make_var_pack(r);
}

void register_chr(void) {
  register_function("chr", 1, 1, bf_chr, TYPE_ANY);
}
