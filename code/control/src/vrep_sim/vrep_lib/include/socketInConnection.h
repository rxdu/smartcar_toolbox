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

#ifdef _WIN32
    #include <winsock2.h>
    #include <Windows.h>
    #include <process.h>
    #ifndef QT_COMPIL
        #pragma message("Adding library: Winmm.lib")
        #pragma comment(lib,"Winmm.lib")
        #pragma message("Adding library: Ws2_32.lib")
        #pragma comment(lib,"Ws2_32.lib")
    #endif
    typedef timeval             _timeval;
    typedef int                 _socklen;
#elif defined (__linux) || defined (__APPLE__)
    #include <string.h>
    #include <sys/time.h>
    #include <unistd.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <netdb.h>
    #define SOCKET int
    #define INVALID_SOCKET (-1)
    typedef socklen_t _socklen;
#endif


class CSocketInConnection
{
public:
    CSocketInConnection(int theConnectionPort,unsigned short maxPacketSize=250,char headerID1=59,char headerID2=57);
    virtual ~CSocketInConnection();

    bool connectToClient();
    char* receiveData(int& dataSize);
    bool replyToReceivedData(char* data,int dataSize);

    std::string getConnectedMachineIP();

protected:
    bool _sendSimplePacket(char* packet,int packetLength,unsigned short packetsLeft);
    int _receiveSimplePacket(std::vector<char>& packet);

    unsigned int _getTimeInMs();
    unsigned int _getTimeDiffInMs(unsigned int lastTime);


    SOCKET _socketServer;
    SOCKET _socketClient;
    struct sockaddr_in _socketLocal;

    fd_set _socketTheSet;
#ifdef _WIN32
    WSADATA _socketWsaData;
#endif /* _WIN32 */

    int _socketConnectionPort;
    bool _socketConnectWasOk;
    std::string _socketConnectedMachineIP;

    char _headerByte1;
    char _headerByte2;
    unsigned short _maxPacketSize;
};