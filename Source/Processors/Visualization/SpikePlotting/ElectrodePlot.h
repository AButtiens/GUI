#ifndef ELECTRODE_PLOT_H
#define ELECTRODE_PLOT_H


#include <list>
#include <math.h>
#include "WaveAxes.h"
#include "BaseUIElement.h"
#include "PlotUtils.h"
#include "SimpleKeyEvent.h"


class ElectrodePlot : public BaseUIElement 
{
	
	bool enabled;
    
    bool limitsChanged;
    double limits[1][2];
    
    WaveAxes axes;
    
    
    
    // void zoomAxes(int n, bool xdim, int zoomval);
    // void zoomProjection (int n, bool xdim, int zoomval);
    // void zoomWaveform (int n, bool xdim, int zoomval);
    
    // void panAxes(int n, bool xdim, int panval);
    // void panProjection (int n, bool xdim, int panval);
    // void panWaveform(int n, bool xdim, int panval);
    
    void initLimits();
	
public:
	ElectrodePlot();
	ElectrodePlot(int x, int y,int w,int h);
	~ElectrodePlot();

	void initAxes();
	void redraw();
	void setEnabled(bool enabled);
	bool getEnabled();
	void setPosition(int,int,double,double);

	void getPreferredDimensions(double*, double*);

	int getNumberOfAxes();
    
    void mouseDown(int x, int y);
    
    void mouseDragX(int dx, bool shift, bool ctr);
    void mouseDragY(int dy, bool shift, bool ctr);

    bool processKeyEvent(SimpleKeyEvent k);

    void processSpikeObject(SpikeObject s);
};



#endif
