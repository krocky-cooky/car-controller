#include "ros/ros.h" //ROSを使うときの定型文
#include "std_msgs/Int32.h" //使用するmsgのインクルード　std_msgsは標準的なmsg群のことで今回はその中でInt32を使用する
#include "std_msgs/Float32.h" //使用するmsgのインクルード std_msgsの中でFloat32を使用する。
//std_msgsの一覧　http://wiki.ros.org/std_msgs
// Bool, Byte, ByteMultiArray, Char, ColorRGBA, Duration, Empty, Float32, Float32MultiArray, Float64, Float64MultiArray, Header, Int16,
//Int16MultiArray, Int32, Int32MultiArray, Int64, Int64MultiArray, Int8, Int8MultiArray, MultiArrayDimension, MultiArrayLayout, String, Time,
//UInt16, UInt16MultiArray, UInt32, UInt32MultiArray, UInt64, UInt64MultiArray, UInt8, UInt8MultiArray
//以下よく使うもの
//Bool ... true または false
//String ... 文字列
//Float32 ... 浮動小数点
//Float32MultiArray ... 浮動小数点のリスト
//Int32 ... 整数
//Int32MultiArray ... 整数のリスト

ros::Publisher chatter_pub; //①パブリッシャーの宣言　パブリッシャーはmsgを送信する役目　ここでの変数名はchatter_pub 変数名にpubを用いることを推奨

void chatterCallback(const std_msgs::Int32::ConstPtr& rcv_msg){ //②コールバック関数 ... サブスクライバによってmsgを取得した時に実行される　void 〇〇Callback(const {msgの型}::ConstPtr& {引数名}){}が基本形
  std_msgs::Float32 float_msg; //publish用の変数の宣言 今回はstd_msgsのFloat32
  float_msg.data = ((float)rcv_msg->data)*0.1f; //std_msgs::Int32型はrcv_msg->dataで値が取得できる
  ROS_INFO("I heard: [%d], and changed to [%.1f]", rcv_msg->data, float_msg.data);  //ROS_INFOはprintfのように用いて、コンソールに文字を出力する
  chatter_pub.publish(float_msg); //float_msgの値をパブリッシュ実行　
}

int main(int argc, char **argv){ // int main(int argc, char **argv){}は定型文　ノード実行時はmain関数から処理がスタートする

  ros::init(argc, argv, "middle_event");//初期化の定型文 ros::init(argc, argv, "{ノード名}");のようにノード名を設定する。ノードの名前はファイル名と一致させることを推奨

  ros::NodeHandle n; //ノードハンドル定義の定型文　以降"n"をノードハンドルとする

  chatter_pub = n.advertise<std_msgs::Float32>("chatter_float", 1000); //パブリッシャーの設定　{①で設定したパブリッシャー変数名} = n.advertise<{msgの型}>("{パブリッシュするmsgの名前}", {バッファリング量});が基本形。バッファリング量が大きいと処理が一時的に重くなったときなどに受け取り側の読み飛ばしを減らせる。小さいと最新のデータのみを用いる。

  ros::Subscriber sub = n.subscribe("chatter_int", 1000, chatterCallback); //サブスクライバの宣言・設定　  ros::Subscriber {サブスクライバの変数名} = n.subscribe("{サブスクライブするmsgの名前}",  {バッファリング量}, {msgを受け取った時に処理する関数。ここでは②});

  ros::spin(); //メッセージがサブスクライブされるたびにコールバック関数にアクセスする処理を行う設定　return 0の直前に書く　これ以降の文は終了後に実行される 

  return 0; //mainの最後に書く
}
