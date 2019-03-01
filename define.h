#ifndef DEFINE_H
#define DEFINE_H
#include <QString>

class Global {
  public:
    Global();
    ~Global();

  public:
    static QString gUserName;
    static QString gPassWord;
    static QString gNatsAddr;
    static QString gNatsPort;
    static QString gTagName;
};

// 定义字符串
#define WindowTitle             "广东计费查询工具"
#define IniFileName             "conf.ini"

#define User_Accu_Display            1
#define User_Indep_Balance_Display   2
#define User_Data_Display            3
#define User_Order_Display           4
#define User_Acct_Make_Display       5
#define User_Accu_Combine_Display    6
#define User_Accu_Out_Net_Display    7
#define User_Net_Slow_Speed_Display  8
#define User_Redis_Queue_Display     9
#define User_Redis_Indep_Display     10
#define User_Indep_Log_Display       11
#define User_Indep_Action_Init       12
#define User_Indep_Flow_Init         13
#define User_Balance_Display         14

// 图标动画
#define ICON_36                    ":/resources/tray.ico"
#define ICON_47                    ":/resources/update.ico"
#define ICON_49                    ":/resources/about.ico"
#define ICON_44                    ":/resources/exit.ico"
#define ICON_101                   ":/resources/101.ico"
#define ICON_102                   ":/resources/102.ico"
#define ICON_103                   ":/resources/103.ico"
#define ICON_104                   ":/resources/104.ico"
#define ICON_53                    ":/resources/display.ico"
#define ICON_54                    ":/resources/hide.ico"

#endif // DEFINE_H
