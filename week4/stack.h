#define max 50
typedef int eltype;
typedef eltype stacktype[max];
int top;

void initialize(stacktype stack);
int empty(stacktype stack);
int full(stacktype stack);
void push(eltype el,stacktype stack);
eltype pop (stacktype stack);
