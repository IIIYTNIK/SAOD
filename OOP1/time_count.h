#pragma once

#include <ctime>    // ���������� ��� ������ � (time)
#include <chrono>   // ���������� ��� ������� ������� (������� �����)
#include <iostream>

using namespace std;
namespace time_count {
    //��������� ������� ������ ������� ���� - func
    template<typename Func> //Func - �������������� ���, ��������� �� �������
    int measure_time(Func func) {
        auto t1 = std::chrono::steady_clock::now(); //������� ����� �� ���������� ����
        func(); //���������� ���������� ����
        auto t2 = std::chrono::steady_clock::now(); //������� ����� ����� ���������� ����

        auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1); // ������� ������� 
        cout << "Time milliseconds: " << delta.count() << endl;
        return delta.count();
    }
}
