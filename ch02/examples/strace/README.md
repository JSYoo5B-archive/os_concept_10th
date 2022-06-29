# System call trace 실험

`strace` 혹은 `dtruss` 등의 도구로 각 유저 어플리케이션이 호출하게 되는 시스템 콜 목록을 확인하기 위한 실험

## 지원 플랫폼

Linux  
(macOS의 경우, dtruss의 설정 및 실행에 문제가 있어 실험 불가능)

## 빌드 방법

```sh
# 기본 컴파일러 (gcc등) 사용 컴파일
make

# 특정 컴파일러/툴체인 지정 컴파일
make CC=musl-gcc # musl toolchain 설치 필요
```

기본 컴파일러를 활용해 빌드해도 상관없으나, glibc 등의 추가적인 코드를 제외한 순수하게 필요한 시스템 콜을 추적하려면 [musl](https://musl.libc.org/) 등의 C 구현체로 컴파일 하는 것을 추천함.

## 실행 방법

개별적으로 strace로 실행하기

```sh
# 어플리케이션 실행 명령 앞에 strace를 추가
strace ./hello

# 예제 어플리케이션 뿐만 아니라, 기본 명령어도 strace로 추적 가능
strace cp hello dummy

# strace의 결과는 stderr로 출력됨. 프로그램의 출력과 구분하려면 아래와 같이 pipe 처리
strace ./hello > /dev/null
```

모든 실행 파일의 strace 결과를 한번에 출력하기

```sh
# 빌드되어 각 소스 별 실행파일이 존재해야 함
./gen_strace_result

# 이후 *_strace_log 등의 결과 로그 파일이 생성됨
cat hello_strace_log
```

## 확인해야 하는 내용

각 프로그램의 시스템 콜 호출 내역을 `blank`의 시스템 콜 호출 내역과 비교해 볼 것  
`blank`는 어떠한 동작도 실행하지 않고 종료되는 프로그램으로, 코드 자체에서 시스템 콜이 전혀 발생하지 않음. `strace`를 통해 추적된 코드는 쉘에서 유저 어플리케이션을 실행해 주기 위해 처리되는 부분의 시스템 콜임.

man page와 비교하며 해당 시스템 콜이 제공되는 함수 형태, 커널 내부의 시스템 콜 이름과 비교해 볼 것.

