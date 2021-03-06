//////////////////////////////////////////////////////////////////////////////
// Filename    : ItemIDRegistry.cpp
// Written by  : excel96
// Description :
// 각 아이템 구현 파일에서 initItemIDRegistry 멤버 함수만을 빼서
// 구현해놓은 파일이다.
//////////////////////////////////////////////////////////////////////////////

#include "DB.h"
#include "ItemInfoManager.h"

#include "Motorcycle.h"
#include "Potion.h"
#include "Water.h"
#include "HolyWater.h"
#include "Magazine.h"
#include "BombMaterial.h"
#include "ETC.h"
#include "Key.h"
#include "Ring.h"
#include "Bracelet.h"
#include "Necklace.h"
#include "Coat.h"
#include "Trouser.h"
#include "Shoes.h"
#include "Sword.h"
#include "Blade.h"
#include "Shield.h"
#include "Cross.h"
#include "Mace.h"
#include "Glove.h"
#include "Helm.h"
#include "SG.h"
#include "SMG.h"
#include "AR.h"
#include "SR.h"
#include "Bomb.h"
#include "Mine.h"
#include "Belt.h"
#include "LearningItem.h"
#include "Money.h"
#include "VampireRing.h"
#include "VampireBracelet.h"
#include "VampireNecklace.h"
#include "VampireCoat.h"
#include "Skull.h"
#include "Serum.h"
#include "VampireETC.h"
#include "SlayerPortalItem.h"
#include "VampirePortalItem.h"
#include "EventGiftBox.h"
#include "EventStar.h"
#include "VampireEarring.h"
#include "Relic.h"
#include "VampireWeapon.h"
#include "VampireAmulet.h"
#include "QuestItem.h"
#include "EventTree.h"
#include "EventETC.h"
#include "BloodBible.h"
#include "CastleSymbol.h"
#include "CoupleRing.h"
#include "VampireCoupleRing.h"
#include "EventItem.h"
#include "DyePotion.h"
#include "ResurrectItem.h"
#include "MixingItem.h"
#include "OustersArmsband.h"
#include "OustersBoots.h"
#include "OustersChakram.h"
#include "OustersCirclet.h"
#include "OustersCoat.h"
#include "OustersPendent.h"
#include "OustersRing.h"
#include "OustersStone.h"
#include "OustersWristlet.h"
#include "Larva.h"
#include "Pupa.h"
#include "ComposMei.h"
#include "OustersSummonItem.h"
#include "EffectItem.h"
#include "CodeSheet.h"
#include "MoonCard.h"
#include "Sweeper.h"
#include "PetItem.h"
#include "PetFood.h"
#include "PetEnchantItem.h"
#include "LuckyBag.h"

void Motorcycle::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from MotorcycleObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM MotorcycleObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Motorcycle...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Potion::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		//pStmt = g_pDatabaseManager->getConnection("DIST_DARKEDEN")->createStatement();
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from PotionObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			//pStmt = g_pDatabaseManager->getConnection("DIST_DARKEDEN")->createStatement();
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM PotionObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Potion...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Water::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from WaterObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM WaterObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Water...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void HolyWater::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from HolyWaterObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM HolyWaterObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "HolyWater...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Magazine::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from MagazineObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM MagazineObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Magazine...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void BombMaterial::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from BombMaterialObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM BombMaterialObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "BombMaterial...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void ETC::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from ETCObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM ETCObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "ETC...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Key::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from KeyObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM KeyObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Key...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Ring::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from RingObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM RingObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Ring...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Bracelet::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from BraceletObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM BraceletObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Bracelet...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Necklace::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from NecklaceObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM NecklaceObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Necklace...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Coat::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from CoatObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM CoatObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Coat...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Trouser::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from TrouserObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM TrouserObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Trouser...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Shoes::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from ShoesObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM ShoesObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Shoes...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Sword::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from SwordObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM SwordObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Sword...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Blade::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from BladeObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM BladeObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Blade...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Shield::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from ShieldObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM ShieldObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Shield...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Cross::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from CrossObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM CrossObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Cross...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Mace::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from MaceObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM MaceObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Mace...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Glove::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from GloveObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM GloveObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Glove...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Helm::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from HelmObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM HelmObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Helm...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void SG::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from SGObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM SGObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "SG...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void SMG::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from SMGObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM SMGObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "SMG...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void AR::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from ARObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM ARObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "AR...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void SR::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from SRObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM SRObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "SR...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Bomb::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from BombObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM BombObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Bomb...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Mine::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from MineObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM MineObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Mine...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Belt::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from BeltObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM BeltObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Belt...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void LearningItem::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from LearningItemObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM LearningItemObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "LearningItem...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Money::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from MoneyObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM MoneyObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Money...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void VampireRing::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from VampireRingObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM VampireRingObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "VampireRing...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}


void VampireBracelet::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from VampireBraceletObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM VampireBraceletObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "VampireBracelet...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void VampireNecklace::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from VampireNecklaceObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM VampireNecklaceObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "VampireNecklace...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void VampireCoat::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from VampireCoatObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM VampireCoatObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "VampireCoat...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Skull::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from SkullObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM SkullObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Skull...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Serum::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from SerumObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM SerumObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Serum...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void VampireETC::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from VampireETCObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM VampireETCObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "VampireETC...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void SlayerPortalItem::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from SlayerPortalItemObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM SlayerPortalItemObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "SlayerPortalItem...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void VampirePortalItem::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from VampirePortalItemObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM VampirePortalItemObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "VampirePortalItem...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void EventGiftBox::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from EventGiftBoxObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM EventGiftBoxObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "GiftBox...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void EventStar::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from EventStarObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM EventStarObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "EventStar...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void VampireEarring::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from VampireEarringObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM VampireEarringObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "VampireEarring...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Relic::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from RelicObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM RelicObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "RelicObject...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void VampireWeapon::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from VampireWeaponObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM VampireWeaponObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "VampireWeaponObject...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void VampireAmulet::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from VampireAmuletObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM VampireAmuletObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "VampireAmuletObject...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void QuestItem::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from QuestItemObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM QuestItemObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "QuestItem...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void EventTree::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from EventTreeObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM EventTreeObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "EventTree...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void EventETC::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from EventETCObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM EventETCObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "EventETC...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void BloodBible::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from BloodBibleObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM BloodBibleObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "BloodBible...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void CastleSymbol::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from CastleSymbolObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM CastleSymbolObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "CastleSymbol...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void CoupleRing::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from CoupleRingObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM CoupleRingObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "CoupleRing...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void VampireCoupleRing::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from VampireCoupleRingObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM VampireCoupleRingObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "CoupleRing...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void EventItem::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from EventItemObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM EventItemObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "EventItem...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void DyePotion::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from DyePotionObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM DyePotionObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "DyePotion...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}
	
void ResurrectItem::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from ResurrectItemObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM ResurrectItemObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "ResurrectItem...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void MixingItem::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from MixingItemObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM MixingItemObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "MixingItem...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void OustersArmsband::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from OustersArmsbandObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM OustersArmsbandObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "OustersArmsband...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void OustersBoots::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from OustersBootsObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM OustersBootsObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "OustersBoots...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void OustersChakram::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from OustersChakramObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM OustersChakramObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "OustersChakram...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void OustersCirclet::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from OustersCircletObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM OustersCircletObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "OustersCirclet...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void OustersCoat::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from OustersCoatObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM OustersCoatObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "OustersCoat...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void OustersPendent::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from OustersPendentObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM OustersPendentObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "OustersPendent...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void OustersRing::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from OustersRingObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM OustersRingObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "OustersRing...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void OustersStone::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from OustersStoneObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM OustersStoneObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "OustersStone...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void OustersWristlet::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from OustersWristletObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM OustersWristletObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "OustersWristlet...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Larva::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from LarvaObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM LarvaObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Larva...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Pupa::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from PupaObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM PupaObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Pupa...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void ComposMei::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from ComposMeiObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM ComposMeiObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "ComposMei...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void OustersSummonItem::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from OustersSummonItemObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM OustersSummonItemObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "OustersSummonItem...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void EffectItem::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from EffectItemObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM EffectItemObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "EffectItem...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}
	
void CodeSheet::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from CodeSheetObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM CodeSheetObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "CodeSheet...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void MoonCard::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from MoonCardObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM MoonCardObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "MoonCard...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void Sweeper::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from SweeperObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM SweeperObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "Sweeper...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void PetItem::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from PetItemObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM PetItemObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "PetItem...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void PetFood::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from PetFoodObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM PetFoodObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "PetFood...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void PetEnchantItem::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL; 

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from PetEnchantItemObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM PetEnchantItemObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "PetEnchantItem...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}

void LuckyBag::initItemIDRegistry(void)
	throw()
{
	__BEGIN_TRY

	Statement* pStmt = NULL;

	__ENTER_CRITICAL_SECTION(m_Mutex)

	BEGIN_DB
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
		Result* pCountResult = pStmt->executeQuery("SELECT COUNT(*) from LuckyBagObject");
		pCountResult->next();
		int count = pCountResult->getDWORD(1);
		SAFE_DELETE(pStmt);

		if (count != 0)
		{
			pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();
			Result* pResult = pStmt->executeQuery("SELECT MAX(ItemID) FROM LuckyBagObject");
			pResult->next();
			m_ItemIDRegistry = pResult->getDWORD(1);
			SAFE_DELETE(pStmt);
		}

		m_ItemIDRegistry +=(g_pItemInfoManager->getItemIDSuccessor() - (m_ItemIDRegistry % g_pItemInfoManager->getItemIDSuccessor())) + g_pItemInfoManager->getItemIDBase();
	}
	END_DB(pStmt)

	__LEAVE_CRITICAL_SECTION(m_Mutex)

	cout << "LuckyBag...ItemIDRegistry:" << m_ItemIDRegistry << endl;

	__END_CATCH
}


