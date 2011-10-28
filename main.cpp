#include <QtCore/QCoreApplication>
#include <QLibrary>
#include <QtDebug>

int main(int argc, char *argv[])
{
    double result;
    QCoreApplication a(argc, argv);
    /* ���ﴴ��һ��QLibrary����,libsum.so��֮ǰ�����ģ�������Ͳ����ؽ���ĺ��� */
    QLibrary mylib2("SiUSBXp");
    mylib2.load();
    QLibrary mylib("GY7502_USBSPI");
    if(mylib.load())
    {
        /* ��load()������DLL�ɹ�*/
        qDebug() << "load DLL success!\n";
        typedef double (*OpenFunc)();
        /*��resolve������sum2����*/
        OpenFunc device_open=(OpenFunc)mylib.resolve("GY7502_USBSPI_Open");
        if(device_open)
            /* �����ɹ�,sum2����ָ�벻Ϊ0,���Ե����� */
            qDebug() << "resolve success!\n";
        else
            qDebug() << "resolve failed!\n";
        /* ����һ�� */
        result = device_open();
        qDebug() << "opening...";
    }
    else
        qDebug() << "load DLL failed!\n";

    a.exit(0);
}
