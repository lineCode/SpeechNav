/****************************************************************************
**
** Qtitan Library by Developer Machines (Advanced OfficeStyle for Qt)
** 
** Copyright (c) 2009-2012 Developer Machines (http://www.devmachines.com)
**           ALL RIGHTS RESERVED
** 
**  The entire contents of this file is protected by copyright law and
**  international treaties. Unauthorized reproduction, reverse-engineering
**  and distribution of all or any portion of the code contained in this
**  file is strictly prohibited and may result in severe civil and 
**  criminal penalties and will be prosecuted to the maximum extent 
**  possible under the law.
**
**  RESTRICTIONS
**
**  THE SOURCE CODE CONTAINED WITHIN THIS FILE AND ALL RELATED
**  FILES OR ANY PORTION OF ITS CONTENTS SHALL AT NO TIME BE
**  COPIED, TRANSFERRED, SOLD, DISTRIBUTED, OR OTHERWISE MADE
**  AVAILABLE TO OTHER INDIVIDUALS WITHOUT WRITTEN CONSENT
**  AND PERMISSION FROM DEVELOPER MACHINES
**
**  CONSULT THE END USER LICENSE AGREEMENT FOR INFORMATION ON
**  ADDITIONAL RESTRICTIONS.
**
****************************************************************************/
#ifndef QTN_OFFICESTYLE_H
#define QTN_OFFICESTYLE_H

#include <QPalette>
#include <QStylePlugin>

#include "QtnCommonStyle.h"

#include "QtitanDef.h"

class QMainWindow;
namespace Qtitan
{
    class RibbonGalleryItem;
    class OfficeStylePrivate;

    /* OfficeStyle */
    class QTITAN_EXPORT OfficeStyle : public CommonStyle
    {
        Q_OBJECT
        Q_ENUMS(OptionsStyle)
        Q_PROPERTY(OptionsStyle optionStyle READ getOptionStyle WRITE setOptionStyle)
    public:
        enum OptionsStyle
        {
            OS_OFFICE2007BLUE,
            OS_OFFICE2007BLACK,
            OS_OFFICE2007SILVER,
            OS_OFFICE2007AQUA,
            OS_WINDOWS7SCENIC,
            OS_OFFICE2010SILVER,
            OS_OFFICE2010BLUE,
            OS_OFFICE2010BLACK,
        };

    public:
        OfficeStyle();
        OfficeStyle(QMainWindow* mainWindow);
        virtual ~OfficeStyle();

    public:
        virtual void setOptionStyle(OptionsStyle style);
        OptionsStyle getOptionStyle() const;

    public:
        virtual void polish(QApplication* );
        virtual void polish(QWidget* widget);
        virtual void polish(QPalette& palette);
        virtual void unpolish(QApplication*);
        virtual void unpolish(QWidget* widget);

    public:
        virtual QSize sizeFromContents(ContentsType ct, const QStyleOption* opt, const QSize& contentsSize, const QWidget* widget = Q_NULL) const;
        virtual QRect subControlRect(ComplexControl cc, const QStyleOptionComplex* opt, SubControl sc, const QWidget* widget) const;
        virtual int   pixelMetric(PixelMetric pm, const QStyleOption* option = Q_NULL, const QWidget* widget = Q_NULL) const;
        virtual int   styleHint(StyleHint hint, const QStyleOption* opt = Q_NULL, const QWidget* widget = Q_NULL, QStyleHintReturn *returnData = Q_NULL) const;

    protected:
        virtual bool drawWorkspace(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawWidget(const QStyleOption*, QPainter*, const QWidget*) const;

        // for QForm
        virtual bool drawFrameTabWidget(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawShapedFrame(const QStyleOption*, QPainter*, const QWidget*) const;

        // for stausBar
        virtual bool drawPanelStatusBar(const QStyleOption*, QPainter*, const QWidget*) const;

        // for menuBar
        virtual bool drawMenuBarEmptyArea(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawPanelMenu(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawMenuBarItem(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawIndicatorMenuCheckMark(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawMenuItem(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawFrameMenu(const QStyleOption* opt, QPainter* p, const QWidget* w) const;

        // for toolBar
        virtual bool drawToolBar(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawToolButtonLabel(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawPanelButtonTool(const QStyleOption*, QPainter*, const QWidget*) const; 
        virtual bool drawToolButton(const QStyleOption*, QPainter*, const QWidget*) const; 
        virtual bool drawGroupControlEntry(const QStyleOption*, QPainter*, const QWidget*) const { return false; }
        virtual bool drawIndicatorToolBarHandle(const QStyleOption*, QPainter*, const QWidget*) const;
        // for Buttons
        virtual bool drawIndicatorToolBarSeparator(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawPanelButtonCommand(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawIndicatorCheckRadioButton(PrimitiveElement element, const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawFrameDefaultButton(const QStyleOption*, QPainter*, const QWidget*) const;
        // for SizeGrip
        virtual bool drawSizeGrip(const QStyleOption*, QPainter*, const QWidget*) const; 
        // for Slider
        virtual bool drawSlider(const QStyleOptionComplex* opt, QPainter* p, const QWidget* w) const;

        // for ScrollBar
        virtual bool drawScrollBar(const QStyleOptionComplex* opt, QPainter* p, const QWidget* w) const;
        virtual bool drawScrollBarLine(ControlElement element, const QStyleOption* opt, QPainter* p, const QWidget* w) const;
        virtual bool drawScrollBarSlider(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawScrollBarPage(ControlElement element, const QStyleOption*, QPainter*, const QWidget*) const;
        // for editors
        virtual bool drawControlEdit(const QStyleOption* opt, QPainter* p, const QWidget* w) const;
        virtual bool drawFrameLineEdit(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawComboBox(const QStyleOptionComplex* opt, QPainter* p, const QWidget* w) const;
        // for DockWidget
        virtual bool drawDockWidgetTitle(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawIndicatorDockWidgetResizeHandle(const QStyleOption*, QPainter*, const QWidget*) const;
        // MDI
        virtual bool drawMdiControls(const QStyleOptionComplex*, QPainter*, const QWidget*) const;
        // for TabBar
        virtual bool drawTabBarTab(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawTabBarTabShape(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawTabBarTabLabel(const QStyleOption*, QPainter*, const QWidget*) const;
        // for SpinBox
        virtual bool drawSpinBox(const QStyleOptionComplex*, QPainter*, const QWidget*) const;
        // for ProgressBar
        virtual bool drawProgressBarGroove(const QStyleOption*, QPainter*, const QWidget*) const;
        // for ToolBox
        virtual bool drawToolBoxTab(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawToolBoxTabShape(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawToolBoxTabLabel(const QStyleOption*, QPainter*, const QWidget*) const;
        // for ViewItem
        virtual bool drawItemViewItem(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawPanelItemViewItem(const QStyleOption*, QPainter*, const QWidget*) const;
        //
        virtual bool drawHeader(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawHeaderSection(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawHeaderEmptyArea(const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawIndicatorHeaderArrow(const QStyleOption*, QPainter*, const QWidget*) const;

        // shared
        virtual void drawDropDownGlyph(QPainter*, QPoint pt, bool selected, bool popuped, bool enabled, bool vert) const;
        virtual bool drawIndicatorArrow(PrimitiveElement, const QStyleOption*, QPainter*, const QWidget*) const;
        virtual bool drawPanelTipLabel(const QStyleOption*, QPainter*, const QWidget*) const;

        virtual void drawRectangle(QPainter* p, const QRect& rect, bool selected, bool pressed, bool enabled, 
            bool checked, bool popuped, BarType barType, BarPosition barPos) const;

        virtual void drawLabelGallery(QPainter* p, RibbonGalleryItem* item, const QRect& rect);
        virtual QColor getTextColor(bool selected, bool pressed, bool enabled, bool checked, bool popuped, BarType barType, BarPosition barPosition) const;

    protected:
        QString getStyle(const QString& str) const;
        bool isStyle2010() const;

    protected:
        virtual QPixmap cached(const QString &img) const;
        virtual QWidgetList getAllWidgets() const;

    protected:
        virtual bool eventFilter(QObject* watched, QEvent* event);

    protected:
        // [Window]
        QColor    m_clrFrame;
        QColor    m_clr3DFace;
        QColor    m_clrFrameBorderActive0;
        QColor    m_clrFrameBorderActive1;
        QColor    m_clrFrameBorderActive2;
        QColor    m_clrFrameBorderActive3;

        QColor    m_clrFrameBorderInactive0;
        QColor    m_clrFrameBorderInactive1;
        QColor    m_clrFrameBorderInactive2;
        QColor    m_clrFrameBorderInactive3;

        QColor    m_clrHighlightBorder;
        QColor    m_clrHighlightPushedBorder;
        QColor    m_clrHighlightCheckedBorder;
        QColor    m_clrHighlightPushed;
        QColor    m_clrHighlightChecked;
        QColor    m_clrHighlight;

        QColor    m_clrFrameCaptionTextInActive;
        QColor    m_clrFrameCaptionTextActive;

        QColor    m_clrTabNormalText;
        QColor    m_clrHighlightText;
        QColor    m_clrSelectedText;
        QColor    m_clrToolBarText;
        QColor    m_clrToolBarGrayText;
        QColor    m_clrMenuPopupGripperShadow;

        QColor    m_clrTooltipLight;
        QColor    m_clrTooltipDark;
        QColor    m_clrTooltipBorder;

        // [Workspace]
        QColor    m_clrAppWorkspace;
        QColor    m_clrWorkspaceClientTop;
        QColor    m_clrWorkspaceClientMiddle;
        QColor    m_clrWorkspaceClientBottom;

        // [Edit]
        QColor    m_clrControlEditNormal;
        QColor    m_clrMenuPopupText;
        QColor    m_clrMenuGripper;

        QColor    m_clrMenuBarGrayText;
        QColor    m_clrHighlightDisabledBorder;
        QColor    m_clrMenubarFace;

        // [DockingPane]
        QPalette  m_palNormalCaption;
        QColor    m_clrNormalCaptionText;
        QPalette  m_palActiveCaption;
        QColor    m_clrActiveCaptionText;
        QPalette  m_palSplitter;

        // [StatusBar]
        QColor    m_clrStatusBarText;
        QColor    m_clrStatusBarShadow;
        QPalette  m_palStatusBarTop;
        QPalette  m_palStatusBarBottom;

        // [Controls]
        QColor    m_crBorderShadow;
        QColor    m_tickSlider;

        // [Toolbar]
        QColor m_clrEditCtrlBorder;
        QColor m_clrMenuBarText;
        QColor m_ToolbarGripper;
        QColor m_clrControlGallerySelected;
        QColor m_clrControlGalleryNormal;
        QColor m_clrControlGalleryBorder;
        QColor m_clrControlGalleryLabel;
        QColor m_clrDockBar;
        QColor m_clrMenubarBorder;
        QColor m_clrToolbarFace;
        QColor m_clrToolbarSeparator;

        // [ShortcutBar]
        QColor m_clrShortcutItemShadow;

        // [PopupControl]
        QColor m_clrBackgroundLight;
        QColor m_clrBackgroundDark;
        QColor m_clrCaptionLight;
        QColor m_clrCaptionDark;

        QPalette m_clrCommandBar;
        QPalette m_clrPopupControl;
        QPalette m_palLunaSelected;
        QPalette m_palLunaPushed;
        QPalette m_palLunaChecked;

        // [ReportControl]
        QPalette m_palGradientColumn;
        QPalette m_palGradientColumnPushed;
        QColor m_clrColumnSeparator;
        QColor m_clrGridLineColor;

    private:
        friend class RibbonGalleryItem;
        Q_DISABLE_COPY(OfficeStyle)
        QTN_DECLARE_PRIVATE(OfficeStyle)
    };

    /* OfficeStylePlugin */
    class OfficeStylePlugin : public QStylePlugin
    {
        Q_OBJECT
    public: // overrides
        QStringList keys() const;
        QStyle* create(const QString& key);
    };

    typedef Qtitan::OfficeStyle Office2007Style;
}; //namespace Qtitan



#endif // QTN_OFFICESTYLE_H
