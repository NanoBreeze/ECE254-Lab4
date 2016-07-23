/**
 * @file memory.c
 * @brief: ECE254 Lab: memory allocation algorithm comparison template file
 * @author: 
 * @date: 2015-11-20
 */

/* includes */
#include <stdio.h> 
#include <stdlib.h> 
#include "mem.h"


/* global varaiables */
node_wf* head_wf;
node_bf* head_bf;


/* Functions */

/* memory initializer */
int best_fit_memory_init(size_t size)
{
	printf("The size of a struct node is: %d\n", sizeof(node_bf));
	
	if(size <= (sizeof(node_bf) + 4)){
		//printf("Size too small");
		return -1;
	}
	// initalize header with size defined by the input
	head_bf = malloc(size);

	printf("The start of the head_bf node is: %d\n", head_bf);

	// checks if malloc failed
	if (!head_bf){
		return -1;
	}
	//sets the head_bf_bf node with information about memory currently initialized
	head_bf -> allocated = 0;
	head_bf -> size = size - sizeof(node_bf);
	head_bf -> next = 0;
	head_bf-> previous = 0;
	
	return 0;
}


/*
Initialize the head_bf Node and set up its values. Also set the global variable size_of_struct_node
*/
int worst_fit_memory_init(size_t size)
{
	
	//sets up the size of the struct point
	
	
	
	size_of_struct_node = sizeof(node_wf);
	printf("The size of a struct node is: %d\n", size_of_struct_node);
	
	//don't allow program to proceed if size is too small, eg, 20bytes
	if (size <= (sizeof(node_wf) + 4)) { return -1;	}
	
	head_wf = malloc(size);
	
	if (head_wf == 0){
//		printf("Unable to initialize. Malloc failed\n");
		return -1;
	}
	
	head_wf->is_free = 1;
	head_wf->next_node = 0;
	head_wf->previous_node = 0;
	head_wf->size_of_this_struct_and_memory_block = size;


//	printf("The address of head_wf is: %d\n", head_wf);
//	printf("It's size is %d\n:", head_wf->size_of_this_struct_and_memory_block);

	return 0;

}

/* memory allocators */
void *best_fit_alloc(size_t size)
{
	size_t size_to_allocate = size;
	// makes sure the size to allocate is modulo of four
	while(size_to_allocate%4 !=0){
		size_to_allocate +=1;
	}
	// makes sure the allocated size also included header space
	size_to_allocate += sizeof(node_bf);
	
	node_bf* current = head_bf;
	node_bf* smallest_node = 0;
	// set the minimum size to ridiculous high value that no one would allocate
	size_t min_size = 99999999;
	// go through the linked list checking if each node does exist first then
	// checking if the node is not allocated, the current minimum size is larger than 
	// the current node size and the size in the node has enough space
	while(current != 0 && min_size >= size_to_allocate){
		if (current -> size >= size_to_allocate && current->size <= min_size && current->allocated == 0){
			// if all conditions met, set the smallest node and the smallest size to the current node
			// size
			min_size = current->size;
			smallest_node = current;
		}
		current = current -> next;
	}
	// if smallest node does not exist, exit
	if(!smallest_node){
		return 0;
	}
	
	//printf("The smallest node address is %d\n", smallest_node);
	
	// Sets the next node address to be the current address of the smallest node
	// plus the header size plus the size of the smallest node after the allocation
	node_bf* node_add = (node_bf*)((size_t)smallest_node + smallest_node->size - size_to_allocate + sizeof(node_bf));

	//printf("The new node size to allocate with head_bfer is %d\n", node_add);

	// if the smallest node does not have pointer to the next node, then smallest node
	// is the tail node and dont need to consider the node after the smallest node for
	// append
	if(smallest_node->next != NULL){
		smallest_node->next->previous = node_add;
		node_add->next = smallest_node->next;
	}
	// append the node to add to the linked list
	node_add-> previous = smallest_node;
	smallest_node->next = node_add;
	
	// sets the node added as an allocated node with its size set by the input of this method
	node_add-> allocated = 1;
	node_add-> size = size_to_allocate - sizeof(node_bf);
	
	// shrinks the smallest node size appropiately
	size_t org_size_smallest_node = smallest_node->size;
	smallest_node->size = org_size_smallest_node - size_to_allocate;
	//printf("The new node address with header is %d\n", node_add);

	// returns the node address plus the header size to get the address of the memory
	return (node_bf*)((size_t)node_add+sizeof(node_bf));
}



/*
(the frame of reference is always with respect to the Node. All sizes and addresses is about the Node and so memory address must be adjusted to talk to Node)
This returns the starting address of a block of memory of appropriate size. 
	If there's not enough memory to allocate, return 0 (like a pointer)
	The amount of memory allocated must be 4-byte aligned, rounding up. 
To allocate, iterate each Node and store a reference of the Node that has is_free set to true and the largest length_of_memory_block value. Call that Node "curent"
	0) If "current" doesn't exist (is 0), then throw error
	a) If the amount of memory requested is more than "current"'s size_of_this_struct_and_memory_block - "size of the Node", then return 0, indicating there's not enough memory to allocate 
	b) If the amount of memory is equal to "current"'s size_of_this_struct_and_memory_block - "size of the Node", then set "current"'s is_free to false and return "current's" address
	c) If the amount of memory is less than "current"'s size_of_this_struct_and_memory_block - "size of the Node", "current" will be occupied
		create a new Node whose next_node is "current"'s next node; previous_node is "current", 
		size_of_this_struct_and_memory_block is "current"'s size_of_this_struct_and_memory_block - "size of current" - memory amount to allocate, and is_free is set to true, 
		and return "current's" address
		set "current"'s next_node to this new node, and current' is_free to false
*/
void *worst_fit_alloc(size_t size)
{
	size_t rounded_size = align_size_to_four_byte(size);
	node_wf* largest_free_node = get_largest_free_node(head_wf);
	
	printf("inside worst_fit_alloc, the largest_free_node's address is %d", largest_free_node);
	
	//0) there are no available free nodes (free memory blocks)
	if (largest_free_node == 0) {
	printf("There is no free nodes\n");
	 return 0; }
	
	//a) 
	if (rounded_size > largest_free_node->size_of_this_struct_and_memory_block){
		printf("There is not enough memory in the largest_free_node. Returning 0\n");
		return 0;
	}
	
	//b)
	else if (rounded_size == largest_free_node->size_of_this_struct_and_memory_block){
		printf("There is just enough memory in the largest_free_node to satisfy rounded_size\n");
		largest_free_node->is_free = 0;
		return (node_wf*) ((size_t) (largest_free_node) + size_of_struct_node); //return address of memory
	}
	
	//c)
	else if (rounded_size + size_of_struct_node < largest_free_node->size_of_this_struct_and_memory_block){

//	else if (rounded_size < get_actual_memory_of_node(largest_free_node)){
		printf("There is ample memory in the largest_free_node to satisfy rounded_size\n");
		node_wf* new_node = (node_wf*) ((size_t) (largest_free_node) + size_of_struct_node + rounded_size);
		new_node->next_node = largest_free_node->next_node;
		new_node->previous_node = largest_free_node;
		new_node->is_free = 1;
		new_node->size_of_this_struct_and_memory_block = largest_free_node->size_of_this_struct_and_memory_block - size_of_struct_node - rounded_size;
		largest_free_node->next_node = new_node;
		largest_free_node->is_free = 0;
		largest_free_node->size_of_this_struct_and_memory_block = size_of_struct_node + rounded_size; 
//		printf("largest_free_node's size is: %d'\n", largest_free_node->size_of_this_struct_and_memory_block);
//		printf("Okay, the returning value in ample spacce is %d: ", (node_wf*) ((size_t) (largest_free_node) + size_of_struct_node));
		return (node_wf*) ((size_t) (largest_free_node) + size_of_struct_node); //return address of memory
	}

}

/* memory de-allocator */
void best_fit_dealloc(void *ptr) 
{
	// makes sure to get the node pointer of the header and not the memory
	node_bf* pointer = (node_bf*) ((size_t)ptr - sizeof(node_bf));
	//printf("the pointer is %d\n", pointer);
	
	// sets nodes to traverse doubly linked list
	node_bf* current;
	node_bf* list = head_bf;
	
	// goes through the linked list to check if the pointer exists
	while(list != 0){
		if (list == pointer) {
			current = list;
			break;
		}
		list = list->next;
	}
	
	//pointer does not exist, exit 
	if(!current){
		//printf("There is no node that starts at the desired address\n");
		return;
	}
	
	//printf("The deallocated node is %d\n", current);
	
	// sets the node as free
	current->allocated = 0;
	
	// gets the previous and next node
	node_bf* previous_node = current -> previous;
	node_bf* next_node = current -> next;
	
	// the next node does not exist but the previous node exists
	// hence the deallocated node is at the tail node and only coalesce
	// if the previous node is free
	if(previous_node !=0 && next_node == 0){
		printf("Deallocate at tail node");
		if(previous_node->allocated == 0){
			previous_node->next = next_node;
			previous_node->size += current->size + sizeof(node_bf);
			
		}
	
	// the previous node does not exist hence the node to deallocate is at head, and only coalesce
	// the next node if it is free
	}else if(previous_node ==0 && next_node !=0){
		printf("Deallocate at head_bf");
		if(next_node->allocated == 0){
			current->next = next_node->next;
			current->size += next_node->size + sizeof(node_bf);
			if(next_node->next != NULL){
				next_node->next->previous = current;
			}
		}	
	// checks if previous node and next node exists	
	}else if(previous_node != 0 && next_node != 0){
		// if previous node is not allocated but the next node is allocated
		// only coalesce the previous node and the deallocated node
		if(previous_node->allocated == 0 && next_node->allocated == 1){
			previous_node->next = next_node;
			previous_node->size += current->size + sizeof(node_bf);
			next_node->previous = previous_node;
			
		// if previous node is allocated but the next node is deallocated
		// then only coalesce the next node and the deallocated node
		}else if(previous_node->allocated == 1 && next_node->allocated == 0){
			current->next = next_node->next;
			current->size += next_node->size + sizeof(node_bf);
			if(next_node->next != NULL){
				next_node->next->previous = current;
			}
		// if both the previous node and next node is deallocated, merge the 
		// the next node, the previous node and the coalesced node
		}else if(previous_node->allocated == 0 && next_node->allocated == 0){

			previous_node->next = next_node->next;
			previous_node->size += current->size + next_node->size + 2*sizeof(node_bf);
			//if the next node is the last node, don't do this because will throw segmentation error
			if (next_node->next){
				next_node->next->previous = previous_node;
			}
		}	
	}
	return;
}



/*
Note the frame of reference is to structs. *ptr points to the memory address of the node and not the actual memory part
Iterate through the Nodes and find the Node whose address matches the desired Node address. If it doesn't exist, throw an error. If it exists, let's call that Node "current", the previous Node "previous", and the next Node "next"
Check if either of "current"'s previous or next nodes have their is_free value set to true. 
If "next" or "previous" don't exist, that's okay, just skip the associated step
	a) If "previous"'s is_free value is false and "next"'s is_free value is false, 
			then set "current"'s is_free value to true
	b) If "previous"'s is_free value is  true and"next"'s  is_free value is false
			set "previous"'s next_node to "current"'s next_node
			add "previous"'s size_of_this_struct_and_memory_block by "current"'s size_of_this_struct_and_memory_block
			free "current"
	c) If "previous"'s is_free value is false and "next"'s is_free value is true
			set "current"'s next_node to be "next"'s next_node
			add "current"'s size_of_this_struct_and_memory_block by "next"'s size_of_this_struct_and_memory_block
			free "next"
	d) If "previous"'s is_free is true and "next"'s is_free is also true
			set "previous"'s next_node to be "next"'s next_node
			add "previous"'s size_of_this_struct_and_memory_block by "current"'s and "next"'s size_of_this_struct_and_memory_block
			free "current" and "next"
*/
void worst_fit_dealloc(void *ptr) 
{
	printf("The value of the head_wf is %d", ptr-size_of_struct_node);
	node_wf* node_to_deallocate = get_node_with_desired_address(head_wf, ptr - size_of_struct_node);
	if (node_to_deallocate == 0) { 
		printf("The desired node doesn't exist");
		return;
	}
	
	node_wf* previous = node_to_deallocate->previous_node;
	node_wf* next = node_to_deallocate->next_node;
	
	//if deallocating the single node in this linked list. This node to deallocate would have already been set to 0, thus, just return
	if (previous == 0 && next ==0) { printf("The previous and next nodes are both 0\n"); return; }
	
	//If the previous node is 0, aka, the node to deallocate is the head_wf. Either free this node to deallocate or coalesce with next node.
	if (previous == 0){
		printf("Inside previous==0 block \n");
		if (next->is_free == 0) { printf("inside next->is_free == 0\n"); node_to_deallocate->is_free = 1; }
		else  {//next->is_free == 1, coallesce
		printf("inside else\n");
					node_to_deallocate->next_node = next->next_node;
					node_to_deallocate->size_of_this_struct_and_memory_block += next->size_of_this_struct_and_memory_block;
					node_to_deallocate->is_free = 1;
					next->next_node->previous_node = node_to_deallocate;
		}
		return;		
	}
	//this is the last node. Either free or coalesce
	if (next == 0) {
		printf("Inside next==0 block \n");
		
		if (previous->is_free == 0) { printf("inside previous->is_free == 0\n"); node_to_deallocate->is_free = 1; }
		
		else  {//previous->is_free == 1, coallesce
			printf("inside else\n");
			previous->size_of_this_struct_and_memory_block += node_to_deallocate->size_of_this_struct_and_memory_block;
			previous->is_free = 1;
		}
		return;	
	}
	
	//Assuming that next and previous nodes are not 0
	//a)
	if ((previous->is_free == 0) && (next->is_free == 0))
	{
		node_to_deallocate->is_free = 1;
	}
	
	//b)
	else if ((previous->is_free == 1) && (next->is_free == 0))
	{
		previous->next_node = node_to_deallocate->next_node;
		previous->size_of_this_struct_and_memory_block += node_to_deallocate->size_of_this_struct_and_memory_block;
		next->previous_node = previous;
		//free(node_to_deallocate);
	}
	
	//c)
	else if ((previous->is_free == 0) && (next->is_free == 1)) 
	{
		node_to_deallocate->next_node = next->next_node;
		node_to_deallocate->size_of_this_struct_and_memory_block += next->size_of_this_struct_and_memory_block;
		node_to_deallocate->is_free = 1;
		//if the next node is the last node, don't do this because will throw segmentation error
		if (next->next_node){
			next->next_node->previous_node = node_to_deallocate;
		}
		
//		free(next);
	}
	
	//d)
	else if ((previous->is_free == 1) && (next->is_free == 1))
	{
		previous->next_node = next->next_node;
		previous->size_of_this_struct_and_memory_block += node_to_deallocate->size_of_this_struct_and_memory_block + next->size_of_this_struct_and_memory_block;
		
		//if the next node is the last node, don't do this because will throw segmentation error
		if (next->next_node){
			next->next_node->previous_node = previous;
		}
//		free (node_to_deallocate);
//		free(next);	
	}
	else
	{
//		printf("This line in deallocation should not happen. No choise available.\n");
	}
	
	return;
}

/* memory algorithm metric utility function(s) */

/* count how many free blocks are less than the input size */ 
int best_fit_count_extfrag(size_t size)
{
	// sets the node to traverse as well as the count of how many memory is fragmented
	node_bf *counter = head_bf;
	int count = 0;
	// traverse the linked list and count the fragmentizations
	while (counter != 0) {
		if (counter->size < size && counter->allocated == 0 && counter->size != 0) {
			count++;
		}
		counter = counter->next;
	}
	return count;
}

int worst_fit_count_extfrag(size_t size)
{
	node_wf* node = head_wf;	
	int free_blocks_of_less_size_count = 0;
	
	while (node != 0){
		if ((node->is_free == 1) && (get_actual_memory_of_node(node) < size) && (get_actual_memory_of_node(node) != 0)){
			free_blocks_of_less_size_count++;
		}
		node = node->next_node;
	}
	
	return free_blocks_of_less_size_count;
}

//=============================== UTILITY FUNCTIONS =======================================


//round size to 4-byte aligned, rounding up
size_t align_size_to_four_byte(size_t size){
	
	size_t rounded_size = 0;
	
	int i;
	for (i = size; i < size+4; i++)
	{
		if (i%4 == 0) {
			rounded_size = i;
			break;
		}
	}
//	printf("The rounded size is: %d\n", rounded_size);
	return rounded_size;
}



//store a reference of the Node that has is_free set to true and the largest length_of_memory_block value.
node_wf* get_largest_free_node(node_wf* node){

	
	node_wf* largest_free_node = 0;
	int largest_size = 0;
	
	 
	
	while(node != 0){
//		printf("Iteration, the node's address is %d\n", node);
		if ((node->is_free == 1) && (node->size_of_this_struct_and_memory_block > largest_size)){
			largest_free_node = node;
		}
		node = node->next_node;
	}
	
	if (largest_free_node == 0)
	{
		return 0;
	}
	else //equivalent to largest_free_node->is_free == 1
	{
		return largest_free_node;
	}
	//initially set largest_free_node to parametered node, thus, we don't know if it is free or not. Must check
//	if (largest_free_node->is_free == 1) { 
//		printf("inside get_largets, return largest\n");
//	}
//	
//	else if (largest_free_node->is_free == 0){ printf("inside get_largest and is 0. \n"); return 0; }
//	else {printf("THIS CODE SHOULD NOT EXECUTE, inside get_largest");
//	}
}



//returns the amount of actual free memory this node holds
int get_actual_memory_of_node(node_wf* node) {
	return node->size_of_this_struct_and_memory_block - size_of_struct_node;
}



//returns a pointer to the Node that starts at the given address
node_wf* get_node_with_desired_address(node_wf* node, void* ptr)
{
	
	while(node != 0){
		if (node == ptr) {
			return node;
		}
		node = node->next_node;
	}
	
	printf("There is no node that starts at the desired address\n");
	return 0;
}


void print_all_nodes_information_wf(){
	node_wf* node = head_wf;
	
	printf("\n========================= PRINTING ALL NODES AND INFO ===========================\n\n");
	
	int node_count = 0;
	
	
	while(node != 0){
		node_count++;
		printf("========== Information about Node %d ========\n ", node_count);
		printf("Current address: %d\n", node);
		printf("Previous node's' address: %d\n", node->previous_node);
		printf("Next node's' address: %d\n", node->next_node);
		printf("size_of_this_struct_and_memory_block: %d\n", node->size_of_this_struct_and_memory_block);
		printf("is_free: %d\n", node->is_free);

		node = node->next_node;
	}
	printf("========== General Stuff ========\n ");
	printf("Total number of nodes: %d\n", node_count);
	printf("Size of a node_wf: %d\n", size_of_struct_node);
	printf(" \n");
}

void print_all_nodes_information_bf(){
	// sets the head_bf node
	node_bf* node = head_bf;
	
	printf("\n========================= PRINTING ALL NODES AND INFO ===========================\n\n");
	
	int node_count = 0;
	
	// traverse the list
	while(node != 0){
		node_count++;
		printf("========== Information about Node %d ========\n ", node_count);
		printf("Current address: %d\n", node);
		printf("Previous node's' address: %d\n", node->previous);
		printf("Next node's' address: %d\n", node->next);
		printf("size_of_this_memory block: %d\n", node->size);
		printf("is_allocated: %d\n", node->allocated);

		node = node->next;
	}
	printf("========== General Stuff ========\n ");
	printf("Total number of nodes: %d\n", node_count);
	printf("Size of a struct node: %d\n\n", sizeof(node_bf));
}

//void print_all_free_nodes_information(){
//		node_wf* node = head;
//	
//	printf("\n========================= PRINTING ALL FREE NODES AND INFO ===========================\n\n");
//	
//	int node_count = 0;
//	
//	
//	while(node != 0){
//		if (node->is_free){
//				node_count++;
//			printf("========== Information about Node %d ========\n ", node_count);
//			printf("Current address: %d\n", node);
//			printf("Previous node's' address: %d\n", node->previous_node);
//			printf("Next node's' address: %d\n", node->next_node);
//			printf("size_of_this_struct_and_memory_block: %d\n", node->size_of_this_struct_and_memory_block);
//			printf("is_free: %d\n", node->is_free);
//		}
//
//		node = node->next_node;
//	}
//	printf("========== General Stuff ========\n ");
//	printf("Total number of free nodes: %d\n", node_count);
//	printf("Size of a node_wf: %d\n", size_of_struct_node);
//	printf(" \n");
//}
//

