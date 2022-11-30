#include <stdio.h>
#include <stdlib.h>
#include "headers/quicklist.h"


// Prototypes


QLPair partition (QuickList _ql);
QuickList quicksort (QuickList _ql);


// Main function


int main (void) {
    // Create list to sort
    List my_list = createEmptyList();
    QuickList my_quick_list;
    QLPair qlpair;

    // Fill with random values
    Data fill[] = {1, 1, 5, 6, 9, 7, 3, 4, 2, 8};
    int i;
    for (i = 0 ; i < 10 ; i++) {
        my_list = add(fill[i], my_list);
    }
    printf("\nInitial list : ");
    printList(my_list);

    // Convert to quicklist and perform quicksort
    my_quick_list = newQL(my_list);
    my_quick_list = quicksort(my_quick_list);

    my_list = my_quick_list.last;
    printf("Sorted list : ");
    printList(my_list);

    return 0;
}


// Quicksort functions


/**
 * Split a quicklist into two quicklists according to
 * quicksort principle
 * 
 * @param _ql The quicklist to split
 * @return A QLPair with the first being all X <= p and the second X > p
 */
QLPair partition (QuickList _ql) {
    QuickList first_half = newQL(NULL), second_half = newQL(NULL);
    List pivot = _ql.first, current = _ql.last, next;
    int i = 0;

    // Parkour all that list
    while (!isEmptyList(current)) {
        // Store next node
        next = current->next_link;

        // Add to corresponding half quicksort like
        if (current->element <= pivot->element && current != pivot) {
            first_half = addQL(current, first_half);
        } else {
            second_half = addQL(current, second_half);
        }

        // Go to next node
        current = next;
    }

    // Return the two halves in form of quicklists
    return newQLPair(first_half, second_half);
}


QuickList quicksort (QuickList _ql) {
    QuickList return_ql = newQL(NULL);
    QLPair merge;
    List pivot;

    // Terminal case
    if (_ql.first == _ql.last) {
        return _ql;
    }

    // Recursive quicksort
    merge = partition(_ql);

    // Get the pivot out
    pivot = merge.second.last;
    merge.second.last = pivot->next_link;

    if (merge.first.last != NULL && merge.second.last != NULL) {
        // Case where both quicklists is not empty
        merge.first = quicksort(merge.first);
        merge.second = quicksort(merge.second);

        // Relink and merge
        merge.first.first->next_link = pivot;
        pivot->next_link = merge.second.last;

        return_ql.first = merge.second.first;
        return_ql.last = merge.first.last;
    } else if (merge.first.last != NULL) {
        // Case where only first quicklist is not empty
        return_ql = quicksort(merge.first);
        pivot->next_link = return_ql.last;
        return_ql.last = pivot;
    } else if (merge.second.last != NULL) {
        // Case where only second quicklist is not empty
        return_ql = quicksort(merge.second);
        pivot->next_link = return_ql.last;
        return_ql.last = pivot;
    }

    return return_ql;
}