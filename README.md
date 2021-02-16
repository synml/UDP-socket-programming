# TCP-communication

> 간단한 UDP 통신 프로그램입니다.

이 프로젝트는 UDP-IP를 이용하여 다른 컴퓨터와 통신할 수 있는 프로젝트입니다. 입문자라도 쉽게 이해하고 사용할 수 있도록 기초적인 네트워크 프로그래밍만 사용했습니다. 프로그래밍 학습에 유용하게 써주면 좋겠습니다.

## 프로젝트 소개

- 동기
  - 네트워크 프로그래밍을 공부하는 사람들에게 도움이 되고자 만들었습니다.
- 목적
  - 학습에 필요한 예제로 사용한다.
- 주요 기능
  - 클라이언트에서 메시지를 보내면 서버에서 그대로 돌려보내준다. (Echo 서버)

## Build Status

[![release](https://img.shields.io/github/release/clovadev/UDP-communication.svg?style=popout-square)](https://github.com/clovadev/UDP-communication/releases/latest) ![download](https://img.shields.io/github/downloads/clovadev/UDP-communication/total.svg?style=popout-square) ![license](https://img.shields.io/github/license/clovadev/UDP-communication.svg?style=popout-square) 

## 설치 방법

1. Release 뱃지를 클릭하여 릴리즈 페이지로 이동한다.
2. 가장 최신 버전을 다운로드한다. (Latest Release)
3. 추가적인 설치과정은 없고 실행파일을 더블클릭만 하면된다.

## 사용 예시

![How_to_use](https://github.com/clovadev/UDP-communication/blob/master/imgs/How_to_use.gif)

- 사용 방법
  1. UDP_Server.exe를 실행한다.
  2. UDP_Client.exe를 실행한다.
  3. 클라이언트 프로그램에서 보낼 메시지를 입력한다.
  4. Enter를 눌러 서버로 메시지를 전송한다.
  5. UDP는 연결 과정이 없으므로 X를 눌러 종료하면 된다.

## 기능

- 서버
  - 클라이언트가 보낸 메시지를 그대로 되돌려 보내준다.
- 클라이언트
  - 서버와 송수신할 수 있다.

## API, 프레임워크

- WinAPI, WinSock2


## 개발 환경

- S/W 개발 환경
  - Visual Studio 2017 Community (15.9.5)
  - Windows 10 SDK (10.0.17763.0)
  - C Language (x64 Build)
- 개발 환경 설정
  - 리포지토리를 클론, 포크하거나 압축파일로 코드를 다운로드하세요.
  - Visual Studio 2017로 솔루션 파일(.sln)을 여세요.
  - 프로젝트 속성에서 Windows SDK 버전을 자신의 컴퓨터에 설치된 버전으로 맞추세요. (10.0.17763.0 권장)
  - 코딩 시작~!

## 기여 방법

1. 이 리포지토리를 포크합니다.
2. GitHub Desktop에서 새 브랜치를 만드세요.
3. 수정사항을 커밋하세요.
4. 새 브랜치에 푸시하세요.
5. 풀리퀘스트를 보내주세요.

## 라이센스

MIT License

`LICENSE`에서 자세한 정보를 확인할 수 있습니다.
