#include <iostream>

using namespace std;

// create a structure to hold every node of linked list
struct node
{
    // data member to hold the value at a node
    int data;

    // pointer to hold the address of the next node
    struct node* next;
};

// Function : split_linked_list
// Description : divides a linked list into two halves
// Parameters : head -> pointer to head element of linked list to be split
//              first-half -> pointer to hold the first half of split list
//              second_half -> pointer to hold the second half of split list
// Return Value : void
void split_linked_list( struct node* head, struct node** first_half, struct node** second_half )
{
    // this pointer moves through the list 2 nodes at a time.
    // this function returns when this pointer points to the last element
    struct node* end_pointer;

    // this pointer moves through the list 1 node at a time
    // thus when the end_pointer is at last element, this pointer is at middle element,
    // because of its half speed;
    struct node* mid_pointer;

    // set initial position of mid_pointer to first element of linked list
    mid_pointer = head;
    // set initial position of end_pointer to second element
    end_pointer = head->next;

    // repeat until end_pointer doesn't point to last element
    while ( end_pointer->next != NULL )
    {
        // move the end_pointer by one position
        end_pointer = end_pointer->next;

        // if the end_pointer isn't yet pointing to the last element,
        if ( end_pointer->next != NULL )
        {
            // move the end_pointer by one position
            end_pointer = end_pointer->next;
            // move the mid_pointer by one position
            mid_pointer = mid_pointer->next;
        }

    }

    // store the address of first node of linked list as head pointer to first half of divided list
    *first_half = head;
    // store the address of node after mid_pointer as head pointer to second half of divided list
    *second_half = mid_pointer->next;

    // sever the linked list upto the middle element to create 2 lists
    mid_pointer->next = NULL;
}

// Function : merge
// Description : Merges two sorted linked lists such that result is sorted list
// Parameters : first_half -> head pointer to first linked list to be merged
//              second_half -> head pointer to second linked list to be merged
// Return Value : result -> head pointer to sorted and merged linked list
struct node* merge( struct node* first_half, struct node* second_half )
{
    // create a node to store the sorted and merged linked list
    struct node* result = NULL;

    // if first linked list is empty,
    if ( first_half == NULL )
        // return the second linked list
        return second_half;

    // if second linked list is empty,
    if ( second_half == NULL )
        // return the first linked list
        return first_half;

    // if first element of first list is greater than that of the second
    if ( first_half->data < second_half->data )
    {
        // add this element to the result
        result = first_half;

        // recursively compute the remaining elements
        result->next = merge( first_half->next, second_half );
    }
    // if the first element of first list is less than that of the second
    else
    {
        // add this element to the result
        result = second_half;

        // resursively compute the remaining elements
        result->next = merge( first_half, second_half->next );
    }

    // return the computed linked list
    return result;
}

// Function : merge_sort
// Description : Sorts a linked list using merge sort
// Parameters : head -> address of pointer to head element of linked list to be sorted
// Return Value : void
void merge_sort( struct node** head_node )
{
    // create a new node pointing to the head node of list
    struct node* head = *head_node;

    // create a node to point to first half of linked list after splitting
    struct node* first_half;
    // create a node to point to second half of linked list after splitting
    struct node* second_half;

    // If linked list has only 1 or no elements
    if ( ( head == NULL ) || ( head->next == NULL ))
        // exit the code as sorting is not needed
        return;

    // otherwise, split the linked list into two elements
    split_linked_list( *head_node, &first_half, &second_half );

    // recursively sort the first half
    merge_sort( &first_half );
    // recursively sort the second half
    merge_sort( &second_half );

    // merge to two sorted halves and store the result
    *head_node = merge(first_half, second_half);

}

// Function : print_list
// Description : Utility function to print a linked list
// Parameters : head -> head pointer to linked list to be printed
// Return Value : void
void print_list(struct node* head)
{
    // repeat the following until the last element is reached
    while ( head != NULL )
    {
        // print the value stored in current node
        cout << head->data << " ";
        // move the head pointer to next node
        head = head->next;
    }
    // print the endline character to move on to the next line
    cout << "\n";
}

// Function : insert
// Description : insert a new element into the linked list
//               element must be added in reverse order
// Parameters : head -> address to head pointer of linked list
//              element -> data to be added
// Return Value : void
void insert(struct node** head, int element)
{
    // create a new node and allocate space to it
    struct node* new_node = (struct node*) malloc( sizeof(struct node) );

    // add the data to this node
    new_node->data = element;
    // point this element to head
    new_node->next = *head;

    // mark this new node as the head pointer
    *head = new_node;
}

// Function : free_list
// Description : Iteratively frees up all allocated space to linked list
// Parameters : head -> head pointer to linked list to be freed
// Return Value : void
void free_list(struct node* head)
{
    // create a temporary node to hold the address of current node
    struct node* temp;

    // repeat until the last element
    while ( head != NULL )
    {
        // store the current element in the temporary node
        temp = head;

        // point the head to the next element
        head = head->next;

        // deallocate the space of current node
        free(temp);
    }
}
// MAIN FUNCTION
int main()
{
    // variable to hold the number of elements to be added to list
    int length = 10;

    // array containing elements to be added to linked list
    int elements[length] = {35, 63, 99, 85, 59, 76, 92, 46, 34, 67};

    // create a node to act as the reference node to list
    struct node* head = NULL;

    // add all elements from the array to the list
    for ( int i = 0; i < length; ++i )
    {
        // insert the elements into the linked list
        insert(&head, elements[length - i - 1]);
    }

    // print the current linked list
    cout << " Original Linked List : ";
    print_list(head);

    // sort the linked list using merge sort
    merge_sort(&head);

    // print the linked list after sorting
    cout << " After Sorting        : ";
    print_list(head);

    // free up all dynamically allocated memory
    free_list(head);

    return 0;
}
