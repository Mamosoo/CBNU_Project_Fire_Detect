# CBNU_Project_Fire_Detect
### 이프로젝트는 대학생 혼자 개발하여 코드상의 오류(스파게티코드) 등으로 이루어져 오류가 많을 수 도 있습니다. 하지만 제가 공부한 흔적과 저와 비슷한 프로젝트를 생각하는 사람들을 위해 업로드 합니다.

## <1> 사용센서

### 1. 불꽃감지 센서 (SZH-EK086)

### 2. 가스 센서 (SZH-SSBH-026)

### 3. 아두이노 우노 (Arduino UNO)

### 4. LCD (16×2, LiquidCrystalDisplay 1602 V1)

### 5. LCD Interface Converter (DRV1)

### 6. Bluetooth (HC-05)

## <2> 사용방법

#### 차후 회로도를 추가하여 핀번호나 애매한 부분을 수정할 예정이지만 기본적으로 코드상에 나와있는 핀번호 및 기본적인 흐름을 따라가야한다.

#### Arduino 의 Vcc 의 개수가 부족하기 때문에 Bread Board 에 배선을 미리 생각하고 제작하여야 한다.

#### 추가적인 Data sheet 는 첨부하지 않음

#### 가스센서 와 LCD 패널을 사용하기 위해서는 각 제조사에서 제공하는 라이브러리를 아두이노 스케치에 추가하여 사용해야 한다 특히 LCD 패널의 경우에는 각각의 핀에 연결하는 방식이 매우 복잡하기 때문에 부품목록의 5번에서 사용한 컨버터를 이용하는 것을 추천한다.

## <3> 코드설명

#### 불꽃 및 가스 를 감지를한다 이때 불꽃감지 센서는 Digital 이고 가스 센서의 경우 Analog 통신을 이용하기 때문에 핀세팅을 할때 주의 하여야 한다. 특히 가스센서의 경우 약간의 예열시간이 필요하며 지속적으로 사용할시 발열이 있다.

#### 블루투스 통신을 할경우 위의 라이브러리를 활용하되 기본적인 ATCOMMAND 를 참고하여 세팅하여야 한다.

#### AT+NAME, AT+PIN1234 등과 같이 디바이스에서 인식할 수 있는 이름과 비밀번호를 설정해야한다. 계속해서 반복되는 Data 가 쌓이게 되면 속도가 저하 되는 현상을 발견하여 Refresh 하는 코드를 추가하여 구성하였다.

#### LCD 의 경우 인터페이스를 활용하였기 때문에 라이브러리를 사용해야 함. https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library 위 링크의 라이브러리를 클론 또는 다운로드 하여 아두이노에 추가하여 인터페이스의 SDA 와 SCL 핀을 각각 Analog 4,5번 핀에 연결하여 사용한다.

#### 불꽃 센서의 경우 적외선 센서 이기 때문에 약간의 오차가 발생할 수 있다 현재 사용하는 센서가 가격이 저렴한 편에 속하는 센서 이기 때문에 위와 같은 문제가 발생하는 것 이다. 따라서 차후에 더욱더 크게 프로젝트를 진행 할 때에는 조금더 정밀하고 공업용에 맞춰진 센서를 이용하는 것을 추천한다

#### 위작품은 임베디드소프트웨어 개론 프로젝트를 위한 것 이므로 간단한 프로토타입으로 되어 있으니 추가적인 질문이나 궁금한 점은 이슈를 올려주시면 잘모르는 대학생 초보 개발자에게 공부할 수 있는 기회가 된다고 생각하니 사소한것 이라도 이슈를 올려주시면 정말 감사하겠습니다.
