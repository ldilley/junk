/* lnxkrnlmod.c */

/*
 * An example Linux kernel module
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

const char *MODULE_NAME = "lnxkrnlmod";

MODULE_AUTHOR("Lloyd Dilley");
MODULE_DESCRIPTION("A demonstrational kernel module");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");

static void lnxkrnlmod_sum(int x, int y)
{
  printk("%s->%s(%d, %d): %d + %d = %d\n", MODULE_NAME, __func__, x, y, x, y, x + y);
  return;
}
EXPORT_SYMBOL(lnxkrnlmod_sum); /* allows function to be called by other modules */

static int __init lnxkrnlmod_init(void)
{
  printk(KERN_INFO "%s->%s(): Kernel module loaded.\n", MODULE_NAME, __func__);
  return 0;
}

static void __exit lnxkrnlmod_exit(void)
{
  printk(KERN_INFO "%s->%s(): Kernel module unloaded.\n", MODULE_NAME, __func__);
  return;
}

module_init(lnxkrnlmod_init);
module_exit(lnxkrnlmod_exit);
