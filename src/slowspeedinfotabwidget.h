#ifndef SLOWSPEEDINFOTABWIDGET_H
#define SLOWSPEEDINFOTABWIDGET_H

#include <QTabWidget>
#include "userinfodisplay.h"

class SlowSpeedInfoTabWidget : public QTabWidget {
    Q_OBJECT
  public:
    explicit SlowSpeedInfoTabWidget(QWidget *parent = nullptr);
  private:

    UserInfoDisplay *userNetSlowSpeedInfo;
    UserInfoDisplay *userRedisQueueInfo;

};

#endif // SLOWSPEEDINFOTABWIDGET_H
