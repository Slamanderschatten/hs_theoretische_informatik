
start x       // Definition des Startzustands x
end e         // Definition des Endzustands e

x 0 -> x 0 R  // Solange im Zustand x, laufe ans rechte Eingabeende
x 1 -> x 1 R
x _ -> y _ L  // Am rechten Ende angekommen, gehe in Zustand y über
        
y 0 -> z 1 L  // y steht für: Übertrag 1 aufaddieren und nach links laufen
y 1 -> y 0 L  
y _ -> e 1 N  // wird das linke Wortende mit Übertrag erreicht, 
              // so wird der Übertrag 1 ans linke Wortende geschrieben
        
z 0 -> z 0 L  // im Zustand z ist kein Übertrag mehr vorhanden und es
z 1 -> z 1 L  // wird nur noch ans linke Wortende gelaufen
z _ -> e _ R  // linkes Wortende erreicht: Kopf zurück auf Ausgabestart setzen
