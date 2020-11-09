using Serialize;
using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using Google.Protobuf;
using System.Net.Sockets;

namespace Client
{

	

	public enum Messages
	{
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
	}
	class Message
	{
		private MsgHeaderProto m_Header;
		private string m_Data;

		public static string SerializeToString_PB(MsgHeaderProto m)
		{
			using (MemoryStream ms = new MemoryStream())
			{
				m.WriteTo(ms);
				return Convert.ToBase64String(ms.GetBuffer(), 0, (int)ms.Length);
			}
		}

		public static MsgHeaderProto DeserializeFromString_PB(string str)
		{
			byte[] arr = Convert.FromBase64String(str);
			using (MemoryStream ms = new MemoryStream(arr))
			{
				return MsgHeaderProto.Parser.ParseFrom(ms);
			}

		}


		public MsgHeaderProto GetM_Header()
		{
			return m_Header;
		}
		public string getM_Data()
		{
			return m_Data;
		}
		public void setM_Data(string d)
		{
			m_Data = d;
		}
		public Message()
		{
			m_Header = new MsgHeaderProto();
			m_Header.MTo = "";
			m_Header.MFrom = "";
			m_Header.MSize = -1;
			m_Header.MType = -1;
		}
		public Message(string To, string From, Messages Type = Messages.M_TEXT, string Data = "")
		{
			m_Header = new MsgHeaderProto();
			m_Header.MTo = To;
			m_Header.MFrom = From;
			m_Header.MType = (int)Type;
			m_Data = Data;
			m_Header.MSize = Data.Length;
		}

		public void Send(Socket s)
		{
			string buffer = SerializeToString_PB(m_Header);
			int len = buffer.Length;
			s.Send(BitConverter.GetBytes(len), sizeof(int), SocketFlags.None);
            byte[] b = new byte[4];
            s.Receive(b, sizeof(int), SocketFlags.None);
            int bufferSize = BitConverter.ToInt32(b, 0);
            if (bufferSize == len)
                s.Send(Encoding.UTF8.GetBytes(buffer), len, SocketFlags.None);

			if (m_Header.MType == (int)Messages.M_TEXT)
			{
				s.Send(Encoding.UTF8.GetBytes(m_Data), m_Header.MSize, SocketFlags.None);
			}

		}

		public MsgHeaderProto Receive(Socket s)
		{

			byte[] b = new byte[4];
			s.Receive(b, sizeof(int), SocketFlags.None);
			int bufferSize = BitConverter.ToInt32(b, 0);
			b = new byte[bufferSize];
			s.Receive(b, bufferSize, SocketFlags.None);
			StringBuilder builder = new StringBuilder();
			builder.Append(Encoding.UTF8.GetString(b, 0, bufferSize));
			m_Header = DeserializeFromString_PB(builder.ToString());

			if (m_Header.MType == (int)Messages.M_TEXT)
            {
				b = new byte[m_Header.MSize];
                s.Receive(b, m_Header.MSize, SocketFlags.None);
                builder = new StringBuilder();
                builder.Append(Encoding.UTF8.GetString(b, 0, m_Header.MSize));
                m_Data = builder.ToString();
            }
			return m_Header;

		}

		public void SendMessage(Socket s, string To, string From, Messages Type = Messages.M_TEXT, string Data = "")
		{
			Message msg = new Message(To, From, Type, Data);
			msg.Send(s);
		}
	}
}
