#include <rtthread.h>

#define SAMPLE_UART_NAME       "uart4"       /* ��Ҫ�������豸 */
static rt_device_t serial;                   /* �豸��� */
//static char str[] = "hello RT-Thread!\r\n";  /* ��Ҫ���͵����� */

void uart_sample(void)
{
    rt_err_t ret = RT_EOK;
    rt_size_t send_len = 0;

    /* ����ϵͳ�еĴ����豸 */
    serial = rt_device_find(SAMPLE_UART_NAME);
    if (!serial)
    {
        rt_kprintf("find %s failed!\n", SAMPLE_UART_NAME);
        return -RT_ERROR;
    }

    /* ���жϽ��ռ���ѯ����ģʽ�򿪴����豸 */
    ret = rt_device_open(serial, RT_DEVICE_FLAG_INT_RX);
    if (ret != RT_EOK)
    {
        rt_kprintf("open device failed\r\n");
        return -RT_ERROR;
    }

    /* �ر��豸 */
    ret = rt_device_close(serial);
    if (ret != RT_EOK)
    {
        rt_kprintf("close device failed\r\n");
        return -RT_ERROR;
    }

    rt_kprintf("serial device test successful\r\n");

    return RT_EOK;
}


