/*  
 _____________________________
 | ╔═╗╦╦  ╦ ╦╦╔═  ╔╗ ╔═╗╔═╗┬ |
 | ║  ║║  ║ ║╠╩╗  ╠╩╗╠═╣╠═╣│ |
 | ╚═╝╩╩═╝╚═╝╩ ╩  ╚═╝╩ ╩╩ ╩o |
 |                           |
 |___________________________|
         o
           o
            o          __---__
                    _-       /--______
               __--( /     \ )XXXXXXXXXXX\v.
             .-XXX(   O   O  )XXXXXXXXXXXXXXX-
            /XXX(       U     )        XXXXXXX\
          /XXXXX(              )--_  XXXXXXXXXXX\
         /XXXXX/ (      O     )   XXXXXX   \XXXXX\
         XXXXX/   /            XXXXXX   \__ \XXXXX
         XXXXXX__/          XXXXXX         \__---->
 ---___  XXX__/          XXXXXX      \__         /
   \-  --__/   ___/\  XXXXXX            /  ___--/=
    \-\    ___/    XXXXXX              '--- XXXXXX
       \-\/XXX\ XXXXXX                      /XXXXX
         \XXXXXXXXX   \                    /XXXXX/
          \XXXXXX      >                 _/XXXXX/
            \XXXXX--__/              __-- XXXX/
             -XXXXXXXX---------------  XXXXXX-
                \XXXXXXXXXXXXXXXXXXXXXXXXXX/
                  ""VXXXXXXXXXXXXXXXXXXV""

*/
int ininilai;

/****************************************FOR RELAY***************************************/
int andabeban = 7;
/****************************************************************************************/
void setup() {

  pinMode(7, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if (Serial.available() > 0)
  {
    ininilai = Serial.parseInt();

    if (ininilai == 221) {
      digitalWrite(andabeban, LOW);
    }
    if (ininilai == 222) {
      digitalWrite(andabeban, HIGH);
    }

    Serial.println(ininilai);
    delay(20);
  }

}
