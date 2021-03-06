#ifndef __SYS_CONTROL_H__
#define __SYS_CONTROL_H__

class CSysControl	//虚基类
{
public:
	// 状态
	enum {					
		STATE_FORWARD = 0,	//向前
		STATE_BACKWARD,		//向后
		STATE_MOVE_LEFT,	//向左移动
		STATE_MOVE_RIGHT,	//向右移动
		STATE_TURN_UP,		//向上转
		STATE_TURN_DOWN,	//向下转
		STATE_TURN_LEFT,	//向左转
		STATE_TURN_RIGHT,	//向右转
		STATE_CROUCH,		//蹲
		STATE_JUMP,			//跳
		STATE_RUN,			//跑
		STATE_USE,			
		STATE_FIRE,			//开火
		STATE_SAVE,			//保存
		STATE_RESTORE,		//恢复
		STATE_SCREENSHOT,	//屏幕快照
		STATE_AUX_0,		//辅助设备
		STATE_AUX_1,
		STATE_AUX_2,
		STATE_AUX_3,
		STATE_AUX_4,
		STATE_AUX_5,
		STATE_AUX_6,
		STATE_AUX_7,
		STATE_AUX_8,
		STATE_AUX_9,
		STATE_AUX_A,
		STATE_AUX_B,
		STATE_AUX_C,
		STATE_AUX_D,
		STATE_AUX_E,
		STATE_AUX_F,
		NUM_STATES,			
	};
	enum ControlMode		//控制模式，只有键鼠和pad两种方式
	{
		CONTROL_KEYBORAD_MOUSE,
		CONTROL_XPAD360,
	};
	CSysControl() {};
	virtual ~CSysControl() {};

	virtual void Init() = 0;	//初始化
	virtual void Update(float ifps) = 0;	
	virtual void Shutdown() = 0;	//关闭
	virtual int GetState(int state) = 0;	//获取状态
	virtual int ClearState(int state) = 0;		//清除状态
	virtual float GetMouseDX() = 0;	//取得鼠标坐标X
	virtual float GetMouseDY() = 0;	//取得鼠标坐标Y

	virtual void SetMouseGrab(int g) = 0;
	virtual int GetMouseGrab() = 0;

	virtual void SetControlMode(ControlMode mode) = 0;		//设置控制模式
	virtual ControlMode GetControlMode() const = 0;				//获取控制模式
private:
	//本类全是公有函数
};
//extern可以置于变量或者函数前，以标示变量或者函数的定义在别的文件中，提示编译器遇到此变量和函数时在其他模块中寻找其定义
extern CSysControl *g_pSysControl;	//【很多模块中都有其引用】
#endif