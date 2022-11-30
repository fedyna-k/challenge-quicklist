#ifndef __LINKLST_H__
#define __LINKLST_H__


//-----------------------------------------------
// Constants
//-----------------------------------------------


#define __LINK_SIZE__ sizeof(struct __s_List)


//-----------------------------------------------
// New data type
//-----------------------------------------------


typedef int Data;
typedef char Bool;

struct __s_List {
    Data element;
    struct __s_List *next_link;
};

typedef struct __s_List * List;


//-----------------------------------------------
// Prototypes
//-----------------------------------------------


//----- ADT

List createEmptyList (void);
List add (Data _data, List _list);
List tail (List _list);
Data head (List _list);
Bool isEmptyList (List _list);

//----- Memory management functions

List copyList (List _list);
void freeLink (List _link);
void freeList (List _list);

//----- Toolbox

void printList(List _list);

#endif