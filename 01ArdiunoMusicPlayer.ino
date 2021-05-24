#include "pitches.h" //含有所有旋律音高宏定义的头文件

void setup(){
  Serial.begin(9600);
}

void loop(){

  play();//播放音乐的命令

  delay(300);

}

//旋律函数

int melody[]={

  NOTE_C4, //1
  
  NOTE_D4, //2
  
  NOTE_E4, //3
  
  NOTE_C4, //1
  
  NOTE_C4, //1
  
  NOTE_D4, //2
  
  NOTE_E4, //3
  
  NOTE_C4, //1
  
  NOTE_E4, //3
  
  NOTE_F4, //4
  
  NOTE_G4, //5
  
  
  NOTE_E4, //3
  
  NOTE_F4, //4
  
  NOTE_G4, //5
  
  
  NOTE_G4, //5
  
  NOTE_A4, //6
  
  NOTE_G4, //5
  
  NOTE_F4, //4
  
  NOTE_E4, //3
  
  NOTE_C4, //1
  
  NOTE_G4, //5
  
  NOTE_A4, //6
  
  NOTE_G4, //5
  
  NOTE_F4, //4
  
  NOTE_E4, //3
  
  NOTE_C4, //1
  
  NOTE_D4, //2
  
  NOTE_G3, //.5
  
  NOTE_C4, //1
  
  0,
  
  NOTE_D4, //2
  
  NOTE_G3, //.5
  
  NOTE_C4, //1
  
  0,
};

//持续时间函数

int noteDurations[]={

  8,8,8,8,
  
  8,8,8,8,
  
  8,8,4,
  
  8,8,4,
  
  8,8,8,8,4,4,
  
  8,8,8,8,4,4,
  
  4,4,4,4,
  
  4,4,4,4,
};

//播放命令

void play()
{

  for(int thisNote = 0;thisNote<(sizeof(melody)/sizeof(melody[0]));thisNote++){
    //计算旋律持续时间
    
    //1秒（1000ms）除以音符类型
    
    //比如：四分音符：1000/noteDurations[thisNote],
    
    //八分音符：1000/noteDurations[thisNote].
    
    int noteDuration = 1000/noteDurations[thisNote];
    
    tone(11,melody[thisNote], noteDuration);//播放音乐
    
    //为了区别不同旋律，设置一个最小的间隔时间
    
    //一般设置为旋律持续时间的130%比较合适
    
    int pauseBetweenNotes = noteDuration * 1.5;
    
    delay(pauseBetweenNotes);
    
    //停止当前旋律播放
    noTone(11);
    
  }
}

//end
