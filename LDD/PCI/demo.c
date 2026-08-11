#include <linux/module.h>
#include <linux/pci.h>

#define MY_VENDOR_ID  0x1c5c   /* Example: SK hynix */
#define MY_DEVICE_ID  0x1f69

/* Called when matching PCI device is found */
static int my_pci_probe(struct pci_dev *pdev,
                        const struct pci_device_id *id)
{
    pr_info("PCI Device Found!\n");

    pr_info("Vendor ID : 0x%x\n", pdev->vendor);
    pr_info("Device ID : 0x%x\n", pdev->device);

    return 0;
}

/* Called when device is removed */
static void my_pci_remove(struct pci_dev *pdev)
{
    pr_info("PCI Device Removed\n");
}

/* PCI Device ID Table */
static const struct pci_device_id my_pci_ids[] = {
    { PCI_DEVICE(MY_VENDOR_ID, MY_DEVICE_ID) },
    { 0, }
};

MODULE_DEVICE_TABLE(pci, my_pci_ids);

/* PCI Driver Structure */
static struct pci_driver my_pci_driver = {
    .name     = "my_pci_driver",
    .id_table = my_pci_ids,
    .probe    = my_pci_probe,
    .remove   = my_pci_remove,
};

/* Module Init */
static int __init my_init(void)
{
    pr_info("Registering PCI Driver\n");
    return pci_register_driver(&my_pci_driver);
}

/* Module Exit */
static void __exit my_exit(void)
{
    pci_unregister_driver(&my_pci_driver);
    pr_info("PCI Driver Unregistered\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ChatGPT");
MODULE_DESCRIPTION("Simple PCI Driver Example");
