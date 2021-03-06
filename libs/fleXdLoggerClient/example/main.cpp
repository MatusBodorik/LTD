/*
Copyright (c) 2018, Globallogic s.r.o.
All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
 * Neither the name of the Globallogic s.r.o. nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL GLOBALLOGIC S.R.O. BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * File:   main.cpp
 * Author: Branislav Podkonicky
 *
 * Created on April 13, 2018, 2:02 PM
 */

#include <cstdlib>
#include <FleXdLogger.h>
#include <FleXdEpoll.h>
#include <unistd.h>

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

    flexd::icl::ipc::FleXdEpoll poller(10);
    std::string appname = "TestApp";
    if (argc > 1){
        appname = std::string(argv[1]);
    }
    bool init = FLEX_LOG_INIT(poller, appname)

    FLEX_LOG_DEBUG(" -> first log - This is debug log.");
    FLEX_LOG_INFO(" -> second log - This is info log.");
    FLEX_LOG_FATAL(" -> third log - This is fatal error log. This is very big problem.");
    FLEX_LOG_ERROR(" -> fourth log - This is error log.");

    if (init)
    {
        poller.loop();
    }
    return 0;
}

