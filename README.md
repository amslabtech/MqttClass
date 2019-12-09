# MqttClass - MQTT C++ Wrapper Class Library

フリーのMQTTライブラリである，mosquitto の C++ ラッパーです．
内容は
- mosquitto.hpp
のヘッダファイル一つのみです．



## 使用方法

example ディレクトリにある，
- talker.cpp
- listener.cpp


を見ればわかると思いますが，どちらもラッパーのおかげで劇的に簡単になっています．

- user name （Pub/Subするそれぞれの主体の名称）
- パスワード
- ip アドレス
- ポート番号（デフォルトの場合は指定不要）
- トピック名


をそれぞれ設定して使います．


## 送受信データ

送受信するデータは任意のバイナリが使え，任意サイズが送れます．データバッファの先頭アドレスとバイト数を指定します．
通常は，任意のstructureを作成して送受信すると便利です．exampleはIMUのデータを想定したstructureを用いています．



## 受信側（subscriber）

- onMessageコールバック


によりデータを受け取ります．
受け取ったらすぐに別の共有メモリにコピーすべきです．
その場合，衝突が起こらないように mutex で保護してください．



## How to make
```
git clone https://github.com/amslabtech/MqttClass.git
cd MqttClass
mkdir build
cd build
cmake ..
make
sudo make install
```


