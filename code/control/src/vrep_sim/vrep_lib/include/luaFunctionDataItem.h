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

#include <vector>
#include <string>

class CLuaFunctionDataItem
{
public:
    CLuaFunctionDataItem();
    CLuaFunctionDataItem(bool v);
    CLuaFunctionDataItem(int v);
    CLuaFunctionDataItem(float v);
    CLuaFunctionDataItem(double v);
    CLuaFunctionDataItem(const std::string& v);
    CLuaFunctionDataItem(const char* bufferPtr,unsigned int bufferLength);

    CLuaFunctionDataItem(const std::vector<bool>& v);
    CLuaFunctionDataItem(const std::vector<int>& v);
    CLuaFunctionDataItem(const std::vector<float>& v);
    CLuaFunctionDataItem(const std::vector<double>& v);
    CLuaFunctionDataItem(const std::vector<std::string>& v);

    virtual ~CLuaFunctionDataItem();

    bool isTable();
    int getType();
    void setNilTable(int size);
    int getNilTableSize();

    std::vector<bool> boolData;
    std::vector<int> intData;
    std::vector<float> floatData;
    std::vector<double> doubleData;
    std::vector<std::string> stringData;

protected:
    int _nilTableSize;
    bool _isTable;
    int _type; // -1=nil,0=bool,1=int,2=float,3=string,4=buffer,5=double
};
