#pragma once

/*
 * »тератор предоставл€ет способ перебора структуры объектов, не вдава€сь в детали их построени€.
 * ќсновна€ иде€ паттерна Iterator заключаетс€ в том, чтобы предоставить возможность осуществл€ть
 * проход по коллекции, но сам механизм передвижени€ по коллекции был реализован в отдельном объекте Ц итераторе.
 */

class Iterator abstract
{
public:
	virtual int First() abstract;
	virtual int Next() abstract;
	virtual bool IsDone() abstract;
	virtual int CurrentItem() abstract;
};
