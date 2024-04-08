#include <iostream>

using namespace std;

/*
		ѕаттерн Chain of Responsibility (÷епочка ќб€занностей) позвол€ет отделить отправител€ запроса от его получател€,
		предоставл€€ возможность нескольким классамЦобработчикам определить, кто из них может данный запрос обработать.
		“от, кто инициирует запрос, как правило, не обладает информацией о том, кто именно из классов, потенциально имеющий
		такую возможность, данный запрос в конечном итоге обработает.
		¬ такой схеме существует несколько классов Ц Handler-ов (обработчиков), каждый из которых наделЄн своими ограниченными
		возможност€ми обработки подобных запросов. ѕричЄм эти объекты - Handler-ы выстраиваютс€ в цепочку (от самых слабых до самых сильных)
		и каждый из них знает, кому он перебросит запрос в том случае, если сам не сможет справитьс€ с его обработкой.
		ѕоследний в цепочке Handler, как правило, обладающий самыми высокими возможност€ми, если сам не может обработать запрос,
		предоставл€ет какое-то поведение по умолчанию или генерирует исключение.
*/

class Receiver
{
	// банковские переводы
	bool BankTransfer;
	// денежные переводы - WesternUnion, Unistream
	bool MoneyTransfer;
	// перевод через PayPal
	bool PayPalTransfer;
public:
	Receiver(bool bt, bool mt, bool ppt)
	{
		BankTransfer = bt;
		MoneyTransfer = mt;
		PayPalTransfer= ppt;
	}
	bool GetBankTransfer()
	{
		return BankTransfer;
	}
	void SetBankTransfer(bool BankTransfer)
	{
		this->BankTransfer = BankTransfer;
	}
	bool GetMoneyTransfer()
	{
		return MoneyTransfer;
	}
	void SetMoneyTransfer(bool MoneyTransfer)
	{
		this->MoneyTransfer = MoneyTransfer;
	}
	bool GetPayPalTransfer()
	{
		return PayPalTransfer;
	}
	void SetPayPalTransfer(bool PayPalTransfer)
	{
		this->PayPalTransfer = PayPalTransfer;
	}
};

class PaymentHandler abstract
{
protected:
	PaymentHandler* Successor;
public:
	PaymentHandler* GetHandler()
	{
		return Successor;
	}
	void SetHandler(PaymentHandler* Successor)
	{
		this->Successor = Successor;
	}
	virtual void Handle(Receiver* receiver) abstract;
};

// банковский перевод
class BankPaymentHandler: public PaymentHandler
{
public:
	void Handle(Receiver* receiver) override
	{
		if (receiver->GetBankTransfer())
			cout << "Bank transfer\n";
		else if (Successor != nullptr)
			Successor->Handle(receiver);
	}
};

// переводы с помощью системы денежных переводов типа WesternUnion или Unistream
class MoneyPaymentHandler: public PaymentHandler
{
public:
	void Handle(Receiver* receiver) override
	{
		if (receiver->GetMoneyTransfer())
			cout << "Transfer through money transfer systems\n";
		else if (Successor != nullptr)
			Successor->Handle(receiver);
	}
};

// система онлайн-платежей PayPal
class PayPalPaymentHandler: public PaymentHandler
{
public:
	void Handle(Receiver* receiver) override
	{
		if (receiver->GetPayPalTransfer())
			cout << "Transfer via paypal\n";
		else if (Successor != nullptr)
			Successor->Handle(receiver);
	}
};

// Ќеобходимо отправить определенную сумму денег. 
// ќднако мы точно не знаем, какой способ отправки может использоватьс€: 
// банковский перевод, системы перевода типа WesternUnion и Unistream или система онлайн-платежей PayPal.

void Request(PaymentHandler* h, Receiver* receiver)
{
	h->Handle(receiver);
}

int main()
{
	PaymentHandler* bankPaymentHandler = new BankPaymentHandler();
	PaymentHandler* moneyPaymentHandler = new MoneyPaymentHandler();
	PaymentHandler* paypalPaymentHandler = new PayPalPaymentHandler();

	bankPaymentHandler->SetHandler(paypalPaymentHandler);
	paypalPaymentHandler->SetHandler(moneyPaymentHandler);

	Receiver* receiver = new Receiver(false, false, true);
	Request(bankPaymentHandler, receiver);
	delete receiver;

	receiver = new Receiver(false, true, false);
	Request(bankPaymentHandler, receiver);
	delete receiver;

	receiver = new Receiver(true, false, false);
	Request(bankPaymentHandler, receiver);
	delete receiver;

	delete bankPaymentHandler;
	delete moneyPaymentHandler;
	delete paypalPaymentHandler;

	system("pause");
	return 0;
}