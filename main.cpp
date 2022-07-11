#include "waze.h"
#include <QtWidgets/QApplication>
#include "Service.h"
#include "QtWidgetsClass.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repo r;
    Service s{r};
    for (auto a : s.get_drivers_serv())
    {
        QtWidgetsClass* w = new QtWidgetsClass{ s,a };
        w->show();
    }
    return a.exec();
}
