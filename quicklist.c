#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "headers/quicklist.h"


/**
 * Creates a new quicklist
 * @param _list The list to convert
 * @return A new quicklist
 */
QuickList newQL (List _list) {
    QuickList new;
    new.last = _list;

    // Parkour ᕕ(⌐■_■)ᕗ
    while (!isEmptyList(_list) && !isEmptyList(_list->next_link)) {
        _list = _list->next_link;
    }

    new.first = _list;

    return new;
}


/**
 * Add elem to quicklist
 * @param _l The node to add
 * @param _ql The quicklist to alter
 * @return The new quicklist
 */
QuickList addQL (List _l, QuickList _ql) {
    _l->next_link = _ql.last;

    if (isEmptyQL(_ql)) {
        _ql.first = _l;
        _ql.last = _l;
    } else {
        _ql.last = _l;
    }
    
    return _ql;
}


/**
 * Checks if a QL is empty
 * @param _ql The QL to test
 * @return A Bool which value is 1 if QL is empty, 0 otherwise 
 */
Bool isEmptyQL (QuickList _ql) {
    return (_ql.first == NULL && _ql.last == NULL);
}


/**
 * Creates a pair of quicklists
 * 
 * @param _first The first QL
 * @param _second The second QL
 * @return The pair (_first, _second)
 */
QLPair newQLPair (QuickList _first, QuickList _second) {
    QLPair pair;
    pair.first = _first;
    pair.second = _second;

    return pair;
}
