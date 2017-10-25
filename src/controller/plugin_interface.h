#ifndef PLUGIN_CONNECTOR_H
#define PLUGIN_CONNECTOR_H

#include <QString>
#include <QWidget>

#include "../view/canvas_image_label.h"
#include "../model/picture.h"
#include "../model/lut.h"

struct plugin_metainfo {
  QString name     = "default plugin name";
  QString category = "default plugin category";
  bool can_work_without_gui = false;
  bool no_gui = false;
  bool can_preview = false;
  bool require_lut = false;
  bool require_image_canvas = false;
};

class PluginView : public QWidget {
  Q_OBJECT
public:
  PluginView (QWidget* parent) : QWidget (parent) {}
};

class PluginModel {
protected:
  picture* backup_image;
  picture* original_image;
public:
  PluginModel () :
    backup_image (nullptr),
    original_image (nullptr)
  {}
  void set_image (picture* pic) {
    backup_image = pic->make_copy();
    original_image = pic;
  }
  picture* get_image ()   { return original_image;                      }
  void restore_backup ()  { original_image->restore_from(backup_image); }
  ~PluginModel () {
    delete backup_image;
    original_image = nullptr;
    backup_image = nullptr;
  }
};

class PluginModelLut : public PluginModel{
protected:
  LUT* lut;
public:
  LUT* get_lut ()         { return lut;                                 }
  void set_lut (LUT* l)   { lut = l;                                    }  
};

class PluginModelCanvas : public PluginModel {
protected:
  image_canvas* slct_pixmap;
  canvas_image_label* label;
public:
  inline image_canvas* get_selectable_pixmap () { return slct_pixmap; }
  virtual void create_selectable_pixmap (QPixmap& pix) {}
  void set_label (canvas_image_label* lbl) { label = lbl; }
  canvas_image_label* get_label () { return label; }
};

class PluginController: public QObject {
  Q_OBJECT
private:
  QWidget* view;
  PluginModel* model;
public:
  PluginController (QWidget* vw, PluginModel* mdl) :
    view (vw),
    model (mdl)
  {
    connect ((PluginView*)view,SIGNAL(update_inform()),
             this,SIGNAL(update_inform()));
  }  
  virtual bool operator () (picture* image, LUT* lut) = 0;
  virtual bool operator () (picture* image, canvas_image_label* canvas) = 0;
signals:
  virtual void update_inform () = 0;
};

class PluginInterface {
protected:
  // Información para los menús
  plugin_metainfo meta_info;
  // Contenido
  QWidget* view;
  QObject* ctrller;
  PluginModel* mdl;  
public:
  PluginInterface () :
    view (nullptr),
    ctrller (nullptr),
    mdl (nullptr)
  {}
  virtual void instance () = 0;
  const plugin_metainfo& get_meta_info ()     { return meta_info; }
        QWidget* get_view ()                  { return view;      }
  const QObject* get_controller ()            { return ctrller;   }
  void uninstance () {
    close ();
    if (ctrller != nullptr) { delete ctrller; ctrller  = nullptr; }
    if (mdl != nullptr)     { delete mdl;     mdl      = nullptr; }
    if (view != nullptr)    { delete view;    view     = nullptr; }
  }
protected:
  virtual void close () = 0;
};

#define PluginInterface_iid "P"

Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)

#endif // PLUGIN_CONNECTOR_H
