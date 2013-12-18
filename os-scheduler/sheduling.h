typedef struct{
        int running;
        int wait;
        int end;
} Status;
typedef struct Process{
        char pname[256];
        int pTime;
        Status pStatus;
        int pPriority;
        struct Process *next;
} Process;

typedef struct{
        Process *head;
        int maxSize;
} scheduler;

scheduler* create();
int insertProcess(scheduler *queue,Process *process);
int removeProcess(scheduler *queue);
void dispose(scheduler *queue);