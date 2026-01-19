// ================================
// Arduino Tennis Ball Launcher
// ================================

// -------- Pin configuration --------
// Motor A (Top wheel)
const int MOTOR_A_IN1 = 5;   // PWM
const int MOTOR_A_IN2 = 7;

// Motor B (Bottom wheel)
const int MOTOR_B_IN1 = 6;   // PWM
const int MOTOR_B_IN2 = 8;

// Enable pins (optional, can be tied HIGH)
const int MOTOR_EN = 9;

// Buzzer
const int BUZZER_PIN = 3;

// -------- Ball launcher module --------
struct LaunchProfile {
  int topWheelSpeed;    // 0-255
  int bottomWheelSpeed; // 0-255
  int spinUpTimeMs;     // time before launch
};

class BallLauncher {
public:
  void begin() {
    pinMode(MOTOR_A_IN1, OUTPUT);
    pinMode(MOTOR_A_IN2, OUTPUT);
    pinMode(MOTOR_B_IN1, OUTPUT);
    pinMode(MOTOR_B_IN2, OUTPUT);
    pinMode(MOTOR_EN, OUTPUT);
    digitalWrite(MOTOR_EN, HIGH);
  }

  void stop() {
    analogWrite(MOTOR_A_IN1, 0);
    analogWrite(MOTOR_B_IN1, 0);
    digitalWrite(MOTOR_A_IN2, LOW);
    digitalWrite(MOTOR_B_IN2, LOW);
  }

  void launch(const LaunchProfile& profile) {
    spinUp(profile);
    // At this point the ball is assumed to be lauched
  }

private:
  void spinUp(const LaunchProfile& profile) {
    // Forward direction
    digitalWrite(MOTOR_A_IN2, LOW);
    digitalWrite(MOTOR_B_IN2, LOW);

    analogWrite(MOTOR_A_IN1, profile.topWheelSpeed);
    analogWrite(MOTOR_B_IN1, profile.bottomWheelSpeed);

    delay(profile.spinUpTimeMs);
  }
};

// -------- Buzzer module --------
class Buzzer {
public:
  void begin() {
    pinMode(BUZZER_PIN, OUTPUT);
  }

  void beep(int times, int durationMs) {
    for (int i = 0; i < times; i++) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(durationMs);
      digitalWrite(BUZZER_PIN, LOW);
      delay(durationMs);
    }
  }
};

// -------- Launch profiles (declarative) --------
LaunchProfile FLAT_SHOT = {
  .topWheelSpeed = 200,
  .bottomWheelSpeed = 200,
  .spinUpTimeMs = 1500
};

LaunchProfile TOP_SPIN = {
  .topWheelSpeed = 230,
  .bottomWheelSpeed = 180,
  .spinUpTimeMs = 1500
};

// -------- Global objects --------
BallLauncher launcher;
Buzzer buzzer;

// -------- Arduino lifecycle --------
void setup() {
  launcher.begin();
  buzzer.begin();
}

void loop() {
  // Example usage: declarative launch
  buzzer.beep(3, 200);
  launcher.launch(TOP_SPIN);

  delay(5000); // wait before next ball
}
