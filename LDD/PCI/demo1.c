#include <linux/module.h>
#include <linux/pci.h>
#include <linux/io.h>

#define MY_VENDOR_ID 0x1234
#define MY_DEVICE_ID 0x5678

static void __iomem *bar0;

static int my_probe(struct pci_dev *pdev,
                    const struct pci_device_id *id)
{
    int ret;
    u32 value;

    ret = pci_enable_device(pdev);
    if (ret)
        return ret;

    ret = pci_request_regions(pdev, "my_pcie");
    if (ret) {
        pci_disable_device(pdev);
        return ret;
    }

    pci_set_master(pdev);

    bar0 = pci_iomap(pdev, 0, 0);
    if (!bar0) {
        pci_release_regions(pdev);
        pci_disable_device(pdev);
        return -ENOMEM;
    }

    /* Read register at offset 0x00 */
    value = ioread32(bar0);

    pr_info("PCIe Register = 0x%08x\n", value);

    return 0;
}

static void my_remove(struct pci_dev *pdev)
{
    pci_iounmap(pdev, bar0);
    pci_release_regions(pdev);
    pci_disable_device(pdev);
}

static const struct pci_device_id ids[] = {
    { PCI_DEVICE(MY_VENDOR_ID, MY_DEVICE_ID) },
    { 0, }
};

MODULE_DEVICE_TABLE(pci, ids);

static struct pci_driver my_driver = {
    .name = "my_pcie",
    .id_table = ids,
    .probe = my_probe,
    .remove = my_remove,
};

module_pci_driver(my_driver);

MODULE_LICENSE("GPL");
