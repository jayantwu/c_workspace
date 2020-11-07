#define MaxSize 1000

typedef struct {
    int data1[MaxSize];  //入队用
    int data2[MaxSize];  //出队用
    int top1;
    int top2;    
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue *simulationQueue=(MyQueue*)malloc(sizeof(MyQueue));
    simulationQueue->top1=-1;
    simulationQueue->top2=-1;
    memset(simulationQueue->data1,0,MaxSize*sizeof(int));  
    memset(simulationQueue->data2,0,MaxSize*sizeof(int));  
    return simulationQueue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if(obj->top1==MaxSize-1)
        return;   //队列满
    obj->data1[++obj->top1]=x;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    if(obj->top2==-1)
    {
        if(obj->top1==-1)
            return NULL; 
        while(obj->top1!=-1)
        {
            obj->data2[++obj->top2]=obj->data1[obj->top1--];  //当栈2为空同时栈1不为空时，将栈1 的元素出栈并入栈到栈2
        }
    }
    return obj->data2[obj->top2--];      //从栈2出栈  即出队
    
}

/** Get the front element. */ //从栈2弹出的元素就是第一个元素
int myQueuePeek(MyQueue* obj) {
    if(obj->top2==-1)
    {
        if(obj->top1==-1)
            return NULL; 
        while(obj->top1!=-1)
        {
            obj->data2[++obj->top2]=obj->data1[obj->top1--];
        }
    }
    return obj->data2[obj->top2]; 
}

/** Returns whether the queue is empty. */  //栈1和栈2都为空时队列为空
bool myQueueEmpty(MyQueue* obj) {
    if(obj->top2==-1 && obj->top1==-1)
        return true;
    else
        return false;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/

作者：think-b
链接：https://leetcode-cn.com/problems/implement-queue-using-stacks/solution/cyu-yan-shuang-bai-jie-fa-yong-liang-ge-zhan-mo-ni/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。