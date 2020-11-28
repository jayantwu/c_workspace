/***利用双栈实现***/
/***
数据栈  正常入栈出栈
辅助最小栈  当前最小值入栈
**/

#define maxsize 10000
typedef struct {
    int* x_stack;    //数据栈
    int* min_stack;  //最小栈
    int x_top;   //下标
    int min_top;
    int minvalue;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->x_stack = (int*)malloc(maxsize*sizeof(int));
    obj->min_stack = (int*)malloc(maxsize*sizeof(int));
    obj->x_top = obj->min_top = -1;
    obj->minvalue = 0;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    if(obj->x_top <= maxsize)
    {
        if (obj->x_top == -1)
            obj->minvalue = x;
        obj->x_stack[++(obj->x_top)] = x;
        if (x < obj->minvalue)
            obj->minvalue = x;
        obj->min_stack[++(obj->min_top)] = obj->minvalue;

    }
        
}

void minStackPop(MinStack* obj) {
    --(obj->x_top);
    --(obj->min_top);
    if(obj->min_top != -1)  //栈不为空时
        obj->minvalue = obj->min_stack[obj->min_top];//最小元素要更新成最小栈的栈顶元素

}

int minStackTop(MinStack* obj) {
    return obj->x_stack[obj->x_top];
}

int minStackMin(MinStack* obj) {
    return obj->min_stack[obj->x_top];
}

void minStackFree(MinStack* obj) {
    free(obj->x_stack);
    free(obj->min_stack);
    free(obj);

}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackMin(obj);
 
 * minStackFree(obj);
*/