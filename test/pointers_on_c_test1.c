/*位操作*/
value = value | 1 << bit_number;   //将指定的位置1

value  = value & ~(1 << bit_number);  //将指定的位清0

value & 1 << bit_number;  //对指定的位进行判断，如果为1则返回1