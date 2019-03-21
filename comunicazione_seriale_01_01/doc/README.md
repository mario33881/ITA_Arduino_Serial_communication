# COMUNICAZIONE_SERIALE
---
![](https://i.imgur.com/9m5oRKe.png)
#### Github ![](https://i.imgur.com/ej4EVF6.png)
[Visualizza questo file su github](https://gist.github.com/mario33881/)
## Descrizione ![](https://i.imgur.com/wMdaLI0.png)
---
La **comunicazione seriale** e' svolta attraverso **due sketch**:

	Trasmettitore.ino

1. Riceve all'**ingresso A0**, pin analogico, la tensione prelevata tra il 
partitore di tensione ottenuto mettendo in **serie un resistore e una fotoresistenza**. (**connessi insieme a +Vcc e a GND**).
    > **Nota:** la **tensione** e' vista da arduino come un **valore compreso tra 0 e 1023**

    ```c++
    int photoPin = A0;
    int val = 0;
    [...]
    void loop(){
        [...]
        val = analogRead(photoPin);
        [...]
    }
    ```
2. In base ad una condizione, **assegna a mex un determinato byte**.
   ```c++
    byte mex;
    [...]
    void loop(){
        [...]
        val>=1000?mex=B000:mex=B001; // if(val>=1000){mex=B000;}
                                     // else{mex=B001;}
        [...]
    }
    ```
3. **invia quel byte** attraverso la comunicazione seriale (**pin TX**)
    ```c++
    void setup(){
        Serial.begin(9600);
        [...]
    }
    void loop(){
        [...]
        Serial.write(mex);
        [...]
    }
    ```
    
    
    Ricevitore.ino

1. **Riceve sul pin RX il byte** inviato dal trasmettitore

    ```c++
    byte comando;
    [...]
    void loop(){
        if (Serial.available () > 0){
            comando = Serial.read ();
            [...]
        }
    }
    
    [...]
    
    ```
2. Con una struttura di controllo (**switch case**) distinguiamo **2 casi** particolari:
    a. Se il **byte** ricevuto e' **uguale a B000**, il livello logico del **pin "controlPin" e' alto**
    b. Se il **byte** ricevuto e' **uguale a B001**, il livello logico del **pin "controlPin" e' basso**
    > Lo **switch case** alla condizione, **non eseguira' gli altri casi**
    
   ```c++
   [...]
   void loop(){
   [...]
   if (Serial.available () > 0){
       switch (comando){
           case B000:
               // se "comando" == B000...
               Serial.println("acceso");        // visualizza sul serial monitor "acceso"
               digitalWrite(controlPin, HIGH);  // imposta il livello logico alto sul pin "controlPin"
               break;                           // esce dal switch
        
            case B001: 
                // se "comando" == B000...
                Serial.println("spento");       // visualizza sul serial monitor "spento"
                digitalWrite(controlPin, LOW);  // imposta il livello logico basso sul pin "controlPin"
                break;                          // esce dal switch
            }
        }
    }
    [...]
    
    ```
 
## Contenuto archivio ![](https://i.imgur.com/FWdiWIM.png)
---
	comunicazione_seriale_01_01/
		├── bin/
		│   ├── ricevitore/
		│   │   └─ ricevitore.ino
		│   └── trasmettitore/
		│       └─ trasmettitore.ino
		└── doc/
			└── README.md