#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig)
{
    std::cout << "get a sig: " << sig << std::endl;
}

int main()
{
    // ����Ϊʲô������������Ƿ����ʡ�����(?), ����OS�����̷����ź������� --- Ϊʲô
    // signal(SIGSEGV, handler);
    // signal(SIGFPE, handler);
    //  ������Ϊʲô���˳���Ĭ������ֹ����
    //  ���Բ��˳��𣿿��ԣ���׽���쳣, �Ƽ���ֹ����(Ϊʲô��) --- Ϊʲô��

    // int *p = nullptr;
    // *p = 100; // SIGSEGV
    int a = 10;
    a /= 0;      // 8) SIGFPE
    while (true)
    {
        std::cout << "hello bit, pid: " << getpid() << std::endl;

        sleep(1);
    }
}

// int cnt = 1;

// void handler(int sig)
// {
//     alarm(1);
//     std::cout << "cnt: " << cnt << " get a sig: " << sig << std::endl;
//     // std::cout << "get a sig: " << sig << std::endl;
//     //exit(1);
// }

// int main()
// {
//     signal(SIGALRM, handler);

//     alarm(1); // �趨1S������� -- 1S --- SIGALRM
//     // sleep(4);
//     // int n = alarm(2); // alarm(0): ȡ�����ӣ� ��һ�����ӵ�ʣ��ʱ��
//     // std::cout << "n : " << n << std::endl;
//     // sleep(10);
//     while (true)
//     {
//         std::cout << "cnt: " << cnt << std::endl;
//         cnt++;
//         sleep(1);
//     }
// }

// void handler(int sig)
// {
//     std::cout << "get a sig: " << sig << std::endl;
// }

// int main()
// {
//     int cnt = 0;
//     // signal(SIGABRT, handler);
//     for(int i = 1; i <= 31; i++)
//         signal(i, handler);

//     while (true)
//     {
//         sleep(1);
//         std::cout << "hello bit, pid: " << getpid() << std::endl;

//         // raise(3);
//         // abort();
//     }
// }

// ./mykill 2 1234
// int main(int argc, char *argv[])
// {
//     if(argc != 3)
//     {
//         std::cerr << "Usage: " << argv[0] << " signum pid" << std::endl;
//         return 1;
//     }

//     pid_t pid = std::stoi(argv[2]);
//     int signum = std::stoi(argv[1]);
//     kill(pid, signum);
// }
// int main()
// {
//     // ���źŵ��Զ��岶׽������ֻҪ��׽һ�Σ�����һֱ��Ч
//     // 1. һֱ��������
//     // 2. �ɲ����ԶԸ�����źŽ��в�׽��
//     // 3. 2 SIGINTĬ����ʲô�����أ���ֹ����
//     // 4. 2 SIGINT��ʲô�أ�ctrl+c --- ��Ŀ����̷���2���źţ�SIGINTĬ����ʲô�����أ���ֹ����
//     signal(3, hander);
//     // signal(3, hander);
//     // signal(4, hander);
//     // signal(5, hander);
//     while(true)
//     {
//         std::cout << "hello bit, pid: " << getpid() << std::endl;
//         sleep(1);
//     }
// }

#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

void hander(int sig)
{
    std::cout << "sig of " << sig << " is already get " << std::endl;
}

int main()
{
    int cnt = 0;
    signal(9, hander);
    while (true)
    {
        sleep(2);
        raise(9); // ÿ��������ǰ���̷���3���ź�
    }
}

// // ��Ҫ��./mykill 2 ����pid ����ʽ���г���
// int main(int argc, char *argv[])
// {
//     if (argc != 3) // �����в�����Ϊ3�ͱ�����
//     {
//         std::cerr << "Usage: " << argv[0] << " signum pid" << std::endl;
//         return 1;
//     }

//     pid_t pid = std::stoi(argv[2]);  // ���������ַ��������л�ȡ����pid
//     int signum = std::stoi(argv[1]); // ���������ַ��������л�ȡ�źű��

//     kill(pid, signum);
//     return 0;
// }
