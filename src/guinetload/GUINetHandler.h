#ifndef GUINetHandler_h
#define GUINetHandler_h
//---------------------------------------------------------------------------//
//                        GUINetHandler.h -
//  The XML-Handler for building networks within the gui-version derived
//      from NLHandlerBuilder
//                           -------------------
//  project              : SUMO - Simulation of Urban MObility
//  begin                : Sept 2002
//  copyright            : (C) 2002 by Daniel Krajzewicz
//  organisation         : IVF/DLR http://ivf.dlr.de
//  email                : Daniel.Krajzewicz@dlr.de
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
//---------------------------------------------------------------------------//
// $Log$
// Revision 1.3  2003/07/07 08:13:15  dkrajzew
// first steps towards the usage of a real lane and junction geometry implemented
//
// Revision 1.2  2003/06/18 11:08:05  dkrajzew
// new message and error processing: output to user may be a message, warning or an error now; it is reported to a Singleton (MsgHandler); this handler puts it further to output instances. changes: no verbose-parameter needed; messages are exported to singleton
//
// Revision 1.1  2003/02/07 10:38:19  dkrajzew
// updated
//
//


/* =========================================================================
 * included modules
 * ======================================================================= */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif // HAVE_CONFIG_H

#include <netload/NLNetHandler.h>


/* =========================================================================
 * class declarations
 * ======================================================================= */
class AttributeList;
class NLContainer;


/* =========================================================================
 * class definitions
 * ======================================================================= */
/**
 * This SAX-Handler overrides some methods of the NLNetHandler, the original
 * network description handler in order to be used together with a GUIContainer
 * and allow instantiations of gui versions of the microsimulation artifacts
 */
class GUINetHandler : public NLNetHandler {
public:
    /// standard constructor
    GUINetHandler(const std::string &file,
        NLContainer &container);

    /// standard destructor
    ~GUINetHandler();

protected:
    /** called on the occurence of the beginning of a tag;
        this method */
    void myStartElement(int element, const std::string &name,
        const Attributes &attrs);

    /** called when simple characters occure; this method */
    void myCharacters(int element, const std::string &name,
        const std::string &chars);

private:
    /// adds information about the source and the destination junctions
    void addSourceDestinationInformation(const Attributes &attrs);

    void addJunctionShape(const std::string &chars);

    void addLaneShape(const std::string &chars);


private:
    /** invalid copy constructor */
    GUINetHandler(const GUINetHandler &s);

    /** invalid assignment operator */
    GUINetHandler &operator=(const GUINetHandler &s);
};

/**************** DO NOT DECLARE ANYTHING AFTER THE INCLUDE ****************/
//#ifndef DISABLE_INLINE
//#include "GUINetHandler.icc"
//#endif

#endif

// Local Variables:
// mode:C++
// End:

