// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "framework.h"
#include "MsgHeader.pb.h"
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}

struct MsgHeader {
    string m_To;
    string m_From;
    int m_Type;
    int m_Size;

    MsgHeader() {
        m_To = "";
        m_From = "";
        m_Type = -1;
        m_Size = 0;
    }
};

extern "C" __declspec(dllexport) MsgHeader getM_HeaderFromString(string buffer) {
    MsgHeader m_header;
    Serialize::MsgHeaderProto HeaderBuffer;
    HeaderBuffer.ParseFromString(buffer);

    
    m_header.m_From = HeaderBuffer.m_from();
    m_header.m_To = HeaderBuffer.m_to();
    m_header.m_Size = HeaderBuffer.m_size();
    m_header.m_Type = HeaderBuffer.m_type();

    return m_header;
}

extern "C" __declspec(dllexport) string getSerializeString(MsgHeader m) {
    string buffer;
    Serialize::MsgHeaderProto HeaderBuffer;

    HeaderBuffer.set_m_from(m.m_From);
    HeaderBuffer.set_m_to(m.m_To);
    HeaderBuffer.set_m_size(m.m_Size);
    HeaderBuffer.set_m_type(m.m_Type);

    bool flag=HeaderBuffer.SerializeToString(&buffer);
    //fstream out(fname, ios::out | ios::trunc | ios::binary);
    //if (!hero.SerializeToOstream(&out))
    //    throw runtime_error("saveHero() failed");

    return buffer;
}

