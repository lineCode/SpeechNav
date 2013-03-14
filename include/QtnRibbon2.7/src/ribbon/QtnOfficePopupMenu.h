/****************************************************************************
**
** Qtitan Library by Developer Machines (Advanced OfficePopupMenu for Qt)
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
#ifndef QTN_OFFICEPOPUPMENU_H
#define QTN_OFFICEPOPUPMENU_H

#include <QMenu>

#include "QtitanDef.h"


namespace Qtitan
{
    class OfficePopupMenuPrivate;
    /* OfficePopupMenu */
    class QTITAN_EXPORT OfficePopupMenu : public QMenu
    {
        Q_OBJECT
        Q_PROPERTY(bool showGripper READ showGripper WRITE setShowGripper)

    public:
        OfficePopupMenu(QWidget* parent = Q_NULL);
        virtual ~OfficePopupMenu();

        static OfficePopupMenu* createPopupMenu(QWidget* parent = Q_NULL);

    public:
        QAction* addWidget(QWidget* widget);

        void setShowGripper(bool show);
        bool showGripper() const;

    public:
        virtual QSize sizeHint() const;

    protected:
        void setWidgetBar(QWidget* widget);

    private Q_SLOTS:
        void aboutToShowBar();

    protected:
        virtual bool event(QEvent* event);
        virtual void paintEvent(QPaintEvent* event);
        virtual void mousePressEvent(QMouseEvent* event);
        virtual void mouseMoveEvent(QMouseEvent* event);
        virtual void mouseReleaseEvent(QMouseEvent* event);
        virtual void moveEvent(QMoveEvent* event);
        virtual void resizeEvent(QResizeEvent* event);

    private:
        friend class RibbonGalleryPrivate;
        QTN_DECLARE_PRIVATE(OfficePopupMenu)
        Q_DISABLE_COPY(OfficePopupMenu)
    };

}; //namespace Qtitan


#endif // QTN_OFFICEPOPUPMENU_H
