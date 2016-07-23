/**
 * @file memory.h
 * @brief: ECE254 Lab: memory allocators
 * @author: 
 * @date: 2015-11-20
 */

#ifndef MEM_H_
#define MEM_H_

#include <stddef.h>

/* Node */
typedef struct Node {
	struct Node* next_node;
	struct Node* previous_node;
	int size_of_this_struct_and_memory_block; //the size of the memory plus this struct node, in bytes
	//int start_address_of_memory_block; the start address is this node's start + 24 bytes? 
	int is_free;
}node_wf;

typedef struct node {
	int size;     	   // size of memory in node
	int allocated;     // 1 means allocated, 0 means not allocated
	struct node* next; // pointer to next node
	struct node* previous;  // pointer to the previous node
} node_bf;

int size_of_struct_node;




/* memory initializers */
int best_fit_memory_init(size_t size);
int worst_fit_memory_init(size_t size);

/* memory allocators */
void *best_fit_alloc(size_t size);
void *worst_fit_alloc(size_t size);

/* memory de-allocators, immediate coalesce */
void best_fit_dealloc(void *ptr);
void worst_fit_dealloc(void *ptr);

/* memory algorithm metric utility function(s) */

/* count how many contiguous bytes are less than specified bytes. Assume specified bytes refer to pure memory space available */ 
int best_fit_count_extfrag(size_t size);
int worst_fit_count_extfrag(size_t size);

//utility functions

//returns the size that is upwards rounded to 4-bytes
size_t align_size_to_four_byte(size_t size);

//returns a pointer to the Node with largest length and is_free
node_wf* get_largest_free_node(struct Node* h);

//returns the amount of memory this node actually stores: size_of_this_struct_and_memory_block - "size of the Node"
int get_actual_memory_of_node(struct Node* n);

//returns a pointer to the Node that starts at the given address
struct Node* get_node_with_desired_address(struct Node* head_node, 	void* ptr);

//prints the information about every node
void print_all_nodes_information_wf();
void print_all_nodes_information_bf();

//void print_all_free_nodes_information();

#endif // !MEM_H_
