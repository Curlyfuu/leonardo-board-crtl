#include"Keyboard.h"
#include"Mouse.h"
int oldx = 0;
int oldy = 0;
int x = 0;
int y = 0;
//SoftwareSerial mySerial(2,3);//RX=2,TX=3
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
void setup() {
  // put your setup code here, to run once:
//  Serial.begin(115200); //设置串口波特率115200
  Serial1.begin(115200);
//  inputString.reserve(200);
  
}

void loop() {
  
  

  if(stringComplete){




    if(inputString[0]='*'){
      
   
      if(inputString[1]=='C'){
        if(inputString[2]=='4'){
          Keyboard.press(KEY_LEFT_CTRL);
          delay(5);
          Keyboard.press(KEY_LEFT_GUI);
          delay(5);
          Keyboard.press(KEY_LEFT_ARROW);
          delay(5);
          Keyboard.release(KEY_LEFT_ARROW);
          delay(5);
          Keyboard.release(KEY_LEFT_GUI);
          delay(5);
          Keyboard.release(KEY_LEFT_CTRL);
        }
        else if(inputString[2]=='6'){
          Keyboard.press(KEY_LEFT_CTRL);
          delay(5);
          Keyboard.press(KEY_LEFT_GUI);
          delay(5);
          Keyboard.press(KEY_RIGHT_ARROW);
          delay(5);
          Keyboard.release(KEY_RIGHT_ARROW);
          delay(5);
          Keyboard.release(KEY_LEFT_GUI);
          delay(5);
          Keyboard.release(KEY_LEFT_CTRL);
        }
        else if(inputString[2]=='h'){
          keyClick(KEY_F5);
        }
        else if(inputString[2]=='u'){
          keyClick(KEY_UP_ARROW);
        }
        else if(inputString[2]=='d'){
          keyClick(KEY_DOWN_ARROW);
        }
        else if(inputString[2]=='l'){
          keyClick(KEY_LEFT_ARROW);
        }
        else if(inputString[2]=='r'){
          keyClick(KEY_RIGHT_ARROW);
        } 
        else if(inputString[2]=='e'){
          keyClick(KEY_ESC);      
          }
        else if(inputString[2]=='s'){
          Keyboard.press(KEY_RIGHT_ALT);
        }
        else if(inputString[2]=='g'){
          Keyboard.press(KEY_LEFT_CTRL);
          delay(5);
          Keyboard.press('l');
          delay(5);
          Keyboard.release('l');
          delay(5);
          Keyboard.release(KEY_LEFT_CTRL);
        }
        else if(inputString[2]=='m'){
          Mouse.press(MOUSE_LEFT);
          delay(5);
          Mouse.release(MOUSE_LEFT);
        }
        else if(inputString[2]=='2'){
          Mouse.press(MOUSE_MIDDLE);
          delay(5);
          Mouse.release(MOUSE_MIDDLE);
//          Mouse.click(MOUSE_MIDDLE);
        }
        else if(inputString[2]=='3'){
//          Mouse.click(MOUSE_RIGHT);
          Mouse.press(MOUSE_RIGHT);
          delay(5);
          Mouse.release(MOUSE_RIGHT);
        }
        else if(inputString[2]=='v'){
          Mouse.press(MOUSE_LEFT);
        }
        else if(inputString[2]=='^'){
          Mouse.release(MOUSE_LEFT);
        }
        
        else if(inputString[2]=='v'){
          Mouse.press(MOUSE_LEFT);
        }
        else if(inputString[2]=='^'){
          Mouse.release(MOUSE_LEFT);
        }
        
        else if(inputString[2]=='o'){
          Keyboard.press(KEY_UP_ARROW);
        }
        else if(inputString[2]=='O'){
          Keyboard.release(KEY_UP_ARROW);
        }

        else if(inputString[2]=='k'){
          Keyboard.press(KEY_DOWN_ARROW);
        }
        else if(inputString[2]=='K'){
          Keyboard.release(KEY_DOWN_ARROW);
        }


        else if(inputString[2]==';'){
          Keyboard.press('W');
        }
        else if(inputString[2]==':'){
          Keyboard.release('W');
        }
        
       else if(inputString[2]=='.'){
          Keyboard.press('S');
        }
        else if(inputString[2]=='>'){
          Keyboard.release('S');
        }

        else if(inputString[2]==','){
          Keyboard.press('A');
        }
        else if(inputString[2]=='<'){
          Keyboard.release('A');
        }

        else if(inputString[2]=='/'){
          Keyboard.press('D');
        }
        else if(inputString[2]=='?'){
          Keyboard.release('D');
        }

        else if(inputString[2]==']'){
          Keyboard.press('E');
        }
        else if(inputString[2]=='}'){
          Keyboard.release('E');
        }
                
        else if(inputString[2]=='t'){
          keyClick(KEY_TAB);
        }
        else if(inputString[2]=='n'){
          Keyboard.press(KEY_LEFT_SHIFT);
          delay(5);
          Keyboard.press(KEY_F5);
          delay(5);
          Keyboard.release(KEY_F5);
          delay(5);
          Keyboard.release(KEY_LEFT_SHIFT);
        }
      }
            
      else{
        if(inputString[1]=='x'){
        int yl = getyindex(inputString);
        x = inputString.substring(2,yl).toInt();
        y = inputString.substring(yl+1,-1).toInt();
        int x_dist = (x-oldx);
        int y_dist = (y-oldy);
        Mouse.move(x_dist,y_dist);
        oldx=x;
        oldy=y;
       }
        
       
      }
         
}
inputString="";
  stringComplete = false;
} 
}

  
int getyindex(String a){
    for(int i=0;i<a.length();i++){
      if(a[i]=='y'){
        return i;
      }
    }
}



void keyClick(int a){
  Keyboard.press(a);
  delay(1);
  Keyboard.release(a);
}

void serialEvent1() {
  while (Serial1.available()>0) {
//    if(stringComplete){
//      inputString="";
//    }
    char inChar = (char)Serial1.read();
    
    
    if(!stringComplete){

      
      if(inputString[0]=='*'){
        inputString += inChar;
      }
      else{
         if (inChar =='*'){
            inputString="*";
         }
        
      }
    }

    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
