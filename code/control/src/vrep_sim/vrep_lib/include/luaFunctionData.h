/*******************************************************************************
 *     Smart Car Toolbox
 *     
 *     Copyright (C) 2016 Ruixiang Du <http://rdu.im> 
 *
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *******************************************************************************/
// Copyright 2006-2016 Coppelia Robotics GmbH. All rights reserved. 
// marc@coppeliarobotics.com
// www.coppeliarobotics.com
// 
// -------------------------------------------------------------------
// THIS FILE IS DISTRIBUTED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
// WARRANTY. THE USER WILL USE IT AT HIS/HER OWN RISK. THE ORIGINAL
// AUTHORS AND COPPELIA ROBOTICS GMBH WILL NOT BE LIABLE FOR DATA LOSS,
// DAMAGES, LOSS OF PROFITS OR ANY OTHER KIND OF LOSS WHILE USING OR
// MISUSING THIS SOFTWARE.
// 
// You are free to use/modify/distribute this file for whatever purpose!
// -------------------------------------------------------------------
//
// This file was automatically created for V-REP release V3.3.2 on August 29th 2016

#pragma once

#include "luaFunctionDataItem.h"
#include "v_repLib.h"

#define SIM_LUA_ARG_NIL_ALLOWED (65536)

class CLuaFunctionData  
{
public:
    CLuaFunctionData();
    virtual ~CLuaFunctionData();

    //------------------------
    static void getInputDataForFunctionRegistration(const int* dat,std::vector<int>& outDat);
    bool readDataFromLua(const SLuaCallBack* p,const int* expectedArguments,int requiredArgumentCount,const char* functionName);
    std::vector<CLuaFunctionDataItem>* getInDataPtr();
    void pushOutData(const CLuaFunctionDataItem& dataItem);
    void writeDataToLua(SLuaCallBack* p);
    //------------------------


    //------------------------
    void pushOutData_luaFunctionCall(const CLuaFunctionDataItem& dataItem);
    void writeDataToLua_luaFunctionCall(SLuaCallBack* p,const int* expectedArguments);
    bool readDataFromLua_luaFunctionCall(const SLuaCallBack* p,const int* expectedArguments,int requiredArgumentCount,const char* functionName);
    std::vector<CLuaFunctionDataItem>* getOutDataPtr_luaFunctionCall();
    void releaseBuffers_luaFunctionCall(SLuaCallBack* p);
    //------------------------



protected:
    std::vector<CLuaFunctionDataItem> _inData;
    std::vector<CLuaFunctionDataItem> _outData;
};
