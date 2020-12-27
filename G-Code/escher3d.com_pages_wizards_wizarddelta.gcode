; Controllo punto in base al sito : https://escher3d.com/pages/wizards/wizarddelta.php
G28                   ; Home
M321                  ; Disattivare temporaneamente l'autolivello
M323 S0               ; Disabilita la correzione
G1 X0       Y0   Z30
G1 X0       Y135      ; Torre Z
G30
G1 X116.91  Y67.50
G30
G1 X116.91  Y-67.50  ; Torre Y
G30
G1 X0       Y-135.00
G30
G1 X-116.91 Y-67.50  ; Torre X
G30
G1 X-116.91 Y67.50
G30
G1 X0       Y0       ; Centro
G30
G1 X0       Y0   Z100
