//////////////////////////////////////////////////////////////////////
// 
// Filename    : GuildMemberInfo.h 
// Written By  : 
// Description :
// 
//////////////////////////////////////////////////////////////////////

#ifndef __GUILD_MEMBER_INFO_H__
#define __GUILD_MEMBER_INFO_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "Packet.h"

//////////////////////////////////////////////////////////////////////
//
// class GuildMemberInfo;
//
// Ŭ���̾�Ʈ�� ����� ����Ʈ�� ������.
//
//////////////////////////////////////////////////////////////////////

class GuildMemberInfo {

public :
	
	// constructor
	GuildMemberInfo () throw ();
	
	// destructor
	~GuildMemberInfo () throw ();

public :
	
	
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read (SocketInputStream & iStream) throw (ProtocolException, Error);
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write (SocketOutputStream & oStream) const throw (ProtocolException, Error);

	// get packet's body size
	// ����ȭ��, �̸� ���� ������ ����Ѵ�.
	PacketSize_t getSize () throw ();

	static uint getMaxSize() throw() {
		return ( szBYTE + 20 + szGuildMemberRank + szbool) * 220 + szBYTE;
	}

	// get packet's debug string
	string toString () const throw ();

	// get/set Name
	string getName() const throw() { return m_Name; }
	void setName( const string& Name ) throw() { m_Name = Name; }

	// get/set GuildMemberRank
	GuildMemberRank_t getRank() const throw() { return m_Rank; }
	void setRank( GuildMemberRank_t rank ) throw() { m_Rank = rank; }

	// get/set Guild Member LogOn
	bool getLogOn() const throw() { return m_bLogOn; }
	void setLogOn( bool logOn ) throw() { m_bLogOn = logOn; }

private :

	// �̸�
	string m_Name;

	// Guild Member Rank
	GuildMemberRank_t m_Rank;


	// Guild Member LogOn
	bool m_bLogOn;

};

#endif