/*
��ָOffer:
˼�����е������
*/

#include <iostream>
class A
{
    private:
    int value;

    public:
    A(int n)
    : value(n){}
    
    A( A& other )
    //A( A other) //�βδ�ֵ���´����ֵ
    {
        value = other.value;
    }

    void Printf()
    {
        std::cout << this->value << std::endl;
    }

};
int main(int arggc, char* argv[])
{
    A a = 10;
    A b = a;
    b.Printf();

}

/*
ѡ�A:������� B:����ɹ������г������ C:�����������������10*/

/*
�������캯��������ֵ�乹�캯����
*/