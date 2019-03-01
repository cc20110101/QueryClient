#ifndef INDEPINFOTABWIDGET_H
#define INDEPINFOTABWIDGET_H

#include <QTabWidget>
#include "userinfodisplay.h"

class IndepInfoTabWidget : public QTabWidget {
    Q_OBJECT
  public:
    explicit IndepInfoTabWidget(QWidget *parent = nullptr);
  private:
    UserInfoDisplay *userMemInfo;
    UserInfoDisplay *userIndepBalanInfo;
    UserInfoDisplay *userBalanInfo;
    UserInfoDisplay *userAccuInfo;
    UserInfoDisplay *userOrderInfo;
    UserInfoDisplay *userAcctMakeInfo;
    UserInfoDisplay *userAccuCombineInfo;
    UserInfoDisplay *userAccuOutNetInfo;
    UserInfoDisplay *userRedisDuplicateInfo;
    UserInfoDisplay *userPlcaIndepLogInfo;
};

#endif // INDEPINFOTABWIDGET_H
