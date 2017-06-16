//////////////////////////////////////////////////////////////////////////////
// Filename    : EffectAuraShield.cpp
// Written by  : elca
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "EffectAuraShield.h"
#include "Slayer.h"
#include "Vampire.h"
#include "Monster.h"

#include "Gpackets/GCRemoveEffect.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
EffectAuraShield::EffectAuraShield(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	Assert(pCreature != NULL);
	Assert(pCreature->isSlayer());

	setTarget(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectAuraShield::affect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectAuraShield::affect(Zone* pZone , ZoneCoord_t x , ZoneCoord_t y , Object* pObject)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectAuraShield::unaffect(Creature* pCreature)
	throw(Error)
{
	__BEGIN_TRY

	//cout << "EffectAuraShield" << "unaffect BEGIN" << endl;

	Assert(pCreature != NULL);
	Assert(pCreature->isSlayer());

	// 플래그를 끈다.
	pCreature->removeFlag(Effect::EFFECT_CLASS_AURA_SHIELD);

	Zone* pZone = pCreature->getZone();
	Assert(pZone != NULL);

	// 이펙트를 삭제하라고 알려준다.
	GCRemoveEffect gcRemoveEffect;
	gcRemoveEffect.setObjectID(pCreature->getObjectID());
	gcRemoveEffect.addEffectList(Effect::EFFECT_CLASS_AURA_SHIELD);
	pZone->broadcastPacket(pCreature->getX(), pCreature->getY(), &gcRemoveEffect);

	//cout << "EffectAuraShield" << "unaffect END" << endl;

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectAuraShield::unaffect()
	throw(Error)
{
	__BEGIN_TRY

	Creature* pCreature = dynamic_cast<Creature *>(m_pTarget);
	unaffect(pCreature);

	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void EffectAuraShield::unaffect(Zone* pZone , ZoneCoord_t x , ZoneCoord_t y , Object* pObject)
	throw(Error)
{
	__BEGIN_TRY
	__END_CATCH
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
string EffectAuraShield::toString()
	const throw()
{
	__BEGIN_TRY

	StringStream msg;
	msg << "EffectAuraShield("
		<< "ObjectID:" << getObjectID()
		<< ")";
	return msg.toString();

	__END_CATCH

}

