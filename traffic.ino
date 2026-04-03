// TOP light
int r1=3, g1=5, b1=6;

// MIDDLE light
int r2=10, g2=11, b2=12;

// BOTTOM light
int r3=A0, g3=A1, b3=A2;

// Buttons
int redBtn=2, yellowBtn=4, greenBtn=7, allBtn=8, whiteBtn=9;

int mode=0;

void setup() {
pinMode(r1,OUTPUT); pinMode(g1,OUTPUT); pinMode(b1,OUTPUT);
pinMode(r2,OUTPUT); pinMode(g2,OUTPUT); pinMode(b2,OUTPUT);
pinMode(r3,OUTPUT); pinMode(g3,OUTPUT); pinMode(b3,OUTPUT);

pinMode(redBtn,INPUT_PULLUP);
pinMode(yellowBtn,INPUT_PULLUP);
pinMode(greenBtn,INPUT_PULLUP);
pinMode(allBtn,INPUT_PULLUP);
pinMode(whiteBtn,INPUT_PULLUP);
}

void loop() {

if(digitalRead(redBtn)==LOW){toggle(1); delay(200);}
if(digitalRead(yellowBtn)==LOW){toggle(2); delay(200);}
if(digitalRead(greenBtn)==LOW){toggle(3); delay(200);}
if(digitalRead(allBtn)==LOW){toggle(4); delay(200);}
if(digitalRead(whiteBtn)==LOW){toggle(5); delay(200);}

updateLights();
}

void toggle(int m){
if(mode==m) mode=0;
else mode=m;
}

void offAll(){
setColor(r1,g1,b1,0,0,0);
setColor(r2,g2,b2,0,0,0);
setColor(r3,g3,b3,0,0,0);
}

void updateLights(){

offAll();

switch(mode){
case 1: setColor(r1,g1,b1,255,0,0); break;
case 2: setColor(r2,g2,b2,255,150,0); break;
case 3: setColor(r3,g3,b3,0,255,0); break;

case 4:
setColor(r1,g1,b1,255,0,0);
setColor(r2,g2,b2,255,150,0);
setColor(r3,g3,b3,0,255,0);
break;

case 5:
setColor(r1,g1,b1,255,255,255);
setColor(r2,g2,b2,255,255,255);
setColor(r3,g3,b3,255,255,255);
break;
}
}

void setColor(int rPin,int gPin,int bPin,int r,int g,int b){
analogWrite(rPin,r);
analogWrite(gPin,g);
analogWrite(bPin,b);
}
