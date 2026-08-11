#include <linux/module.h>
#include <linux/pci.h>
#include <linux/io.h>

#define MY_VENDOR_ID   0x1234
#define MY_DEVICE_ID   0x5678

struct my_pci_dev {
    struct pci_dev *pdev;
    void __iomem *bar0;
};

/* PCI Device Table */
static const struct pci_device_id my_pci_ids[] = {
    { PCI_DEVICE(0x1c5c, 0x1f69) },
    { 0, }
};

MODULE_DEVICE_TABLE(pci, my_pci_ids);

/* Probe Function */
static int my_pci_probe(struct pci_dev *pdev,
                        const struct pci_device_id *id)
{
    struct my_pci_dev *dev;
    int ret;
    u32 value;

    printk(KERN_INFO "PCI Device Found\n");

    ret = pci_enable_device(pdev);
    if (ret)
        return ret;

    ret = pci_request_regions(pdev, "my_pci_driver");
    if (ret) {
        pci_disable_device(pdev);
        return ret;
    }

    pci_set_master(pdev);

    dev = kzalloc(sizeof(*dev), GFP_KERNEL);
    if (!dev) {
        pci_release_regions(pdev);
        pci_disable_device(pdev);
        return -ENOMEM;
    }

    dev->pdev = pdev;

    dev->bar0 = pci_iomap(pdev, 0, 0);
    if (!dev->bar0) {
        kfree(dev);
        pci_release_regions(pdev);
        pci_disable_device(pdev);
        return -ENOMEM;
    }

    pci_set_drvdata(pdev, dev);

    /* Read Register Offset 0x00 */
    value = readl(dev->bar0);
    printk(KERN_INFO "Register Value = 0x%x\n", value);

    /* Write Register Offset 0x04 */
    writel(0x12345678, dev->bar0 + 0x04);

    printk(KERN_INFO "PCI Driver Initialized\n");

    return 0;
}

/* Remove Function */
static void my_pci_remove(struct pci_dev *pdev)
{
    struct my_pci_dev *dev = pci_get_drvdata(pdev);

    printk(KERN_INFO "Removing PCI Driver\n");

    pci_iounmap(pdev, dev->bar0);

    pci_release_regions(pdev);

    pci_disable_device(pdev);

    kfree(dev);
}

/* PCI Driver Structure */
static struct pci_driver my_pci_driver = {
    .name = "my_pci_driver",
    .id_table = my_pci_ids,
    .probe = my_pci_probe,
    .remove = my_pci_remove,
};

/* Module Init */
static int __init my_init(void)
{
    printk(KERN_INFO "Loading PCI Driver\n");
    return pci_register_driver(&my_pci_driver);
}

/* Module Exit */
static void __exit my_exit(void)
{
    pci_unregister_driver(&my_pci_driver);
    printk(KERN_INFO "PCI Driver Unloaded\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Simple PCI Driver");
