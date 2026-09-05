#include <Servo.h>

Servo myServo;  // Tạo đối tượng để điều khiển servo

const int potPin = A0;  // Chân cắm biến trở
const int servoPin = 9; // Chân cắm servo (D9)

int potValue;     // Biến lưu giá trị đọc từ biến trở
int angle;        // Biến lưu góc quay của servo

void setup() {
  myServo.attach(servoPin); // Khai báo chân điều khiển servo
}

void loop() {
  // Đọc giá trị Analog từ biến trở (khoảng từ 0 đến 1023)
  potValue = analogRead(potPin);            
  
  // Chuyển đổi dải giá trị từ 0-1023 của biến trở sang dải 0-180 độ của servo
  angle = map(potValue, 0, 1023, 0, 180);   
  
  // Ghi giá trị góc quay ra servo
  myServo.write(angle);                     
  
  // Đợi một khoảng thời gian ngắn để servo kịp quay tới vị trí
  delay(15);                                
}