; Controllo Base Torri con il Centro.
G28                   ; Home
M321                  ; Disattivare temporaneamente l'autolivello
M323 S0               ; Disabilita la correzione
G1 X0       Y0   Z30 
;
G1 X0       Y0        ; To Center
G30
G1 X-116.91 Y-67.50   ; Tower X
G30
G1	X116.91 Y-67.50   ; Tower Y
G30
G1 X0       Y135      ; Tower Z
G30
G1 X0       Y0   Z100 ; To Center Z=100
