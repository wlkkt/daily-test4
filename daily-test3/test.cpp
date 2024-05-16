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
    // 程序为什么会崩溃？？？非法访问、操作(?), 导致OS给进程发送信号啦！！ --- 为什么
    // signal(SIGSEGV, handler);
    // signal(SIGFPE, handler);
    //  崩溃了为什么会退出？默认是终止进程
    //  可以不退出吗？可以，捕捉了异常, 推荐终止进程(为什么？) --- 为什么？

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

//     alarm(1); // 设定1S后的闹钟 -- 1S --- SIGALRM
//     // sleep(4);
//     // int n = alarm(2); // alarm(0): 取消闹钟， 上一个闹钟的剩余时间
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
//     // 对信号的自定义捕捉，我们只要捕捉一次，后续一直有效
//     // 1. 一直不产生？
//     // 2. 可不可以对更多的信号进行捕捉？
//     // 3. 2 SIGINT默认是什么动作呢？终止进程
//     // 4. 2 SIGINT是什么呢？ctrl+c --- 给目标进程发送2号信号，SIGINT默认是什么动作呢？终止进程
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
        raise(9); // 每隔两秒向当前进程发送3号信号
    }
}

// // 想要以./mykill 2 进程pid 的形式运行程序
// int main(int argc, char *argv[])
// {
//     if (argc != 3) // 命令行参数不为3就报错返回
//     {
//         std::cerr << "Usage: " << argv[0] << " signum pid" << std::endl;
//         return 1;
//     }

//     pid_t pid = std::stoi(argv[2]);  // 从命令行字符串数组中获取进程pid
//     int signum = std::stoi(argv[1]); // 从命令行字符串数组中获取信号编号

//     kill(pid, signum);
//     return 0;
// }
