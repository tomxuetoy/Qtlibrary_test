#include <QtCore/QCoreApplication>
#include <QLibrary>
#include <QtDebug>

int main(int argc, char *argv[])
{
    double result;
    QCoreApplication a(argc, argv);
    /* 这里创建一个QLibrary对象,libsum.so在之前创建的，用于求和并返回结果的函数 */
    QLibrary mylib2("SiUSBXp");
    mylib2.load();
    QLibrary mylib("GY7502_USBSPI");
    if(mylib.load())
    {
        /* 用load()来加载DLL成功*/
        qDebug() << "load DLL success!\n";
        typedef double (*OpenFunc)();
        /*用resolve来解析sum2函数*/
        OpenFunc device_open=(OpenFunc)mylib.resolve("GY7502_USBSPI_Open");
        if(device_open)
            /* 解析成功,sum2函数指针不为0,可以调动了 */
            qDebug() << "resolve success!\n";
        else
            qDebug() << "resolve failed!\n";
        /* 测试一下 */
        result = device_open();
        qDebug() << "opening...";
    }
    else
        qDebug() << "load DLL failed!\n";

    a.exit(0);
}
