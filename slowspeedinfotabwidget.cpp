#include "slowspeedinfotabwidget.h"

SlowSpeedInfoTabWidget::SlowSpeedInfoTabWidget(QWidget *parent) :
    QTabWidget(parent) {

    userNetSlowSpeedInfo = new UserInfoDisplay(User_Net_Slow_Speed_Display);
    userRedisQueueInfo = new UserInfoDisplay(User_Redis_Queue_Display);
    addTab(userNetSlowSpeedInfo, "用户达量降速会话信息");
    addTab(userRedisQueueInfo, "达量降速REDIS队列信息");
}
