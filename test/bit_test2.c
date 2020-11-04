#include <stdio.h>
int store_bit_field(int original_value, int value_to_store, 
    unsigned starting_bit,  unsigned ending_bit);
	
	
int main()
{
	printf("%x\n",store_bit_field(0x0,0x1,4,4));
	printf("%x\n",store_bit_field(0xffff,0x123,15,4));
	printf("%x\n",store_bit_field(0xffff,0x123,13,9));
}


int store_bit_field(int original_value, int value_to_store, 
    unsigned starting_bit,  unsigned ending_bit)
{
	int num, i, mask = 0, unmask = 0;
	int value;
	num = starting_bit - ending_bit + 1;
	i  = ending_bit;
	//计算掩码
	for (i = ending_bit; i <= starting_bit; i++)
        mask = mask | 1 << i;
	
	unmask = ~mask;
	
	original_value &= unmask;
	value_to_store <<= ending_bit;
	
	
	value_to_store &= mask;
	value = value_to_store | original_value;
	
	return value;
	
}
	
	

	
	
	