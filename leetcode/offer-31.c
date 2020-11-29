/**剑指offer31 栈的压入弹出序列，利用一个辅助栈**/
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    int* stack = (int *) malloc (sizeof(int) * pushedSize); //辅助栈，
    int top = -1, p1 = 0, p2 = 0;  //-1代表空栈, p1 p2都指向第一个元素
    while(p1 < pushedSize) {
        stack[top++] = pushed[p1++];  //第一轮将第一个元素入栈，top++, p1++
        while(top != -1 && stack[top] == popped[p2]) {  //比较此时的栈顶 stack[top],是否和poped[p2]相等，相等则弹出
            --top; ++p2;  //stack弹出栈顶，同时p2指向下一个元素
        }
    }
    return top==-1;  //stack为空时返回true，否则返回false
}
