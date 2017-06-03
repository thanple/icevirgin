#include "CharacterStateProvider.h"

static CharacterStateProvider * _provider = NULL;

CharacterStateProvider::CharacterStateProvider()
{
	statesMap.insert(std::map<CharacterStateType, IState *>::value_type(
		CharacterStateType::FStateAttack, new CharacterAttack()));

	statesMap.insert(std::map<CharacterStateType, IState *>::value_type(
		CharacterStateType::FStateCaster, new CharacterCaster()));

	statesMap.insert(std::map<CharacterStateType, IState *>::value_type(
		CharacterStateType::FStateDeath, new CharacterDeath()));

	statesMap.insert(std::map<CharacterStateType, IState *>::value_type(
		CharacterStateType::FStateHurt, new CharacterHurt()));

	statesMap.insert(std::map<CharacterStateType, IState *>::value_type(
		CharacterStateType::FStateNone, new CharacterNoneState()));

	statesMap.insert(std::map<CharacterStateType, IState *>::value_type(
		CharacterStateType::FStateRun, new CharacterRun()));

	statesMap.insert(std::map<CharacterStateType, IState *>::value_type(
		CharacterStateType::FStateStand, new CharacterStand()));

	statesMap.insert(std::map<CharacterStateType, IState *>::value_type(
		CharacterStateType::FStateWalk, new CharacterWalk()));
}

CharacterStateProvider * CharacterStateProvider::getInstance()
{
	if (NULL == _provider)
	{
		_provider = new CharacterStateProvider();
	}
	return _provider;
}

IState * CharacterStateProvider::getStateFromType(CharacterStateType type)
{
	return statesMap[type];
}

