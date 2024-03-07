#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
 
MODULE_LICENSE("Dual BSD/GPL");
 
/*
 * These lines, although not shown in the book,
 * are needed to make hello.c run properly even when
 * your kernel has version support enabled
 */
 
 
// Module parameters
static int a = 1;
static int b = 1;
static char *c = "not valid string";

// Get parameters from cli
module_param(a, int, S_IRUGO); // S_IRUGO means read-only
module_param(b, int, S_IRUGO);
module_param(c, charp, S_IRUGO);
 
static int hello_p3_init(void)
{
        int i;
        for (i = 0; i < a * b; i++)
                printk(KERN_ALERT "(%s)\n",c);
        return 0;
}
 
static void hello_p3_exit(void)
{
        printk(KERN_ALERT "Hellop3 module unloaded.\n");
}
 
module_init(hello_p3_init);
module_exit(hello_p3_exit);
