#include "histogram_widget.h"

histogram_widget::histogram_widget(QWidget *parent) : QTabWidget(parent) {
  addTab(&chart_histogram, TAB1_NAME);
  addTab(&chart_ac_histogram, TAB2_NAME);
  addTab(&chart_norm_histogram, TAB3_NAME);
  addTab(&chart_norm_ac_histogram, TAB4_NAME);
}

void histogram_widget::update_charts(histogram hist) {  
  chart_histogram.update(hist.regular);
  chart_ac_histogram.update(hist.acumulated);
  chart_norm_histogram.update(hist.normalized_regular);
  chart_norm_ac_histogram.update(hist.normalized_acumulated);
}
