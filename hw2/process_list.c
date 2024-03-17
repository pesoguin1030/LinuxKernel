#include <linux/init.h>
#include <linux/module.h>
 
//#include <linux/sched/signal.h>
#include <linux/sched.h>
 
MODULE_LICENSE("Dual BSD/GPL");
 
struct task_struct *task;  //Structure defined in sched.h for tasks/processes
 
static int process_list_init(void)
{
	printk(KERN_INFO "%s","LOADING PROCESS_LIST MODULE\n");
	
	for_each_process( task ){  // for_each_process() MACRO for iterating through each task in the os located in linux/sched/signal.h
		printk(KERN_INFO "PID: %d, UID: %d, PROCESS: %s\n", task->pid, __kuid_val(task->cred->uid), task->comm);
	}

	return 0;
}
 
static void process_list_exit(void)
{
	printk(KERN_INFO "%s","REMOVING PROCESS_LIST MODULE\n");
}
 
module_init(process_list_init);
module_exit(process_list_exit);
