# Open Source Software Design - Assignment Archive

[cite_start]This repository contains all assignments, labs, and exam code for the Open Source Software Design (Fall 2025) course[cite: 600, 607].

## 📖 Course Information

* [cite_start]**Course:** Open Source Software Design [cite: 606]
* [cite_start]**University:** Incheon National University [cite: 607]
* [cite_start]**Semester:** Fall 2025 [cite: 607]

## 🗂️ Repository Structure

This repository is organized by week and topic. [cite_start]Each directory corresponds to a specific assignment or lecture [cite: 608-610].

* [cite_start]**week02_linux:** Introduction to Linux & Basic Commands [cite: 611]
* **week03_linux:** Introduction to Linux & Basic Commands [cite: 612]
* **week04_linux:** Introduction to Linux & Basic Commands [cite: 613]
* **week06_bash:** Assignments related to Bash scripting [cite: 614]
* **week07_gcc:** Assignments on using the GCC compiler and linking [cite: 615]
* **week08_make:** Introduction to Makefiles for project automation [cite: 616]
* **week08_make_v2:** Advanced Makefiles, including recursive calls [cite: 617]
* **week09_git:** Git for version control (branching, merging)
- Week 11: Linux System Programming (File I/O, System Calls)
* **week11_syscall_file/**: File I/O system calls

# 13주차 과제: System Call & Signal

**오픈소스SW설계 13주차 과제 제출물입니다.**
리눅스 시스템 콜과 시그널 핸들링(Signal Handling), 블로킹(Blocking)을 실습했습니다.

## 👤 학생 정보
* **학번:** 202201677
* **이름:** 장윤석

## 📂 제출 파일 설명
1. **loop.c (Q1~Q3)**
   * 무한 루프를 돌며 프로세스 ID를 출력합니다.
   * `kill` 명령어와 단축키(Ctrl+C, Z, \)를 이용해 시그널 전송 실습을 수행했습니다.

2. **Q4.c (Q4)**
   * `sigaction`을 사용하여 시그널 핸들러를 등록했습니다.
   * SIGINT(ls), SIGQUIT(date), SIGALRM(whoami) 수신 시 자식 프로세스를 생성하여 명령어를 실행합니다.

3. **Q5.c (Q5)**
   * `sigprocmask`를 사용하여 Critical Section 보호를 구현했습니다.
   * 데이터를 수정하는 동안 `SIGALRM`을 Block하여 데이터 불일치를 방지합니다.

4. **Q6.c (Q6)**
   * `sigpending`을 실습했습니다.
   * 5초간 `SIGINT`를 Block하고, 그동안 들어온 시그널이 Pending 되었는지 확인합니다.

## 🚀 컴파일 및 실행 방법
```bash
# Q4 실행
gcc Q4.c -o Q4
./Q4

# Q5 실행
gcc Q5.c -o Q5
./Q5

# Q6 실행
gcc Q6.c -o Q6
./Q6