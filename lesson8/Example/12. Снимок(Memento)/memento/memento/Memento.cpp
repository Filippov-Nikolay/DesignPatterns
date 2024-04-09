#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<ctime>
#include<windows.h>
using namespace std;
/**
 * ��������� ������ ������������� ������ ���������� ���������� ������, ����� ���
 * ���� �������� ��� ��������. ������ �� �� ���������� ��������� ���������.
 */
class Memento
{
public:
    virtual string GetName() const = 0;
    virtual string date() const = 0;
    virtual string state() const = 0;
};

/**
 * ���������� ������ �������� �������������� ��� �������� ��������� ���������.
 */
class ConcreteMemento: public Memento
{
private:
    string state_;
    string date_;

public:
    ConcreteMemento(string state) : state_(state)
    {
        state_ = state;
        time_t now = time(0);
        date_ = ctime(&now);
    }
    /**
     * ��������� ���������� ���� �����, ����� ��������������� ��� ���������.
     */
    string state() const override
    {
        return state_;
    }
    /**
     * ��������� ������ ������������ �������� ��� ����������� ����������.
     */
    string GetName() const override 
    {
        return date_ + " / (" + state_.substr(0, 9) + "...)";
    }
  string date() const override
  {
        return date_;
    }
};

/**
 * ��������� �������� ��������� ������ ���������, ������� ����� �� ��������
 * ��������. �� ����� ��������� ����� ���������� ��������� ������ ������ � �����
 * �������������� ��������� �� ����.
 */
class Originator
{
    /**
     * @var string ��� �������� ��������� ��������� �������� ������ �����
     * ����������.
     */
private:
    string state_;

    string GenerateRandomString(int length = 10) 
    {
        const char alphanum[] =
            "Hello world"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        int stringLength = sizeof(alphanum) - 1;

        string random_string;
        for (int i = 0; i < length; i++) {
            random_string += alphanum[rand() % stringLength];
        }
        return random_string;
    }

public:
    Originator(string state) : state_(state) {
        cout << "Originator: My initial state is: " << state_ << "\n";
    }
    /**
     * ������-������ ��������� ����� �������� �� ��� ���������� ���������. �������
     * ������ ������ ��������� ��������� ����������� ��������� � ������� ������
     * save ����� �������� ������� ������-������.
     */
    void DoSomething() 
    {
        cout << "Originator: I'm doing something important.\n";
        state_ = GenerateRandomString(30);
        cout << "Originator: and my state has changed to: " <<state_ << "\n";
    }

    /**
     * ��������� ������� ��������� ������ ������.
     */
    Memento* Save() 
    {
        return new ConcreteMemento(state_);
    }
    /**
     * ��������������� ��������� ��������� �� ������� ������.
     */
    void Restore(Memento* memento)
    {
        state_ = memento->state();
       cout << "Originator: My state has changed to: " << state_ << "\n";
    }
};

/**
 * ������ �� ������� �� ������ ����������� ������. ����� �������, �� �� �����
 * ������� � ��������� ���������, ����������� ������ ������. �� �������� ��
 * ����� �������� ����� ������� ��������� ������.
 */
class Caretaker 
{
    /**
     * @var Memento[]
     */
private:
    vector<Memento*> mementos_;

    /**
     * @var Originator
     */
    Originator * originator_;

public:
    Caretaker(Originator* originator) : originator_(originator)
    {
        //originator_ = originator;
    }

    void Backup() 
    {
        cout << "\nCaretaker: Saving Originator's state...\n";
        mementos_.push_back(originator_->Save());
    }
    void Undo()
    {
        if (!this->mementos_.size())
        {
            return;
        }
        Memento* memento = mementos_.back();
        mementos_.pop_back();
        cout << "Caretaker: Restoring state to: " << memento->GetName() << "\n";
        try
        {
           originator_->Restore(memento);
        }
        catch (...) 
        {
            Undo();
        }
    }
    void ShowHistory() const 
    {
        cout << "Caretaker: Here's the list of mementos:\n";
        for (auto memento : mementos_)
        {
            cout << memento->GetName() << "\n";
        }
    }
};
/**
 * ���������� ���.
 */
void ClientCode()
{
    Originator* originator = new Originator("Super-duper-super-puper-super.");
    Caretaker* caretaker = new Caretaker(originator);
    caretaker->Backup();
    originator->DoSomething();
    caretaker->Backup();
    originator->DoSomething();
    caretaker->Backup();
    originator->DoSomething();
    cout << "\n";
    caretaker->ShowHistory();
    cout << "\nClient: Now, let's rollback!\n\n";
    caretaker->Undo();
    cout << "\nClient: Once more!\n\n";
    caretaker->Undo();

    cout << "\n-------------------------------------------\n";
    caretaker->ShowHistory();
    delete originator;
    delete caretaker;
}

int main()
{
 srand((unsigned)time(NULL));
    ClientCode();
    return 0;
}