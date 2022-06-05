//definir quels sons le buzzer doit faire pour chaque note.
//dans le cas de la première ligne (#define T_C 264)
      // #define est la fonction
      // T_C signifie Ton_notemusicale
      // parce qu'un Do (C en anglais) a une fréquence de 264 Hz, on écrit T_C est egal à 264  
#define T_C 264
#define T_D 294
#define T_E 330
#define T_F 349
#define T_G 392
#define T_A 440
#define T_B 493

//Ici, on definit des variables qui ne changeront jamais.
//On dit que la pin 10 sera égale à la note C, la pin 9 la note D, ect...
const int C = 2;
const int D = 3;
const int E = 4;
const int F = 5;
const int G = 6;
//const int A = 5;
//const int B = 4;

//La pin 11 est reliée à notre buzzer, donc il faut écrire que le buzzer (on le nommme Buzz) est égal à 11
//la petite lumière LED qui est déjà attachée à notre Arduino est reliée à la pin 13, donc on écrit LED = 13
const int Buzz = 11;
const int LED = 13;

void setup()
{
  pinMode(LED, OUTPUT);

  //cela veut dire que la pin C va nous donner de l'information (si on pèse le bouton ou pas), donc il "imput" de l'information
  //on dit aussi que C est HIGH, donc il n'est pas activé (on ne pèse pas dessus)
        //quand on pèse le bouton, il baisse donc on dit qu'il est LOW. Lorsqu'on ne le touche pas, il est releve donc dans à la position HIGH
  pinMode(C, INPUT);
  digitalWrite(C,HIGH);
  
  pinMode(D, INPUT);
  digitalWrite(D,HIGH);
  
  pinMode(E, INPUT);
  digitalWrite(E,HIGH);
  
  pinMode(F, INPUT);
  digitalWrite(F,HIGH);
  
  pinMode(G, INPUT);
  digitalWrite(G,HIGH);
  
/*  pinMode(A, INPUT);
  digitalWrite(A,HIGH);
  
  pinMode(B, INPUT);
  digitalWrite(B,HIGH);
  */

  digitalWrite(LED,LOW);
}

void loop()
{
  //quand on pèse sur le bouton de la note C (il sera LOW), le buzzer fera T_C (264 Hz) et la lumière LED s'allumera.
  while(digitalRead(C) == LOW)
  {
    tone(Buzz,T_C);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(D) == LOW)
  {
    tone(Buzz,T_D);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(E) == LOW)
  {
    tone(Buzz,T_E);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(F) == LOW)
  {
    tone(Buzz,T_F);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(G) == LOW)
  {
    tone(Buzz,T_G);
    digitalWrite(LED,HIGH);
  }

/*  while(digitalRead(A) == LOW)
  {
    tone(Buzz,T_A);
    digitalWrite(LED,HIGH);
  }

  while(digitalRead(B) == LOW)
  {
    tone(Buzz,T_B);
    digitalWrite(LED,HIGH);
  }
*/
  noTone(Buzz);
  digitalWrite(LED,LOW);

}
