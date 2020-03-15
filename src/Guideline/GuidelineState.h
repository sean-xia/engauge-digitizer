/******************************************************************************************************
 * (C) 2019 markummitchell@github.com. This file is part of Engauge Digitizer, which is released      *
 * under GNU General Public License version 2 (GPLv2) or (at your option) any later version. See file *
 * LICENSE or go to gnu.org/licenses for details. Distribution requires prior written permission.     *
 ******************************************************************************************************/

#ifndef GUIDELINE_STATE_H
#define GUIDELINE_STATE_H

#include <QString>

/// Set of possible Guideline states. See class Guideline for more information
enum GuidelineState {
  GUIDELINE_STATE_DEPLOYED_CONSTANT_R_SELECT_EDIT,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_R_SELECT_EDIT_APPEARING,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_R_SELECT_EDIT_HOVER,  
  GUIDELINE_STATE_DEPLOYED_CONSTANT_R_SELECT_HIDE,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_R_SELECT_LOCK,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_R_UNSELECT_EDIT,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_R_UNSELECT_HIDE,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_R_UNSELECT_LOCK,  
  GUIDELINE_STATE_DEPLOYED_CONSTANT_T_SELECT_EDIT,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_T_SELECT_EDIT_APPEARING,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_T_SELECT_EDIT_HOVER,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_T_SELECT_HIDE,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_T_SELECT_LOCK,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_T_UNSELECT_EDIT,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_T_UNSELECT_HIDE,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_T_UNSELECT_LOCK,   
  GUIDELINE_STATE_DEPLOYED_CONSTANT_X_SELECT_EDIT,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_X_SELECT_EDIT_APPEARING,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_X_SELECT_EDIT_HOVER,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_X_SELECT_HIDE,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_X_SELECT_LOCK,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_X_UNSELECT_EDIT,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_X_UNSELECT_HIDE,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_X_UNSELECT_LOCK,    
  GUIDELINE_STATE_DEPLOYED_CONSTANT_Y_SELECT_EDIT,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_Y_SELECT_EDIT_APPEARING,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_Y_SELECT_EDIT_HOVER,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_Y_SELECT_HIDE,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_Y_SELECT_LOCK,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_Y_UNSELECT_EDIT,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_Y_UNSELECT_HIDE,
  GUIDELINE_STATE_DEPLOYED_CONSTANT_Y_UNSELECT_LOCK,    
  GUIDELINE_STATE_DISCARDED,  
  GUIDELINE_STATE_HANDLE_R,
  GUIDELINE_STATE_HANDLE_T,
  GUIDELINE_STATE_HANDLE_X,
  GUIDELINE_STATE_HANDLE_Y,  
  NUM_GUIDELINE_STATES
};

extern QString guidelineStateAsString (GuidelineState state);

#endif // GUIDELINE_STATE_H
