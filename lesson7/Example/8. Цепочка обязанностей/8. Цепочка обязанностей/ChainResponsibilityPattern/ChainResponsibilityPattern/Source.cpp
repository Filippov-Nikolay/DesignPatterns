#include <iostream>

using namespace std;

/*
		������� Chain of Responsibility (������� ������������) ��������� �������� ����������� ������� �� ��� ����������,
		������������ ����������� ���������� ������������������� ����������, ��� �� ��� ����� ������ ������ ����������.
		���, ��� ���������� ������, ��� �������, �� �������� ����������� � ���, ��� ������ �� �������, ������������ �������
		����� �����������, ������ ������ � �������� ����� ����������.
		� ����� ����� ���������� ��������� ������� � Handler-�� (������������), ������ �� ������� ������ ������ �������������
		������������� ��������� �������� ��������. ������ ��� ������� - Handler-� ������������� � ������� (�� ����� ������ �� ����� �������)
		� ������ �� ��� �����, ���� �� ���������� ������ � ��� ������, ���� ��� �� ������ ���������� � ��� ����������.
		��������� � ������� Handler, ��� �������, ���������� ������ �������� �������������, ���� ��� �� ����� ���������� ������,
		������������� �����-�� ��������� �� ��������� ��� ���������� ����������.
*/

class Receiver
{
	// ���������� ��������
	bool BankTransfer;
	// �������� �������� - WesternUnion, Unistream
	bool MoneyTransfer;
	// ������� ����� PayPal
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

// ���������� �������
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

// �������� � ������� ������� �������� ��������� ���� WesternUnion ��� Unistream
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

// ������� ������-�������� PayPal
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

// ���������� ��������� ������������ ����� �����. 
// ������ �� ����� �� �����, ����� ������ �������� ����� ��������������: 
// ���������� �������, ������� �������� ���� WesternUnion � Unistream ��� ������� ������-�������� PayPal.

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