#pragma once


enum Messages {
	M_INIT,
	M_EXIT,
	M_GETDATA,
	M_NODATA,
	M_TEXT,
	M_CONFIRM,
	M_INCORRECT,
	M_ACTIVE,
	M_INACTIVE,
	M_ABSENT
};

struct MsgHeader {
	string m_To;
	string m_From;
	int m_Type;
	int m_Size;
};

extern "C" {
	__declspec(dllimport) MsgHeader getM_HeaderFromString(string buffer);
	__declspec(dllimport) string getSerializeString(MsgHeader m);
}

class Message {
private:
	MsgHeader m_header;
	string m_data;
public:
	MsgHeader getM_Header() {
		return m_header;
	}

	void setM_Header(MsgHeader h) {
		m_header = h;
	}

	string getM_Data() {
		return m_data;
	}

	void setM_Data(string d) {
		m_data = d;
	}
	Message() {
		m_header.m_From="";
		m_header.m_To="";
		m_header.m_Type = -1;
		m_header.m_Size=0;

	}

	Message(string to, string from, int type = M_TEXT, const string& data = "") {
		m_header.m_From=from;
		m_header.m_To=to;
		m_header.m_Type=type;
		m_header.m_Size=data.length();
		m_data = data;
	}

	void Send(CSocket& s) {
		string buffer = getSerializeString(m_header);
		int len = buffer.size();
		s.Send(&len, sizeof(int));
		s.Send(&buffer, len);

		if (m_header.m_Type == M_TEXT) {
			s.Send(&m_data, m_header.m_Size);
		}


	}

	int Receive(CSocket& s) {
		string buffer;
		int len;
		s.Receive(&len, sizeof(int));
		s.Send(&len, sizeof(int));
		char* pBuff = new char[len + 1];
		s.Receive(pBuff, len+1);
		pBuff[len] = '\0';
		buffer = pBuff;

		m_header = getM_HeaderFromString(buffer);

		if (m_header.m_Type == M_TEXT) {
			pBuff = new char[m_header.m_Size + 1];
			s.Receive(pBuff, m_header.m_Size + 1);
			pBuff[m_header.m_Size] = '\0';
			m_data = pBuff;
			
		}
		delete[] pBuff;
		
		return m_header.m_Type;
	}

	static void SendMessage(CSocket& s, string To, string From, int Type = M_TEXT, const string& Data = "")
	{
		Message msg(To, From, Type, Data);
		msg.Send(s);
	}
};