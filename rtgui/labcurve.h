/*
 *  This file is part of RawTherapee.
 *
 *  Copyright (c) 2004-2010 Gabor Horvath <hgabor@rawtherapee.com>
 *
 *  RawTherapee is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 * 
 *  RawTherapee is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with RawTherapee.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _LABCURVE_H_
#define _LABCURVE_H_

#include <gtkmm.h>
#include <adjuster.h>
#include <toolpanel.h>
#include <curveeditor.h>
#include <mycurve.h>

class LCurve : public Gtk::VBox, public AdjusterListener, public FoldableToolPanel, public CurveListener {

  protected:
	Gtk::ComboBoxText* channel;

	CurveEditorGroup* curveEditorG;
    Adjuster* brightness;
    Adjuster* contrast;
	Adjuster* saturation;
    CurveEditor* lshape;
	CurveEditor* ashape;
    CurveEditor* bshape;
	
	//%%%%%%%%%%%%%%%%
	Gtk::CheckButton* avoidclip;  
    Gtk::CheckButton* enablelimiter;  
    Adjuster* saturationlimiter;
    bool cbAdd;
    sigc::connection  acconn, elconn;
    bool lastACVal, lastELVal;
	//%%%%%%%%%%%%%%%%

    bool brAdd, contrAdd, satAdd;

  public:

    LCurve ();
    ~LCurve ();

    void read           (const rtengine::procparams::ProcParams* pp, const ParamsEdited* pedited=NULL); 
    void write          (rtengine::procparams::ProcParams* pp, ParamsEdited* pedited=NULL);
    void setDefaults    (const rtengine::procparams::ProcParams* defParams, const ParamsEdited* pedited=NULL);
    void setBatchMode   (bool batchMode);
    void setAdjusterBehavior (bool bradd, bool contradd, bool satadd);   

    void curveChanged (CurveEditor* ce);
    void adjusterChanged (Adjuster* a, double newval);
	void avoidclip_toggled ();
    void enablelimiter_toggled ();
    void updateCurveBackgroundHistogram (unsigned* hist);
};

#endif