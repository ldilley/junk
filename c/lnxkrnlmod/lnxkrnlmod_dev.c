/* lnxkrnlmod_dev.c */

/*
 * An example Linux kernel module to demonstrate I/O via a device
 */

#include <asm/uaccess.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/rtc.h>
#include <linux/time.h>
#include <linux/vmalloc.h>

#define MSG_SIZE 64

const char *MODULE_NAME = "lnxkrnlmod_dev";
const char *DEVICE_NAME = "lnxkrnlmod";

MODULE_AUTHOR("Lloyd Dilley");
MODULE_DESCRIPTION("An example Linux kernel module to demonstrate I/O via a device");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");
/* MODULE_SUPPORTED_DEVICE() is currently unused, but may be supported in the future. */
MODULE_SUPPORTED_DEVICE(DEVICE_NAME); /* /dev entry */

/* Function prototypes for device file operations */
static int device_open(struct inode *in, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);

static int major_num;             /* /dev file major number */
static int device_open_count = 0; /* amount of file operations taking place on device */
static char *msg_buffer = NULL;   /* contains read/written message contents */

/* Structure of device file operations tied to functions */
static struct file_operations file_ops =
{
  .read = device_read,
  .write = device_write,
  .open = device_open,
  .release = device_release
};

/* Called when device is accessed */
static int device_open(struct inode *inode, struct file *file)
{
  if(device_open_count)
  {
    printk(KERN_WARNING "%s->%s(): EBUSY encountered on /dev/%s.\n", MODULE_NAME, __func__, DEVICE_NAME);
    return -EBUSY;
  }
 device_open_count++;
 try_module_get(THIS_MODULE);
 return 0;
}

/* Called when device use is relinquished */
static int device_release(struct inode *inode, struct file *file)
{
  device_open_count--;     /* unless device_open_count is zero, module cannot be unloaded! */
  module_put(THIS_MODULE);
  return 0;
}

/* Called when device is read from */
static ssize_t device_read(struct file *flip, char *buffer, size_t len, loff_t *offset)
{
  int bufflen = strlen(msg_buffer);
  /* Used to determine how much data left to read */
  ssize_t bytes = len < (bufflen - (*offset)) ? len : (bufflen - (*offset));
  if(copy_to_user(buffer, msg_buffer, bytes))
  {
    printk(KERN_ERR "%s->%s(): EFAULT during read from /dev/%s.\n", MODULE_NAME, __func__, DEVICE_NAME);
    return -EFAULT;
  }
  (*offset) += bytes;
  printk(KERN_INFO "%s->%s(): %zu read from /dev/%s.\n", MODULE_NAME, __func__, bytes, DEVICE_NAME);
  return bytes;
}

/* Called when device is written to */
static ssize_t device_write(struct file *flip, const char *buffer, size_t len, loff_t *offset)
{
  /* Uncomment the code below to make the device read only */
  /*printk(KERN_WARNING "%s->%s(): /dev/%s is a read-only device (EINVAL).\n", MODULE_NAME, __func__, DEVICE_NAME);
  return -EINVAL;*/

  if(msg_buffer)
    vfree(msg_buffer);
  msg_buffer = (char *)vmalloc((sizeof(char) + 1) * len);
  if(!msg_buffer)
  {
    printk(KERN_ERR "%s->%s(): ENOMEM during write to /dev/%s.\n", MODULE_NAME, __func__, DEVICE_NAME);
    return -ENOMEM;
  }
  if(!strncpy_from_user(msg_buffer, buffer, len))
  {
    printk(KERN_ERR "%s->%s(): EFAULT during write to /dev/%s.\n", MODULE_NAME, __func__, DEVICE_NAME);
    return -EFAULT;
  }
  msg_buffer[len] = '\0'; /* append null terminator */
  printk(KERN_INFO "%s->%s(): %zu written to /dev/%s.\n", MODULE_NAME, __func__, len, DEVICE_NAME);
  return len;
}

static int __init lnxkrnlmod_dev_init(void)
{
  int len = 0;
  struct timeval time;
  unsigned long local_time;
  struct rtc_time tm;
  char time_output[MSG_SIZE];

  /* Determine current time */
  do_gettimeofday(&time);
  local_time = (u32)(time.tv_sec - (sys_tz.tz_minuteswest * 60));
  rtc_time_to_tm(local_time, &tm);

  snprintf(time_output, MSG_SIZE, "Kernel module loaded on: %02d/%02d/%04d %02d:%02d:%02d UTC\n", tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
  len = strlen(time_output);
  msg_buffer = (char *)vmalloc((sizeof(char) + 1) * len);
  if(!msg_buffer)
  {
    printk(KERN_ERR "%s->%s(): ENOMEM during module init.\n", MODULE_NAME, __func__);
    return -ENOMEM;
  }
  strncpy(msg_buffer, time_output, len);
  msg_buffer[len] = '\0'; /* append null terminator */

  /* Determine character device major number */
  major_num = register_chrdev(0, DEVICE_NAME, &file_ops);
  if(major_num < 0)
  {
    printk(KERN_ERR "%s->%s(): Unable to register /dev/%s with major number: %d\n", MODULE_NAME, __func__, DEVICE_NAME, major_num);
    return major_num;
  }
  else
  {
    printk(KERN_INFO "%s->%s(): Kernel module loaded using /dev/%s with major number: %d\n", MODULE_NAME, __func__, DEVICE_NAME, major_num);
  }
  return 0;
}

static void __exit lnxkrnlmod_dev_exit(void)
{
  vfree(msg_buffer);
  printk(KERN_INFO "%s->%s(): vfree(msg_buffer)\n", MODULE_NAME, __func__);
  unregister_chrdev(major_num, DEVICE_NAME);
  printk(KERN_INFO "%s->%s(): Unregistered /dev/%s with major number: %d\n", MODULE_NAME, __func__, DEVICE_NAME, major_num);
  printk(KERN_INFO "%s->%s(): Kernel module unloaded.\n", MODULE_NAME, __func__);
  return;
}

module_init(lnxkrnlmod_dev_init);
module_exit(lnxkrnlmod_dev_exit);
