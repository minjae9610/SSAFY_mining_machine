#include "ssafy_mining_machine.h"

/*
 * Prompt Message : “ssafy>>”
 * 프로그램 실행 시, 채굴기가 자동으로 하나 생성되어 채굴 시작됨 ( 0.1초에 코인은 1씩 증가 )
 * 생성한 코인 출력 명령어 : show
 * 현재 채굴한 코인 개수 출력
 * 채굴기 생성 명령어 : add
 * 채굴기가 하나 더 추가 됨(Thread)
 * 0.1초에 코인 1씩 증가
 * 채굴기 제거 명령어 : del
 * 가장 오래된 채굴기 하나 제거 (Queue 자료구조)
 */

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
unsigned long long coin = 0;

int main(void)
{
    char cmd[100];
    command cmd_type;
    bool status;
    Queue *queue = newQueue();
    if (queue == NULL)
    {
        putstr_fd(STDERR_FILENO, "[ERROR] Queue 생성 실패\n");
        exit(1);
    }
    status = add_mining_machine(queue);
    if (status == false)
        putstr_fd(STDERR_FILENO, "[ERROR] 채굴기 추가 실패\n");

    while (true)
    {
        putstr_fd(STDOUT_FILENO, PROMPT);
        scanf("%s", cmd);
        tolower_str(cmd, strlen(cmd));
        cmd_type = valid_command(cmd);

        switch (cmd_type)
        {
        case SHOW:
            show_coin();
            break;
        case ADD:
            putstr_fd(STDOUT_FILENO, "채굴기를 추가합니다.\n");
            status = add_mining_machine(queue);
            if (status == false)
                putstr_fd(STDERR_FILENO, "[ERROR] 채굴기 추가 실패\n");
            status_mining_machine(queue);
            break;
        case DEL:
            putstr_fd(STDOUT_FILENO, "채굴기를 제거합니다.\n");
            status = del_mining_machine(queue);
            if (status == false)
                putstr_fd(STDERR_FILENO, "[ERROR] 채굴기 제거 실패\n");
            status_mining_machine(queue);
            break;
        case STATUS:
            status_mining_machine(queue);
            break;
        case EXIT:
            putstr_fd(STDOUT_FILENO, "채굴을 종료합니다.\n");
            deleteQueue(queue);
            pthread_mutex_destroy(&mutex);
            exit(0);
            break;
        default:
            putstr_fd(STDERR_FILENO, "[ERROR] 잘못된 명령어입니다.\n");
            break;
        }
    }

    return 0;
}

command valid_command(const char *cmd)
{
    if (strcmp(cmd, "show") == 0)
        return SHOW;
    else if (strcmp(cmd, "add") == 0)
        return ADD;
    else if (strcmp(cmd, "del") == 0)
        return DEL;
    else if (strcmp(cmd, "status") == 0)
        return STATUS;
    else if (strcmp(cmd, "exit") == 0)
        return EXIT;
    else
        return NONVALID;
}
