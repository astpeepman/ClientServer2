// Server.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include "framework.h"
#include "Server.h"
#include "Message.h"
#include "Session.h"
#include "User.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Единственный объект приложения

CWinApp theApp;

using namespace std;

map<string,User> Users;

void TimeOut() {
    while (true)
    {
        for (auto i : Users) {
            double workTime = clock() - i.second.GetActiveTime();
            if (workTime > 150000 && i.second.GetStatus() == true) {
                cout << "Client " << i.first << " has been disconnected due to long inactivity" << endl;
                i.second.InActive();
            }
        }
        Sleep(1000);
    }
}

void ProcessClient(SOCKET hSock) {
    CSocket s;
    s.Attach(hSock);
    Message m;

    switch (m.Receive(s))
    {
    case M_INIT: {
        bool findUser = false;
        Message::SendMessage(s, m.getM_Header().m_From, "@SERVER", M_CONFIRM);
        //Получаем пароль
        int len; string Password;
        s.Receive(&len, sizeof(int));
        char* pBuff = new char[len+1];
        s.Receive(pBuff, len+1);
        pBuff[len] = '\0';
        Password = pBuff;
        delete[] pBuff;
        
        for (auto  i : Users) {
            if (m.getM_Header().m_From == i.second.getU_Login()) {
                
                if (Password == i.second.getU_Pass()) {
                    if (i.second.GetStatus()) {
                        Message::SendMessageW(s, m.getM_Header().m_From, "@SERVER", M_ACTIVE);
                    }
                    else {
                        i.second.Active();
                        i.second.Send(s, clock());
                        cout << "Client " << m.getM_Header().m_From << " connected" << endl;
                        Message::SendMessage(s, m.getM_Header().m_From, "@SERVER", M_CONFIRM);
                    }
                    
                }
                else {
                    Message::SendMessage(s, m.getM_Header().m_From, "@SERVER", M_INCORRECT);
                }
                findUser = true;
                break;
                
            }

        }
        if (!findUser) {
            User u_buffer(m.getM_Header().m_From, Password, Session(), clock());
            Users[u_buffer.getU_Login()] = u_buffer;
            
            cout << "Client " << u_buffer.getU_Login() << " connected" << endl;
            Message::SendMessage(s, m.getM_Header().m_From, "@SERVER", M_CONFIRM);
        }
        break;
    }
    case M_EXIT: {
        if (Users[m.getM_Header().m_From].GetStatus()) {
            Users[m.getM_Header().m_From].InActive();
            cout << "Client " << m.getM_Header().m_From << " disconnected" << endl;
            Message::SendMessage(s, m.getM_Header().m_From, "@SERVER", M_CONFIRM);
        }
        else {
            Message::SendMessage(s, m.getM_Header().m_From, "@SERVER", M_INACTIVE);
        }
        break;
    }
    case M_GETDATA: {
        if (Users[m.getM_Header().m_From].GetStatus()) {
            Users[m.getM_Header().m_From].Send(s, clock());
        }
        break;
    }
    default: {
        if (Users.find(m.getM_Header().m_From) != Users.end()) {
            if (Users.find(m.getM_Header().m_To) != Users.end()) {
                Users[m.getM_Header().m_To].AddMsg(m);
                if (!Users[m.getM_Header().m_To].GetStatus()) {
                    Message::SendMessage(s, m.getM_Header().m_From, "@SERVER", M_INACTIVE);
                }
                else {
                    Message::SendMessage(s, m.getM_Header().m_From, "@SERVER", M_CONFIRM);
                }
            }
            else if (m.getM_Header().m_To == "@ALL") {
                for (auto i : Users) {
                    if (i.first != m.getM_Header().m_From) {
                        i.second.AddMsg(m);
                    }
                }
                Message::SendMessage(s, m.getM_Header().m_From, "@SERVER", M_CONFIRM);
            }
            else {
                Message::SendMessage(s, m.getM_Header().m_From, "@SERVER", M_ABSENT);
            }
            Users[m.getM_Header().m_From].SetActiveTime(clock());
        }
        break;
    }
    }
}

void start() {
  /*  Message m;
    MsgHeader m_Header;
    m_Header.m_To = "testTo";
    m_Header.m_From = "testFrom";
    m_Header.m_Size = 1;
    m_Header.m_Type = 2;

    m.setM_Header(m_Header);

    string buffer= getSerializeString(m_Header);


    MsgHeader NewM_Header = getM_HeaderFromString(buffer);

    cout << "Complete" << endl;*/

    AfxSocketInit();
    CSocket Server;
    Server.Create(11111);

    thread tt(TimeOut);
    tt.detach();

    while (true)
    {
        Server.Listen();
        CSocket s;
        Server.Accept(s);
        thread t(ProcessClient, s.Detach());
        t.detach();
    }
}

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // инициализировать MFC, а также печать и сообщения об ошибках про сбое
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: вставьте сюда код для приложения.
            wprintf(L"Критическая ошибка: сбой при инициализации MFC\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: вставьте сюда код для приложения.
            start();
        }
    }
    else
    {
        // TODO: измените код ошибки в соответствии с потребностями
        wprintf(L"Критическая ошибка: сбой GetModuleHandle\n");
        nRetCode = 1;
    }

    return nRetCode;
}
