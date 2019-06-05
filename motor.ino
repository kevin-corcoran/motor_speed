class Motor {
public:
  Motor(int control_pin) {
    pin_ = control_pin;
    speed_ = 0;
    max_volt_ = 255;
  }

  void setup() {
    pinMode(pin_, OUTPUT);
  }

  void loop() {
    analogWrite(pin_, speedToVolt(speed_));
    // if (/* condition */) {
    //   /* slowDown */
    // }
  }

  /* "Getter" returns speed */
  int getSpeed() {
    return speed_;
  }

  int getMaxVolt() {
    return max_volt_;
  }

  void setSpeed(int speed) {
    if (speed > speed_) {
      slowDown(speed);
    } else if (speed > speed_) {
      speedUp(speed);
    } // else do nothing
  }

  void setMaxVolt() {

  }

private:
  int pin_;
  int speed_;
  // 255 might be too fast. Should be determined experimentally.
  int max_volt_;

  int speedToVolt(int speed) {
    return map(speed, 0, 9, 0, max_volt_);
  }

  void speedUp(int target_speed) {
    // int volt = speedToVolt(speed_); // 0 - 255
    int target_volt = speedToVolt(target_speed);
    // for (int v = volt; v < target_volt; v += 10) {
    //   analogWrite(pin_, v);
    // }
    analogWrite(pin_, target_volt);

    speed_ = target_speed;
  }

  void slowDown(int target_speed) {
    // int volt = speedToVolt(speed_); // 0 - 255
    int target_volt = speedToVolt(target_speed);
    // for (int v = volt; v > target_volt; v -= 10) {
    //   analogWrite(pin_, v);
    // }
    analogWrite(pin_, target_volt);

    speed_ = target_speed;
  }

  void stop() {
    slowDown(0);
  }
};


/* Code for arduino sketch */ 
// Initialize Motor object at pin 9
// Motor motor(9);
// 
// void setup() {
//   motor.setup();
// }
// 
// void loop() {
//   motor.loop();
//   motor.setSpeed(9);
// }
