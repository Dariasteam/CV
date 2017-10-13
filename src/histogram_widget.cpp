#include "histogram_widget.h"

histogram_widget::histogram_widget(QWidget *parent) : QTabWidget(parent) {
  addTab(&chart_histogram, TAB1_NAME);
  addTab(&chart_ac_histogram, TAB2_NAME);
}

void histogram_widget::update_charts(histogram hist) {  
  chart_histogram.update(hist.regular_r, hist.regular_g, hist.regular_b);
  chart_ac_histogram.update(hist.acumulated_r, hist.acumulated_g, hist.acumulated_b);
}
