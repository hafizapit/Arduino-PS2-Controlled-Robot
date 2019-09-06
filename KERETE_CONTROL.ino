/*
 * Code By: Mohamad Hafiz Bin Ahmad
 * Email: hafiz_apik99@yahoo.com
*/

#include <SoftwareSerial.h> 
#include <Cytron_PS2Shield.h>  // https://github.com/CytronTechnologies/Cytron_PS2Shield ( utk download library )
#include <CytronMotorDriver.h> // https://github.com/CytronTechnologies/CytronMotorDriver 

Cytron_PS2Shield ps2(2, 3); // pastikan jumper ada pada ps2 shield pada D2  dan D3

// Configure the motor driver.
CytronMD motor1(PWM_PWM, 4, 5);   // PWM 1A = Pin 5, PWM 1B = Pin 4. Kalau motor pusing terbalik, tukarkan PWM 1A = Pin 4, PWM 1B = Pin 5
CytronMD motor2(PWM_PWM, 6, 7); // PWM 2A = Pin 7, PWM 2B = Pin 6. Kalau motor pusing terbalik, tukarkan PWM 2A = Pin 6,PWM 2B = Pin 7

void setup()
{
  ps2.begin(9600); // Pastikan jumper ada pada 9.6k
  Serial.begin(9600); // Set monitor baudrate to 9600
}

void loop()
{
  /*
   * Nilai PWM adalah daripada 0-255
   * Anda boleh ubah nilai mengikut kesesuaian dan kelajuan robot anda
  */
     if(ps2.readButton(PS2_UP)==0)// 0 maksudnya button tgh ditekan
   { 
    
  Serial.println("Forward");
  motor1.setSpeed(128);   // Motor 1 runs forward at 50% speed.
  motor2.setSpeed(255);  // Motor 2 runs forward at 100% speed.
  
  }

      else if(ps2.readButton(PS2_DOWN)==0)
   { 
    
  Serial.println("backward");
  motor1.setSpeed(-255);   // Motor 1 runs backward at 100% speed.
  motor2.setSpeed(-128);  // Motor 2 runs backward at 50% speed.
  
  }

      else if(ps2.readButton(PS2_RIGHT)==0)
   { 
    
  Serial.println("right");
  motor1.setSpeed(128);   // Motor 1 runs forward at 50% speed.
  motor2.setSpeed(0);  // Motor 2 stops
  
  }

       else if(ps2.readButton(PS2_LEFT)==0)
   { 
    
  Serial.println("left");
  motor1.setSpeed(0);   // Motor 1 stops.
  motor2.setSpeed(128);  // Motor 2 runs forward at 50% speed.
  
  }
  
  else{
  Serial.println("stop");
  motor1.setSpeed(0);   
  motor2.setSpeed(0);   
  }
}
