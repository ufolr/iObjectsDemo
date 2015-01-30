#ifndef MAPTAB_H
#define MAPTAB_H

#include "mapbase_global.h"
#include "..\\..\\interface\mapbaseinterface.h"
#include "tabbar.h"
#include "tabwidget.h"
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

class MapBase : public QWidget , MapBaseInterface
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "{38E64368-2917-4426-8E1B-CC9D72250A25}" FILE "mapbase.json")
	Q_INTERFACES(MapBaseInterface)
public:
	MapBase(QWidget *parent = NULL);
	~MapBase();

	virtual void test();
	//virtual QWidget* getWidget();

	virtual QObject* getObject();
	virtual void setPluginGeometry(const QRect& rect);
	virtual void setPluginGeometry(int ax, int ay, int aw, int ah);
	virtual void setPluginParent(QWidget* parentWidget);
	virtual void showPlugin();
	virtual void raisePlugin();
	virtual void lowerPlugin();
	virtual void resizePlugin(int ax, int ay, int aw, int ah);
	virtual void setPluginWidth(int width);
	virtual void setPluginHeight(int height);
	virtual int pluginWidth();
	virtual int pluginHeight();

	virtual void addCentralWidget(QWidget* map, int tabIndex, QString tabName);
	virtual void setCurrentIndex(int index);
	virtual void loadSkin();

protected:
	void paintEvent(QPaintEvent*);
	void resizeEvent(QResizeEvent*);
private slots:
	void OnChangeDimension(int isTwoDimension);
	//void OnChangeToThreeDimension();
private:
	static const int tabrwidth = 81;
	TabWidget* m_pTabWidget;
	TabBar* m_pTabBar;
	
};

#endif // MAPTAB_H