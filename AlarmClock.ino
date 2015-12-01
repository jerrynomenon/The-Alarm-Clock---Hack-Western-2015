/* 
AlarmClock.ino
(C) Eastern Union Inc.  All right reserved / Tous droits réservés. 

Eastern Union is Jeremy Kim, Alex Siolas, Charlotte Ding and Andrew Jiang.

Author : Jeremy Kim, jeremy.kim@mail.mcgill.ca

In Collaboration with : Alex Siolas, Charlotte Ding and Andrew Jiang

The Alarm Clock is based on Arduino Uno (TM) with the Grove Button, LED Display and Buzzer. It requires the user to solve a math question to turn off the alarm.


*/ 

#include <rgb_lcd.h>
#include <Time.h>

int alarmHour = 9; // default alarm time
int alarmMin = 0;

int button1 = 2; // where buttons are plugged (D2 for button 1 and vice versa)
int button2 = 3;
int button3 = 4;
int button4 = 6;
int speakerPin = 8;
int buzzer = 7;

int note = 988;


rgb_lcd lcd;
void setup() {
  // put your setup code here, to run once:
    randomSeed(analogRead(0)); // initialise pseudo-random seed
    // set up the LCD's number of columns and rows:

    lcd.begin(16, 2);
    pinMode(button1, INPUT); //set button 1 as an INPUT device
    pinMode(button2, INPUT); //set button 2 as an INPUT device
    pinMode(button3, INPUT); //set button 3 as an INPUT device
    pinMode(button4, INPUT); //set button 4 as an INPUT device
    pinMode(buzzer, OUTPUT); //set buzzer as an OUTPUT device
    
    // Print a message to the LCD.

    lcd.print("Welcome / Bienvenue");
    setTime(9,59,55,28,11,2015); // default time
    delay(150);
    // scroll 13 positions (string length) to the left
    // to move it offscreen left:
    for (int positionCounter = 0; positionCounter < 18; positionCounter++) {
        // scroll one position left:
        lcd.scrollDisplayLeft();
        // wait a bit:
        delay(150);
    }

}

void alarm() {
  lcd.clear();
  int numAnswers = 4;
  int numQuestions = 4; // change when adding questions
  int whichQuestion = random(numQuestions); 
  int answer[numAnswers];
  int correct = random(numAnswers) + 1; // 1 to 4
  int a,b,c,solution;
  switch(whichQuestion) {
    case 0 : // two digit multiplication
      a = random(17) + 3; // 3 to 19
      b = random(17) + 3;
      solution = a * b;
      lcd.print(String(a) +" X "+ String(b) + "?");
      for (int i = 1; i <= numAnswers; i++) {
        if (i == correct) answer[i-1] = solution;
        else answer[i-1] = solution + random((int) (-0.60 * solution), (int) (0.60 * solution)); // 60% offset
      }
      break;
    case 1 : // three digit addition
      a = random(187) + 12; // 12 to 199
      b = random(187) + 12;
      solution = a + b;
      lcd.print(String(a) +" + "+ String(b) + "?");
      for (int i = 1; i <= numAnswers; i++) {
        if (i == correct) answer[i-1] = solution;
        else answer[i-1] = solution + random((int) (-0.60 * solution), (int) (0.60 * solution)); // 60% offset
      }
      break;

    case 2 : // three digit subtraction
      a = random(187) + 12; // 12 to 199
      b = random(187) + 12;
      solution = a - b;
      lcd.print(String(a) +" - "+ String(b) + "?");
      for (int i = 1; i <= numAnswers; i++) {
        if (i == correct) answer[i-1] = solution;
        else answer[i-1] = solution + random((int) (-0.60 * solution), (int) (0.60 * solution)); // 60% offset
      }
      break;
    case 3 : // two digit addition and subtraction
      a = random(87) + 12; // 12 to 99
      b = random(87) + 12;
      c = random(87) + 12;
      solution = a + b - c;
      lcd.print(String(a) + " + "+ String(b) + " - "+ String(c)+ "?");
      for (int i = 1; i <= numAnswers; i++) {
        if (i == correct) answer[i-1] = solution;
        else answer[i-1] = solution + random((int) (-0.60 * solution), (int) (0.60 * solution)); // 60% offset
      }
      break;
  }

  lcd.setCursor(0, 1);

  for (int i = 1; i <= numAnswers; i++) {
    lcd.print(String(i) + ". " + String(answer[i-1]) + " ");      // print out answers
  }
  
  delay(300);

  while(true){
        lcd.setRGB(255,64,64); // red backlight
        tone(speakerPin, note, 300); // alarm sound
        digitalWrite(buzzer, HIGH); // buzzer
        // scroll one position left:
        lcd.scrollDisplayLeft();

        /*
         *  detect button presses and determine if correct or not
         */
        
        if (digitalRead(button1) == 1) {
          if (correct == 1) { // correct answer
            lcd.clear();
            lcd.print("Correct!");
            digitalWrite(buzzer, LOW);
            delay(100);
            digitalWrite(buzzer, HIGH);
            delay(100);
            digitalWrite(buzzer, LOW);
            delay(100);
            digitalWrite(buzzer, HIGH);
            delay(100);
            break;
          } else { // incorrect
            lcd.clear();
            lcd.print("Incorrect!");
            delay(5000);
            alarm(); // go through another question (recursively call the alarm() )
            break;
          }
        }
        
        if (digitalRead(button2) == 1) {
          if (correct == 2) { // correct answer
            lcd.clear();
            lcd.print("Correct!");
            digitalWrite(buzzer, LOW);
            delay(100);
            digitalWrite(buzzer, HIGH);
            delay(100);
            digitalWrite(buzzer, LOW);
            delay(100);
            digitalWrite(buzzer, HIGH);
            delay(100);
            break;
          } else { // incorrect
            lcd.clear();
            lcd.print("Incorrect!");
            delay(5000);
            alarm(); // go through another question (recursively call the alarm() )
            break;
          }
        }

        if (digitalRead(button3) == 1) {
          if (correct == 3) { // correct answer
            lcd.clear();
            lcd.print("Correct!");
            digitalWrite(buzzer, LOW);
            delay(100);
            digitalWrite(buzzer, HIGH);
            delay(100);
            digitalWrite(buzzer, LOW);
            delay(100);
            digitalWrite(buzzer, HIGH);
            delay(100);
            break;
          } else { // incorrect
            lcd.clear();
            lcd.print("Incorrect!");
            delay(5000);
            alarm(); // go through another question (recursively call the alarm() )
            break;
          }
        }

        if (digitalRead(button4) == 1) {
          if (correct == 4) { // correct answer
            lcd.clear();
            lcd.print("Correct!");
            digitalWrite(buzzer, LOW);
            delay(100);
            digitalWrite(buzzer, HIGH);
            delay(100);
            digitalWrite(buzzer, LOW);
            delay(100);
            digitalWrite(buzzer, HIGH);
            delay(100);
            break;
          } else { // incorrect
            lcd.clear();
            lcd.print("Incorrect!");
            delay(5000);
            alarm(); // go through another question (recursively call the alarm() )
            break;
          }
        }
        // wait a bit and flicker:
        // adjust speed
        delay(125);
        lcd.setRGB(255,255,255);  // Flicker between white and red
        delay(125);
  }
  lcd.setRGB(255,255,255);
  digitalWrite(buzzer, LOW); // buzzer low
}
bool isLeapYear (int y) {
  return ((y % 4 == 0) && ((y % 100 != 0) || (y % 400 == 0)));
}
void changeTime(int y, int m, int d, int h, int mins, int s) {
  while(true) {
    lcd.clear();
    if (y > 2050) y = 1970;
    if (m > 12) m = 1;
    if (((d > 28) && (m==2) && !isLeapYear(y)) || ((d>29) && (m==2)) || ((d>30) && (m==4 || m==6 || m==9 || m==11)) || (d>31)) d=1;
    lcd.print("Set Date 1-Y 2-M 3-D");
    lcd.setCursor(0, 1);
    
    lcd.print(y);
    lcd.print("-");
    lcd.print(m < 10 ? "0" + String(m): m);
    lcd.print("-");
    lcd.print(d < 10 ? "0" + String(d): d);
    delay(500);
    while((digitalRead(button1) != 1) && (digitalRead(button2) != 1) && (digitalRead(button3) != 1) && (digitalRead(button4) != 1)){} // wait until button is pressed;
    if (digitalRead(button1) == 1) y++;
    if (digitalRead(button2) == 1) m++;
    if (digitalRead(button3) == 1) d++;
    if (digitalRead(button4) == 1) break;
    delay(500);
  }
  while(true) {
    lcd.clear();
    if (h>23) h = 0;
    if (mins > 59) mins = 0;
    if (s > 59) s=0;
    lcd.print("Set Time 1-H 2-M 3-S");
    lcd.setCursor(0, 1);
    
    lcd.print(h < 10 ? "0" + String(h): h);
    lcd.print(":");
    lcd.print(mins < 10 ? "0" + String(mins): mins);
    lcd.print(":");
    lcd.print(s < 10 ? "0" + String(s): s);
    delay(500);
    while((digitalRead(button1) != 1) && (digitalRead(button2) != 1) && (digitalRead(button3) != 1) && (digitalRead(button4) != 1)){} // wait until button is pressed;
    if (digitalRead(button1) == 1) h++;
    if (digitalRead(button2) == 1) mins++;
    if (digitalRead(button3) == 1) s++;
    if (digitalRead(button4) == 1) break;
    delay(500);
  }

  setTime(h,mins,s,d,m,y);
  
}

void changeAlarm() {
  while(true) {
    lcd.clear();
    
    if (alarmHour > 23) alarmHour = 0;
    if (alarmMin > 59) alarmMin = 0;

    lcd.print("Set Alarm Time 1-H 2-M 3-S");
    lcd.setCursor(0, 1);
    
    lcd.print(alarmHour < 10 ? "0" + String(alarmHour): alarmHour);
    lcd.print(":");
    lcd.print(alarmMin < 10 ? "0" + String(alarmMin): alarmMin);
    delay(500);
    while((digitalRead(button1) != 1) && (digitalRead(button2) != 1) && (digitalRead(button4) != 1)){} // wait until button is pressed;
    if (digitalRead(button1) == 1) alarmHour++;
    if (digitalRead(button2) == 1) alarmMin++;
    if (digitalRead(button4) == 1) break;
    
  }
}

void loop() {
  // put your main code here, to run repeatedly:
    lcd.clear();
    time_t t = now(); // Store the current time in time 
    if ((hour(t) == alarmHour) && (minute(t) == alarmMin) && (second(t) == 0)) {
      alarm();
    } else {
      lcd.print(year(t));
      lcd.print("-");
      lcd.print(month(t));
      lcd.print("-");
      lcd.print(day(t));
      lcd.print(" ");
      lcd.print(dayShortStr(weekday(t)));
  
      lcd.setCursor(0, 1);
      
      lcd.print(hour(t) < 10 ? "0" + String(hour(t)): hour(t));
      lcd.print(":");
      lcd.print(minute(t) < 10 ? "0" + String(minute(t)): minute(t));
      lcd.print(":");
      lcd.print(second(t) < 10 ? "0" + String(second(t)): second(t));
      
      
    }
    if (digitalRead(button1) == 1) changeTime(year(t),month(t),day(t),hour(t),minute(t),second(t));
    if (digitalRead(button2) == 1) changeAlarm();
    delay(200);
    if (digitalRead(button1) == 1) changeTime(year(t),month(t),day(t),hour(t),minute(t),second(t));
    if (digitalRead(button2) == 1) changeAlarm();
    delay(200);
    if (digitalRead(button1) == 1) changeTime(year(t),month(t),day(t),hour(t),minute(t),second(t));
    if (digitalRead(button2) == 1) changeAlarm();
    delay(200);
    if (digitalRead(button1) == 1) changeTime(year(t),month(t),day(t),hour(t),minute(t),second(t));
    if (digitalRead(button2) == 1) changeAlarm();
    delay(200);
    delay(196);
}
