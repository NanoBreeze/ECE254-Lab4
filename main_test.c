/**
  * ECE254 Linux Dynamic Memory Management Lab
  * @file: main_test.c
  * @brief: The main file to write tests of memory allocation algorithms
  */ 

/* includes */
/* system provided header files. You may add more */
#include <stdio.h>

/* non-system provided header files. 
   Do not include more user-defined header files here
 */
#include "mem.h"



int main(int argc, char *argv[])
{


//============== TO RUN THESE TESTS, uncomment one section at a time



//initialize memory too small, expect both returns to be -1
//	int return_wf = worst_fit_memory_init(10);	// initizae 1KB, worst fit
//	int return_bf = best_fit_memory_init(10);	// initizae 1KB, worst fit
//
//	printf("The return_wf is: %d\n", return_wf);
//	printf("The return_bf is: %d\n", return_bf);

	//test can add node: expect 4 nodes, last node not allocated
//		worst_fit_memory_init(1024);
//			void* one_100_wf = worst_fit_alloc(100);
//			void* two_200_wf = worst_fit_alloc(200);
//			void* three_300_wf = worst_fit_alloc(300);
//			void* zero_0_wf = worst_fit_alloc(400);
//			
//			print_all_nodes_information_wf();
//			
//		best_fit_memory_init(1024);
//			void* one_100_bf = best_fit_alloc(100);
//			void* two_200_bf = best_fit_alloc(200);
//			void* three_300_bf = best_fit_alloc(300);
//			void* zero_0_bf = best_fit_alloc(400);
//			
//			print_all_nodes_information_bf();
		
		
	//test deallocation (no coalescence), assuming not deallocating from start or end. Expect the three_wf and three_bf node would be not allocated 
//			worst_fit_memory_init(1024);
//				void* one_wf = worst_fit_alloc(100);
//				void* two_wf = worst_fit_alloc(100);
//				void* three_wf = worst_fit_alloc(100);
//				void* four_wf = worst_fit_alloc(100);
//				void* five_wf = worst_fit_alloc(100);
//				void* six_wf = worst_fit_alloc(100);
//				void* seven_wf = worst_fit_alloc(100);
//	
//				worst_fit_dealloc(three_wf);
//				print_all_nodes_information_wf();
//
//			best_fit_memory_init(1024);
//				void* one_bf = best_fit_alloc(100);
//				void* two_bf = best_fit_alloc(100);
//				void* three_bf = best_fit_alloc(100);
//				void* four_bf = best_fit_alloc(100);
//				void* five_bf = best_fit_alloc(100);
//				void* six_bf = best_fit_alloc(100);
//				void* seven_bf = best_fit_alloc(100);
//	
//				best_fit_dealloc(three_bf);
//				print_all_nodes_information_bf();


	//test deallocation with coalescencing with previous node, assuming not deallocating from start or end. Expect there to be 7 nodes
//			worst_fit_memory_init(1024);
//				void* one_wf = worst_fit_alloc(100);
//				void* two_wf = worst_fit_alloc(100);
//				void* three_wf = worst_fit_alloc(100);
//				void* four_wf = worst_fit_alloc(100);
//				void* five_wf = worst_fit_alloc(100);
//				void* six_wf = worst_fit_alloc(100);
//				void* seven_wf = worst_fit_alloc(100);
//	
//				worst_fit_dealloc(three_wf);
//				worst_fit_dealloc(four_wf);
//				print_all_nodes_information_wf();
//				
//				
//			best_fit_memory_init(1024);
//				void* one_bf = best_fit_alloc(100);
//				void* two_bf = best_fit_alloc(100);
//				void* three_bf = best_fit_alloc(100);
//				void* four_bf = best_fit_alloc(100);
//				void* five_bf = best_fit_alloc(100);
//				void* six_bf = best_fit_alloc(100);
//				void* seven_bf = best_fit_alloc(100);
//	
//				best_fit_dealloc(three_bf);
//				best_fit_dealloc(four_bf);
//				print_all_nodes_information_bf();


//		test deallocation with coalescencing with next node, assuming not deallocating from start or end. Expect there to be 7 nodes
//			worst_fit_memory_init(1024);
//				void* one_wf = worst_fit_alloc(100);
//				void* two_wf = worst_fit_alloc(100);
//				void* three_wf = worst_fit_alloc(100);
//				void* four_wf = worst_fit_alloc(100);
//				void* five_wf = worst_fit_alloc(100);
//				void* six_wf = worst_fit_alloc(100);
//				void* seven_wf = worst_fit_alloc(100);
//
//				worst_fit_dealloc(four_wf);
//				worst_fit_dealloc(three_wf);
//				print_all_nodes_information_wf();
//				
//				
//			best_fit_memory_init(1024);
//				void* one_bf = best_fit_alloc(100);
//				void* two_bf = best_fit_alloc(100);
//				void* three_bf = best_fit_alloc(100);
//				void* four_bf = best_fit_alloc(100);
//				void* five_bf = best_fit_alloc(100);
//				void* six_bf = best_fit_alloc(100);
//				void* seven_bf = best_fit_alloc(100);
//	
//				best_fit_dealloc(four_bf);
//				best_fit_dealloc(three_bf);
//				print_all_nodes_information_bf();


//		test deallocation with coalescencing with next and previous node, assuming not deallocating from start or end. Expect there to be 6 nodes
//			worst_fit_memory_init(1024);
//				void* one_wf = worst_fit_alloc(100);
//				void* two_wf = worst_fit_alloc(100);
//				void* three_wf = worst_fit_alloc(100);
//				void* four_wf = worst_fit_alloc(100);
//				void* five_wf = worst_fit_alloc(100);
//				void* six_wf = worst_fit_alloc(100);
//				void* seven_wf = worst_fit_alloc(100);
//
//				worst_fit_dealloc(three_wf);
//				worst_fit_dealloc(five_wf);
//				worst_fit_dealloc(four_wf);
//				print_all_nodes_information_wf();


//			best_fit_memory_init(1024);
//				void* one_bf = best_fit_alloc(100);
//				void* two_bf = best_fit_alloc(100);
//				void* three_bf = best_fit_alloc(100);
//				void* four_bf = best_fit_alloc(100);
//				void* five_bf = best_fit_alloc(100);
//				void* six_bf = best_fit_alloc(100);
//				void* seven_bf = best_fit_alloc(100);
//	
//				best_fit_dealloc(three_bf);
//				best_fit_dealloc(five_bf);
//				best_fit_dealloc(four_bf);
//				print_all_nodes_information_bf();


//		test external fragmentation, expect 2 blocks to have external fragmentation.
//			worst_fit_memory_init(1024);
//				void* one_wf = worst_fit_alloc(100);
//				void* two_wf = worst_fit_alloc(100);
//				void* three_wf = worst_fit_alloc(100);
//				void* four_wf = worst_fit_alloc(100);
//				void* five_wf = worst_fit_alloc(100);
//				void* six_wf = worst_fit_alloc(100);
//				void* seven_wf = worst_fit_alloc(100);
//				
//				worst_fit_dealloc(five_wf);
//				int external_frag_count_wf = worst_fit_count_extfrag(150);
//				printf("The value of external_frag_count_wf is: %d", external_frag_count_wf);
//
//			best_fit_memory_init(1024);
//				void* one_bf = best_fit_alloc(100);
//				void* two_bf = best_fit_alloc(100);
//				void* three_bf = best_fit_alloc(100);
//				void* four_bf = best_fit_alloc(100);
//				void* five_bf = best_fit_alloc(100);
//				void* six_bf = best_fit_alloc(100);
//				void* seven_bf = best_fit_alloc(100);
//				
//				best_fit_dealloc(five_bf);
//				int external_frag_count_bf = best_fit_count_extfrag(150);
//				printf("The value of external_frag_count_bf is: %d", external_frag_count_bf);



//		test removing head, expect one_wf and one_bf to be unallocated to have is_free = 1
//			worst_fit_memory_init(1024);
//				void* one_wf = worst_fit_alloc(100);
//				void* two_wf = worst_fit_alloc(100);
//				void* three_wf = worst_fit_alloc(100);
//				void* four_wf = worst_fit_alloc(100);
//				void* five_wf = worst_fit_alloc(100);
//				void* six_wf = worst_fit_alloc(100);
//				void* seven_wf = worst_fit_alloc(100);
//				
//				worst_fit_dealloc(one_wf);
//				print_all_nodes_information_wf();

//			best_fit_memory_init(1024);
//				void* one_bf = best_fit_alloc(100);
//				void* two_bf = best_fit_alloc(100);
//				void* three_bf = best_fit_alloc(100);
//				void* four_bf = best_fit_alloc(100);
//				void* five_bf = best_fit_alloc(100);
//				void* six_bf = best_fit_alloc(100);
//				void* seven_bf = best_fit_alloc(100);
//				
//				best_fit_dealloc(one_bf);
//				print_all_nodes_information_bf();



//testing multiple allocation and deallocation, as well as used to compare best fit and worst fit external fragmentations

worst_fit_alloc(1024);

while (1) {
	void* four_1 = worst_fit_alloc(5);
	printf("The return value of four_1 is: %d\n", four_1);
	if (four_1 == 0) {  break; }
	
	void* two_five_six_1 = worst_fit_alloc(256);
	printf("The return value of two_five_six_1 is: %d\n", two_five_six_1);
	if (two_five_six_1 == 0) { break; }
	
	void* eight_1 = worst_fit_alloc(9);
	printf("The return value of eight_1 is: %d\n", eight_1);
	if (eight_1 == 0) { break; }
	
	void* one_two_eight_1= worst_fit_alloc(128);
	printf("The return value of one_two_eight_1 is: %d\n", one_two_eight_1);
	if (one_two_eight_1 == 0) { break; }
	
	void* sixteen_1 = worst_fit_alloc(17);
	printf("The return value of sixteen_1 is: %d\n", sixteen_1);
	if (sixteen_1 == 0) { break; }
	
	void* sixty_four_1 = worst_fit_alloc(65);
	printf("The return value of sixty_four_1 is: %d\n", sixty_four_1);
	if (sixty_four_1 == 0) { break; }
	
	void* thirty_two_1 = worst_fit_alloc(33);
	printf("The return value of thirty_two_1 is: %d\n", thirty_two_1);
	if (thirty_two_1 == 0) { break; }
	
	worst_fit_dealloc(eight_1);
	worst_fit_dealloc(thirty_two_1);
	worst_fit_dealloc(one_two_eight_1);
}


print_all_nodes_information_wf();

int four_wf, eight_wf, sixteen_wf, thirty_two_wf, sixty_four_wf, one_two_eight_wf, two_five_six_wf;

four_wf = worst_fit_count_extfrag(4);
eight_wf = worst_fit_count_extfrag(8);
sixteen_wf = worst_fit_count_extfrag(16);
thirty_two_wf = worst_fit_count_extfrag(32);
sixty_four_wf = worst_fit_count_extfrag(64);
one_two_eight_wf = worst_fit_count_extfrag(128);
two_five_six_wf = worst_fit_count_extfrag(256);



printf("the extern frag for best fit for four bytes is %d\n", four_wf);
printf("the extern frag for best fit for eight bytes is %d\n", eight_wf);
printf("the extern frag for best fit for 16 bytes is %d\n", sixteen_wf);
printf("the extern frag for best fit for 32 bytes is %d\n", thirty_two_wf);
printf("the extern frag for best fit for 64 bytes is %d\n", sixty_four_wf);
printf("the extern frag for best fit for 128 bytes is %d\n", one_two_eight_wf);
                    printf("the extern frag for best fit for 256 bytes is %d\n", two_five_six_wf);

printf("============================================ =======================================================\n");
printf("============================================ BEST FIT================================================\n");
printf("============================================ =======================================================\n");

best_fit_memory_init(1024);
	
while (1) {

	void* four_1 =	best_fit_alloc(5);
	printf("The return value of four_1 is: %d\n", four_1);
	if (four_1 == 0) {  break; }
	
	
	void* two_five_six_1 = best_fit_alloc(256);
  	printf("The return value of two_five_six_1 is: %d\n", two_five_six_1);
	if (two_five_six_1 == 0) { break; }
	
	void* eight_1 = best_fit_alloc(9);
	printf("The return value of eight_1 is: %d\n", eight_1);
	if (eight_1 == 0) { break; }
	
	void* one_two_eight_1 = best_fit_alloc(128);
	printf("The return value of one_two_eight_1 is: %d\n", one_two_eight_1);
	if (one_two_eight_1 == 0) { break; }
	
 	void* sixteen_1 = best_fit_alloc(17);
 	printf("The return value of sixteen_1 is: %d\n", sixteen_1);
	if (sixteen_1 == 0) { break; }

	void* sixty_four_1 = best_fit_alloc(65);
 	printf("The return value of sixty_four_1 is: %d\n", sixty_four_1);
	if (sixty_four_1 == 0) { break; }
	
 	void* thirty_two_1 = best_fit_alloc(33);
 	printf("The return value of thirty_two_1 is: %d\n", thirty_two_1);
	if (thirty_two_1 == 0) { break; }


	best_fit_dealloc(eight_1);
	best_fit_dealloc(thirty_two_1);
	best_fit_dealloc(one_two_eight_1);
}

print_all_nodes_information_bf();

int four_bf, eight_bf, sixteen_bf, thirtytwo_bf, sixtyfour_bf, onetwentyeight_bf, twofiftysix_bf;

four_bf = best_fit_count_extfrag(4);
eight_bf = best_fit_count_extfrag(8);
sixteen_bf = best_fit_count_extfrag(16);
thirtytwo_bf = best_fit_count_extfrag(32);
sixtyfour_bf = best_fit_count_extfrag(64);
onetwentyeight_bf = best_fit_count_extfrag(128);
twofiftysix_bf = best_fit_count_extfrag(256);

printf("the extern frag for best fit for four bytes is %d\n", four_bf);
printf("the extern frag for best fit for eight bytes is %d\n", eight_bf);
printf("the extern frag for best fit for 16 bytes is %d\n", sixteen_bf);
printf("the extern frag for best fit for 32 bytes is %d\n", thirtytwo_bf);
printf("the extern frag for best fit for 64 bytes is %d\n", sixtyfour_bf);
printf("the extern frag for best fit for 128 bytes is %d\n", onetwentyeight_bf);
printf("the extern frag for best fit for 256 bytes is %d\n", twofiftysix_bf);


	return 0;
}





