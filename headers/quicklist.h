#ifndef __QUICKLIST_H__
#define __QUICKLIST_H__

#include "linklst.h"

//-----------------------------------------------
// Constants
//-----------------------------------------------


#define __QUICKLIST_SIZE__ sizeof(struct __s_QuickList)
#define __QLPAIR_SIZE__ sizeof(QLPair)


//-----------------------------------------------
// New data type
//-----------------------------------------------


struct __s_QuickList {
    List first;
    List last;
};

typedef struct __s_QuickList QuickList;

struct __s_QLPair {
    QuickList first;
    QuickList second;
};

typedef struct __s_QLPair QLPair;


//-----------------------------------------------
// Prototypes
//-----------------------------------------------


QuickList newQL (List _list);
Bool isEmptyQL (QuickList _ql);
QuickList addQL (List _l, QuickList _ql);
QLPair newQLPair (QuickList _first, QuickList _second);


#endif